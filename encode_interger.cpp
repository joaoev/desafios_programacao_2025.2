#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long N;

        cin >> N;

        if (N == 0)
        {
            cout << 10 << "\n";
            continue;
        }

        if (N >= 1 && N <= 9)
        {
            cout << N << "\n";
            continue;
        }

        vector<int> digitos;
        for (int d = 9; d >= 2; --d)
        {
            cout << "N: " << N << " d: " << d << "\n";

            while (N % d == 0)
            {
                cout << N << "%" << d << "== 0" << "\n";
                cout << N << " = " << N << " / " << d << "\n";
                N /= d;

                cout << "  dividido por " << d << " = " << N << "\n";
                digitos.push_back(d);
            }
        }

        if (N != 1)
        { // sobrou fator > 9
            cout << -1 << "\n";
            continue;
        }

        // imprimir conteúdo atual de digitos (antes de ordenar)
        for (size_t j = 0; j < digitos.size(); ++j)
        {
            if (j)
                cout << ' ';
            cout << digitos[j];
        }
        cout << '\n';

        sort(digitos.begin(), digitos.end());

        // menor número possível

        cout << "vetor organizado   : ";
        for (size_t j = 0; j < digitos.size(); ++j)
        {
            if (j)
                cout << ' ';
            cout << digitos[j];
        }
        cout << '\n';

        for (int x : digitos)
            cout << x;
        cout << "\n";
        continue;
    }

    return 0;
}
