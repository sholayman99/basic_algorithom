#include <bits/stdc++.h>
#define ll long long int

using namespace std;
vector<pair<ll, ll>> adj_list[100005];
ll dis[100005];
ll parent[100005];

void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<ll, ll> cur = pq.top();
        pq.pop();

        ll par_dis = cur.first;
        ll par_node = cur.second;

        for (auto p : adj_list[par_node])
        {
            ll child_node = p.first;
            ll child_dis = p.second;

            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
                parent[child_node] = par_node;
            }
        }
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;

    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for (ll i = 1; i <= n; i++)
       {
         dis[i] = LLONG_MAX;
         parent[i] = -1;
       }

    dijkstra(1);

    if (dis[n] == LLONG_MAX)
        cout << "-1" << endl;
    else
    {
        ll node = n;
        vector<ll> path;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }

        reverse(path.begin(), path.end());
        for (auto v : path)
            cout << v << " ";

        cout << endl;
    }

    return 0;
}