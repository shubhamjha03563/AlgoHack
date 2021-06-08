//Idea used - Detection of a backedge. (an edge that is from a node to itself(selfloop) or one of its ancestors)
//DFS is applied

#include <iostream>
#include <list>

class DirGraph
{
private:
    int vertices;
    std::list<int> *adj_list;
    bool isCyclicUtil(int src, bool visited[], bool rec_stack[]);
public:
    DirGraph(int vertices);
    void addEdge(int src, int dest);
    bool isCyclic();
};

DirGraph::DirGraph(int vertices)
{
    this->vertices = vertices;
    adj_list = new  std::list<int>[vertices];
}

void DirGraph::addEdge(int src, int dest)
{
    adj_list[src].push_back(dest);
}

bool DirGraph::isCyclicUtil(int src, bool visited[], bool rec_stack[])
{
    visited[src] = true;
    rec_stack[src] = true;

    std::list<int>::iterator itr;

    for(itr = adj_list[src].begin(); itr != adj_list[src].end(); itr++)
    {
        if(!visited[*itr] && isCyclicUtil(*itr, visited, rec_stack)) return true;
        //if visited node
        else if(rec_stack[*itr]) return true;
    }
    rec_stack[src] = false;
    return false;
}

bool DirGraph::isCyclic()
{
    bool *visited = new bool[vertices];
    bool *rec_stack = new bool[vertices];
    for(int i=0; i<vertices; i++)
    {
        visited[i] = false;
        rec_stack[i] = false;
    }

    //for non-connected graphs
    for(int i=0; i<vertices; i++)
    {
        if(!visited[i] && isCyclicUtil(i, visited, rec_stack)) return true; //dont recur for an already visited vertice.
    }
    return false;
}

int main()
{      
    DirGraph g(4); 
    g.addEdge(0, 1);  
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    if(g.isCyclic()) std::cout << "DirGraph contains cycle.\n"; 
    else std::cout << "DirGraph doesn't contain cycle.\n"; 

    return 0;
}