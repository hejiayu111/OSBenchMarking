#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <iostream>

#define HOST "100.80.241.207"

#define PORT_NUM 1234

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servAddr;
    int PORT = PORT_NUM;
    char HOSTNAME[] = HOST;
    char buffer[256];
    struct timespec start_time, end_time;

    std::cout << "create socket" << std::endl;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR WHEN WE TRY TO CREATE A SOCKET");
        return -1;
    }

    std::cout << "socket creat success"<< std::endl;

    // Configuration
    servAddr.sin_family = AF_INET;
    if(inet_pton(AF_INET, HOSTNAME, &servAddr.sin_addr)<=0)
    {
        printf("WRONG ADDRESS!\n");
        return -1;
    }

    std::cout << "address config success" <<std::endl;

    servAddr.sin_port = htons(PORT);
    if (connect(sockfd,(struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
        std:: cout << "ERROR WHILE CONNECTING" << std::endl;
        return -1;
    }

    std::cout << "connect success" << std::endl;

    // Send
    char sendbuffer[64];
    for (int i = 0; i < 64; i++){
        sendbuffer[i] = rand() % 128;
    }
    //Clock start
   
    clock_gettime(CLOCK_REALTIME,&start_time);
    int n = write(sockfd, sendbuffer, strlen(sendbuffer));
    if (n < 0) {
        printf("ERROR WHILE SENDING TO SERVER");
        return -1;
    }
    n = read(sockfd, buffer, 4);
    if (n < 0) {
        printf("ERROR WHILE READING");
        return -1;
    }
    //Receiving succeeded, clock end
    clock_gettime(CLOCK_REALTIME, &end_time);

    double time_sec = (end_time.tv_sec * 1e9 - start_time.tv_sec * 1e9);
    double time_nsec = (end_time.tv_nsec - start_time.tv_nsec);
    double time_total = 1.0 * (time_nsec + time_sec) / 1e6;

    printf("Total time is: %f\n", time_total);
    printf("%s\n",buffer);
        // sleep(6);

    close(sockfd);
    return 0;
}
