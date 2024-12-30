#include <stdio.h>
#include <stdlib.h>
#include "hashing.c"

int main(){

    
    HashingTable hash_table;
    Employee **employees;
    int table_size, option, total_collisions, num_employees = 1000;
    double insertion_time; 

    do{

        printf("Tamanho da tabela de Hash (101 ou 150): ");
        scanf("%d", &table_size);

        if(table_size != 101 && table_size != 150){
            printf("Tamanho invalido. Tente Novamente.\n");
            continue;
        }

        Initialize_Hash_Table(&hash_table, table_size);

        printf("************* CASO DE HASHING *************");
        printf("1. Funcao Hashing Rotacao + Extracao de Digitos)\n");
        printf("2. Funcao Hashing Fold Shift\n");
        printf("3. sair\n");
        printf("*******************************************");
        printf("Selecione uma opcao: ");
        scanf("%d", &option);

        switch(option){
            case 1:

                insertion_time = Measure_Insertion_Performance(&hash_table, employees, num_employees,1);
                total_collisions = Compare_Collisions(&hash_table,employees, num_employees,1);
                printf("Desempenho: ");
                printf("Tempo de Insercao: %.5f segundos\n", insertion_time);
                printf("Numero de Colisoes: %d\n", total_collisions);
                break;

            case 2:

                insertion_time = Measure_Insertion_Performance(&hash_table, employees, num_employees,2);
                total_collisions = Compare_Collisions(&hash_table,employees, num_employees,2);
                printf("Desempenho: ");
                printf("Tempo de Insercao: %.5f segundos\n", insertion_time);
                printf("Numero de Colisoes: %d\n", total_collisions);
                break;

            default:
                printf("opcao invalida. tente novamente.\n");
                break;
        }

        Show_Hash_Table(&hash_table);
        printf("Deseja tentar novamente com um novo tamanho de tabela e hashing? (1 - Sim, 0 - Não): ");
        scanf("%d", &option);

    }while(option == 1);

    //liberar memória

    return 0;
    
}
