#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int findNthPrime(int n) {
    int count = 0;
    int num = 1;
    while (count < n) {
        ++num;
        if (isPrime(num)) {
            ++count;
        }
    }
    return num;
}

int main() {
    std::cout << findNthPrime(10001) << std::endl; // Resultado: 104743
    return 0;
}
