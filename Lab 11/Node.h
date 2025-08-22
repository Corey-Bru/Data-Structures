#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(const T& item) : data(item), next(nullptr), prev(nullptr) {}
};

#endif
