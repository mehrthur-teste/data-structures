#include <iostream>
#include <vector>
using namespace std;

int linear_search(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> lista = {4, 2, 7, 1, 9};
    int alvo = 7;
    int resultado = linear_search(lista, alvo);
    cout << "Índice encontrado: " << resultado << endl;  // Saída: 2
    return 0;
}
