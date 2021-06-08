#include <iostream>
#include <vector>
#include <list>

void addEdge(std::vector<int> adj_list[], int src, int dest)
{
    adj_list[src].push_back(dest);
    adj_list[dest].push_back(src);
}

bool BFS(std::vector<int> adj_list[], int prev[], int dist[], int src, int dest, int vertices)
{
    std::list<int> queue;
    bool visited[vertices];

    for(int i=0; i<vertices; i++)
    {
        visited[i] = false;
        dist[i] = INT32_MAX;
        prev[i] =  -1;
    }
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    while(!queue.empty())
    {
        src = queue.front();
        queue.pop_front();

        for(int i=0; i<adj_list[src].size(); i++)
        {
            if(!visited[adj_list[src][i]])
            {
                visited[adj_list[src][i]] = true;
                prev[adj_list[src][i]] = src;
                dist[adj_list[src][i]] = dist[src] + 1;
                queue.push_back(adj_list[src][i]);

                if(adj_list[src][i] == dest) return true;
            }
        }
    }
    return false;
}

void shortestPath(std::vector<int> adj_list[], int src, int dest, int vertices)
{
    int prev[vertices], dist[vertices];
    std::vector<int> path;
    if(!BFS(adj_list, prev, dist, src, dest, vertices))
    {
        std::cout << "No connection found between source and destination!\n";   
        return; 
    }

    std::cout << dist[dest] << "\nPath -> ";

    while(dest != -1)
    {
        path.push_back(dest);
        dest = prev[dest];
    }
    for(int i=path.size()-1; i>=0; i--) std::cout << path[i] << "\t";
}

int main()
{      
    int vertices = 8; 
    std::vector<int> adj_list[vertices]; 
  
    addEdge(adj_list, 0, 1); 
    addEdge(adj_list, 0, 3); 
    addEdge(adj_list, 1, 2); 
    addEdge(adj_list, 3, 4); 
    addEdge(adj_list, 3, 7); 
    addEdge(adj_list, 4, 5); 
    addEdge(adj_list, 4, 6); 
    addEdge(adj_list, 4, 7); 
    addEdge(adj_list, 5, 6); 
    addEdge(adj_list, 6, 7); 

    int source = 0, dest = 7; 
    shortestPath(adj_list, source, dest, vertices); 

    return 0;
}