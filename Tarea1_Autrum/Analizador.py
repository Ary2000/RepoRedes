import pyaudio
import wave
import tkinter as tk
import struct
import numpy as np
from scipy.fftpack import fft
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from tkinter import messagebox
from tkinter import filedialog as fd
from zipfile import ZipFile
import json
import os
from queue import Queue
from threading import Thread

# nombre de archivos por default
default_filename_wav = "output.wav"
default_filename_json = "puntos.json"

# amplitud de la grabacion
amplitud = 2**15

# Clase UI usando tkinter para la interfaz
class Recorder_UI:
    def __init__(self):
        self.ui = tk.Tk()
        self.ui.geometry("1000x700")

        # Label de notificacion
        self.playerlabel = tk.Label(self.ui, text="Ready")
        self.playerlabel.grid(row=0, column=0)

        # Contenedor
        frame = tk.Frame(self.ui)
        frame.grid(row=1, column=0)

        # Lista de botones
        self.buttons = [tk.Button(frame, text="Record"), 
                        tk.Button(frame, text="Pause"), 
                        tk.Button(frame, text="Unpause"), 
                        tk.Button(frame, text="Stop"),
                        tk.Button(frame, text="Select a file name (.wav)")]

        self.buttons[0].grid(row=0, column=0)
        self.buttons[1].grid(row=1, column=0)
        self.buttons[2].grid(row=2, column=0)
        self.buttons[3].grid(row=3, column=0)
        self.buttons[4].grid(row=4, column=0)

        self.ui.protocol("WM_DELETE_WINDOW", self.on_closing)
    
    # Comienza el tkinter
    def start(self):
        self.stop_button()
        self.ui.mainloop()

    # Inicializar el plot con valores por default
    def plot_graphs(self, chunk, rate):
        self.fig, (ax, ax2) = plt.subplots(2, figsize=(15, 8))

        x = np.arange(0, 2 * chunk, 2)
        self.line, = ax.plot(x, np.random.rand(chunk), '-')
        ax.set_ylim(-amplitud, amplitud)
        ax.set_xlim(0, chunk*2)

        x_fft = np.linspace(0, rate, chunk)
        self.line_fft, = ax2.semilogx(x_fft, np.random.rand(chunk), '-')
        ax2.set_xlim(20, rate/2)
        ax2.set_ylim(0, 2*10)
        
        graph1 = FigureCanvasTkAgg(self.fig, self.ui)
        graph1.get_tk_widget().grid(row=2, column=1)
    
    # Estado cuando comienza la grabacion
    def start_button(self):
        self.buttons[0]['state'] = tk.DISABLED
        self.buttons[1]['state'] = tk.NORMAL
        self.buttons[2]['state'] = tk.DISABLED
        self.buttons[3]['state'] = tk.NORMAL

    # Estado cuando pausa la grabacion
    def pause_button(self):
        self.buttons[0]['state'] = tk.DISABLED
        self.buttons[1]['state'] = tk.DISABLED
        self.buttons[2]['state'] = tk.NORMAL
        self.buttons[3]['state'] = tk.NORMAL
    
    # Estado cuando reanuda la grabacion
    def unpause_button(self):
        self.buttons[0]['state'] = tk.DISABLED
        self.buttons[1]['state'] = tk.NORMAL
        self.buttons[2]['state'] = tk.DISABLED
        self.buttons[3]['state'] = tk.NORMAL

    # Estado cuando detiene la grabacion
    def stop_button(self):
        self.buttons[0]['state'] = tk.NORMAL
        self.buttons[1]['state'] = tk.DISABLED
        self.buttons[2]['state'] = tk.DISABLED
        self.buttons[3]['state'] = tk.DISABLED

    # Tomado de: https://www.pythontutorial.net/tkinter/tkinter-open-file-dialog/
    # Seleccionar un wav file para el procesamiento de wav
    def select_file(self):
        filetypes = (('wav files', '*.wav'),)

        filedirectory = fd.askopenfilename(
            title='Open a file',
            initialdir='/',
            filetypes=filetypes)

        return filedirectory

    def on_closing (self):
        self.ui.quit()

# Analiza una grabacion o achivo .wav y produce un archivo .wav y .atm
class Analizer:
    def __init__(self, chunk, sample_format, channels, fs):
        # formato de grabacion 
        self.chunk = chunk
        self.sample_format = sample_format
        self.channels = channels
        self.fs = fs

        # guarda los datos para el calculo de los puntos a graficar
        self.frames = []

        # instancia de un objeto stream para la manipulacion de un archivo wav
        self.stream = None
        
        # instancia para graficar en el plot y se usa en un hilo
        self.queue = Queue()

        # instancia de PyAudio
        self.p = None

        # Instancia de la interfaz y configura la funcionalidad de los botones
        self.window = Recorder_UI()
        self.window.buttons[0].configure(command = lambda: self.record(default_filename_wav))
        self.window.buttons[1].configure(command = lambda: self.pause())
        self.window.buttons[2].configure(command = lambda: self.unpause())
        self.window.buttons[3].configure(command = lambda: self.stop())
        self.window.buttons[4].configure(command = self.open_wav_file)

        # crea los plots de la interfaz
        self.window.plot_graphs(self.chunk, self.fs)

        # comienza la interfaz
        self.window.start()

    # abre el explorador para buscar un .wav y lo reproduce
    def open_wav_file(self):
        file_path = self.window.select_file()
        self.play(file_path)

    # Funcion non-blocking para PyAudio que obtiene los datos del audio, corre en un hilo por aparte
    def callback(self, in_data, frame_count, time_info, status):
        self.frames.append(in_data)
        self.queue.put(in_data)
        return (in_data, pyaudio.paContinue)
        
    # Tomado de: https://www.youtube.com/watch?v=jbKJaHw0yo8
    def record(self, filename):
        self.p = pyaudio.PyAudio()  # Create an interface to PortAudio
        print('Recording')
        # actualiza los botones
        self.window.start_button()
        self.window.playerlabel["text"] = "Recording" 

        # abre un stream
        self.stream = self.p.open(format = self.sample_format,
                        channels = self.channels,
                        rate = self.fs,
                        frames_per_buffer = self.chunk,
                        input = True,
                        stream_callback=self.callback)

        self.frames = []  # Initialize array to store frames
        self.stream.start_stream() # comienza el stream, microfono capta datos

        # comienza el plot en un hilo
        self.plot_thread = Thread(target=self.graph_plot, args=(self.queue,))
        self.plot_thread.start()
    
    # grafica lo que capta el microfono en un hilo por aparte
    def graph_plot(self, queue):
        try: 
            while self.stream:
                # si no hay datos que graficar o no este activo
                if queue.empty() or not self.stream.is_active():
                    continue
                # obtiene datos del queue
                data = queue.get()

                data_int = np.frombuffer(data, dtype = np.int16) # de bytes a int16
                y_fft = fft(data_int) # transformacion de fourier

                # set de los datos en el plot
                self.window.line.set_ydata(data_int)
                self.window.line_fft.set_ydata(np.abs(y_fft[0:self.chunk]) * 2 / (512 * self.chunk))

                # actualiza el plot
                self.window.fig.canvas.draw()
                self.window.fig.canvas.flush_events()

                # indica que el dato del queue se proceso bien
                queue.task_done()
            return 
        except OSError:
            print("Retornar")
            return 

    # Pausa el streaming y actualiza el UI
    def pause(self):
        self.stream.stop_stream()
        self.window.pause_button()
        self.window.playerlabel['text'] = 'Paused, click unpause to continue'

    # Reanuda el streaming y actualiza el UI
    def unpause(self):
        self.window.unpause_button()
        self.stream.start_stream()
        self.window.playerlabel['text'] = 'Recording'
    
    # Para el streaming y crea el .atm 
    def stop(self):
        print("Stopping --------------------------------------------------")
        self.window.stop_button()

        # Stop and close the stream 
        self.stream.stop_stream()
        self.stream.close()
        self.p.terminate()

        print('Finishing recording')
        self.window.playerlabel['text'] = 'Finishing recording, in seconds the output.wav will be available'

        self.save_file(default_filename_wav, self.frames, self.p)
        # self.play(default_filename_wav)

    # Guarda los datos capturados en un .wav
    def save_file(self, filename, frames, stream):
        # Save the recorded data as a WAV file
        wf = wave.open(filename, 'wb')
        wf.setnchannels(self.channels)
        wf.setsampwidth(stream.get_sample_size(self.sample_format))
        wf.setframerate(self.fs)
        wf.writeframes(b''.join(frames))
        wf.close()
        self.create_atm_file(filename)

    # Crea el archivo .atm
    def create_atm_file(self, filename):
        wf = wave.open(filename, 'rb')

        data = wf.readframes(self.chunk)

        # lista para guardar los puntos calculados
        fft_list = []
        audio_list = []

        # mientras haya datos
        while len(data) > 0:
            # calculos
            data_int = np.frombuffer(data, dtype = np.int16).tolist() # bytes a int16
            y_fft = fft(data_int) # fft

            # guarda en las listas
            audio_list.append(data_int)
            fft_list.append((np.abs(y_fft[0:self.chunk]) * 2 / (512 * self.chunk)).tolist()) # de np.array a array

            # obtiene el siguiente frame
            data = wf.readframes(self.chunk)
        
        # template de json
        data_json = {
              "puntosFFT": fft_list,
              "puntosAudio": audio_list
        }

        # serializa a formato json
        data_serialized = json.dumps(data_json, indent=2)

        # crea el json
        with open(default_filename_json, 'w') as f:
            f.write(data_serialized)
            print("New json file is created")
        print()

        # obtiene el nombre del archivo
        filename = os.path.basename(filename)
        
        # crea y zip de extension .atm 
        with ZipFile(filename[:len(filename)-4]+'.atm','w') as zip:
            # writing each file one by one
            zip.write(filename)  # .wav
            zip.write(default_filename_json) # guarda el json

        # quita el json
        os.remove(default_filename_json)
        
        # cierra el archivo wav
        wf.close()

    def play(self, file):
        try:
            wf = wave.open(file, 'rb')

            p = pyaudio.PyAudio()

            stream = p.open(format = p.get_format_from_width(wf.getsampwidth()),
                            channels = wf.getnchannels(),
                            rate = wf.getframerate(),
                            output=True)
            data = wf.readframes(self.chunk)
            print(len(data))

            

            while len(data) > 0:
                
                data_int = np.frombuffer(data, dtype = np.int16)
                print(len(data_int))
                y_fft = fft(data_int)
                print(data_int[:10])
                print(len(np.abs(y_fft[0:self.chunk]) * 2 / (512 * self.chunk)))
                print((np.abs(y_fft[0:self.chunk]) * 2 / (512 * self.chunk))[:10])
                print("----------------------------")
                self.window.line.set_ydata(data_int[:len(data_int)])
                self.window.line_fft.set_ydata(np.abs(y_fft[0:self.chunk]) * 2 / (512 * self.chunk))

                self.window.fig.canvas.draw()
                self.window.fig.canvas.flush_events()

                stream.write(data)
                data = wf.readframes(self.chunk)
                
            stream.stop_stream()
            stream.close()

            p.terminate()

            self.create_atm_file(file)
            wf.close()

        except FileNotFoundError:
            messagebox.showinfo("Error", "No existe el archivo puesto. Formato name.wav")

if __name__ == "__main__":
    # datos para la grabacion
    chunk = 1024 * 2
    sample_format = pyaudio.paInt16 
    channels = 1 # canal mono
    rate = 44100
    analizer = Analizer(chunk, sample_format, channels, rate)