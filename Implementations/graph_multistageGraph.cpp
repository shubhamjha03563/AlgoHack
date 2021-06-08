//Find the min path from starting to the ending vertex.
//Approach -> Dynamic programming

#include <iostream>
#define vertices 8

void multistageGraph(int graph[][vertices], int stages)
{
    int min_cost[vertices], min_vertex[vertices], path[stages];
    min_vertex[vertices-1] = vertices-1;
    for(int i=0; i<vertices; i++) min_cost[i] = 0; 

    for(int u=vertices-1; u>=0; u--)
    {
        int min = INT32_MAX;
        for(int v=u+1; v<vertices ;v++)
        {
            if(graph[u][v] && graph[u][v]+min_cost[v] < min)
            {
                min_cost[u] = graph[u][v] + min_cost[v];
                min_vertex[u] = v;
            }
        }
    }
    std::cout << "Minimum distance = " << min_cost[0] << std::endl;

    path[0] = 0, path[stages-1] = vertices-1;
    std::cout << "Path taken : 0 -> ";
    for(int i=1; i<stages-1; i++)
    {
        path[i] = min_vertex[path[i-1]];
        std::cout << path[i] << " -> ";
    }
    std::cout << vertices-1 << std::endl;
}   

int main() 
{
    int stages = 4;
    int graph[vertices][vertices] = {
        {0, 1, 2, 5, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 4, 11, 0, 0}, 
        {0, 0, 0, 0, 9, 5, 16, 0}, 
        {0, 0, 0, 0, 0, 0, 2, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 18}, 
        {0, 0, 0, 0, 0, 0, 0, 13}, 
        {0, 0, 0, 0, 0, 0, 0, 2}
    }; 
    
    multistageGraph(graph, stages);

    return 0; 
}