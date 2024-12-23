#include <stdio.h>
#include <stdlib.h>
#include <grafordenado.h>


//função para inicialização do grafo
Graph *Create_Graph(int number_vertices, int number_edges){
    Graph *graph = (Graph*)malloc(sizeof(Graph));

    graph->number_vertices = number_vertices;
    graph->number_edges = number_edges;

    graph->edgelist = (Edge*)malloc(number_edges*sizeof(Edge));

    return graph;
    
}