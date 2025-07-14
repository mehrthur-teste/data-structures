#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> idade;

    idade["Alice"] = 30;
    idade["Bob"] = 25;

    cout << "Idade de Alice: " << idade["Alice"] << endl;

    for (auto& par : idade) {
        cout << par.first << " tem " << par.second << " anos.\n";
    }

    return 0;
}
