#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int MAXW = 100010;
const long long INF = (long long)MAXN * MAXW;

int peso[MAXN];
int paginas[MAXN];
int dp[MAXN][MAXW];
int n, w;

int solve(int i, int cap)
{
    if (cap < 0)
    {
        return -INF;
    }

    if (i == n)
    {
        return 0;
    }

    if (dp[i][cap] != -1)
    {
        return dp[i][cap];
    }

    int pegar = paginas[i] + solve(i + 1, cap - peso[i]);
    int naoPegar = solve(i + 1, cap);

    return dp[i][cap] = max(pegar, naoPegar);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> peso[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> paginas[i];
    }

    cout << solve(0, w) << endl;

    return 0;
}