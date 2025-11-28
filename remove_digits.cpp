#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000 + 1
int dp[MAXN];

vector<int> coletaDigitos(int x)
{

    cout << "Collecting digits for x = " << x << endl;
    vector<int> dig;
    int aux = x;

    cout << "Auxiliary value before collecting digits: " << aux << endl;

    while (aux > 0)
    {
        dig.push_back(aux % 10);
        aux = aux / 10;
    }

    return dig;
}

int solve(int x)
{
    cout << "Solving for x = " << x << endl;
    if (x == 0)
        return 0;
    if (x <= 9)
        return 1;

    if (dp[x] != -1)
    {
        cout << "Memoized result for x = " << x << " is " << dp[x] << endl;
        return dp[x];
    }

    int resultado = MAXN + 128;

    for (int d : coletaDigitos(x))
    {
        if (d != 0)
        {
            resultado = min(resultado, 1 + solve(x - d));
        }
    }

    dp[x] = resultado;

    return resultado;
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }

    cout << solve(n) << endl;

    return 0;
}
