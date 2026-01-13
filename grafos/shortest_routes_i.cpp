#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const ll INF = 1e18;
const int MAXN = 100005;

vector<pli> lista_adjacencia[MAXN];
ll menor_distancia_atual[MAXN];
int n, m;

void dijkstra(int start)
{
    for (int i = 1; i <= n; i++)
    {
        menor_distancia_atual[i] = INF;
    }

    priority_queue<pli, vector<pli>, greater<pli>> fila;

    menor_distancia_atual[start] = 0;
    fila.push({0, start});

    while (!fila.empty())
    {
        ll distancia_atual = fila.top().first;
        int no_atual = fila.top().second;
        fila.pop();

        if (distancia_atual > menor_distancia_atual[no_atual])
            continue;

        for (auto aresta : lista_adjacencia[no_atual])
        {
            ll peso_aresta = aresta.first;
            int no_vizinho = aresta.second;

            if (menor_distancia_atual[no_atual] + peso_aresta < menor_distancia_atual[no_vizinho])
            {
                menor_distancia_atual[no_vizinho] = menor_distancia_atual[no_atual] + peso_aresta;
                fila.push({menor_distancia_atual[no_vizinho], no_vizinho});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> n >> m)
    {
        for (int i = 0; i < m; i++)
        {
            int a, b;
            ll w;
            cin >> a >> b >> w;

            lista_adjacencia[a].push_back({w, b});
        }

        dijkstra(1);

        for (int i = 1; i <= n; i++)
        {
            cout << menor_distancia_atual[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}