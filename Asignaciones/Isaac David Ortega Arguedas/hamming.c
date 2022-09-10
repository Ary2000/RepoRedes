#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void encode(int input){
    int a = input;
    printf("value of a: %X [%x]\n",a,a);
    /*char* hexadecimal = input+2;
    int len = strlen(hexadecimal);
    printf(hexadecimal);
    printf("size = %lu bytes \n", strlen(hexadecimal));*/
}

int main(int argc, char* argv[]){
    if(argc < 2){
        encode(0x2541);
        return 0;
    }else{
        int num = atoi(argv[1]);
        encode(num);
        return 0;
    }
}