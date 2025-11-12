#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;

    cin >> a >> b >> c;

    int m;

    cin >> m;

    vector<long long> precosUSB, precosPS2;

    for (int i = 0; i < m; ++i)
    {
        long long preco;
        string tipo;

        cin >> preco >> tipo;

        if (tipo == "USB")
        {
            precosUSB.push_back(preco);
        }
        else
        {
            precosPS2.push_back(preco);
        }
    }

    sort(precosUSB.begin(), precosUSB.end());
    sort(precosPS2.begin(), precosPS2.end());

    long long usados = 0;
    long long gastoTotal = 0;

    for (int i = 0; i < precosUSB.size() && a > 0; ++i, --a)
    {
        gastoTotal += precosUSB[i];

        usados++;

        precosUSB[i] = -1;
    }

    for (int i = 0; i < precosPS2.size() && b > 0; ++i, --b)
    {
        gastoTotal += precosPS2[i];

        usados++;

        precosPS2[i] = -1;
    }

    int i = 0, j = 0;
    while (i < precosUSB.size() && precosUSB[i] == -1)
    {
        ++i;
    }
    while (j < precosPS2.size() && precosPS2[j] == -1)
    {
        ++j;
    }

    for (long long alocados = 0; alocados < c; ++alocados)
    {
        bool aindaTemUSB = (i < precosUSB.size());
        bool aindaTemPS2 = (j < precosPS2.size());

        if (!aindaTemUSB && !aindaTemPS2)
            break;

        if (!aindaTemPS2 || (aindaTemUSB && precosUSB[i] <= precosPS2[j]))
        {
            gastoTotal += precosUSB[i++];
            usados++;
        }
        else
        {
            gastoTotal += precosPS2[j++];
            usados++;
        }
    }

    cout << usados << " " << gastoTotal << "\n";

    return 0;
}
