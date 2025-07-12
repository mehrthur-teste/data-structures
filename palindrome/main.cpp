#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(int n) {
    string s = to_string(n);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int main() {
    int maior = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int produto = i * j;
            if (isPalindrome(produto) && produto > maior) {
                maior = produto;
            }
        }
    }
    cout << maior << endl;  // Saída: 906609
    return 0;
}
