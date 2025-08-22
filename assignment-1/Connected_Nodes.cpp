#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];

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

    int q;
    cin >> q;

    while (q--)
    {
        int node;
        cin >> node;

        if (adj_list[node].empty())
            cout << -1 << endl;
        else
        {
            vector<int> tmp = adj_list[node];
            sort(tmp.rbegin(), tmp.rend());

            for (int x : tmp)
                cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}