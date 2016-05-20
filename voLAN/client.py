import struct
import alsaaudio
import socket
import sys

s = socket.socket()
host = sys.argv[1]
port = 12346

sound_out = alsaaudio.PCM()  # open default sound output
sound_out.setchannels(1)  # use only one channel of audio (aka mono)
sound_out.setperiodsize(160) # buffer size, default is 32
sound_out.setrate(8000)

s.connect((host, port))

while True:
	sample = s.recv(320)
	sound_out.write(sample)