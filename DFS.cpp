#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int currNode, vector<vector<int>> &adj, int V, vector<int> &vis)
{
    vis[currNode] = 1;
    cout << currNode << " ";
    for (auto ngbr : adj[currNode])
    {
        if (!vis[ngbr])
        {
            dfs(ngbr, adj, V, vis);
        }
    }
}
void printDFS(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, adj, V, vis);
    }
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C:/Users/aadar/Desktop/input.txt", "r", stdin);
#endif

    int V, E;
    cin >> V >> E;
    bool oneBased = 0;
    oneBased = 1;
    if (oneBased)
        V++;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printDFS(V, adj);

    return 0;
}