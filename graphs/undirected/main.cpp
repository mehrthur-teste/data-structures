#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Criando um grafo com 3 vértices: 0, 1, 2
    vector<vector<int>> grafo(3);

    // Adicionando arestas (grafo não direcionado)
    grafo[0].push_back(1);
    grafo[0].push_back(2);

    grafo[1].push_back(0);
    grafo[1].push_back(2);

    grafo[2].push_back(0);
    grafo[2].push_back(1);

    // Exibindo conexões
    for (int i = 0; i < grafo.size(); i++) {
        cout << "Vértice " << i << " está conectado com: ";
        for (int vizinho : grafo[i]) {
            cout << vizinho << " ";
        }
        cout << endl;
    }

    return 0;
}
