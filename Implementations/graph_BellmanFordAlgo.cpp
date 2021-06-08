#include <iostream>

class Edge
{
public:
    int src, dest, weight;
};

class DirWeiGraph
{
    int no_of_vertices, no_of_edges, edge_index = 0;
    Edge *edges;

public:
    DirWeiGraph(int no_of_vertices, int no_of_edges)
    {
        this->no_of_vertices = no_of_vertices;
        this->no_of_edges = no_of_edges;
        this->edges = new Edge[no_of_edges];
        this->edge_index = 0;
    }

    void add_edge(int src, int dest, int weight)
    {
        if(this->edge_index >= this->no_of_edges)
        {
            std::cout << "Edge container full.";
            return;
        }

        this->edges[edge_index].src = src;
        this->edges[edge_index].dest = dest;
        this->edges[edge_index].weight = weight;
        this->edge_index++;
    }

    void bellmanFord(int src)
    {
        int dist[this->no_of_vertices];
        for(int i=0; i<no_of_vertices; i++) dist[i] = INT32_MAX;
        dist[src] = 0;
        for(int i = 0; i < this->no_of_vertices-1; i++)
        {
            for(int j = 0; j < this->no_of_edges; j++)
            {
                int u = this->edges[j].src;
                int v = this->edges[j].dest;
                int weight = this->edges[j].weight;

                if(dist[u] != INT32_MAX && dist[u]+weight < dist[v]) dist[v] = dist[u]+weight;
            }
        }
        
        //printing the paths
        std::cout << "Vertex\tDist. from source vertex " << src << std::endl;
        for(int i=0; i < this->no_of_vertices; i++)
        {
            std::cout << "  " << i << "\t\t" << dist[i] << std::endl;
        }
    }
};

int main()
{
    int vertices = 5, edges = 8;
    DirWeiGraph g1(vertices, edges);
    
    g1.add_edge(0, 1, -1);
    g1.add_edge(0, 2, 4);
    g1.add_edge(1, 2, 3);
    g1.add_edge(1, 3, 2);
    g1.add_edge(1, 4, 2);
    g1.add_edge(3, 2, 5);
    g1.add_edge(3, 1, 1);
    g1.add_edge(4, 3, -3);

    g1.bellmanFord(0);

    return 0;
}