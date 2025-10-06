#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    int x;

    cin >> x;

    vector<int> numeros(n);

    int sub = 0;

    for (int i = 0; i < numeros.size(); i++) {
        int numero;
        
        cin >> numero;
        
        numeros[i] = numero;
    }

    for(int i = 0; i < numeros.size(); i++) {
        if(numeros[i] < x) {
            sub = x - numeros[i];

            for(int j = i + 1; j < numeros.size(); j++) {
                if(numeros[j] == sub) {
                    cout << i + 1 << " " << j + 1 << "\n";
                    
                    return 0;
                }
            }
        }

    }


    cout << "IMPOSSIBLE" << endl;
    return 0;
}
