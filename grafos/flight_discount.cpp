#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAXN = 100005;

vector<pair<int, int>> lista_adjacencia[MAXN];

long long menor_custo[MAXN][2];

int qtd_cidades, qtd_voos;

struct Estado
{
    long long custo_acumulado;
    int cidade_atual;
    int cupom_usado;

    bool operator>(const Estado &outro) const
    {
        return custo_acumulado > outro.custo_acumulado;
    }
};

void dijkstra()
{
    for (int i = 1; i <= qtd_cidades; i++)
    {
        menor_custo[i][0] = INF;
        menor_custo[i][1] = INF;
    }

    priority_queue<Estado, vector<Estado>, greater<Estado>> fila_prioridade;

    menor_custo[1][0] = 0;
    fila_prioridade.push({0, 1, 0});

    while (!fila_prioridade.empty())
    {
        Estado atual = fila_prioridade.top();
        fila_prioridade.pop();

        long long custo_acumulado = atual.custo_acumulado;
        int cidade_atual = atual.cidade_atual;
        int cupom_usado = atual.cupom_usado;

        if (custo_acumulado > menor_custo[cidade_atual][cupom_usado])
            continue;

        for (auto voo : lista_adjacencia[cidade_atual])
        {
            int preco_voo = voo.first;
            int cidade_destino = voo.second;

            // Caso o cupom ja tenha sido usado
            // Somente podemos pagar o preco cheio do voo
            if (cupom_usado == 1)
            {
                if (menor_custo[cidade_atual][1] + preco_voo < menor_custo[cidade_destino][1])
                {
                    menor_custo[cidade_destino][1] = menor_custo[cidade_atual][1] + preco_voo;
                    fila_prioridade.push({menor_custo[cidade_destino][1], cidade_destino, 1});
                }
            }

            // Caso o cupom nao tenha sido usado
            if (cupom_usado == 0)
            {
                // Preço normal
                if (menor_custo[cidade_atual][0] + preco_voo < menor_custo[cidade_destino][0])
                {
                    menor_custo[cidade_destino][0] = menor_custo[cidade_atual][0] + preco_voo;
                    fila_prioridade.push({menor_custo[cidade_destino][0], cidade_destino, 0});
                }

                // Preço com desconto
                if (menor_custo[cidade_atual][0] + (preco_voo / 2) < menor_custo[cidade_destino][1])
                {
                    menor_custo[cidade_destino][1] = menor_custo[cidade_atual][0] + (preco_voo / 2);
                    fila_prioridade.push({menor_custo[cidade_destino][1], cidade_destino, 1});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> qtd_cidades >> qtd_voos;
    for (int i = 0; i < qtd_voos; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        lista_adjacencia[a].push_back({c, b});
    }

    dijkstra();

    cout << menor_custo[qtd_cidades][1] << endl;
    return 0;
}