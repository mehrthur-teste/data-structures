#include <iostream>
using namespace std;

long long sumSquareDifference(int n) {
    long long sum = n * (n + 1) / 2;
    long long squareOfSum = sum * sum;

    long long sumOfSquares = n * (n + 1) * (2 * n + 1) / 6;

    return squareOfSum - sumOfSquares;
}

int main() {
    cout << sumSquareDifference(100) << endl;  // Saída: 25164150
    return 0;
}
