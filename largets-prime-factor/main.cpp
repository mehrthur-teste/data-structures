#include <iostream>
#include <cstdint>

unsigned long long maiorFatorPrimo(unsigned long long n) {
    // Remove fatores 2
    while (n % 2 == 0) n /= 2;

    // Agora n é ímpar; testamos apenas ímpares
    unsigned long long fator = 3;
    while (fator * fator <= n) {
        if (n % fator == 0)
            n /= fator;               // divide quantas vezes for possível
        else
            fator += 2;               // próximo ímpar
    }
    // Quando o loop termina, n é o maior fator primo
    return n;
}

int main() {
    unsigned long long numero = 600851475143ULL;
    std::cout << "Maior fator primo: " 
              << maiorFatorPrimo(numero) << '\n';
    return 0;
}
