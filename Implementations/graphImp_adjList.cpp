//Graph representation through adjaceny list.
//Easy way is to use vectors, but here, classes have been used which is a bit lengthy but can learn more than vectors.

#include <iostream>

class AdjacencyListNode
{
public:
    int data;
    AdjacencyListNode *next;
};

class AdjacencyList
{
public:
    AdjacencyListNode *head;
};

class Graph
{
public:
    int vertices;
    AdjacencyList *adj_list;
};

AdjacencyListNode* create_node(Graph *graph, int data)
{
    AdjacencyListNode* new_node = new AdjacencyListNode();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//undirected graph creation
Graph* create_graph(int vertices)
{
    Graph* new_graph = new Graph();
    new_graph->vertices = vertices;
    
    new_graph->adj_list = new AdjacencyList[vertices];
    for(int i=0; i<vertices; i++) new_graph->adj_list[i].head = NULL;
    return new_graph;
}

void add_edge(Graph* graph, int src, int dest)
{
    //add edge from source to destination
    AdjacencyListNode* new_node = create_node(graph, dest);
    new_node->next = graph->adj_list[src].head;
    graph->adj_list[src].head = new_node;

    //add edge from destination to source
    new_node = create_node(graph, src);
    new_node->next = graph->adj_list[dest].head;
    graph->adj_list[dest].head = new_node;
}

void print_graph(Graph* graph) 
{  
    for (int v = 0; v < graph->vertices; v++) 
    { 
        AdjacencyListNode* temp = graph->adj_list[v].head; 
        std::cout << "\n" << v; 
        while (temp != NULL) 
        { 
            std::cout << " -> " << temp->data; 
            temp = temp->next; 
        } 
        printf("\n"); 
    } 
}

int main()
{
    int vertices = 5;
    Graph *graph = create_graph(vertices);
    add_edge(graph, 0, 1); 
    add_edge(graph, 0, 4); 
    add_edge(graph, 1, 2); 
    add_edge(graph, 1, 3); 
    add_edge(graph, 1, 4); 
    add_edge(graph, 2, 3); 
    add_edge(graph, 3, 4); 

    print_graph(graph);

    return 0;
}