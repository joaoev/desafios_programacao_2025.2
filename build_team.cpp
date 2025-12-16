#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int time_aluno[MAXN];
bool possivel = true;

void bfs(int inicio)
{
    queue<int> q;

    time_aluno[inicio] = 1;
    q.push(inicio);

    while (!q.empty())
    {
        int atual = q.front();
        q.pop();

        for (int vizinho : adj[atual])
        {

            if (time_aluno[vizinho] == 0)
            {
                if (time_aluno[atual] == 1)
                {
                    time_aluno[vizinho] = 2;
                }
                else
                {
                    time_aluno[vizinho] = 1;
                }
                q.push(vizinho);
            }

            else
            {
                if (time_aluno[vizinho] == time_aluno[atual])
                {
                    possivel = false;
                    return;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    if (!(cin >> n >> m))
        return 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        time_aluno[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (time_aluno[i] == 0 && possivel)
        {
            bfs(i);
        }
    }

    if (!possivel)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << time_aluno[i] << (i == n ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}