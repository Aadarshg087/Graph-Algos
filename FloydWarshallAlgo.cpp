#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
- Finds the shortest path from one nodes to all the other nodes
- Helps to detect negative cycles as well and works on  Directed graphs
-
*/

void FloydWarshall(int V, vector<vector<int>> &adj)
{
    vector<vector<int>> mat(V, vector<int>(V, 1e9));
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            mat[i][i] = 0;
            for (int j = 0; j < V; j++)
            {
                mat[i][j] = min(mat[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    // to check negative cycles
    for (int i = 0; i < V; i++)
    {
        if (mat[i][i] < 0)
        {
            cout << "Graph has negative cycles" << endl;
            return;
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C:/Users/aadar/Desktop/Graph Algos/input.txt", "r", stdin);
#endif

    int V, E;
    cin >> V >> E;
    bool oneBased = 0;
    bool weight = 0;
    weight = 1;

    // check once
    oneBased = 1;
    if (oneBased)
        V++;

    vector<vector<int>> adj(V, vector<int>(V, 1e9));
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v;
        if (weight)
            cin >> w;

        adj[u][v] = w;
        // adj[v].push_back(u);
    }

    /*
    Topo sort
    - linear ordering of vertices such that if there is an edge between u & v, u appears before v
    - only in directed acyclic graph
    - Also called Kahn Algo
    */
    int source = 0;
    int destination = adj.size() - 1;
    FloydWarshall(V, adj);

    return 0;
}