// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "base64.c"
//#include "other.c"

#define PORT 53
#define MAXLINE 4096

// Driver code
int main()
{
    int sockfd;
    unsigned char buffer[MAXLINE];
    char *hello = "Hello from server";
    char encodecontent[100];
    char *encoded;
    unsigned char *decoded;
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
    size_t* outlen;
    char *resultado;

    len = sizeof(cliaddr); // len is value/result

    
    //b64('e',"log.bin","output.txt",n);

    while (1)
    {
        bzero(buffer, MAXLINE);
        n = recvfrom(sockfd, &buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
        printf("%i\n",n);
        unsigned int number = (unsigned int)buffer[2];
        number = number << 24;
        number = number >> 31;
        printf("QR : %u \n", number);
        number = (unsigned int)buffer[2];
        number = number << 25;
        number = number >> 28;
        printf("OPCODE: %u \n", number);
        b64('e',"log.bin","output.txt",n);
        printf("Lei algo \n");
        /*log_file = fopen("output.txt","r");
        char c;
        while( feof( log_file ) == 0 ) {
            c = getc(log_file);
            strncat(encodecontent, &c, 1);
        }
        fclose(log_file);
        printf("%s\n",encodecontent);
        memset(encodecontent, 0, sizeof encodecontent);*/
        encoded = base64_encode(buffer,n);
        printf("%s\n",encoded);
        decoded = base64_decode(encoded,4 * ((n + 2) / 3));
        printf("%s\n",decoded);
    }
    return 0;
}
