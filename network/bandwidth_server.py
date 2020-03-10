import socket
import time

HOST = "127.0.0.1"
PORT = 8080
sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sockfd.bind((HOST, PORT))
sockfd.listen(1)
block_num = 0
while True:
    newsockfd= sockfd.accept()[0]
    while True:
        try:
            data = newsockfd.recv(1024)
            block_num += 1
            print(block_num)
            if not data:
                break
        except ConnectionResetError as e:
            print("Connection Error")
    newsockfd.close()
print("Connection Terminated")