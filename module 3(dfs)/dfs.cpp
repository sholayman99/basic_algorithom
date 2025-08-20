#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis_arr[1005];

void dfs(int src)
{
    cout << src << " ";
    vis_arr[src] = true;

    for (int child : adj_list[src])
        if (!vis_arr[child])
            dfs(child);
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

    memset(vis_arr, false, sizeof(vis_arr));
    dfs(0);

    return 0;
}