#ifndef grafordenado_h
#define grafordenado_h


//structs
typedef struct edge{
    int origin_vertex, destination_vertex;
    double edge_reliability; //probabbilidade de sucesso da aresta
} Edge;

typedef struct graph{
    int number_vertices, number_edges;
    Edge *edgelist; //lista de arestas
} Graph;

typedef struct priorityqueuenode{
    int current_vertex;
    double accumulated_reliability;
} PriorityQueueNode; //nó de fila de prioridade

typedef struct priorityqueue{
    PriorityQueueNode *nodes;
    int current_size, maximum_capacity;
} PriorityQueue; //fila de prioridades


//escopo das funções
Graph *Create_Graph(int number_vertices, int number_edges);
void Add_Edge(Graph *graph, int edge_index, int origin_vertex, int destination_vertex, double edge_reliability);
PriorityQueue *Create_PriorityQueue(int maximum_capacity);
void Push(PriorityQueue *priorityqueue_variable, int vertex, double accumulated_reliability);
PriorityQueueNode Remove_MorePriority(PriorityQueue *priorityqueue_variable);
double Find_MostReliableWay(Graph *graph, int start, int endgame);


#endif