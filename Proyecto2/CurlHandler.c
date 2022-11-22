#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

CURL *handle;
CURLcode res;


void post(char* data, int port){
    curl_global_init(CURL_GLOBAL_ALL);
    /*get a curl handle*/
    handle = curl_easy_init();
    if(handle){
        curl_easy_cleanup(handle);
    }
    curl_global_cleanup();
}