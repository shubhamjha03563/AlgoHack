#include <iostream>
#include <list>
#include <stack>

class Graph 
{ 
    int vertices;     
    std::list<int> *adj_list;   
    void topologicalSortUtil(int src, bool visited[], std::stack<int> &Stack); 
public: 
    Graph(int  vertices);    
    void addEdge(int v, int w);   
    void topologicalSort(); 
};

Graph::Graph(int vertices)
{
    this->vertices = vertices;
    adj_list = new std::list<int>[vertices];
}

void Graph::addEdge(int src, int dest)
{
    adj_list[src].push_back(dest);
}

void Graph::topologicalSortUtil(int src, bool visited[], std::stack<int> &Stack)
{
    visited[src] = true;
    std::list<int>::iterator itr;

    for(itr = adj_list[src].begin(); itr != adj_list[src].end(); itr++)
    {
        if(!visited[*itr]) topologicalSortUtil(*itr, visited, Stack);
    }
    Stack.push(src);
}   

void Graph::topologicalSort()
{
    bool visited[vertices];
    for(int i=0; i<vertices; i++) visited[i] = false;
    std::stack<int> Stack;

    for(int i=0; i<vertices; i++)
    {
        if(!visited[i]) topologicalSortUtil(i, visited, Stack);
    }

    while(!Stack.empty())
    {
        std::cout << Stack.top() << "\t";
        Stack.pop();
    }
}

int main()
{
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    std::cout << "Topological Sort : "; 
    g.topologicalSort(); 

    return 0;
}