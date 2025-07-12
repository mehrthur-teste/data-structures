
#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivo = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivo) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> nums = {3, 6, 8, 10, 1, 2, 1};
    quick_sort(nums, 0, nums.size() - 1);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
