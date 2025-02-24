#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isCycleDFS(int currNode, int parent, vector<vector<int>> &adj, int V, vector<int> &vis)
{
    vis[currNode] = 1;
    for (auto ngbr : adj[currNode])
    {
        if (!vis[ngbr])
        {
            if (isCycleDFS(ngbr, currNode, adj, V, vis))
                return true;
        }
        else if (ngbr != parent)
            return true;
    }
    return false;
}
void cycleDetectionUsingDFS(int V, vector<vector<int>> &adj)
{
    /*
    Traversing the graph using DFS if certain node is already visited
    and it is not parent, then the cycle is present
    */
    vector<int> vis(V, 0);
    vis[0] = 1;
    for (int i = 0; i < V; i++)
    {
        int parent = -1;
        if (!vis[i])
        {
            if (isCycleDFS(i, parent, adj, V, vis))
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
}
bool isCycleBFS(int source, vector<vector<int>> &adj, int V, vector<int> &vis)
{
    queue<pair<int, int>> q; // node, parent
    q.push({source, -1});

    vis[source] = 1;
    while (q.size())
    {
        auto front = q.front();
        int currNode = front.first;
        int parent = front.second;

        for (auto ngbr : adj[currNode])
        {
            if (!vis[ngbr])
            {
                vis[ngbr] = 1;
                q.push({ngbr, currNode});
            }
            else if (vis[ngbr] && parent != ngbr)
            {
                return true;
            }
        }
    }
    return false;
}
void cycleDetectionUsingBFS(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    vis[0] = 1;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (isCycleBFS(i, adj, V, vis))
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
        adj[v].push_back(u);
    }

    cycleDetectionUsingDFS(V, adj);
    cycleDetectionUsingBFS(V, adj);

    return 0;
}