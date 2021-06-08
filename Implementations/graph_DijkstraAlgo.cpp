#include <iostream>
#define vertices 9

int minVertexIndex(bool selected[], int dist[])
{
    int min = INT32_MAX, min_index;
    for(int i=0; i<vertices; i++)
    {
        if(!selected[i] && dist[i]<=min) min=dist[i], min_index=i;
    }
    return min_index;
}

void dijkstra(int graph[][vertices], int src)
{
    int dist[vertices];
    bool selected[vertices];
    for(int i=0; i<vertices; i++)
    {
        dist[i] = INT32_MAX;
        selected[i] = false;
    }
    dist[src] = 0;
    
    for(int i=0; i<vertices-1; i++)
    {
        int u = minVertexIndex(selected, dist);
        selected[u] = true;

        for(int v=0; v<vertices; v++)
        {
            if(!selected[v] && graph[u][v] && dist[u] != INT32_MAX && dist[u]+graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    std::cout << "Vertex\tDistance from source ( " << src << " )\n";
    for(int i=0; i<vertices; i++)
    {
        std::cout << "  " << i << "\t\t" << dist[i] << std::endl;
    }
}

int main()  
{
    int graph[vertices][vertices] = { 
    {0, 4, 0, 0, 0, 0, 0, 8, 0}, 
    {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
    {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
    {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
    {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
    {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
    {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
    {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
    {0, 0, 2, 0, 0, 0, 6, 7, 0 } 
    }; 
  
    dijkstra(graph, 0); 

    return 0;
}