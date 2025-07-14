#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Grafo com 3 vértices: 0, 1, 2
    vector<vector<int>> grafo(3);

    // Adicionando arestas direcionadas
    grafo[0].push_back(1); // 0 → 1
    grafo[0].push_back(2); // 0 → 2
    grafo[1].push_back(2); // 1 → 2

    // Exibindo conexões
    for (int i = 0; i < grafo.size(); i++) {
        cout << "Vértice " << i << " aponta para: ";
        for (int vizinho : grafo[i]) {
            cout << vizinho << " ";
        }
        cout << endl;
    }

    return 0;
}
