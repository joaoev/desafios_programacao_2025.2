#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> algoritmos;

    for (int i = 0; i < n; ++i)
    {
        long long tempo;
        cin >> tempo;
        algoritmos.push_back(tempo);
    }

    sort(algoritmos.begin(), algoritmos.end());

    int soma = 0;
    int contador = 0;

    for (int i = 0; i < algoritmos.size(); i++)
    {

        if (algoritmos[i] + soma <= q)
        {
            soma += algoritmos[i];
            contador++;
        }
    }

    cout << contador << endl;

    return 0;
}