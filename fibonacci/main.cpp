#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2;
    int soma = 0;

    while (a <= 4000000) {
        if (a % 2 == 0)
            soma += a;
        int proximo = a + b;
        a = b;
        b = proximo;
    }

    cout << "Soma dos termos pares da sequência de Fibonacci até 4 milhões: " << soma << endl;
    return 0;
}
