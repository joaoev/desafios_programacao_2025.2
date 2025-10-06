#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;

    cin >> n >> x;

    map<int, int> indice;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        if (indice.count(x - v[i]))
        {
            cout << i + 1 << " " << indice[x - v[i]] + 1 << endl;

            return 0;
        }

        indice[v[i]] = i;
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
