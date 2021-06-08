#include <iostream>
#define vertices 5

int minVertexIndex(int key[], bool selected[])
{
    int min = INT32_MAX, min_index;
    for(int i=0; i<vertices; i++)
    {
        if(key[i] < min && !selected[i]) min = key[i], min_index = i;
    }
    return min_index;
}

void primMST(int graph[][vertices])
{
    int parent[vertices], key[vertices];
    bool selected[vertices];

    for(int i=0; i<vertices; i++)
    {
        parent[i] = -1;
        key[i] = INT32_MAX;
        selected[i] = false;
    }
    key[0] = 0;
    for(int i=0; i<vertices-1; i++)
    {
        int u = minVertexIndex(key, selected);
        selected[u] = true;
        for(int v=0; v<vertices; v++)
        {
            if(graph[u][v] && !selected[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    std::cout << "Edge\tWeight\n";
    for(int i=1; i<vertices; i++)
    {
        std::cout << parent[i] << " - " << i << "\t  " << key[i] << std::endl;
    }
}

int main() 
{
    int graph[vertices][vertices] = {
        { 0, 2, 0, 6, 0 }, 
        { 2, 0, 3, 8, 5 }, 
        { 0, 3, 0, 0, 7 }, 
        { 6, 8, 0, 0, 9 }, 
        { 0, 5, 7, 9, 0 }
    }; 
    
    primMST(graph); 
 
    return 0; 
}