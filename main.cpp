#include <iostream>
#include "queue.cpp"
#include "insertion_sort.cpp"
#include "recursive_search.cpp"

int main() {
    Queue<int> q;

    // Q1a: Push 10 integers
    for (int i = 1; i <= 10; ++i) {
        q.push(i * 10);
    }

    std::cout << "Queue contents:\n";
    q.display();  // Q1b

    std::cout << "After moving front to rear:\n";
    q.move_to_rear();  // Q1c
    q.display();

    // ask input for target value
    int target;
    std::cout << "Enter a target value to search for its last occurrence: ";
    std::cin >> target;
    // Q2: Last occurrence search
    int index = lastOccurrence({10, 20, 30, 40, 50, 30}, target, 5);
    if (index != -1) {
        std::cout << "Last occurrence of " << target << " is at index: " << index << std::endl;
    } else {
        std::cout << target << " not found in the vector." << std::endl;
    }

    // Q3: Insertion sort on queue
    insertionSortQueue(q);
    std::cout << "Queue after insertion sort:\n";
    q.display();
    
    return 0;
}
