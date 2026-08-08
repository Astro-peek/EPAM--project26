#include <bits/stdc++.h>
using namespace std;

int bfs(int n, int d, vector<vector<int>>& adj)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int child : adj[node])
        {
            if (dist[child] == -1)
            {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != -1 && dist[i] <= d)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int n, m, d;
    cin >> n >> m >> d;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << bfs(n, d, adj);

    return 0;
}