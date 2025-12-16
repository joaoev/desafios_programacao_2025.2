#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

vector<int> adj[MAXN];

int grad[MAXN];

int n, m;

// bfs
vector<int> topological_sort()
{
    queue<int> fila;

    vector<int> resultado;

    for (int i = 0; i < n; i++)
    {
        if (grad[i] == 0)
        {
            fila.push(i);
        }
    }

    while (!fila.empty())
    {
        int atual = fila.front();
        fila.pop();
        resultado.push_back(atual);

        for (int vizinho : adj[atual])
        {
            grad[vizinho]--;
            if (grad[vizinho] == 0)
            {
                fila.push(vizinho);
            }
        }
    }

    if (resultado.size() == n)
    {
        return resultado;
    }

    else
    {
        return {};
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        grad[v]++;
    }

    vector<int> ordem = topological_sort();

    if (ordem.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int curso : ordem)
        {
            cout << curso + 1 << " ";
        }
        cout << endl;
    }
}