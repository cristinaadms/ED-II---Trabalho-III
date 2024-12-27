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

//função 2: para tratamento de colisões
void Insert_Employee(HashingTable *hash_table, Employee *employee){

    int index_employee;
    
    index_employee = Hash_Function(employee->registration, hash_table->size);

    while (hash_table->table[index_employee].busy == 1){
        index_employee = (index_employee + (employee->registration[0] - '0')) % hash_table->size;
        hash_table->collisions++;
    }

    hash_table->table[index_employee].employee = employee;
    hash_table->table[index_employee].busy = 1;

}

