#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MASCARA1BIT 0b1000000
#define MASCARA2BIT 0b0100000
#define MASCARA3BIT 0b0010000
#define MASCARA4BIT 0b0001000
#define MASCARA5BIT 0b0000100
#define MASCARA6BIT 0b0000010
#define MASCARA7BIT 0b0000001

#define MASCARAN8BIT 0b01111111
#define MASCARAN12BIT 0b011111111111

#define MASCARAD1BIT 0b10000000000
#define MASCARAD2BIT 0b01000000000
#define MASCARAD3BIT 0b00100000000
#define MASCARAD4BIT 0b00010000000
#define MASCARAD5BIT 0b00001000000
#define MASCARAD6BIT 0b00000100000
#define MASCARAD7BIT 0b00000010000
#define MASCARAD8BIT 0b00000001000
#define MASCARAD9BIT 0b00000000100
#define MASCARAD10BIT 0b00000000010
#define MASCARAD11BIT 0b00000000001

#define CANTIDADBITS 7
#define CANTIDADDBITS 11

int p1Paridad(int input){
    int cantidadUnos = 0;
    int primerBit = input & MASCARA1BIT;
    primerBit >>= CANTIDADBITS - 1;
    if(primerBit == 1) cantidadUnos++;

    int segundoBit = input & MASCARA2BIT;
    segundoBit >>= CANTIDADBITS - 2;
    if(segundoBit == 1) cantidadUnos++;

    int tercerBit = input & MASCARA4BIT;
    tercerBit >>= CANTIDADBITS - 4;
    if(tercerBit == 1) cantidadUnos++;

    int cuartoBit = input & MASCARA5BIT;
    cuartoBit >>= CANTIDADBITS - 5;
    if(cuartoBit == 1) cantidadUnos++;

    int quintoBit = input & MASCARA7BIT;
    quintoBit >>= CANTIDADBITS - 7;
    if(quintoBit == 1) cantidadUnos++;

    if(cantidadUnos % 2 == 0) return 0;
    else return 1;
}

int p2Paridad(int input) {
    int cantidadUnos = 0;
    int primerBit = input & MASCARA1BIT;
    primerBit >>= CANTIDADBITS - 1;
    if(primerBit == 1) cantidadUnos++;

    int segundoBit = input & MASCARA3BIT;
    segundoBit >>= CANTIDADBITS - 3;
    if(segundoBit == 1) cantidadUnos++;

    int tercerBit = input & MASCARA4BIT;
    tercerBit >>= CANTIDADBITS - 4;
    if(tercerBit == 1) cantidadUnos++;

    int cuartoBit = input & MASCARA6BIT;
    cuartoBit >>= CANTIDADBITS - 6;
    if(cuartoBit == 1) cantidadUnos++;

    int quintoBit = input & MASCARA7BIT;
    quintoBit >>= CANTIDADBITS - 7;
    if(quintoBit == 1) cantidadUnos++;

    if(cantidadUnos % 2 == 0) return 0;
    else return 1;
}

int p4Paridad(int input) {
    int cantidadUnos = 0;
    int primerBit = input & MASCARA2BIT;
    primerBit >>= CANTIDADBITS - 2;
    if(primerBit == 1) cantidadUnos++;

    int segundoBit = input & MASCARA3BIT;
    segundoBit >>= CANTIDADBITS - 3;
    if(segundoBit == 1) cantidadUnos++;

    int tercerBit = input & MASCARA4BIT;
    tercerBit >>= CANTIDADBITS - 4;
    if(tercerBit == 1) cantidadUnos++;

    if(cantidadUnos % 2 == 0) return 0;
    else return 1;
}

int p8Paridad(int input) {
    int cantidadUnos = 0;
    int primerBit = input & MASCARA5BIT;
    primerBit >>= CANTIDADBITS - 5;
    if(primerBit == 1) cantidadUnos++;

    int segundoBit = input & MASCARA6BIT;
    segundoBit >>= CANTIDADBITS - 6;
    if(segundoBit == 1) cantidadUnos++;

    int tercerBit = input & MASCARA7BIT;
    tercerBit >>= CANTIDADBITS - 7;
    if(tercerBit == 1) cantidadUnos++;

    if(cantidadUnos % 2 == 0) return 0;
    else return 1;
}

int p1ParidadR(int input){
    int cantidadUnos = 0;
    int primerBit = input & MASCARAD1BIT;
    primerBit >>= CANTIDADDBITS - 1;
    if(primerBit == 1) cantidadUnos++;

    int segundoBit = input & MASCARAD3BIT;
    segundoBit >>= CANTIDADDBITS - 3;
    if(segundoBit == 1) cantidadUnos++;

    int tercerBit = input & MASCARAD5BIT;
    tercerBit >>= CANTIDADDBITS - 5;
    if(tercerBit == 1) cantidadUnos++;

    int cuartoBit = input & MASCARAD7BIT;
    cuartoBit >>= CANTIDADDBITS - 7;
    if(cuartoBit == 1) cantidadUnos++;

    int quintoBit = input & MASCARAD9BIT;
    quintoBit >>= CANTIDADDBITS - 9;
    if(quintoBit == 1) cantidadUnos++;

    int sextoBit = input & MASCARAD11BIT;
    sextoBit >>= CANTIDADDBITS - 11;
    if(sextoBit == 1) cantidadUnos++;

    if(cantidadUnos % 2 == 0) return 0;
    else return 1;
}

int p2ParidadR(int input) {
    int cantidadUnos = 0;
    int primerBit = input & MASCARAD2BIT;
    primerBit >>= CANTIDADBITS - 2;
    if(primerBit == 1) cantidadUnos++;

    int segundoBit = input & MASCARAD3BIT;
    segundoBit >>= CANTIDADBITS - 3;
    if(segundoBit == 1) cantidadUnos++;

    int tercerBit = input & MASCARAD6BIT;
    tercerBit >>= CANTIDADBITS - 6;
    if(tercerBit == 1) cantidadUnos++;

    int cuartoBit = input & MASCARAD7BIT;
    cuartoBit >>= CANTIDADBITS - 7;
    if(cuartoBit == 1) cantidadUnos++;

    int quintoBit = input & MASCARAD10BIT;
    quintoBit >>= CANTIDADBITS - 10;
    if(quintoBit == 1) cantidadUnos++;

    int sextoBit = input & MASCARAD11BIT;
    sextoBit >>= CANTIDADBITS - 11;
    if(sextoBit == 1) cantidadUnos++;

    if(cantidadUnos % 2 == 0) return 0;
    else return 1;
}

int p4ParidadR(int input) {
    int cantidadUnos = 0;
    int primerBit = input & MASCARAD4BIT;
    primerBit >>= CANTIDADBITS - 4;
    if(primerBit == 1) cantidadUnos++;

    int segundoBit = input & MASCARAD5BIT;
    segundoBit >>= CANTIDADBITS - 5;
    if(segundoBit == 1) cantidadUnos++;

    int tercerBit = input & MASCARAD6BIT;
    tercerBit >>= CANTIDADBITS - 6;
    if(tercerBit == 1) cantidadUnos++;

    int cuartoBit = input & MASCARAD7BIT;
    cuartoBit >>= CANTIDADBITS - 7;
    if(tercerBit == 1) cantidadUnos++;

    if(cantidadUnos % 2 == 0) return 0;
    else return 1;
}

int p8ParidadR(int input) {
    int cantidadUnos = 0;
    int primerBit = input & MASCARAD8BIT;
    primerBit >>= CANTIDADBITS - 8;
    if(primerBit == 1) cantidadUnos++;

    int segundoBit = input & MASCARAD9BIT;
    segundoBit >>= CANTIDADBITS - 9;
    if(segundoBit == 1) cantidadUnos++;

    int tercerBit = input & MASCARAD10BIT;
    tercerBit >>= CANTIDADBITS - 10;
    if(tercerBit == 1) cantidadUnos++;

    int cuartoBit = input & MASCARAD11BIT;
    cuartoBit >>= CANTIDADBITS - 11;
    if(cuartoBit == 1) cantidadUnos++;

    if(cantidadUnos % 2 == 0) return 0;
    else return 1;
}

int verificarHamming(unsigned numero) {
    int bitParidadUno = p1ParidadR(numero);
    int bitParidadDos = p2ParidadR(numero);
    int bitParidadTres = p4ParidadR(numero);
    int bitParidadCuatro = p8ParidadR(numero);
    int suma = bitParidadUno + bitParidadDos + bitParidadTres + bitParidadCuatro;
    if(suma > 0){
        printf("Se encontro una cantidad impar en la paridad");
        return 0;
    }
    return 1;
}

unsigned getHamming(unsigned numero) {
    int bitParidadUno = p1Paridad(numero);
    int bitParidadDos = p2Paridad(numero);
    int bitParidadTres = p4Paridad(numero);
    int bitParidadCuatro = p8Paridad(numero);
    unsigned respuesta = 0;
    respuesta ^= (-bitParidadUno ^ respuesta) & (1UL << 10);
    respuesta ^= (-bitParidadDos ^ respuesta) & (1UL << 9);

    int bitActual = (numero & ( 1 << 6 )) >> 6;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 8);

    respuesta ^= (-bitParidadTres ^ respuesta) & (1UL << 7);

    bitActual = (numero & ( 1 << 5 )) >> 5;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 6);
    bitActual = (numero & ( 1 << 4 )) >> 4;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 5);
    bitActual = (numero & ( 1 << 3 )) >> 3;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 4);

    respuesta ^= (-bitParidadCuatro ^ respuesta) & (1UL << 3);

    bitActual = (numero & ( 1 << 2 )) >> 2;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 2);
    bitActual = (numero & ( 1 << 1 )) >> 1;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 1);
    bitActual = (numero & ( 1 << 0 )) >> 0;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 0);
    return respuesta;
}

unsigned decodificar(unsigned numero) {
    int bitParidadUno = p1ParidadR(numero);
    int bitParidadDos = p2ParidadR(numero);
    int bitParidadTres = p4ParidadR(numero);
    int bitParidadCuatro = p8ParidadR(numero);
    unsigned respuesta = bitParidadUno + bitParidadDos + bitParidadTres + bitParidadCuatro;
    if(respuesta > 0){
        printf("Numero impar en el bit de parity\n");
        exit(0);
    }
    int bitActual = (numero & ( 1 << 0 )) >> 0;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 0);
    bitActual = (numero & ( 1 << 1 )) >> 1;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 1);
    bitActual = (numero & ( 1 << 2 )) >> 2;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 2);

    bitActual = (numero & ( 1 << 4 )) >> 4;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 3);
    bitActual = (numero & ( 1 << 5 )) >> 5;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 4);
    bitActual = (numero & ( 1 << 6 )) >> 6;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 5);

    bitActual = (numero & ( 1 << 8 )) >> 8;
    respuesta ^= (-bitActual ^ respuesta) & (1UL << 6);
    return respuesta;
}

int main(int arcg, char *argv[]) {
    unsigned arreglo[10];
    int cantidadElementos = 0;
    int cantidadUsados = 0;
    if(strcmp(argv[1], "encode") == 0){
        unsigned long hexadecimal = (unsigned long)strtol(argv[3], NULL, 16);
        unsigned long respuesta = 0;
        while(hexadecimal != 0) {
            unsigned low8bits = hexadecimal & 0xFF;
            unsigned low7bits = low8bits & MASCARAN8BIT;
            unsigned long hamming = getHamming(low7bits);
            hamming <<= cantidadUsados;
            respuesta += hamming;
            hexadecimal >>= 7;
            cantidadUsados += 11;
        }
        printf("El elemento codificado seria: %lX\n", respuesta);
    }
    else if(strcmp(argv[1], "decode") == 0) {
        unsigned long hexadecimal = (unsigned long)strtoul(argv[3], NULL, 16);
        if(arcg > 5) {
            for(int indiceArgs = 5; indiceArgs < arcg; indiceArgs++) {
                int posicionError = atoi(argv[indiceArgs]);
                hexadecimal ^= 1UL << posicionError;
            }
        } 
        unsigned long respuesta = 0;
        while(hexadecimal != 0) {
            unsigned low12bits = hexadecimal & 0xFFF;
            unsigned low11bits = low12bits & MASCARAN12BIT;
            unsigned long hamming = decodificar(low11bits);
            hamming <<= cantidadUsados;
            respuesta += hamming;
            cantidadUsados += 7;
            hexadecimal >>= 11;
        }
        printf("El elemento decodificado seria: %lX\n", respuesta);
    }

    return 0;
}