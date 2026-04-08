#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V = 5)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for (int neighbor : l[i])
                cout << neighbor << " ";
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }

    void bfs(int start)
    {
        queue<int> Q;
        vector<bool> vis(V, false);

        Q.push(start);
        vis[0] = true;

        while (Q.size() > 0)
        {
            int u = Q.front(); // u-v
            Q.pop();
            cout << u << " ";
            for (int v : l[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << endl;
        cout << endl;
    }

    void dfsHelper(int u, vector<bool> &visted)
    {
        visted[u] = true;
        cout << u << " ";
        for (int v : l[u])
        {
            if (!visted[v])
            {
                dfsHelper(v, visted);
            }
        }
    }

    void dfs(int start)
    {
        vector<bool> vis(V, false);
        dfsHelper(start, vis);
        cout << endl;
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

    g.bfs(0);

    g.dfs(0);

    return 0;
}