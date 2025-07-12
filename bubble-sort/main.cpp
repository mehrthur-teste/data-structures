#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main() {
    vector<int> nums = {5, 2, 9, 1, 5, 6};
    bubble_sort(nums);
    for (int num : nums)
        cout << num << " ";
    return 0;
}
