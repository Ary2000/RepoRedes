import pyaudio
import wave
import tkinter as tk
import struct
import numpy as np
from scipy.fftpack import fft
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from tkinter import messagebox

filename = "output.wav"

class Recorder_UI:
    def __init__(self):
        self.ui = tk.Tk()
        self.ui.geometry("1000x700")
        self.playerlabel = tk.Label(self.ui, text="Ready")
        self.playerlabel.grid(row=0, column=0)
        
        frame = tk.Frame(self.ui)
        frame.grid(row=1, column=0)

        self.buttons = [tk.Button(frame, text="Record"), 
                        tk.Button(frame, text="Pause"), 
                        tk.Button(frame, text="Unpause"), 
                        tk.Button(frame, text="Stop"),
                        tk.Button(frame, text="Select a song name (.wav): ")]
        self.song_var = tk.StringVar()
        self.song_var.set('output.wav') 
        song_var_entry = tk.Entry(frame, textvariable = self.song_var)
        song_var_entry.grid(row = 4, column = 0)

        self.buttons[0].grid(row=0, column=0)
        self.buttons[1].grid(row=1, column=0)
        self.buttons[2].grid(row=2, column=0)
        self.buttons[3].grid(row=3, column=0)
        self.buttons[4].grid(row=5, column=0)
    

    def start(self):
        self.stop_button()
        self.ui.mainloop()

    def plot_graphs(self, chunk, rate):
        self.fig, (ax, ax2) = plt.subplots(2, figsize=(15, 8))

        x = np.arange(0, 2 * chunk, 2)
        self.line, = ax.plot(x, np.random.rand(chunk), '-')
        ax.set_ylim(-1*chunk, chunk)
        ax.set_xlim(0, chunk)

        x_fft = np.linspace(0, rate, chunk)
        self.line_fft, = ax2.semilogx(x_fft, np.random.rand(chunk), '-')
        #ax2.set_xlim(20, rate)
        
        graph1 = FigureCanvasTkAgg(self.fig, self.ui)
        graph1.get_tk_widget().grid(row=2, column=1)
    
    def start_button(self):
        self.buttons[0]['state'] = tk.DISABLED
        self.buttons[1]['state'] = tk.NORMAL
        self.buttons[2]['state'] = tk.DISABLED
        self.buttons[3]['state'] = tk.NORMAL

    def pause_button(self):
        self.buttons[0]['state'] = tk.DISABLED
        self.buttons[1]['state'] = tk.DISABLED
        self.buttons[2]['state'] = tk.NORMAL
        self.buttons[3]['state'] = tk.NORMAL
    
    def unpause_button(self):
        self.buttons[0]['state'] = tk.DISABLED
        self.buttons[1]['state'] = tk.NORMAL
        self.buttons[2]['state'] = tk.DISABLED
        self.buttons[3]['state'] = tk.NORMAL

    def stop_button(self):
        self.buttons[0]['state'] = tk.NORMAL
        self.buttons[1]['state'] = tk.DISABLED
        self.buttons[2]['state'] = tk.DISABLED
        self.buttons[3]['state'] = tk.DISABLED

class Analizer:
    def __init__(self, chunk, sample_format, channels, fs):
        self.chunk = chunk
        self.sample_format = sample_format
        self.channels = channels
        self.fs = fs

        self.frames = []
        self.stream = None
        self.stop_callback = False
        self.data = b''

        self.p = None

        self.window = Recorder_UI()
        self.window.buttons[0].configure(command = lambda: self.record(filename))
        self.window.buttons[1].configure(command = lambda: self.pause())
        self.window.buttons[2].configure(command = lambda: self.unpause())
        self.window.buttons[3].configure(command = lambda: self.stop())
        self.window.buttons[4].configure(command = lambda: self.play(self.window.song_var.get()))

        self.window.plot_graphs(self.chunk, self.fs)
        self.window.start()

    def callback(self, in_data, frame_count, time_info, status):
        self.frames.append(in_data)
        return (in_data, pyaudio.paContinue)

    # https://www.youtube.com/watch?v=jbKJaHw0yo8
    def record(self, filename):
        self.stop_callback = False
        self.p = pyaudio.PyAudio()  # Create an interface to PortAudio
        print('Recording')
        self.window.start_button()
        self.window.playerlabel["text"] = "Recording" 

        self.stream = self.p.open(format = self.sample_format,
                        channels = self.channels,
                        rate = self.fs,
                        frames_per_buffer = self.chunk,
                        input = True,
                        stream_callback=self.callback)

        self.frames = []  # Initialize array to store frames
        self.stream.start_stream()
    
    def pause(self):
        self.stream.stop_stream()
        self.window.pause_button()
        self.window.playerlabel['text'] = 'Paused, click unpause to continue'

    def unpause(self):
        self.window.unpause_button()
        self.stream.start_stream()
        self.window.playerlabel['text'] = 'Recording'
    
    def stop(self):
        self.stop_callback = True
        print("Stopping --------------------------------------------------")
        self.window.stop_button()
        # Stop and close the stream 
        #while self.stream.is_active():
        #    time.sleep(0.1)
        self.stream.stop_stream()
        self.stream.close()
        self.p.terminate()
        print('Finished recording')
        self.window.playerlabel['text'] = 'Finished recording, in seconds the output.wav will be available'
        self.save_file(filename, self.frames, self.p)
        self.play(filename)

    
    def save_file(self, filename, frames, stream):
        # Save the recorded data as a WAV file
        wf = wave.open(filename, 'wb')
        wf.setnchannels(self.channels)
        wf.setsampwidth(stream.get_sample_size(self.sample_format))
        wf.setframerate(self.fs)
        wf.writeframes(b''.join(frames))
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

            while len(data) > 0:
                data_int = struct.unpack(str(self.chunk) + 'h', data)
                y_fft = fft(data_int)

                self.window.line.set_ydata(data_int)
                self.window.line_fft.set_ydata(np.abs(y_fft[0:self.chunk]) * 2 / (256 * self.chunk))

                self.window.fig.canvas.draw()
                self.window.fig.canvas.flush_events()

                stream.write(data)
                data = wf.readframes(self.chunk)
                
            stream.stop_stream()
            stream.close()

            p.terminate()

        except FileNotFoundError:
            messagebox.showinfo("Error", "No existe el archivo puesto. Formato name.wav")

if __name__ == "__main__":
    chunk = 1024 * 2
    sample_format = pyaudio.paInt16 
    channels = 1 # canal stereo
    rate = 44100
    analizer = Analizer(chunk, sample_format, channels, rate)

