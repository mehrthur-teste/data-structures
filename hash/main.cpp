#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> tabela;
    tabela["idade"] = 30;
    tabela["ano"] = 2025;

    cout << tabela["idade"] << endl;  // 30

    return 0;
}
