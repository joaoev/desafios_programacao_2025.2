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
            cout << 10 << endl;
            continue;
        }

        if (N >= 1 && N <= 9)
        {
            cout << N << endl;
            continue;
        }

        vector<int> digitos;

        for (int d = 9; d >= 2; --d)
        {
            while (N % d == 0)
            {
                N = N / d;

                digitos.push_back(d);
            }
        }

        if (N != 1)
        {
            cout << -1 << endl;
            continue;
        }

        sort(digitos.begin(), digitos.end());

        for (int i = 0; i < digitos.size(); i++)
        {
            cout << digitos[i];
        }
        cout << endl;
    }

    return 0;
}
