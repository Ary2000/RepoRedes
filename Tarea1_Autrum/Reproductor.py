from zipfile import ZipFile
import datetime
import pyaudio
import wave
import tkinter as tk
from array import array
from struct import pack
import json
import matplotlib.pyplot as plt
import numpy as np

#%matplotlib tk

#https://www.geeksforgeeks.org/working-zip-files-python/
#https://stackoverflow.com/questions/19371860/python-open-file-in-zip-without-temporarily-extracting-it
default_file_name = "output.atm"

with ZipFile(default_file_name, 'r') as zip:
    for info in zip.infolist():
        print(info.filename)
        print('\tModified:\t' + str(datetime.datetime(*info.date_time)))
        print('\tSystem:\t\t' + str(info.create_system) + '(0 = Windows, 3 = Unix)')
        print('\tZIP version:\t' + str(info.create_version))
        print('\tCompressed:\t' + str(info.compress_size) + ' bytes')
        print('\tUncompressed:\t' + str(info.file_size) + ' bytes')

file = ""
jsonFile = ""
with ZipFile(default_file_name, 'r') as zip:
    file = zip.open("output.wav")
    jsonFile = zip.open("puntos.json")

#https://www.youtube.com/watch?v=fVJTrcEqgIo
#https://www.w3schools.com/python/python_json.asp
puntos = json.load(jsonFile)
chunk = 1024 * 2
sample_format = pyaudio.paInt16 
channels = 1 # canal stereo
rate = 44100
#print(puntos)
puntosAudio = puntos["puntosAudio"]
puntosFFT = puntos["puntosFFT"]
print(len(puntosAudio))
print(len(puntosFFT))
#data_int = np.array
#fig, ax = plt.subplots(5,'-')
fig, (ax, ax2) = plt.subplots(2, figsize=(15, 8))

x = np.arange(0, 2 * chunk, 2)
xf = np.linspace(0, rate, chunk)     # frequencies (spectrum)
line, = ax.plot(x, np.random.rand(chunk), '-')
ax.set_ylim(0, 255)
ax.set_xlim(0, chunk)

x_fft = np.linspace(0, rate, chunk)

line_fft, = ax2.semilogx(xf, np.random.rand(chunk), '-', lw=2)

ax2.set_xlim(20, rate/2)

#graph1 = FigureCanvasTkAgg(fig, ui)
#graph1.get_tk_widget().grid(row=2, column=1)

ax.plot()

CHUNK = 1024
wf = wave.open(file,'rb')
p=pyaudio.PyAudio()
stream = p.open(format=p.get_format_from_width(wf.getsampwidth()),
                channels = wf.getnchannels(),
                rate=wf.getframerate(),
                output = True)
data = wf.readframes(CHUNK)
while len(data) > 0:
    stream.write(data)
    data = wf.readframes(CHUNK)
stream.stop_stream()
stream.close()
p.terminate()

class Player:
    def __init__(self, file_name, CHUNK):
        self.file_name = file_name
        self.WAV_name = (file_name[:len(file_name)-4]+'.wav')
        self.WAVfile = None
        self.JSONfile = None
        self.json = None
        self.CHUNK = CHUNK

    def loadFile(self):
        with ZipFile(self.file_name, 'r') as zip:
            self.WAVfile = zip.open(self.WAV_name)
            self.JSONfile = zip.open("puntos.json")

    def loadJSON(self):
        self.json = json.load(self.JSONfile)

    def play(self):
        wf = wave.open(self.WAVfile,'rb')
        p=pyaudio.PyAudio()
        stream = p.open(format=p.get_format_from_width(wf.getsampwidth()),
                        channels = wf.getnchannels(),
                        rate=wf.getframerate(),
                        output = True)
        data = wf.readframes(self.CHUNK)
        while len(data) > 0:
            stream.write(data)
            data = wf.readframes(self.CHUNK)
        stream.stop_stream()
        stream.close()
        p.terminate()

if __name__ == "__main__":
    chunk = 1024