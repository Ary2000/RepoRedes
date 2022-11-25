// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <curl/curl.h>
#include "cdecoder.c"
#include "cencoder.c"
#include "CurlHandler.c"

#define MAXLINE 4096
#define MAX_LEN_HOSTNAME 253
#define IP_LEN 18 
#define MAX_IPS 30
#define MAX_BODY_LEN 200

unsigned int static TTL = 0;

char *call_elastic(char* host_search){
    CURL *curl;
    CURLcode res;

    char* get_url = getenv("URL_GET_ELASTIC");
    char* update_url = getenv("URL_UPDATE_ELASTIC");

    char *postFields1 = getenv("POST_FIELD_1");
    char *postFields2 = getenv("POST_FIELD_2");
    char *postFields_updateIndex = getenv("POST_INDEX");
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    struct curl_slist *hs = NULL;
    hs = curl_slist_append(hs, "Content-Type: application/json");

    if (curl)
    {
        struct string s;
        init_string(&s);
        // URL de la api de elasticsearch
        curl_easy_setopt(curl, CURLOPT_URL, get_url);
        
        // Desactivar verificaciones
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        // Por aqui se pasa el usuario y la contrasena del elasticseearch
        curl_easy_setopt(curl, CURLOPT_USERPWD, getenv("ECK_USER_PASS"));

        // se arma el request con el hostname deseado
        char request[MAX_BODY_LEN] = {};
        strcat(request, postFields1);
        strcat(request, host_search);
        strcat(request, postFields2);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(request));
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hs);

        // Salvar informacion
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform( ) returned %s\n", curl_easy_strerror(res));
        else{
          char *ptr = s.ptr;
          long value, index, ttl;
          char *id;
          char *ip;
          char ip_lists [MAX_IPS][IP_LEN];

          // revisar si existe el hostname
          ptr = strstr(ptr, "\"value\"");
          ptr = strchr(ptr, ':');
          ptr++;
          value = strtol(ptr, &ptr, 10);
          printf("Valor es: %lu\n", value);
          ptr++;
          if (value == 1) { 
            // obtener id de doc
            ptr = strstr(ptr, "\"_id\"");
            ptr = strchr(ptr, ':');
            ptr = strchr(ptr, '"');
            ptr++;

            char copy[strlen(ptr)];
            strcpy(copy, ptr);
            const char deli[] = "\"";
            id = strtok(copy, deli);
            printf("ID: %s\n", id);

            // Procesar los IPS
            ptr = strstr(ptr, "\"IP\"");
            char temp[strlen(ptr)];
            strcpy(temp, ptr);

            ptr = strchr(ptr, '[');
            ptr = strchr(ptr, '"');
            ptr++;

            char ips_string[strlen(ptr)];
            strcpy(ips_string, ptr);
            
            ip = strtok(ips_string, "]");

            int len_ips = 0;
            ip = strtok(ip, ", ");
            while (ip != NULL){
              strcpy(ip_lists[len_ips++], ip);
              ip = strtok(NULL,", ");
            }
            ip_lists[len_ips-1][strlen(ip_lists[len_ips-1])-1] = '\0'; //remove " character from last ip

            // agarrar index para el round-robin
            ptr = strstr(ptr, "\"index\"");
            ptr = strchr(ptr, ':');
            ptr = strchr(ptr, '[');
            ptr++;
            index = strtol(ptr, &ptr, 10);

            printf("index: %lu\n", index);

            ptr = strstr(ptr, "\"TTL\"");
            ptr = strchr(ptr, ':');
            ptr = strchr(ptr, '[');
            ptr++;
            ttl = strtol(ptr, &ptr, 10);

            printf("ttl: %lu\n", ttl);
            TTL = ttl;

            // ROUND ROBIN
            char *ip_rr = malloc(IP_LEN);
            strcpy(ip_rr, ip_lists[index%len_ips]);
            printf("Ip a devolver: %s\n", ip_rr);

            char index_url[strlen(update_url)+strlen(id)];
            strcpy(index_url, update_url);
            strcat(index_url, id);

            // Actualiza el index de elastic
            curl_easy_setopt(curl, CURLOPT_URL, index_url);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields_updateIndex);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(postFields_updateIndex));
            res = curl_easy_perform(curl);
            if (res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform POST( ) returned %s\n", curl_easy_strerror(res));
            else printf("Exito al actualizar el index\n");   
            
            curl_easy_cleanup(curl);
            free(s.ptr);
            return ip_rr;
          }    
        }
        curl_easy_cleanup(curl);
        free(s.ptr);

        return NULL;
    }
}

// Driver code
int main()
{
    int sockfd;
    char buffer[MAXLINE];

    struct sockaddr_in servaddr, cliaddr;

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
    servaddr.sin_port = htons(atoi(getenv("DNS_INTERCEPTOR_PORT")));

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n, isFirstCase;

    len = sizeof(cliaddr); // len is value/result

    while (1)
    {   
        isFirstCase = 0;
        bzero(buffer, MAXLINE);
        n = recvfrom(sockfd, &buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
        unsigned int qr = (unsigned int)buffer[2];
        qr = qr << 24;
        qr = qr >> 31;

        printf("QR : %u \n", qr);
        unsigned int opcode = (unsigned int)buffer[2];
        opcode = opcode << 25;
        opcode = opcode >> 28;
        printf("OPCODE: %u \n", opcode);
        
        if (qr == 0 && opcode == 0 ){ // send to elastic
          isFirstCase = 1;
          unsigned int hostname_index = 12; // start at hostname position
          int left = buffer[hostname_index++]; // size of first part

          char hostname[MAX_LEN_HOSTNAME];
          int i = 0;
          while (buffer[hostname_index] != '\0'){
              if (left == 0) {
                  left = buffer[hostname_index++];
                  hostname[i++] = '.';
              } else {
                  hostname[i++] = buffer[hostname_index++];
                  left--;
              }
          }
          hostname[i] = '\0';

          char *ip = call_elastic(hostname); // buscar el hostname en elastic
          if (ip == NULL) // no encuentra el hostname
            isFirstCase = 0;
          else { //entra si encontró hostname
            unsigned int mask = 1;
            mask = mask << 7;
            buffer[2] = buffer[2] | mask; // cambiar QR bit

            buffer[3] = buffer[3] | mask; // cambiar RA bit

            // ANCOUNT (answer count) to 1 
            buffer[7] = 1;

            // Cuerpo de response ------------------------
            buffer[n++] = 192; // c0
            buffer[n++] = 12; // 0c

            // type 1
            n++;
            buffer[n++] = 1;

            // class 1
            n++;
            buffer[n++] = 1;

            // ttl
            n++;
            n++;
            n++;
            if (TTL > 255){ // mayor a FF FF FF FF
              TTL = 255; 
            }
            buffer[n++] = TTL; // c2

            // rlength 4 bytes always
            n++;
            buffer[n++] = 4;

            //rdata
            int octet = 0;
            for (int j=0; j<strlen(ip); j++){
                if (ip[j] != '.'){
                    octet = octet*10 + (ip[j] - '0');

                } else{
                    buffer[n++] = octet;
                    octet = 0;
                }
            }
            buffer[n++] = octet;
            buffer[n] = '\0';
            sendto(sockfd, buffer, n, 0, (struct sockaddr *)&cliaddr, len); 
          }
        } // other cases
        if (isFirstCase == 0){
          // caso donde QR o OPCODE no son 0 ó que no encontró el hostname en elastic
          // send to API
          char *encoded;
          unsigned char *decoded;
          encoded = base64_encode(buffer, n, NULL);
          char* response = postToApi(encoded);
          decoded = decode(response);

          // send to client
          sendto(sockfd, decoded, MAXLINE, 0, (struct sockaddr *)&cliaddr, len);
        }
    }
    return 0;
}
