#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[start] = 0;

    // Min-heap (distância, nó)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Exibe resultado
    for (int i = 0; i < n; i++) {
        cout << "Distância de " << start << " até " << i << " = ";
        if (dist[i] == INF) cout << "infinito";
        else cout << dist[i];
        cout << endl;
    }
}

int main() {
    vector<vector<pair<int, int>>> graph(4);
    graph[0] = {{1, 5}, {2, 3}};
    graph[1] = {{2, 2}};
    graph[2] = {{3, 4}};
    graph[3] = {};

    dijkstra(5, graph);

    return 0;
}
