#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13};
    int result = binary_search(nums, 11);
    cout << "Índice encontrado: " << result << endl;  // Saída: 3
    return 0;
}
