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

        int qts_vezes = 0;

        for (auto const &par : freq)
        {
            if (par.second > qts_vezes)
            {
                qts_vezes = par.second;
            }
        }

        cout << (n - qts_vezes) << endl;
    }

    return 0;
}
