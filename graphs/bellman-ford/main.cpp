#include <iostream>
#include <vector>
#include <limits>
#include <stack>
using namespace std;

const int INF = numeric_limits<int>::max();

void bellman_ford(int V, int start, int end, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(V, INF), parent(V, -1);
    dist[start] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (auto [v, w] : graph[u]) {
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    // Verificar ciclo negativo
    for (int u = 0; u < V; ++u) {
        for (auto [v, w] : graph[u]) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                cout << "Ciclo negativo detectado" << endl;
                return;
            }
        }
    }

    if (dist[end] == INF) {
        cout << "Sem caminho de " << start << " até " << end << endl;
        return;
    }

    // Reconstruir caminho
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
    int V = 9;
    vector<vector<pair<int, int>>> graph(V);
    graph[2] = {{3, 5}, {4, -4}};
    graph[3] = {{5, 4}};
    graph[4] = {{6, 7}};
    graph[5] = {{7, -2}};
    graph[6] = {{7, 1}};
    graph[7] = {{8, 6}};

    bellman_ford(V, 2, 8, graph);
    return 0;
}
