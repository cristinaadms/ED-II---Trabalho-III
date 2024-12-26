#include <stdio.h>
#include <stdlib.h>
#include <grafordenado.h>
#include <grafordenado.c>

int main(){

    int option;
    Graph *graph = NULL;

    do{
        printf("***************** MENU *****************");
        printf("1. Criar Grafo\n");
        printf("2. Adicionar Aresta\n");
        printf("3. Calcular Caminho mais Confiavel entre Dois Vértices\n");
        printf("4. Sair\n");
        printf("****************************************");
        printf("Selecione uma option:");
        scanf("%d", &option);

        switch(option){
            case 1:
                int vertices, edges;
                printf("Digite o numero de vertices:");
                scanf("%d", &vertices);
                printf("Digite o numero de arestas:");
                scanf("%d", &edges);
                graph = Create_Graph(vertices, edges);
                //adicionar mensagens de tratamento de erro e sucesso
                break;
            case 2:
                //adicionar tratamento de erro se o grafo for null

                break;
            case 3:
                //adicionar tratamento de erro se o grafo for null
                break;
            case 4:
                printf("programa encerrado.\n");
                break;
            default:
                printf("opcao invalida. por favor, tente novamente.\n");
                break;
        }
        
    }while(option != 4);

    return 0;
}