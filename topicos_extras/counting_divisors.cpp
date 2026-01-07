#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int count_div[MAXN];

void crivo()
{
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = i; j < MAXN; j += i)
        {
            count_div[j]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    crivo();

    int n;
    if (cin >> n)
    {
        while (n--)
        {
            int x;
            cin >> x;
            cout << count_div[x] << "\n";
        }
    }

    return 0;
}