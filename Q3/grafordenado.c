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

//função para adição de uma aresta no grafo
void Add_Edge(Graph *graph, int edge_index, int origin_vertex, int destination_vertex, double edge_reliability){

    graph->edgelist[edge_index].origin_vertex = origin_vertex;
    graph->edgelist[edge_index].destination_vertex = destination_vertex;
    graph->edgelist[edge_index].edge_reliability = edge_reliability;

}

