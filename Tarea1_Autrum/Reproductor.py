from zipfile import ZipFile
import datetime
import pyaudio
import wave
from array import array
from struct import pack

#https://www.geeksforgeeks.org/working-zip-files-python/
#https://stackoverflow.com/questions/19371860/python-open-file-in-zip-without-temporarily-extracting-it
file_name = "output.atm"

with ZipFile(file_name, 'r') as zip:
    for info in zip.infolist():
        print(info.filename)
        print('\tModified:\t' + str(datetime.datetime(*info.date_time)))
        print('\tSystem:\t\t' + str(info.create_system) + '(0 = Windows, 3 = Unix)')
        print('\tZIP version:\t' + str(info.create_version))
        print('\tCompressed:\t' + str(info.compress_size) + ' bytes')
        print('\tUncompressed:\t' + str(info.file_size) + ' bytes')

file = ""
with ZipFile(file_name, 'r') as zip:
    file = zip.open("output.wav")

#https://www.youtube.com/watch?v=fVJTrcEqgIo

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
