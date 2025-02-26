#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Bellman Ford algo = O(V E)
Dijkstra algo fails if it has negative edges, then we will use the bellman ford algo
Bellman will work on directed, graph (can have negative weightsor negative cycle)

Steps
- Relax all the edges n - 1 times sequentially
- Relaxation means if(dist[u] + w < dist[v]) dist[v] = dist[u] + w;
- We will the min distance to all nodes from source in n - 1 iterations
- If there is an updation that we have to make, then there is an ngeative cycle

*/

void BellmanFord(int V, vector<vector<pair<int, int>>> &adj, int source, int destination)
{
    vector<int> dist(V, 1e9);
    dist[source] = 0;
    int times = V - 1;
    while (times--)
    {
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int u = i;
                int v = it.first;
                int w = it.second;
                if (dist[u] != 1e9 && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    times = 1;
    while (times--)
    {
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int u = i;
                int v = it.first;
                int w = it.second;
                if (dist[u] != 1e9 && dist[u] + w < dist[v])
                {
                    cout << "There is negative cycle in the graph" << endl;
                    return;
                }
            }
        }
    }

    cout << "Distance between " << source << " to : " << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " is " << dist[i] << endl;
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

    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v;
        if (weight)
            cin >> w;

        adj[u].push_back({v, w});
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
    BellmanFord(V, adj, source, destination);

    return 0;
}