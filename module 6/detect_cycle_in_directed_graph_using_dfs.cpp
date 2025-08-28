#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105];
bool path[105];
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    path[src] = true;
    for (int child : adj_list[src])
    {
        if (vis[child] && path[child])
            cycle = true;
        if (!vis[child])
            dfs(child);
    }
    path[src] = false;
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(path, false, sizeof(path));
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    if (cycle)
        cout << "cycle\n";
    else
        cout << "no cycle\n";
    return 0;
}