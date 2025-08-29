#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[105];
int dis[105];

//Complexity: O(logV(V+E))

void dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    dis[src] = 0;

    while(!pq.empty()){ // O(V)
        pair<int,int> parent = pq.top(); // logV
        pq.pop(); // logV

        int par_dis = parent.first;
        int par_node = parent.second;

        for(auto p : adj_list[par_node]){ //O(E)
            int child_node = p.first;
            int child_dis = p.second;

            if(par_dis+child_dis < dis[child_node]){
                dis[child_node] = par_dis+child_dis;
                pq.push({ dis[child_node],child_node});
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
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dijkstra(0);

    for (int i = 0; i < n; i++)
        cout
            << i << " -> " << dis[i] << endl;

    return 0;
}