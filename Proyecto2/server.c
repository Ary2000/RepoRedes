// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 53
#define MAXLINE 4096

// Driver code
int main()
{
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;

    // archivo para guardar el request
    FILE *log_file, log_file2;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n;

    len = sizeof(cliaddr); // len is value/result

    while (1)
    {
        bzero(buffer, MAXLINE);
        n = recvfrom(sockfd, &buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
        unsigned int number = (unsigned int)buffer[2];
        number = number << 24;
        number = number >> 31;
        printf("QR : %u \n", number);
        number = (unsigned int)buffer[2];
        number = number << 25;
        number = number >> 28;
        printf("OPCODE: %u \n", number);

        printf("Lei algo \n");
    }
    return 0;
}
