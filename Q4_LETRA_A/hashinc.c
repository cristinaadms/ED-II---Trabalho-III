#include <stdio.h>
#include <stdlib.h>
#include "hashing.h"

//função 1: para rotacionamento da matrícula para a esquerda e extração dos dígitos solicitados
int Hash_Function(const char *registration, int table_size){

    int two_digit_rotation_left, second_digit, fourth_digit, sixth_digit, hash_value;
    
    two_digit_rotation_left = ((registration[2] - '0')*1000 + (registration[3] - '0')*100 + (registration[4] - '0')*10 + (registration[5] - '0')) % table_size;

    second_digit = registration[1] -'0';
    fourth_digit = registration[3] -'0';
    sixth_digit = registration[5] -'0';

    hash_value = (second_digit*100 + fourth_digit*10 + sixth_digit) % table_size;

    return hash_value;

}

