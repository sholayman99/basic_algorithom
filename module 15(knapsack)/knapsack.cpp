#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];
int knapsack(int v, int m)
{
    int op1 = knapsack(v-1,m-weight[v]);
    int op2 = knapsack(v-1,m);
    return max(op1,op2);
}

int main()
{
    int n, mx_weight;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cin >> mx_weight;
    knapsack(n - 1, mx_weight);

    return 0;
}