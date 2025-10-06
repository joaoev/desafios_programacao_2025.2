#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tCasos;
    cin >> tCasos;

    for (int i = 0; i < tCasos; i++) {
        unordered_map<int, int> bonecas;
        int nBonecas;
        cin >> nBonecas;

        for (int j = 0; j < nBonecas; j++) {
            int tipoBoneca;
            cin >> tipoBoneca;
            bonecas[tipoBoneca]++;
        }

        for (const auto& par : bonecas) {
            if(par.second % 2 != 0) {
                cout << par.first << "\n";
                break;
            }
        }
    }

    return 0;
}