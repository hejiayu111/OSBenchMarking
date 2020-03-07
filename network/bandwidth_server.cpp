#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUM 1234
#define FILE_SIZE 1024 * 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servAddr, cliAddr;
    socklen_t clilen = sizeof(cliAddr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR WHEN WE TRY TO CREATE A SOCKET");
        return -1;
    }

    // Configurations
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(PORT_NUM);

    if (bind(sockfd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
        printf("BINDING ERROR");
        return -1;
    }
    listen(sockfd, 1);

    while(1) {
        int newsockfd = accept(sockfd, (struct sockaddr *) &cliAddr, &clilen);
        if (newsockfd < 0) {
            printf("ERROR WHEN TRY TO ACCPECT");
            return -1;
        }

        // char *buffer = NULL;
        // buffer = static_cast<char*>(malloc(FILE_SIZE));
        // int len = sizeof(buffer);
        // char *p = buffer;
        // int m;
        // while (len > 0 && (m = recv(newsockfd, p, len, 0)) > 0 ) {
        //     p += m;
        //     len -= m;
        //     printf("receive %d\n", m);
        // }
        // free(buffer);
        // while (1) {
        //     char buffer[4096];
        //     int n = read(newsockfd, buffer, 4096);
        //     if (n == 0) {
        //         break;
        //     }
        //     printf("%d\n", n);
        // }
        // send back response

        // buffer for receiving data
        char buffer[FILE_SIZE];

        int n = read(newsockfd, buffer, FILE_SIZE);
        if (n < 0) {
            printf("ERROR WHILE READING");
            return -1;
        }
        char text[4] = "OK";
        n = write(newsockfd, text, strlen(text));
        if (n < 0) {
            printf("ERROR WHILE SENDING BACK TO CLIENT");
            return -1;
        }
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}
