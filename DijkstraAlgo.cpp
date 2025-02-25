#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void DijkstraAlgo(int V, vector<vector<pair<int, int>>> &adj, int source, int destination)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);

    dist[source] = 0;
    pq.push({0, source});

    while (pq.size())
    {
        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for (auto it : adj[node])
        {
            int ngbrWeight = it[1];
            int ngbrNode = it[0];
            if (dis + ngbrWeight < dist[ngbrNode])
            {
                dist[ngbrNode] = dis + ngbrWeight;
                pq.push({dist[ngbrNode], ngbrNode});
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
    DijkstraAlgo(V, adj, source, destination);

    return 0;
}