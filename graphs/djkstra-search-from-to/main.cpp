#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, int end, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF), parent(n, -1);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[end] == INF) {
        cout << "Sem caminho de " << start << " até " << end << endl;
        return;
    }

    // Reconstruir o caminho
    stack<int> path;
    for (int v = end; v != -1; v = parent[v]) path.push(v);
    cout << "Caminho mínimo de " << start << " até " << end << ": ";
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << "\nDistância total: " << dist[end] << endl;
}

int main() {
    vector<vector<pair<int, int>>> graph(9);
    graph[2] = {{3, 5}, {4, 2}};
    graph[3] = {{5, 4}};
    graph[4] = {{6, 7}};
    graph[5] = {{7, 3}};
    graph[6] = {{7, 1}};
    graph[7] = {{8, 6}};
    
    dijkstra(2, 8, graph);
    return 0;
}
