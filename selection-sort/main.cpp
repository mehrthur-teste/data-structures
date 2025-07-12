#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int menor = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[menor])
                menor = j;
        }
        swap(arr[i], arr[menor]);
    }
}

int main() {
    vector<int> nums = {29, 10, 14, 37, 13};

    cout << "Antes da ordenação: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    selection_sort(nums);

    cout << "Depois da ordenação: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
