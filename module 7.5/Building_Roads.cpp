#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[10005];
bool visited[10005];
vector<int> v;

void dfs(int src)
{
    visited[src] = true;

    for (int child : adj_list[src])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            v.push_back(i);
        }
    }

    cout << v.size() - 1 << endl;

    for (int i = 0; i < v.size() - 1; i++)
        cout << v[i] << " " << v[i + 1] << endl;

    return 0;
}