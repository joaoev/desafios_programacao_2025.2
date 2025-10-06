#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Digite o tamanho do vetor: " << endl;
    cin >> n;

    int x;
    cout << "Digite o valor de x: " << endl;
    cin >> x;

    vector<int> numeros(n);

    // Ler corretamente nos n espaços já alocados
    for (int i = 0; i < n; i++)
    {
        int numero;
        cin >> numero;
        numeros[i] = numero;
    }

    // Procura par que some x
    for (int i = 0; i < n; i++)
    {
        int sub = x - numeros[i];
        for (int j = i + 1; j < n; j++)
        {
            if (numeros[j] == sub)
            {
                cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
