#include <stdio.h>
#include <curl/curl.h>

int main()
{
    CURL *curl;
    CURLcode res;
    char *postFields = "{\"prueba\" : \"hola\"}";

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    struct curl_slist *hs = NULL;
    hs = curl_slist_append(hs, "Content-Type: application/json");

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://localhost:9200/boards/_doc");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_USERPWD, "elastic:5X4s2E9ImjCX35eZl97cS1i4");
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(postFields));
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hs);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform( ) returned %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
    return 0;
}