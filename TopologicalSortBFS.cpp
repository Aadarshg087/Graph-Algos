#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void topoSortUsingBFS(int V, vector<vector<int>> &adj)
{
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            inDegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (q.size())
    {
        int currNode = q.front();
        q.pop();
        topo.push_back(currNode);

        for (auto ngbr : adj[currNode])
        {
            inDegree[ngbr]--;
            if (inDegree[ngbr] == 0)
                q.push(ngbr);
        }
    }

    for (int it : topo)
        cout << it << " ";
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C:/Users/aadar/Desktop/Graph Algos/input.txt", "r", stdin);
#endif

    int V, E;
    cin >> V >> E;
    bool oneBased = 0;

    // check once
    oneBased = 1;
    if (oneBased)
        V++;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v;

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    /*
    Topo sort
    - linear ordering of vertices such that if there is an edge between u & v, u appears before v
    - only in directed acyclic graph
    - Also called Kahn Algo
    */
    topoSortUsingBFS(V, adj);

    return 0;
}