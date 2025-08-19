#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
int vis_arr[1005];
int level[1005];

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis_arr[src] = true;
    level[src] = 0;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(int child:adj_list[par]){
            if(!vis_arr[child]){
                q.push(child);
                vis_arr[child] = true;
                level[child] = level[par]+1;
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
    int src, des;
    cin >> src >> des;

    memset(vis_arr, false, sizeof(vis_arr));
    memset(level,-1,sizeof(level));
    bfs(src);

    cout << level[des] << endl;

    return 0;
}