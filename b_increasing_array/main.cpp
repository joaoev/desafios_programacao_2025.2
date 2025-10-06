#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> numeros(n);
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    long long movimentos = 0;

    for (int i = 1; i < n; i++) {
        if (numeros[i] < numeros[i - 1]) {
            movimentos += numeros[i - 1] - numeros[i];
            numeros[i] = numeros[i - 1];
        }
    }

    cout << movimentos << "\n";
    
    return 0;
}
