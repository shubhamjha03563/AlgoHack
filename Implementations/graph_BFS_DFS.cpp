#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

class Graph
{
private:
    int vertices;
    std::list<int> *adj_list;

public:
    Graph(int vertices);
    void add_edge(int src, int dest);
    void BFS(int src);
    void DFS(int src);
};

Graph::Graph(int vertices)
{
    this->vertices = vertices;
    adj_list = new std::list<int>[vertices];
}

void Graph::add_edge(int src, int dest)
{
    adj_list[src].push_back(dest);
}

void Graph::BFS(int src)
{
    bool *visited = new bool[vertices];
    for(int i=0; i<vertices; i++) visited[i] = false;
    visited[src] = true;

    std::queue<int> queue;
    queue.push(src);

    //lists use bidirectional iterators
    std::list<int>::iterator itr; ///itr is used to traverse through the list

    while(!queue.empty())
    {
        src = queue.front();
        std::cout << src << "\t";
        queue.pop();

        //itr is a pointer to the elements of the list
        for(itr = adj_list[src].begin(); itr != adj_list[src].end(); ++itr)
        {
            if(!visited[*itr])
            {
                visited[*itr] = true;
                queue.push(*itr);
            } 
        }
    }
    printf("\n");
}

//This is iterative method. For recursive , visit https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
void Graph::DFS(int src)
{
    std::vector<int> visited(vertices, false);
    std::stack<int> stack;
    stack.push(src);

    std::list<int>::iterator itr;

    while(!stack.empty())
    {
        src = stack.top();
        stack.pop();
        if(!visited[src])
        {   
            std::cout << src << "\t";
            visited[src] = true;
        }

        for(itr = adj_list[src].begin(); itr != adj_list[src].end(); ++itr)
        {
            if(!visited[*itr]) stack.push(*itr);
        }
    }
    printf("\n");
}

int main()
{
    Graph g(4); 
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3);

    g.BFS(2);

    Graph g2(5);
    g2.add_edge(1, 0); 
    g2.add_edge(0, 2); 
    g2.add_edge(2, 1); 
    g2.add_edge(0, 3); 
    g2.add_edge(1, 4);

    g2.DFS(0);

    return 0;
}