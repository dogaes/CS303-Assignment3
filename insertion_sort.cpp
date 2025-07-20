#include "insertion_sort.h"
#include <vector>

void insertionSortQueue(Queue<int>& q) {
    std::vector<int> v;
    while (!q.empty()) {
        v.push_back(q.front());
        q.pop();
    }

    // Standard insertion sort
    for (int i = 1; i < v.size(); ++i) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }

    for (int val : v) q.push(val);
}
