#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tCasos;
    cin >> tCasos;

    for (int i = 0; i < tCasos; i++) {
        int nBonecas;

        cin >> nBonecas;
        
        int resultado = 0;
        
        for (int j = 0; j < nBonecas; j++) {
            int tipoBoneca;
            
            cin >> tipoBoneca;
            
            resultado ^= tipoBoneca;
        }

        cout << resultado << "\n";
    }
    return 0;
}