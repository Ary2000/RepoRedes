#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

CURL *curl;
CURLcode res;


void post(char* data, int port){
    curl_global_init(CURL_GLOBAL_ALL);
    /*get a curl handle*/
    curl = curl_easy_init();
    if(curl){
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}