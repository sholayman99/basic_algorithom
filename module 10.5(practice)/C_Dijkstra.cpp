#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[100005];
int dis[100005];
int parent[100005];

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();

        int par_dis = parent.first;
        int par_node = parent.second;

        for (auto p : adj_list[par_node])
        {
            int child_node = p.first;
            int child_dis = p.second;

            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
         parent[i] = -1;
    }
    dijkstra(1);

    if(dis[n] == INT_MAX) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;
    for(int v=n; v!=-1; v=parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    for(int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}