#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(int source, vector<vector<int>> &adj, int V, vector<int> &vis)
{
    queue<int> q;
    q.push(source);
    vis[source] = true;
    while (q.size())
    {
        int currNode = q.front();
        q.pop();

        cout << currNode << " ";

        for (auto ngbr : adj[currNode])
        {
            if (!vis[ngbr])
            {
                q.push(ngbr);
                vis[ngbr] = true;
            }
        }
    }
}
void printBFS(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    vis[0] = 1;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            bfs(i, adj, V, vis);
        }
    }
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
    oneBased = 1;
    if (oneBased)
        V++;
    vector<vector<int>> adj(V); // undirected graph
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printBFS(V, adj);

    return 0;
}