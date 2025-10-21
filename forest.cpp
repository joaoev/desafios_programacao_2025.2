#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<long long>> matrizPrefixo(n + 1, vector<long long>(n + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        string linha;

        cin >> linha;

        for (int j = 1; j <= n; ++j)
        {
            int v = (linha[j - 1] == '*') ? 1 : 0;

            matrizPrefixo[i][j] = v + matrizPrefixo[i - 1][j] + matrizPrefixo[i][j - 1] - matrizPrefixo[i - 1][j - 1];
        }
    }

    for (int i = 0; i < q; ++i)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        long long soma = matrizPrefixo[y2][x2] - matrizPrefixo[y1 - 1][x2] - matrizPrefixo[y2][x1 - 1] + matrizPrefixo[y1 - 1][x1 - 1];

        cout << soma << '\n';
    }

    return 0;
}
