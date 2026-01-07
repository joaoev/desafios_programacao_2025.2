#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const ll INF = 1e18;
const int MAXN = 100005;

vector<pli> adj[MAXN];
ll dist[MAXN];
int n, m;

void dijkstra(int start)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }

    priority_queue<pli, vector<pli>, greater<pli>> q;

    dist[start] = 0;
    q.push({0, start});

    while (!q.empty())
    {
        ll d_atual = q.top().first;
        int u = q.top().second;
        q.pop();

        if (d_atual > dist[u])
            continue;

        for (auto edge : adj[u])
        {
            ll peso = edge.first;
            int v = edge.second;

            if (dist[u] + peso < dist[v])
            {
                dist[v] = dist[u] + peso;
                q.push({dist[v], v});
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

            adj[a].push_back({w, b});
        }

        dijkstra(1);

        for (int i = 1; i <= n; i++)
        {
            cout << dist[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}