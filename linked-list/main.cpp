#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* proximo;

    Node(int v) : valor(v), proximo(nullptr) {}
};

void imprimir(Node* cabeca) {
    Node* atual = cabeca;
    while (atual != nullptr) {
        cout << atual->valor << " -> ";
        atual = atual->proximo;
    }
    cout << "NULL\n";
}

int main() {
    // Criando os nós
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);

    // Ligando os nós
    n1->proximo = n2;
    n2->proximo = n3;

    // Cabeça da lista
    Node* cabeca = n1;

    imprimir(cabeca);  // Saída: 10 -> 20 -> 30 -> NULL

    // Liberação de memória
    while (cabeca != nullptr) {
        Node* temp = cabeca;
        cabeca = cabeca->proximo;
        delete temp;
    }

    return 0;
}
