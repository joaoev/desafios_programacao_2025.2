#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int INF = 1000000000;

    vector<int> dp(n + 1, INF);

    dp[0] = 0;

    for (int x = 1; x <= n; ++x)
    {
        int y = x;

        cout << "Processing number: " << x << endl;
        cout << "Current dp state: " << dp[y] << endl;

        while (y > 0)
        {
            int d = y % 10;

            cout << "  Considering digit: " << d << endl;
            y = y / 10;
            cout << "  Remaining number after removing digit: " << y << endl;

            if (d > 0 && x - d >= 0)
            {
                dp[x] = min(dp[x], 1 + dp[x - d]);
                cout << "  Updated dp[" << x << "] to " << dp[x] << endl;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}
