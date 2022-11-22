#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "base64.c"
#include "curlHandler.c"

#define PORT 53
#define MAXLINE 4096

// Driver code
int main()
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    unsigned char buffer[MAXLINE];

    char *encoded;
    unsigned char *decoded;

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

    printf("Server running... \n");

    int qr, opcode;

    while (1)
    {
        bzero(buffer, MAXLINE);
        n = recvfrom(sockfd, &buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);

        printf("Bytes received: %i\n", n);

        unsigned int number = (unsigned int)buffer[2];
        number = number << 24;
        qr = number >> 31;

        printf("QR : %u \n", qr);

        number = (unsigned int)buffer[2];
        number = number << 25;
        opcode = number >> 28;

        printf("OPCODE: %u \n", opcode);

        if (qr != 0 || opcode != 0)
        {
            // caso paquete diferente a query estándar

            // encodear a base 64
            // enviar con lib curl a DNS API
            // recibir respuesta, decodearla y enviarla al cliente solicitante
            // "responder nslookup"

            encoded = base64_encode(buffer, n);

            postToApi(encoded);

            decoded = base64_decode(encoded, 4 * ((n + 2) / 3));
        }
    }
    return 0;
}