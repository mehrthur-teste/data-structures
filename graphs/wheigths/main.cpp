#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Lista de adjacência com par (destino, peso)
    vector<vector<pair<int, int>>> grafo(3);

    // Adicionando arestas com pesos
    grafo[0].push_back({1, 5}); // 0 → 1 (peso 5)
    grafo[0].push_back({2, 3}); // 0 → 2 (peso 3)
    grafo[1].push_back({2, 2}); // 1 → 2 (peso 2)

    // Exibindo conexões
    for (int i = 0; i < grafo.size(); i++) {
        cout << "Vértice " << i << " aponta para:\n";
        for (auto [destino, peso] : grafo[i]) {
            cout << "  → " << destino << " (peso " << peso << ")\n";
        }
    }
    return 0;
}
