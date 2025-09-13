#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];
int dp[1005][1005];

int knapsack(int v, int m)
{
    if (v < 0 || m <= 0)
        return 0;
    if (dp[v][m] != -1)
        return dp[v][m];
    if (weight[v] <= m)
    {
        int op1 = knapsack(v - 1, m - weight[v]) + val[v];
        int op2 = knapsack(v - 1, m);
        dp[v][m] = max(op1, op2);
        return dp[v][m];
    }
    else
        dp[v][m] = knapsack(v - 1, m);
        return dp[v][m];
}

int main()
{
    int n, mx_weight;
    cin >> n >> mx_weight;

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> val[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= mx_weight; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n - 1, mx_weight) << endl;

    return 0;
}