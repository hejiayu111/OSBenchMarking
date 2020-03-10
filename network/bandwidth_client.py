import time
import socket

HOST = "100.83.45.163"
file_size = 32 * 1024 * 1024
PORT = 1234

msg = ""
for i in range(file_size):
    msg += "a"

sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sockfd.connect((HOST, PORT))
print("Start Sending")
start = time.time()
sockfd.sendall(msg.encode('utf-8'))
end = time.time()
print("Rtt Measured: " + str(end - start))
sockfd.close()