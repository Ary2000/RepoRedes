#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

CURL *handle;
CURLcode res;

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

// Agregar metodo post para Kibana
void postToKibana();

// POST api/dns_resolver
char* postToApi(char *data)
{
    char URL[255] = "https://localhost:5000/api/dns_resolver/";
    curl_global_init(CURL_GLOBAL_ALL);
    /*get a curl handle*/
    handle = curl_easy_init();

    struct curl_slist *hs = NULL;
    hs = curl_slist_append(hs, "Content-Type: application/json");

    if (handle)
    {
        struct string s;
        init_string(&s);
        strcat(URL, data);
        // API url set
        curl_easy_setopt(handle, CURLOPT_URL, URL);
        // Disable verification
        curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 0L);
        // curl_easy_setopt(handle, CURLOPT_POST, 1);
        curl_easy_setopt(handle, CURLOPT_HTTPHEADER, hs);
        // Write request response
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, &s);
        res = curl_easy_perform(handle);

        if (res != CURLE_OK)
            printf("Theres been an error: %s\n", curl_easy_strerror(res));

        char *ptr = s.ptr;
        ptr = strstr(ptr, "\"response\"");
        ptr = strchr(ptr, '\'');
        ptr++;
        char * paquete = strtok(ptr, "\'");
        printf("response: %s\n", paquete);
        curl_easy_cleanup(handle);
        curl_global_cleanup();
        return paquete;
    }
}