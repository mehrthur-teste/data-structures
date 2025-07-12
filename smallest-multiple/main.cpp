#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, int b) {
    return a * b / gcd(a, b);
}

long long smallestMultiple(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = lcm(result, i);
    }
    return result;
}

int main() {
    cout << smallestMultiple(20) << endl;  // Saída: 232792560
    return 0;
}
