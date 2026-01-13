#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int qtd_divisores[MAXN];

void crivo()
{
    for (int div = 1; div < MAXN; div++)
    {
        for (int mult = div; mult < MAXN; mult += div)
        {
            qtd_divisores[mult]++;
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
            cout << qtd_divisores[x] << "\n";
        }
    }

    return 0;
}