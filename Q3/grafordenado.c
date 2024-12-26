#include <stdio.h>
#include <stdlib.h>
#include "grafordenado.h"


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

//função 7: para exploração de arestas de um vértice
void Explore_Edges(Graph *graph, PriorityQueue *priorityqueue_variable, double *reliabilities, int origin_vertex, double reliability){

    for(int i = 0; i < graph->number_edges; i++){
        if (graph->edgelist[i].origin_vertex == origin_vertex){
            int destination_vertex = graph->edgelist[i].destination_vertex;
            double edge_reliability = graph->edgelist[i].edge_reliability;
            double new_reliability = reliability*edge_reliability;

            if(new_reliability > reliabilities[destination_vertex]){
                reliabilities[destination_vertex] = new_reliability;
                Push(priorityqueue_variable, destination_vertex,new_reliability);
            }
        }
    }
}

//função 8: para processamento da fila de prioridade
double Process_PriorityQueue(Graph *graph, PriorityQueue *priorityqueue_variable, double *reliabilities, int start, int endgame){

    double final_reliability = 0.0;

    while(priorityqueue_variable->current_size > 0 && final_reliability == 0.0){

        PriorityQueueNode current = Remove_MorePriority(priorityqueue_variable);

        int origin_vertex = current.current_vertex;
        double reliability = current.accumulated_reliability;

        if(origin_vertex == endgame){
            final_reliability = reliability;
        }else{
            Explore_Edges(graph, priorityqueue_variable, reliabilities, origin_vertex, reliability);
        }
    }

    return final_reliability;

}

//função 9: para liberação de recursos
void Clean_Up_Resources(PriorityQueue *priorityqueue_variable, double *reliabilities){

    free(priorityqueue_variable->nodes);
    free(priorityqueue_variable);
    free(reliabilities);

}

//função 10: calcula o caminho mais confiável entre dois vértices
double Find_MostReliableWay(Graph *graph, int start, int endgame){

    double *reliabilities = Initialize_Reliabilities(graph->number_vertices, start);

    PriorityQueue *priorityqueue_variable = Create_PriorityQueue(graph->number_vertices);

    Push(priorityqueue_variable, start, 1.0);

    double result = Process_PriorityQueue(graph, priorityqueue_variable, reliabilities, start, endgame);

    Clean_Up_Resources(priorityqueue_variable, reliabilities);

    return result;

}

//função 11: para exibição das informações gerais do grafo
void Show_Graph_Info(Graph *graph){
    printf("O grafo contem:\n");
    printf("%d vertices\n", graph->number_vertices);
    printf("%d arestas\n", graph->number_edges);
}

//função 12: para exibição dos detalhes das arestas do grafo
void Show_Graph_Edges(Graph *graph){
    for (int i=0; i<graph->number_edges; i++){
        Edge edge = graph->edgelist[i];
        printf("Aresta %d -> Origem:%d - Destino:%d - Confiabilidade=%.6lf\n", i, edge.origin_vertex, edge.destination_vertex, edge.edge_reliability);
    }
}

//função 13: para exibição do grafo
void Show_Graph(Graph *graph){

    Show_Graph(graph);
    printf("Arestas:\n");
    Show_Graph_Edges(graph);
}












