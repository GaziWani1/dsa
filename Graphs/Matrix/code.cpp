#include <iostream>
using namespace std;

class Graph
{
    int V;
    int **matrix;

public:
    Graph(int V = 5)
    {
        this->V = V;
        matrix = new int *[V];

        for (int i = 0; i < V; i++)
        {
            matrix[i] = new int[V];
            for (int j = 0; j < V; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v)
    {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printGraph();
    return 0;
}