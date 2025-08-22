#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[10005];

bool bfs(int src, int des)
{
    if (src == des)
        return true;

    for (int child : adj_list[src])
    {
        if (child == des)
            return true;
    }
    return false;
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
    int q;
    cin >> q;
    while (q--)
    {
        int src, des;
        cin >> src >> des;
        bool result = bfs(src, des);
        if (result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}