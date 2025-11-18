#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> preco(n);
    vector<int> paginas(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> preco[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> paginas[i];
    }

    vector<int> precoTotalMaximo(x + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        int precoLivro = preco[i];
        int paginasLivro = paginas[i];

        for (int j = x; j >= precoLivro; --j)
        {
            precoTotalMaximo[j] = max(precoTotalMaximo[j], precoTotalMaximo[j - precoLivro] + paginasLivro);
        }
    }

    cout << precoTotalMaximo[x] << endl;

    return 0;
}
