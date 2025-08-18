#include <bits/stdc++.h>
using namespace std;
vector<int>adj_list[1005];
bool vis_arr[1005];

//Total Time Complexity O(N+E)
// We've only one extra space queue. That's why O(N)/O(V) space complexity

void bfs(int src){
   queue<int>q;
   q.push(src);
   vis_arr[src] = true;

   while(!q.empty()){     // O(N) or O(V) N=Node/V=Vertex
      int par = q.front();
      q.pop();

      cout << par << " ";
      for(int child : adj_list[par]){ //O{E} E=Edge
        if(!vis_arr[child]){
            q.push(child);
            vis_arr[child] = true;
        }
      }
   }
}

int main()
{
    int n,e;
    cin >> n >> e;

    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis_arr,false,sizeof(vis_arr));
    bfs(0);

    return 0;
}