#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Prim Algo is used for the min spanning tree
O(E log E)
*/

void Prim(int V, vector<vector<int>> &adj)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // w, node, parent
    vector<int> vis(V, 0);
    pq.push({0, 0, -1});
    vis[0] = 1;

    int sum = 0;
    while (pq.size())
    {
        auto it = pq.top();
        int w = it[0];
        int node = it[1];
        int parent = it[2];

        if (vis[node])
            continue;

        vis[node] = 1;
        sum += w;
        for (auto ngbr : adj[node])
        {
            int adjNode = it[0];
            int wt = it[1];
            if (!vis[adjNode])
            {
                pq.push({wt, adjNode, node});
            }
        }
    }
    cout << "The sum of MST is : " << sum << endl;
}
int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u] = {v, w};
        adj[v] = {u, w};
    }

    Prim(V, adj);

    return 0;
}