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

//função para inicialização da fila de prioridade
PriorityQueue *Create_PriorityQueue(int maximum_capacity){

    PriorityQueue *priorityqueue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    priorityqueue->nodes = (PriorityQueueNode*)malloc(maximum_capacity*sizeof(PriorityQueueNode));

    priorityqueue->current_size = 0;
    priorityqueue->maximum_capacity = maximum_capacity;

    return priorityqueue;

}

//função para inserção de um nó na fila de prioridade com um vértice e sua confiabilidade
void Push(PriorityQueue *priorityqueue_variable, int current_vertex, double accumulated_reliability){

    int i = priorityqueue_variable->current_size++;

    while(i>0 && priorityqueue_variable->nodes[(i-1)/2].accumulated_reliability < accumulated_reliability){

        priorityqueue_variable->nodes[i] = priorityqueue_variable->nodes[(i-1)/2];
        i = (i-1)/2;

        priorityqueue_variable->nodes[i].current_vertex = current_vertex;

        priorityqueue_variable->nodes[i].accumulated_reliability = accumulated_reliability;

    }

}


