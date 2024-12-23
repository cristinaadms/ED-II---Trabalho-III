#include <stdio.h>
#include <stdlib.h>
#include <grafordenado.h>


//função 1: para inicialização do grafo
Graph *Create_Graph(int number_vertices, int number_edges){

    Graph *graph = (Graph*)malloc(sizeof(Graph));

    graph->number_vertices = number_vertices;
    graph->number_edges = number_edges;

    graph->edgelist = (Edge*)malloc(number_edges*sizeof(Edge));

    return graph;

}

//função 2: para adição de uma aresta no grafo
void Add_Edge(Graph *graph, int edge_index, int origin_vertex, int destination_vertex, double edge_reliability){

    graph->edgelist[edge_index].origin_vertex = origin_vertex;
    graph->edgelist[edge_index].destination_vertex = destination_vertex;
    graph->edgelist[edge_index].edge_reliability = edge_reliability;

}

//função 3: para inicialização da fila de prioridade
PriorityQueue *Create_PriorityQueue(int maximum_capacity){

    PriorityQueue *priorityqueue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    priorityqueue->nodes = (PriorityQueueNode*)malloc(maximum_capacity*sizeof(PriorityQueueNode));

    priorityqueue->current_size = 0;
    priorityqueue->maximum_capacity = maximum_capacity;

    return priorityqueue;

}

//função 4: para inserção de um nó na fila de prioridade com um vértice e sua confiabilidade
void Push(PriorityQueue *priorityqueue_variable, int current_vertex, double accumulated_reliability){

    int i = priorityqueue_variable->current_size++;

    while(i>0 && priorityqueue_variable->nodes[(i-1)/2].accumulated_reliability < accumulated_reliability){

        priorityqueue_variable->nodes[i] = priorityqueue_variable->nodes[(i-1)/2];

        i = (i-1)/2;

        priorityqueue_variable->nodes[i].current_vertex = current_vertex;
        priorityqueue_variable->nodes[i].accumulated_reliability = accumulated_reliability;

    }

}


//função 5: para remoção do nó com maior confiabilidade
PriorityQueueNode Remove_MorePriority(PriorityQueue *priorityqueue_variable){
    
    PriorityQueueNode root = priorityqueue_variable->nodes[0];
    priorityqueue_variable->current_size--;
    PriorityQueueNode last_node = priorityqueue_variable->nodes[priorityqueue_variable->current_size];

    int i = 0, heap_adjusted = 0, left_child;

    while (!heap_adjusted && (left_child = 2*i+1) < priorityqueue_variable->current_size){

        if (left_child + 1 < priorityqueue_variable->current_size && priorityqueue_variable->nodes[left_child].accumulated_reliability < priorityqueue_variable->nodes[left_child + 1].accumulated_reliability)
        left_child++;

        if (last_node.accumulated_reliability >= priorityqueue_variable->nodes[left_child].accumulated_reliability)
        heap_adjusted = 1;

        else {
            priorityqueue_variable->nodes[i] = priorityqueue_variable->nodes[left_child];
            i = left_child;
        }

    }

    priorityqueue_variable->nodes[i] = last_node;
    return root;

}

//função 6: para inicialização de confiabilidades
double *Initialize_Reliabilities(int number_vertices, int start){

    double *reliabilities = (double*)malloc(number_vertices*sizeof(double));

    for (int i=0; i<number_vertices;i++) reliabilities[i] = 0.0;
    reliabilities[start] = 1.0;

    return reliabilities;

}



