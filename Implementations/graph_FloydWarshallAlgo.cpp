#include <iostream>
#define INF 999999999

int main()
{   
    int V = 4;
    int graph[V][V] = {
        {0, 5, INF, 10},  
        {INF, 0, 3, INF},  
        {INF, INF, 0, 1},  
        {INF, INF, INF, 0}  
    };
    
    //Floyd Warshall algo for all pair shortest path
    for(int itr = 0; itr<V; itr++)
    {
        for(int i = 0; i<V; i++)
        {
            for(int j = 0; j<V; j++)
            {
                graph[i][j] = std::min(graph[i][j], graph[i][itr]+graph[itr][j]);
            }
        }
    }

    //print resultant matrix
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            if(graph[i][j] == INF) std::cout << "INF\t";
            else std::cout << graph[i][j] << "\t";
        }
        printf("\n");
    }

    return 0;
}