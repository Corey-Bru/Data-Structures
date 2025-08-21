#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Clear();
    }

    bool IsEmpty() const {
        return head == nullptr;
    }

    void Insert(const T& item) {
        Node<T>* newNode = new Node<T>(item);
        if (IsEmpty()) {
            head = tail = newNode;
        }
        else {
            Node<T>* current = head;
            Node<T>* prevNode = nullptr;

            while (current && current->data < item) {
                prevNode = current;
                current = current->next;
            }
            //head insert
            if (!prevNode) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            //tail insert
            else if (!current) {
                prevNode->next = newNode;
                newNode->prev = prevNode;
                tail = newNode;
            }
            //inserted in between
            else {
                prevNode->next = newNode;
                newNode->prev = prevNode;
                newNode->next = current;
                current->prev = newNode;
            }
        }
    }

    bool Delete(const T& item) {
        if (IsEmpty()) return false;

        Node<T>* current = head;
        while (current && !(current->data == item)) {
            current = current->next;
        }

        if (!current) return false;

        if (current == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        }
        else if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        return true;
    }

    bool GetItem(const T& searchItem, T& foundItem) const {
        Node<T>* current = head;
        while (current) {
            if (current->data == searchItem) {
                foundItem = current->data;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    //Used to Call Display() method in Part class
    void DisplayList() const {
        Node<T>* current = head;
        while (current) {
            current->data.Display();  
            current = current->next;
        }
    }

    void Clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }
};

#endif
