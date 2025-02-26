#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

/*
Krushkal Algo
- Sort all the edges according to weight
- Need of some Disjoint Set Implementation
- Add the edges if it does not belong to the current graph or component
- otherwise discard the edegs
- Since, the edges are sorted by weight, we are gonna pick the smallest edges first if they dont belong to the component

*/
void KurhskalAlgo(int V, vector<vector<pair<int, int>>> &adj)
{
    vector<pair<int, pair<int, int>>> edges; // {wt, {parent, adjNode}}
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int adjNode = it.first;
            int w = it.second;
            int node = i;

            edges.push_back({w, {node, adjNode}});
        }
    }
    DisjointSet ds(V);
    sort(edges.begin(), edges.end());
    int sum = 0; // mstWt

    for (auto it : edges)
    {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (ds.findUPar(u) != ds.findUPar(v))
        { // if u and v does not belong from the same component (check from the disjoint set)
            sum += w;

            // add to the disjoint set
            ds.unionBySize(u, v);
        }
    }

    cout << sum << endl;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < V; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    KurhskalAlgo(V, adj);

    return 0;
}