#include <stdio.h>
#include <stdlib.h>
#include "grafordenado.c"

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
                //adicionar tratamento de erro/blindagem nas entradas abaixo
                int edge_index, origin_vertex, destiny_vertex;
                double reliability;
                printf("Digite o indice da aresta (0 a %d): ", graph->number_edges - 1);
                scanf("%d", &edge_index);
                printf("Digite o vertice de origem: ");
                scanf("%d", &origin_vertex);
                printf("Digite o vertice de destino: ");
                printf("%d", &destiny_vertex);
                printf("Digite a confiabilidade da aresta (0 e 1): ");
                scanf("%lf", &reliability);
                Add_Edge(graph, edge_index, origin_vertex, destiny_vertex, reliability);
                printf("Aresta adicionada com sucesso!\n");
                break;
            case 3:
                //adicionar tratamento de erro se o grafo for null
                //adicionar tratamento de erro/blindagem nas entradas abaixo
                int origin_vertex, destiny_vertex;
                double reliability;
                printf("Digite o vertice de origem: ");
                scanf("%d", &origin_vertex);
                printf("Digite o vertice de destino: ");
                printf("%d", &destiny_vertex);
                reliability = Find_MostReliableWay(graph, origin_vertex, destiny_vertex);
                printf("O caminho mais confiavel entre os vertices %d e %d tem confiabilidade %.6lf\n",origin_vertex, destiny_vertex, reliability);
                break;
            case 4:
                printf("programa encerrado.\n");
                break;
            default:
                printf("opcao invalida. por favor, tente novamente.\n");
                break;
        }
        
    }while(option != 4);

    if(graph != NULL){
        free(graph->edgelist);
        free(graph);
    }

    return 0;
}