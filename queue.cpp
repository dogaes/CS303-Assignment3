#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int count;

public:
    Queue();
    ~Queue();
    void push(const T& value);
    void pop();
    T front() const;
    int size() const;
    bool empty() const;
    void display();
    void move_to_rear();
};


template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) pop();
}

template <typename T>
void Queue<T>::push(const T& value) {
    Node* newNode = new Node(value);
    if (empty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    count++;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) return;
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    count--;
    if (empty()) rearNode = nullptr;
}

template <typename T>
T Queue<T>::front() const {
    if (!empty())
        return frontNode->data;
    throw std::out_of_range("Queue is empty");
}

template <typename T>
int Queue<T>::size() const {
    return count;
}

template <typename T>
bool Queue<T>::empty() const {
    return count == 0;
}

template <typename T>
void Queue<T>::display() {
    int n = size();
    for (int i = 0; i < n; ++i) {
        T val = front();
        std::cout << val << " ";
        pop();
        push(val);
    }
    std::cout << std::endl;
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (empty()) return;
    T val = front();
    pop();
    push(val);
}

#endif // QUEUE_H
