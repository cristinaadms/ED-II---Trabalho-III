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

//função 2: para substituição de registro quando todas as tentativas falharem
void Replace_Employee(HashingTable *hash_table, int index_employee){

    free(hash_table->table[index_employee].employee);
    hash_table->table[index_employee].busy = 0;

}

//função 3: para tratamento de colisões
void Insert_Employee(HashingTable *hash_table, Employee *employee){

    int index_employee, original_index_employee, replaced =0;
    
    index_employee = Hash_Function(employee->registration, hash_table->size);

    original_index_employee = index_employee;

    while (hash_table->table[index_employee].busy == 1){
        index_employee = (index_employee + (employee->registration[0] - '0')) % hash_table->size;
        hash_table->collisions++;

        if(index_employee == original_index_employee){
            Replace_Employee(hash_table, original_index_employee);
            replaced = 1;
        }
    }

    hash_table->table[index_employee].employee = employee;
    hash_table->table[index_employee].busy = 1;

}

//função 4: inicialização da tabela de hash
void Initialize_Hash_Table(HashingTable *hash_table, int size){

    hash_table->size = size;
    hash_table->collisions = 0;
    hash_table->table = (HashEntry*)malloc(sizeof(HashEntry)*size);

    for(int i=0; i < size; i++){
        hash_table->table[i].employee = NULL;
        hash_table->table[i].busy = 0;
    }
}

//função 5: exibição para verificação dos dados dos funcionários na tabela de hash
void Show_Hash_Table(HashingTable *hash_table){

    for(int i = 0; i < hash_table->size; i++){
        if(hash_table->table[i].busy == 1){
            printf("Index Employee %d: %s - %s - %s - %.2f\n", i, hash_table->table[i].employee->registration, hash_table->table[i].employee->name, hash_table->table[i].employee->function, hash_table->table[i].employee->salary);
        }
    }
}

//função 6: liberação de memória alocada para a tabela de hash
void Free_Hash_Table(HashingTable *hash_table){

    for(int i=0; i<hash_table->size; i++){
        if(hash_table->table[i].busy == 1){
            free(hash_table->table[i].employee);
        }
    }

    free(hash_table->table);
}





