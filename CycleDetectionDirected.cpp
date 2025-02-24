#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isCycleDFS(int currNode, vector<vector<int>> &adj, int V, vector<int> &vis, vector<int> &pathVis)
{
    vis[currNode] = 1;
    pathVis[currNode] = 1;

    for (auto ngbr : adj[currNode])
    {
        if (!vis[ngbr])
        {
            if (isCycleDFS(ngbr, adj, V, vis, pathVis))
                return true;
        }
        else if (pathVis[ngbr])
            return true;
    }
    pathVis[currNode] = false;
    return false;
}

void cycleDetectionUsingDFS(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vis[0] = 1;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (isCycleDFS(i, adj, V, vis, pathVis))
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

void cycleDetectionUsingBFS(int V, vector<vector<int>> &adj)
{
    /*
    Topo sort using BFS
    if size of topo sort if equal to total elements, then it does not have cycle
    topo sort only applies on graph which have no cycle (DAG)
    */
    vector<int> inDegree(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            inDegree[it]++;
        }
    }
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (q.size())
    {
        int currNode = q.front();
        q.pop();

        topo.push_back(currNode);
        count++;
        for (auto ngbr : adj[currNode])
        {
            inDegree[ngbr]--;
            if (inDegree[ngbr] == 0)
                q.push(ngbr);
        }
    }
    if (topo.size() == V || count == V)
    {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
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

    cycleDetectionUsingDFS(V, adj);
    cycleDetectionUsingBFS(V, adj);

    return 0;
}