//Idea used: for every visited vertex 'v', if there is an adjacent vertex 'u' such that 'u' is already visited and is not the parent of 'v'.
//DFS is used.

#include <iostream>
#include <list>

class UnDirGraph
{
private:
    int vertices;
    std::list<int> *adj_list;
    bool isCyclicUtil(int src, bool visited[], int parent);
public:
    UnDirGraph(int vertices);
    void addEdge(int src, int dest);
    bool isCyclic();
};

UnDirGraph::UnDirGraph(int vertices)
{
    this->vertices = vertices;
    adj_list = new std::list<int>[vertices];
}

void UnDirGraph::addEdge(int src, int dest)
{
    adj_list[src].push_back(dest);
    adj_list[dest].push_back(src);
}

bool UnDirGraph::isCyclicUtil(int src, bool visited[], int parent)
{
    visited[src] = true;
    std::list<int>::iterator itr;
    for(itr = adj_list[src].begin(); itr != adj_list[src].end(); itr++)
    {
        if(!visited[*itr] && isCyclicUtil(*itr, visited, src)) return true;
        //if visited node
        else if(*itr != parent) return true;
    }
    return false;
}

bool UnDirGraph::isCyclic()
{
    bool *visited = new bool[vertices];
    for(int i=0; i<vertices; i++) visited[i] = false;

    //for non-connected graphs
    for(int i=0; i<vertices; i++)
    {
        //dont recur for an already visited vertice.
        //pass parent of root node as -1.
        if(!visited[i] && isCyclicUtil(i, visited, -1)) return true;
    }
    return false;
}

int main()
{   
    UnDirGraph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.isCyclic()? std::cout << "Graph contains cycle.\n" : std::cout << "Graph doesn't contain cycle.\n"; 
  
    UnDirGraph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.isCyclic()? std::cout << "Graph contains cycle.\n" : std::cout << "Graph doesn't contain cycle.\n"; 

    return 0;
}

//Some error is there in the program