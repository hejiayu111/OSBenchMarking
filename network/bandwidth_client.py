import time
import socket

HOST = "127.0.0.1"
file_size = 32 * 1024 * 1024
PORT = 8080

msg = ""
for i in range(file_size):
    msg += "a"

sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sockfd.connect((HOST, PORT))
utf_8_msg = msg.encode('utf-8')
print("Start Sending")
start = time.time()
sockfd.sendall(utf_8_msg)
end = time.time()
print("Rtt Measured: " + str(end - start))
print("bandwidth is " + str(file_size/(end - start)))
sockfd.close()