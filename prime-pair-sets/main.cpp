#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

int concat(int a, int b) {
    std::stringstream ss;
    ss << a << b;
    return std::stoi(ss.str());
}

bool concatPrimes(int a, int b) {
    return isPrime(concat(a, b)) && isPrime(concat(b, a));
}

int main() {
    std::vector<int> primes;
    for (int i = 2; i < 10000; ++i)
        if (isPrime(i)) primes.push_back(i);

    for (size_t i = 0; i < primes.size(); ++i) {
        for (size_t j = i+1; j < primes.size(); ++j) {
            if (!concatPrimes(primes[i], primes[j])) continue;
            for (size_t k = j+1; k < primes.size(); ++k) {
                if (!concatPrimes(primes[i], primes[k]) || !concatPrimes(primes[j], primes[k])) continue;
                for (size_t l = k+1; l < primes.size(); ++l) {
                    if (!concatPrimes(primes[i], primes[l]) || !concatPrimes(primes[j], primes[l]) || !concatPrimes(primes[k], primes[l])) continue;
                    for (size_t m = l+1; m < primes.size(); ++m) {
                        if (concatPrimes(primes[i], primes[m]) &&
                            concatPrimes(primes[j], primes[m]) &&
                            concatPrimes(primes[k], primes[m]) &&
                            concatPrimes(primes[l], primes[m])) {
                            int sum = primes[i] + primes[j] + primes[k] + primes[l] + primes[m];
                            std::cout << "Found: " << primes[i] << " " << primes[j] << " "
                                      << primes[k] << " " << primes[l] << " " << primes[m] << "\n";
                            std::cout << "Sum: " << sum << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}
