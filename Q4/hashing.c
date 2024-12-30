#include <stdio.h>
#include <stdlib.h>
#include "hashing.h"

//função para calcular o valor rotacionado com os digitos 3º,4º,5º e 6º
int Calculate_Rotated_Value(const char *registration, int table_size){

    int rotated_value;

    rotated_value = ((registration[2] - '0')*1000 + (registration[3] - '0')*100 + (registration[4] - '0')*10 + (registration[5] - '0')) % table_size;

    return rotated_value;

}

//função para extração de dígitos específicos e formação de um número com 2º, 4º e 6º dígitos
int Extract_Digits(const char *registration){

    int two_digit_rotation_left, second_digit, fourth_digit, sixth_digit, hash_value_aux;

    second_digit = registration[1] -'0';
    fourth_digit = registration[3] -'0';
    sixth_digit = registration[5] -'0';

    hash_value_aux = second_digit*100 + fourth_digit*10 + sixth_digit;

    return hash_value_aux;

}

//função para cálculo do índice de hash final
int Hash_Function_LA(const char *registration, int table_size){

    int rotated_value, extracted_value, hash_value;

    rotated_value = Calculate_Rotated_Value(registration, table_size);
    extracted_value = Extract_Digits(registration);

    hash_value = extracted_value % table_size;

    return hash_value;

}


//função para fold shift com 3 dígitos (1º, 3º, 6º e 2º, 4º, 5º)
int Hash_Function_LB(const char *registration, int table_size){
    int part1, part2, hash_value;

    part1 = (registration[0] - '0')*100 + (registration[2] - '0')*10 + (registration[5] - '0');

    part2 = (registration[1] - '0')*100 + (registration[3] - '0')*10 + (registration[4] - '0');

    hash_value = (part1 + part2) % table_size;

    return hash_value;
    
}

//função para substituição de registro quando todas as tentativas falharem
void Replace_Employee(HashingTable *hash_table, int index_employee){

    if(hash_table->table[index_employee].employee != NULL){
        free(hash_table->table[index_employee].employee);
        hash_table->table[index_employee].busy = 0;
    }

    //essa verificação para ver se a matrícula já está ocupada antes de liberar poderia ser movido para as duas funções de insert?

}

//função para tratamento de colisões (letra a)
int Handle_Collision_LA(HashingTable *hash_table, const char *registration, int original_index){

    int index_employee = original_index;

    do{
        index_employee = (index_employee + (registration[0] - '0')) % hash_table->size;
        hash_table->collisions++;
    }while(hash_table->table[index_employee].busy == 1 && index_employee != original_index);

    return index_employee;
}

//função para inserção (letra a)
void Insert_Employee_LA(HashingTable *hash_table, Employee *employee){

    int index_employee, original_index_employee;
    
    index_employee = Hash_Function_LA(employee->registration, hash_table->size);

    original_index_employee = index_employee;

    if(hash_table->table[index_employee].busy == 1){
        index_employee = Handle_Collision_LA(hash_table, employee->registration, original_index_employee);

        if(index_employee == original_index_employee){
            Replace_Employee(hash_table, original_index_employee);
        }
    }

    hash_table->table[index_employee].employee = employee;
    hash_table->table[index_employee].busy = 1;

}

//função para tratamento de colisções (lebra b)
int Handle_Collision_LB(HashingTable *hash_table, const char *registration, int original_index){

    int index_employee = original_index;

    do{
        index_employee = (index_employee + 7) % hash_table->size;
        hash_table->collisions++;
    }while (hash_table->table[index_employee].busy == 1 && index_employee != original_index);

    return index_employee; 
}

//função para inserção (letra b)
void Insert_Employee_LB(HashingTable *hash_table, Employee *employee){

    int index_employee, original_index_employee;
    
    index_employee = Hash_Function_LB(employee->registration, hash_table->size);

    original_index_employee = index_employee;

    if(hash_table->table[index_employee].busy == 1){
        index_employee = Handle_Collision_LB(hash_table, employee->registration, original_index_employee);

        if(index_employee == original_index_employee){
            Replace_Employee(hash_table, original_index_employee);
        }
    }

    hash_table->table[index_employee].employee = employee;
    hash_table->table[index_employee].busy = 1;

}

//função para inicialização da tabela de hash
void Initialize_Hash_Table(HashingTable *hash_table, int size){

    hash_table->size = size;
    hash_table->collisions = 0;
    hash_table->table = (HashEntry*)malloc(sizeof(HashEntry)*size);

    for(int i=0; i < size; i++){
        hash_table->table[i].employee = NULL;
        hash_table->table[i].busy = 0;
    }
}

//função para exibição dos dados dos funcionários na tabela de hash
void Show_Hash_Table(HashingTable *hash_table){

    for(int i = 0; i < hash_table->size; i++){
        if(hash_table->table[i].busy == 1){
            printf("Index Employee %d: %s - %s - %s - %.2f\n", i, hash_table->table[i].employee->registration, hash_table->table[i].employee->name, hash_table->table[i].employee->function, hash_table->table[i].employee->salary);
        }
    }
}

//função para liberação de memória alocada para a tabela de hash
void Free_Hash_Table(HashingTable *hash_table){

    for(int i=0; i<hash_table->size; i++){
        if(hash_table->table[i].busy == 1){
            free(hash_table->table[i].employee);
        }
    }

    free(hash_table->table);
}


/*

anotações:

1. nas funções de colissões, deveria ter uma condição de parada mais para evitar loops infinitos em tabelas pequenas ou mal preenchidas?


*/


