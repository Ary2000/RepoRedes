from zipfile import ZipFile
import datetime
import pyaudio
import wave
import json
import matplotlib.pyplot as plt
import numpy as np
from tkinter import TclError

# https://www.geeksforgeeks.org/working-zip-files-python/
# https://stackoverflow.com/questions/19371860/python-open-file-in-zip-without-temporarily-extracting-it
default_file_name = "output.atm"

# Se verifica si el archivo output.atm existe
try:
    # Si existe se imprimen información de este archivo
    with ZipFile(default_file_name, 'r') as zip:
        for info in zip.infolist():
            print(info.filename)
            print('\tModified:\t' + str(datetime.datetime(*info.date_time)))
            print('\tSystem:\t\t' + str(info.create_system) +
                  '(0 = Windows, 3 = Unix)')
            print('\tZIP version:\t' + str(info.create_version))
            print('\tCompressed:\t' + str(info.compress_size) + ' bytes')
            print('\tUncompressed:\t' + str(info.file_size) + ' bytes')
except:
    # Si no existe se le notifica al usuario que no existe y se
    # cierra el programa
    print("Archivo output.atm no existe")
    exit()

file = ""
jsonFile = ""
# Se sacan los archivos que se encuentran dentro del atm
with ZipFile(default_file_name, 'r') as zip:
    file = zip.open("output.wav")
    jsonFile = zip.open("puntos.json")

# https://www.youtube.com/watch?v=fVJTrcEqgIo
# https://www.w3schools.com/python/python_json.asp
puntos = json.load(jsonFile)
chunk = 1024 * 2
sample_format = pyaudio.paInt16
channels = 1
rate = 44100
# Se sacan los puntos del archivo json que estaba dentro del atm
puntosAudio = puntos["puntosAudio"]
puntosFFT = puntos["puntosFFT"]

# Se crean las graficas
fig, (ax, ax2) = plt.subplots(2, figsize=(15, 8))

# Se le dan atributos a las gráficas
x = np.arange(0, 2 * chunk, 2)
xf = np.linspace(0, rate, chunk)     # frequencies (spectrum)
line, = ax.plot(x, np.random.rand(chunk), '-', lw=2)
ax.set_title('AUDIO WAVEFORM')
ax.set_xlabel('samples')
ax.set_ylabel('volume')
ax.set_ylim(0, 255)
ax.set_xlim(0, chunk)
plt.setp(ax, xticks=[0, chunk, 2 * chunk], yticks=[0, 128, 255])
x_fft = np.linspace(0, rate, chunk)
line_fft, = ax2.semilogx(xf, np.random.rand(chunk), '-', lw=2)
ax2.set_xlim(20, rate/2)

# Se abre el archivo wav para la reproducción del audio
wf = wave.open(file, 'rb')
p = pyaudio.PyAudio()
stream = p.open(format=p.get_format_from_width(wf.getsampwidth()),
                channels=wf.getnchannels(),
                rate=wf.getframerate(),
                output=True)
data = wf.readframes(chunk)

fig.show()

frame_count = 0
indice = 0
# Loop que se encargara de reproducir el sonido y
# dibujar las graficas
while len(data) > 0 and indice < len(puntosAudio):
    stream.write(data)
    data = wf.readframes(chunk)
    line.set_ydata(puntosAudio[indice])
    line_fft.set_ydata(puntosFFT[indice])

    indice += 1

    # Re dibujo de los gráficos
    try:
        fig.canvas.draw()
        fig.canvas.flush_events()
        frame_count += 1

    except TclError:
        break
stream.stop_stream()
stream.close()
p.terminate()
