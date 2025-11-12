#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    solve(int x)
    {
        if (x < 0)
            return INF;
        if (x == 0)
            return 0;
        if (ready[x])
            return value[x];
        int best = INF;
        for (auto c : coins)
        {
            best = min(best, solve(x - c) + 1);
        }
        value[x] = best;
        ready[x] = true;
        return best;
    }

    bool ready[N];
    int value[N];

    count[0] = 1;

    for (int x = 1; x <= n; x++)
    {
        for (auto c : coins)
        {
            if (x - c >= 0)
            {
                count[x] += count[x - c];
            }
        }
    }

    return 0;
}
