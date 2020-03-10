import socket
import time

HOST = "100.83.45.163"
PORT = 1234
sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sockfd.bind((HOST, PORT))
sockfd.listen(1)
while True:
    newsockfd= sockfd.accept()[0]
    while True:
        try:
            data = newsockfd.recv(1024)
            if data is None:
                break
        except ConnectionResetError as e:
            print("Connection Error")
    newsockfd.close()
print("Connection Terminated")