#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void topoSort(int currNode, vector<vector<int>> &adj, int V, vector<int> &vis, stack<int> &st)
{
    vis[currNode] = 1;

    for (auto ngbr : adj[currNode])
    {
        if (!vis[ngbr])
            topoSort(ngbr, adj, V, vis, st);
    }

    st.push(currNode);
}

void topoSortUsingDFS(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    stack<int> st;
    vis[0] = 1;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            topoSort(i, adj, V, vis, st);
    }
    vector<int> ans;
    while (st.size())
    {
        ans.push_back(st.top());
        st.pop();
    }
    for (auto it : ans)
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
    */
    topoSortUsingDFS(V, adj);

    return 0;
}