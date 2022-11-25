#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_BODY_LEN 200

struct string {
    char * ptr;
    size_t len;
};

void init_string(struct string *s) {
  s->len = 0;
  s->ptr = malloc(s->len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
    size_t new_len = s->len + size * nmemb;
    s->ptr = realloc(s->ptr, new_len + 1);
    if (s->ptr == NULL)
    {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr + s->len, ptr, size * nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size * nmemb;
}


// POST api/dns_resolver
char* postToApi(char *data)
{
    CURL *curl;
    CURLcode res;

    char* URL = getenv("URL_POST_API");

    curl_global_init(CURL_GLOBAL_ALL);
    /*get a curl curl*/
    curl = curl_easy_init();

    struct curl_slist *hs = NULL;
    hs = curl_slist_append(hs, "Content-Type: application/json");

    if (curl)
    {
        struct string s;
        init_string(&s);
        // API url set
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, URL);

        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        // Disable verification
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hs);
        
        char request[MAX_BODY_LEN] = {};
        char *postFields1 = "{\"code\":\"";
        strcat(request, postFields1);
        strcat(request, data);
        strcat(request, "\"}");
        printf("request = %s\n",request);
        
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(request));

        // Write request response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            printf("Theres been an error: %s\n", curl_easy_strerror(res));
        char *ptr = s.ptr;
        ptr = strstr(ptr, "\"response\"");
        ptr = strchr(ptr, '\'');
        ptr++;
        char * paquete = strtok(ptr, "\'");
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return paquete;
    }
}