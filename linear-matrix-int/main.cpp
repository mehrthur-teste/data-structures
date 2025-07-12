#include <iostream>
#include <vector>
using namespace std;


int linear_matrix_search(const vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == target) {
                cout << " Linha i " << i << endl;
                cout << " Linha j " << j << endl;
                cout << "Valor : " << matrix[i][j] << endl;
                cout << "Valor Size: " << matrix[i].size() << endl;
                return i * matrix[i].size() + j; // Retorna o índice linear
            }
        }
    }
    return -1; // Retorna -1 se não encontrar
}

int main() {
    vector<vector<int>> matriz = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int alvo = 9;
    int resultado = linear_matrix_search(matriz, alvo);
    cout << "Índice encontrado: " << resultado << endl; // Saída: 4
    return 0;
}