#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

// https://stackoverflow.com/questions/2329571/c-libcurl-get-output-into-a-string
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
  size_t new_len = s->len + size*nmemb;
  s->ptr = realloc(s->ptr, new_len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->ptr+s->len, ptr, size*nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size*nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;
    // Este espacio no es solo para post, es el espacio de corchetes que se ven en los queries
    // Ejemplo de queries en el dev tools de kibana: https://www.youtube.com/watch?v=e5awiVnkuEc&t=605s&ab_channel=SoumilShah
    //                                               Los ejemplos se encuentran alrededor de los 10 minutos
    char *postFields = "{\"query\": {\"match_phrase\": {\"text\": \"AAAh funny text\"}}}";

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    struct curl_slist *hs = NULL;
    hs = curl_slist_append(hs, "Content-Type: application/json");

    if (curl)
    {
        struct string s;
        init_string(&s);
        // URL de la api de elasticsearch
        curl_easy_setopt(curl, CURLOPT_URL, "https://localhost:5000/api/dns_resolver/lol");
        // Desactivar verificaciones
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        //curl_easy_setopt(curl, CURLOPT_PUT, 1);
        // Por aqui se pasa el usuario y la contrasena del elasticseearch
        curl_easy_setopt(curl, CURLOPT_USERPWD, "elastic:s*oP4MNXI=VBw4ys*jV_");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(postFields));
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hs);
        // Salvar informacion
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform( ) returned %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
        free(s.ptr);
    }
    return 0;
}