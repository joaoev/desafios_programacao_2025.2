#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAXN = 100005;

vector<pair<int, int>> adj[MAXN];

long long dist[MAXN][2];

int n, m;

struct Node
{
    long long d;
    int u;
    int f;

    bool operator>(const Node &other) const
    {
        return d > other.d;
    }
};

void dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    priority_queue<Node, vector<Node>, greater<Node>> q;

    dist[1][0] = 0;
    q.push({0, 1, 0});

    while (!q.empty())
    {
        Node atual = q.top();
        q.pop();

        long long d = atual.d;
        int u = atual.u;
        int f = atual.f;

        if (d > dist[u][f])
            continue;

        for (auto edge : adj[u])
        {
            int w = edge.first;
            int v = edge.second;

            if (f == 1)
            {
                if (dist[u][1] + w < dist[v][1])
                {
                    dist[v][1] = dist[u][1] + w;
                    q.push({dist[v][1], v, 1});
                }
            }

            if (f == 0)
            {
                if (dist[u][0] + w < dist[v][0])
                {
                    dist[v][0] = dist[u][0] + w;
                    q.push({dist[v][0], v, 0});
                }

                if (dist[u][0] + (w / 2) < dist[v][1])
                {
                    dist[v][1] = dist[u][0] + (w / 2);
                    q.push({dist[v][1], v, 1});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    dijkstra();

    cout << dist[n][1] << endl;

    return 0;
}