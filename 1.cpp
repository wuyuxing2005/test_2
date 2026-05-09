#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;

const int INF = 1e9;

struct Edge
{
    int to;
    int w;
};

vector<int> dijkstra(int n, vector<vector<Edge>> &graph, int start)
{
    vector<int> dist(n + 1, INF);
    // pair<距离, 点>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto [curDist, u] = pq.top();
        pq.pop();
        for (auto edge : graph[u])
        {
            int v = edge.to;
            int w = edge.w;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // 有向图
        graph[u].push_back({v, w});

        // 如果是无向图，再加这一句
        // graph[v].push_back({u, w});
    }

    int start;
    cin >> start;

    vector<int> dist = dijkstra(n, graph, start);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }

    return 0;
}