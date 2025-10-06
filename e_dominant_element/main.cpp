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
        int n;
        cin >> n;

        vector<int> a(n);

        map<int, int> freq;

        for (int j = 0; j < n; j++)
        {
            cin >> a[j];

            freq[a[j]]++;
        }

        int max_vezes = 0;
        int contador = 0;

        for (auto const &par : freq)
        {
            if (par.second > max_vezes)
            {
                max_vezes = par.second;
                contador = 1;
            }
            else if (par.second == max_vezes)
            {
                contador++;
            }
        }

        if (contador == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
