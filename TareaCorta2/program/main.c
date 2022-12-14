#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define MAX 80
#define PORT 9666
#define SA struct sockaddr

#define BUFFINT 20

int BIT_MAX = 32;

int IP_MAX_SIZE = 15; // len 255.255.255.255

char error_message [MAX]; 
int ERROR_APPEAR;

// Original tomado de: https://www.lemoda.net/c/ip-to-integer/
// Modificado para propósitos de la tarea
// Transforma un char* a int32 de un ip
unsigned int ip_to_int(char *ip)
{
    unsigned value = 0;

    int i = 0;

    const char *start;

    start = ip;

    char c;
    c = *start;
    while (c != '\0')
    { // Va punto por punto
        int n = 0;
        while (1)
        {
            c = *start;
            start++;
            if (c >= '0' && c <= '9')
            {
                n *= 10;
                n += c - '0';
            }
            else if ((i < 3 && c == '.') || i == 3)
            { // finish 255.
                break;
            }
            else
            {
                printf("Mal formato de ip: %s\n", ip);
                ERROR_APPEAR = 1;
                strcpy(error_message, "Mal formato de ip");
                return -1;
            }
        }
        if (n >= 256)
        {
            printf("Rango ip no aceptado (0-255): %s\n", ip);
            strcpy(error_message, "Rango ip no aceptado (0-255)");
            ERROR_APPEAR = 1;
            return -1;
        }
        value *= 256;
        value += n;
        i++;
    }
    return value;
}

// Transforma un ip int32 en un char* equivalente xxx.xxx.xxx.xxx
char *int_to_ip(int ip)
{
    char *text = malloc(IP_MAX_SIZE * (sizeof(char)));

    int copy;
    int number = 0;
    int cont = 0;

    char buffer[3];

    int cont_text = 0;

    for (int i = 1; i <= BIT_MAX; i++)
    {
        copy = ip << cont++;
        int bit_t = copy >> (BIT_MAX - 1);

        number = number << 1;
        if (bit_t != 0)
        { // put 1 in number
            number += 1;
        }

        if (i % 8 == 0)
        {
            sprintf(buffer, "%d", number);
            // itoa(number, buffer, 10);
            int j = 0;
            while (buffer[j] != '\0')
            {
                text[cont_text++] = buffer[j++];
            }

            number = 0;

            if (i != BIT_MAX)
                text[cont_text++] = '.';
        }
    }

    return text;
}

// Transform mask format /xx to int32 value
unsigned int mask_to_int(char *mask)
{
    if (strlen(mask) == 0 || strlen(mask) > 3 || mask[0] != '/')
    {
        strcpy(error_message, "Mal formato de mask");
        ERROR_APPEAR = 1;
        return -1;
    }

    unsigned v = 0;
    int mask_number = 0;

    for (int i = 1; i < strlen(mask); i++)
    {
        if (mask[i] < '0' || mask[i] > '9')
        {
            printf("Mal formato de mask : %s\n", mask);
            strcpy(error_message, "Mal formato de mask");
            ERROR_APPEAR = 1;
            return -1;
        }
        mask_number = mask_number * 10 + (mask[i] - '0');
    }
    if (mask_number > 30 || mask_number < 8)
    {
        printf("Numero no aceptado de mask (se espera 8-30) : %s\n", mask);
        strcpy(error_message, "Numero no aceptado de mask (se espera 8-30)");
        ERROR_APPEAR = 1;
        return -1;
    }

    v = 1;
    for (int i = 1; i < 32 - mask_number; i++)
    {
        v = v << 1;
        v++;
    }
    v = ~v;

    return v;
}

// Validar mask en formato ip
int check_mask_ip(int mask, char *mask_ori)
{
    int i = 1;
    int bit = mask & 1; // mask 1, obtener ultimo bit
    // recorrer todos los 0 hasta que encuentre un 1
    while (bit == 0)
    {
        mask = mask >> 1; // corre un bit
        bit = mask & 1;   // mask 1
    }

    // bit = mask & 1;
    for (i; i < BIT_MAX; i++)
    {
        if (bit == 0)
        {
            printf("Mal formato ip mask: %s\n", mask_ori);
            
            strcpy(error_message, "Mal formato ip mask");
            ERROR_APPEAR = 1;
            return -1;
        }
        mask = mask >> 1; // corre un bit
        bit = mask & 1;   // mask 1
    }
    return 1;
}

// Obtiene el ip en int32 de un ip con su mascara
int get_broadcast(char *p_ip, char *p_mask)
{
    int integer = ip_to_int(p_ip);
    if (integer < 0) return -1;
    // mask
    int mask;
    if (p_mask[0] == '/'){
        mask = mask_to_int(p_mask); // formato /mask
    }
    else
    { // formato 255.255.255.255
        mask = ip_to_int(p_mask);
        check_mask_ip(mask, p_mask);
    }

    mask = ~mask;             // complemento de mask
    integer = integer | mask; // ip OR mask

    return integer;
}

// Obtiene el network number en int32 de un ip con su mascara
int get_network_number(char *p_ip, char *p_mask)
{
    int integer = ip_to_int(p_ip);
    if (integer < 0) return -1;
    // mask
    int mask;
    if (p_mask[0] == '/')
        mask = mask_to_int(p_mask); // formato /mask
    else
    { // formato 255.255.255.255
        mask = ip_to_int(p_mask);
        check_mask_ip(mask, p_mask);
    }
    integer = integer & mask; // ip AND mask

    return integer;
}

char *get_hosts_range(char *p_ip, char *p_mask)
{
    int minimo = get_network_number(p_ip, p_mask) + 1;
    if (minimo <= 0) return "";
    int maximo = get_broadcast(p_ip, p_mask) - 1;
    if (maximo <= 0) return "";
    char *respuesta = int_to_ip(minimo);
    char *maximoString = int_to_ip(maximo);
    strcat(respuesta, "-");
    strcat(respuesta, maximoString);
    return respuesta;
}

char **get_random_subnet(char *p_ip, char *p_mask, int n, char *size, char *result[])
{
    int min = get_network_number(p_ip, p_mask) + 1;
    if (min <= 0) return "";
    int max = get_broadcast(p_ip, p_mask) - 1;
    if (max <= 0) return "";
    int total_hosts = max - min + 1;

    for (int i = 1; i <= n; i++)
    {
        int r = rand() % total_hosts;
        char *rand_ip = int_to_ip(min + r);
        strcat(rand_ip, size);
        result[i - 1] = rand_ip;
    }
    return result;
}

void comunication(int connfd)
{
    char buff[MAX];
    int n;
    char delim[] = " ";
    // infinite loop for chat
    for (;;)
    {
        memset(error_message, 0, MAX);
        ERROR_APPEAR = 0;
        bzero(buff, MAX);
        // read the message from client and copy it in buffer
        read(connfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        char *ptr = strtok(buff, delim);
        if (strncmp("EXIT", buff, 4) == 0)
            break;
        if (strcmp(ptr, "GET") == 0)
        {
            ptr = strtok(NULL, delim);
            if (strcmp(ptr, "BROADCAST") == 0)
            {
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);
                char *IP = strdup(ptr);
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, "\r");
                char *MASK = strdup(ptr);
                int respuesta = get_broadcast(IP, MASK);
                char *respuestaString;
                if (respuesta > 0 && ERROR_APPEAR == 0){
                    respuestaString = int_to_ip(respuesta);
                } else{
                    respuestaString = error_message;
                }
                strcat(respuestaString, "\n\0");
                write(connfd, respuestaString, strlen(respuestaString));
            }
            else if (strcmp(ptr, "NETWORK") == 0)
            {
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);
                char *IP = strdup(ptr);
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, "\r");
                char *MASK = strdup(ptr);
                int respuesta = get_network_number(IP, MASK);
                char *respuestaString;
                if (respuesta > 0 && ERROR_APPEAR == 0){
                    respuestaString = int_to_ip(respuesta);
                } else{
                    respuestaString = error_message;
                }
                strcat(respuestaString, "\n\0");
                write(connfd, respuestaString, strlen(respuestaString));
            }
            else if (strcmp(ptr, "HOSTS") == 0)
            {
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);
                char *IP = strdup(ptr);
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, "\r");
                char *MASK = strdup(ptr);
                char *respuesta = get_hosts_range(IP, MASK);;
                if (ERROR_APPEAR==1){
                    respuesta = error_message;
                }
                strcat(respuesta, "\n\0");
                write(connfd, respuesta, strlen(respuesta));
            }
            else if (strcmp(ptr, "RANDOM") == 0)
            {
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);
                char *IP = strdup(ptr);
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);
                char *MASK = strdup(ptr);
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);
                int NUM = atoi(strdup(ptr));
                ptr = strtok(NULL, delim);
                ptr = strtok(NULL, delim);
                char *SIZE = strdup(ptr);
                ptr = strtok(NULL, "\r");
                char *respuesta[NUM];
                get_random_subnet(IP, MASK, NUM, SIZE, respuesta);
                if (ERROR_APPEAR==1){
                    char * respuestaString = error_message;
                    strcat(respuestaString, "\n\0");
                    write(connfd, respuestaString, strlen(respuestaString));

                } else {
                    for (int i = 0; i < NUM; i++)
                    {
                        write(connfd, respuesta[i], strlen(respuesta[i]));
                        write(connfd, "\n", sizeof(char));
                    }
                    
                }
            }
        }
    }
}

int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0)
    {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA *)&cli, &len);
    if (connfd < 0)
    {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");

    comunication(connfd);
    close(sockfd);

    return 0;
}
