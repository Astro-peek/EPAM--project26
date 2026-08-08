#include <bits/stdc++.h>
using namespace std;

vector<int> val;
vector<vector<int>> adj;
int ans = 0;
int k;

void dfs(int node, int parent, int xr)
{
    if (xr >= k)
        ans++;

    for (int child : adj[node])
    {
        if (child != parent)
        {
            dfs(child, node, xr ^ val[child]);
        }
    }
}

int main()
{
    int n;
    cin >> n >> k;

    val.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, val[1]);

    cout << ans;

    return 0;
}
