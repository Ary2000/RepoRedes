import pyaudio
import wave
from array import array
from struct import pack

import os
import struct
import numpy as np
import matplotlib.pyplot as plt
import matplotlib
from scipy.fftpack import fft
import time
from tkinter import TclError

matplotlib.use('TkAgg')


def play(file):
    fig, ax = plt.subplots(1, figsize=(15, 8))
    CHUNK = 1024
    wf = wave.open(file, 'rb')
    p = pyaudio.PyAudio()
    RATE = 44100
    xf = np.linspace(0, RATE, CHUNK)     # frequencies (spectrum)

    # format spectrum axes
    ax.set_xlim(20, RATE / 2)

    print('stream started')

    plt.show(block=False)

    # for measuring frame rate
    frame_count = 0
    start_time = time.time()

    # create semilogx line for spectrum
    line_fft, = ax.semilogx(xf, np.random.rand(CHUNK), '-', lw=2)

    stream = p.open(format=p.get_format_from_width(wf.getsampwidth()),
                    channels=wf.getnchannels(),
                    rate=wf.getframerate(),
                    output=True)
    data = wf.readframes(CHUNK)
    while len(data) > 0:
        stream.write(data)
        data = wf.readframes(CHUNK)
        # convert data to integers, make np array, then offset it by 127
        data_int = np.frombuffer(data, dtype=np.int16)
        if(data_int.size == 0):
            break

        # compute FFT and update lineS
        y_fft = fft(data_int)
        line_fft.set_ydata(np.abs(y_fft[0:CHUNK]) * 2 / (256 * CHUNK))

        # update figure canvas
        try:
            fig.canvas.draw()
            fig.canvas.flush_events()
            frame_count += 1

        except TclError:

            # calculate average frame rate
            frame_rate = frame_count / (time.time() - start_time)

            print('stream stopped')
            print('average frame rate = {:.0f} FPS'.format(frame_rate))
            break

    stream.stop_stream()
    stream.close()
    p.terminate()


play('output1.wav')
