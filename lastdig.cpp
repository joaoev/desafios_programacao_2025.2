#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 10;
ll fast_pow(int x, ll e)
{
    if (e == 0)
        return 1;
    if (e == 1)
        return x;

    if (e % 2 == 0)
    {
        ll half = fast_pow(x, e / 2);
        return (half * half) % MOD;
    }
    else
    {
        return (x * fast_pow(x, e - 1)) % MOD;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << fast_pow(a, b) << "\n";
    }

    return 0;
}