#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
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
    void move_to_rear();  // Q1(c)
};

#include "queue.cpp"  // For template definitions

#endif
