#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
int visited[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int x = parent.first;
        int y = parent.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = x + d[i].first;
            int cj = y + d[i].second;

            if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != '-')
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    memset(visited, false, sizeof(visited));
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    if (grid[si][sj] == '-' || grid[di][dj] == '-')
    {
        cout << "NO" << endl;
        return 0;
    }

    if (!visited[si][sj] && grid[si][sj] != '-')
        bfs(si, sj);

    if (visited[di][dj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}