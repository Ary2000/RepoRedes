// Quiz # 2 y #3
// Hecho por Zhong Jie Liu Guo
// Carné: 2018319114
// Fecha: 10/9/2022

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

// convert hexadecimal to decimal
unsigned long hex_to_dec (char hexa_value[]) {
    unsigned long result = 0;
    for (int i = 2; i < strlen(hexa_value); i++){
        result = result << 4;
        if (hexa_value[i] >= 'A' && hexa_value[i] <= 'F') 
            result += hexa_value[i] - '7';
        else
            result += hexa_value[i] - '0';
    }
    return result;
}

// get the first parity bit from encoder
int p1_enc (unsigned int bits){
    int par_count = 0;
    int position_p1[] = {6, 5, 3, 2, 0};
    
    unsigned int temp_bits = 0;
    for (int i = 0; i < 5; i++){
        temp_bits = bits >> position_p1[i];
        temp_bits = temp_bits & 1; // mask 0000 0001
        if (temp_bits == 1) par_count++;
    }
    return par_count % 2;
}

// get the second parity bit from encoder
int p2_enc (unsigned int bits){
    int par_count = 0;
    int position_p2[] = {6, 4, 3, 1, 0};
    
    unsigned int temp_bits = 0;
    for (int i = 0; i < 5; i++){
        temp_bits = bits >> position_p2[i];
        temp_bits = temp_bits & 1; // mask 0000 0001
        if (temp_bits == 1) par_count++;
    }
    return par_count % 2;
}

// test the fourth parity bit from encoder
int p4_enc (unsigned int bits){
    int par_count = 0;
    int position_p3[] = {5, 4, 3};
    
    unsigned int temp_bits = 0;
    for (int i = 0; i < 3; i++){
        temp_bits = bits >> position_p3[i];
        temp_bits = temp_bits & 1; // mask 0000 0001
        if (temp_bits == 1) par_count++;
    }
    return par_count % 2;
}

// test the eight parity bit from encoder
int p8_enc (unsigned int bits){
    int par_count = 0;
    int position_p4[] = {2, 1, 0};
    
    unsigned int temp_bits = 0;
    for (int i = 0; i < 3; i++){
        temp_bits = bits >> position_p4[i];
        temp_bits = temp_bits & 1; // mask 0000 0001
        if (temp_bits == 1) par_count++;
    }
    return par_count % 2;
}

// get the parity of the first bit of parity for the decoder
int p1_dec (unsigned int bits){
    int par_count = 0;
    int position_p1[] = {10, 8, 6, 4, 2, 0};
    
    unsigned int temp_bits = 0;
    for (int i = 0; i < 6; i++){
        temp_bits = bits >> position_p1[i];
        temp_bits = temp_bits & 1; // mask 0000 0001
        if (temp_bits == 1) par_count++;
    }
    return par_count % 2;
}

// get the parity of the second bit of parity for the decoder
int p2_dec (unsigned int bits){
    int par_count = 0;
    int position_p2[] = {9, 8, 5, 4, 1, 0};
    
    unsigned int temp_bits = 0;
    for (int i = 0; i < 6; i++){
        temp_bits = bits >> position_p2[i];
        temp_bits = temp_bits & 1; // mask 0000 0001
        if (temp_bits == 1) par_count++;
    }
    return par_count % 2;
}

// get the parity of the fourth bit of parity for the decoder
int p4_dec (unsigned int bits){
    int par_count = 0;
    int position_p3[] = {7, 6, 5, 4};
    
    unsigned int temp_bits = 0;
    for (int i = 0; i < 4; i++){
        temp_bits = bits >> position_p3[i];
        temp_bits = temp_bits & 1; // mask 0000 0001
        if (temp_bits == 1) par_count++;
    }
    return par_count % 2;
}

// get the parity of the eight bit of parity for the decoder
int p8_dec (unsigned int bits){
    int par_count = 0;
    int position_p4[] = {3, 2, 1, 0};
    
    unsigned int temp_bits = 0;
    for (int i = 0; i < 4; i++){
        temp_bits = bits >> position_p4[i];
        temp_bits = temp_bits & 1; // mask 0000 0001
        if (temp_bits == 1) par_count++;
    }
    return par_count % 2;
}

// It takes a seven bit number and encodes it in a 11 bit number
unsigned long form_new_11_number(unsigned int bits){
    unsigned long new_number, temp;
    int bit_par;
    new_number = 0;
    
    bit_par = p1_enc(bits);
    new_number += bit_par;
    new_number = new_number << 1;
    
    bit_par = p2_enc(bits);
    new_number += bit_par;
    new_number = new_number << 1;
    
    temp = bits << 1;
    temp = temp >> 7;
    new_number += temp;
    new_number = new_number << 1;
    
    bit_par = p4_enc(bits);
    new_number += bit_par;
    new_number = new_number << 3;
    
    temp = bits >> 3;
    temp = temp & 7; // mask 0000 0111
    new_number += temp;
    new_number = new_number << 1;
    
    bit_par = p8_enc(bits);
    new_number += bit_par;
    new_number = new_number << 3;
    
    temp = bits & 7; // mask 0000 0111
    new_number += temp;
    
    return new_number;
}

// it decodes a 11 bit and extracts the 7 bit number.
unsigned long decode_11_bits(unsigned int bits){
    unsigned long result = 0;
    int position[] = {8, 6, 5, 4, 2, 1, 0};
    
    unsigned long temp_bits = 0;
    for (int i = 0; i < 7; i++){
        result = result << 1;
        temp_bits = bits >> position[i];
        temp_bits = temp_bits & 1; // mask 0000 0001
        result += temp_bits;
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 4){
        printf("Usage of program is: ./hamming encode --input 0x12AF\n");
        printf("Or usage of program is: ./hamming decode --input 0x12AF [--error bitnumber]* ");
        return 1;
    }
    int encode_confirm = 0;
    if (strcmp(argv[1], "encode") == 0){
        printf("Encoding\n");
        encode_confirm = 1;
    }
    else if (strcmp(argv[1], "decode") == 0){
        printf("Decoding\n");
        encode_confirm = 0;
    } else{
        printf("ERROR: must be decode or encode\n");
        return 1;
    }
    
    if (strcmp(argv[2], "--input") == 1){
        printf("ERROR: must be --input\n");
        return 1;
    }
    
    unsigned long value = hex_to_dec (argv[3]);
    printf("%lu\n",value);
    
    int number_of_extra_0s = (strlen(argv[3])-2)*4 % 7;
    int number_bits = (strlen(argv[3])-2)*4;
    
    if (encode_confirm == 1){// encode
        int number_of_7s = (strlen(argv[3])-2)*4 / 7;
    
        unsigned int actual_bits = 0;
        unsigned int first_bits = value >> (number_bits - number_of_extra_0s);
        
        unsigned long new_number = form_new_11_number(first_bits);
        
        for (int i = 1; i <= number_of_7s; i++){
            printf("----------------------------\n");
            actual_bits = value >> (7*(number_of_7s-i));
            actual_bits = actual_bits & 127; // mask 0111 1111
            new_number = new_number << 11;
            new_number += form_new_11_number(actual_bits);
        }
        
        printf("The encoded number of %s, is: 0x%X\n", argv[3], new_number);
        
    } else{ // decode
        int error_bit = -1;
        int maxbits = number_bits - number_of_extra_0s;
        unsigned long mask_error;
        
        printf("The information before the errors is: 0x%X\n", value);
        // modifying bit for error
        for (int i = 5; i < argc; i = i + 2){
            error_bit = atoi(argv[i]);
            mask_error = 1 << (maxbits - error_bit);
            value = value ^ mask_error;      
        }
        
        if (argc > 6){
            printf("Multiple errors requested, it's possible that the data can't be fully recovered\n");
        }
        printf("The information after the errors is: 0x%X\n", value);
    
        int actual_bits = 0;
        int parity_result = 0;
        int counter_bits = 0;
        unsigned long copy_value = value;
        unsigned long repairing_mask;
        unsigned long decoded_value = 0;
        unsigned long decoding_mask = 375; // 0001 0111 0111
        
        while (copy_value != 0) {
            actual_bits = copy_value & 2047; // mask 0111 1111 1111
            parity_result += p8_dec(actual_bits);
            parity_result = parity_result << 1;
            
            parity_result += p4_dec(actual_bits);
            parity_result = parity_result << 1;
            
            parity_result += p2_dec(actual_bits);
            parity_result = parity_result << 1;
            
            parity_result += p1_dec(actual_bits);
            if (parity_result != 0){ // error
                repairing_mask = 1 << (11-parity_result); 
                actual_bits = actual_bits ^ repairing_mask; // XOR to change the bit
            }
            decoded_value +=  decode_11_bits(actual_bits) << (7*counter_bits);
            counter_bits++;
            copy_value = copy_value >> 11;
        }
        printf("The decoded number of %s, is: 0x%X\n", argv[3], decoded_value);
    }
    
    return 0;
}