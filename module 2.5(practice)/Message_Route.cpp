#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
int vis_arr[100005];
int level[100005];
int parent[100005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis_arr[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
            if (!vis_arr[child])
            {
                q.push(child);
                vis_arr[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis_arr, false, sizeof(vis_arr));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    bfs(1);

    if (!vis_arr[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int node = n;
    vector<int> path;

    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (int x : path)
    {
        cout << x << " ";
    }

    return 0;
}