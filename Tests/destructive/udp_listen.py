import socket,sys
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM); s.bind(('0.0.0.0',9999)); s.settimeout(240)
f=open(sys.argv[1],'a')
try:
    while True:
        d,a=s.recvfrom(4096); f.write(d.decode('latin1')); f.flush()
except socket.timeout: pass
