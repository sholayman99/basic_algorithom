#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105];
int par[105];
bool cycle;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int pa = q.front();
        q.pop();

        for (int child : adj_list[pa])
        {
            if (vis[child] && par[pa] != child)
                cycle = true;
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                par[child] = pa;
            }
        }
    }
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
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            bfs(i);
    }
    if (cycle)
        cout << "cycle\n";
    else
        cout << "no cycle\n";
    return 0;
}