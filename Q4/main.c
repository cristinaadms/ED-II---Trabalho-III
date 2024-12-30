#include <stdio.h>
#include <stdlib.h>
#include "hashing.c"

int main(){

    HashingTable hash_table;
    int option, table_initialized = 0;

    do{
        printf("************* MENU *************");
        printf("1. inicializacao da tabela de hash\n");
        printf("2. inserir um funcionario\n");
        printf("3. exibir tabela de hash\n");
        printf("4. liberacao da tabela de hash\n");
        printf("5. sair\n");
        printf("********************************");
        printf("selecione uma opcao: ");
        scanf("%d", &option);

        switch(option){
            case 1:

                if(table_initialized){
                    Free_Hash_Table(&hash_table);
                }
                
                int size;
                printf("Tamanho da tabela de hash (101 ou 150): ");
                scanf("%d", &size);
                //blindagem para a entrada do size

                Initialize_Hash_Table(&hash_table, size);
                table_initialized = 1;

                printf("Tabela de Hash inicializada com tamanho %d.\n", size);
                //blindagem para caso dê errado

                break;
            case 2:

                //blindagem para quando não tiver a tabela inicializada

                Employee *employee = (Employee*)malloc(sizeof(Employee));

                //fazer blindagem em cada entrada
                printf("Matricula de 6 digitos: ");
                scanf("%s", employee->registration);
                printf("Nome: ");
                scanf(" %[^\n]", employee->name);
                printf("Funcao: ");
                scanf(" %[^\n]", employee->function);
                printf("Salario: ");
                scanf("%f", employee->salary);

                Insert_Employee(&hash_table, employee);
                printf("Funcionario inserido com sucesso.\n");
                //blindagem para caso dê errado
                break;
            case 3:

                //blindagem para quando não tiver a tabela inicializada
                Show_Hash_Table(&hash_table);
                break;
            case 4:
                //blindagem para quando não tiver a tabela inicializada

                Free_Hash_Table(&hash_table);
                table_initialized = 0;

                printf("Tabela de Hash liberada com sucesso.\n");
                //blindagem para caso dê errado
                break;
            case 5:
                if(table_initialized){
                    Free_Hash_Table(&hash_table);
                }
                printf("programa encerrado.\n");
                break;
            default:
                printf("opcao invalida. tente novamente.\n");
                break;
        }        
    }while(option != 5);

    return 0;
    
}
