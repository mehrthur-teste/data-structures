#include <vector>
#include <iostream>
using namespace std;

void insertion_sort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    vector<int> arr = { 12, 11, 13, 5, 6 };
    insertion_sort(arr);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}