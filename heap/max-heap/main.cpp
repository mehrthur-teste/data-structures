#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> heap;

    heap.push(20);
    heap.push(5);
    heap.push(15);
    heap.push(30);
    heap.push(10);

    while (!heap.empty()) {
        cout << heap.top() << " ";  // maior primeiro
        heap.pop();
    }
    return 0;
}
