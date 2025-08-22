#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

bool bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        if (par_i == di && par_j == dj)
            return true;

        for (int i = 0; i < 4; i++)
        {

            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
    return false;
}

int main()
{

    cin >> n >> m;
    int si = -1, sj = -1, di = -1, dj = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                si = i, sj = j;
            if (grid[i][j] == 'B')
                di = i, dj = j;
        }
    }

    if (si == -1 || di == -1)
    {
        cout << "NO" << endl;
        return 0;
    }

    memset(vis, false, sizeof(vis));
    bool result = bfs(si, sj, di, dj);
    if (result)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}