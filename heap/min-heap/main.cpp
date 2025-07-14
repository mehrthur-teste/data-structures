#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(15);
    minHeap.push(30);
    minHeap.push(10);

    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";  // menor primeiro
        minHeap.pop();
    }
    return 0;
}
