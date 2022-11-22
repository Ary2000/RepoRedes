#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

CURL *handle;
CURLcode res;

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
void postToApi(char *data)
{
    curl_global_init(CURL_GLOBAL_ALL);
    /*get a curl handle*/
    handle = curl_easy_init();

    struct curl_slist *hs = NULL;
    hs = curl_slist_append(hs, "Content-Type: application/json");

    // modificar para un post valido de DNS API
    char *postFields = "{\"query\": {\"match_phrase\": {\"text\": \"AAAh funny text\"}}}";

    if (handle)
    {
        struct string s;
        init_string(&s);
        // API url set
        curl_easy_setopt(handle, CURLOPT_URL, "https://localhost:5000/api/dns_resolver");
        // Disable verification
        curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 0L);
        // Post data
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hs);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(postFields));
        // Write request response
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, &s);
        res = curl_easy_perform(handle);

        if (res != CURLE_OK)
            printf("Theres been an error: %s\n", curl_easy_strerror(res));
        
        free(s.ptr);
    }

    curl_easy_cleanup(handle);
    curl_global_cleanup();
}