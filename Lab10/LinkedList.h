#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"
#include "Student.h"
#include <string>
using namespace std;

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int location = 0;
public:

    //Constructor:
    LinkedList() : head(nullptr), tail(nullptr) {}

    //Destructor:
    ~LinkedList() {
        Clear();
    }

    T* getData() {
        Node<T>* current = head;
        
        if(current) {
            return &(current->data);
            current = current->next;
        }

    }

    bool operator ==(Node<T> right) {
        Node<T> current = head;
        for (int i = 0; i <= location; i++) {
            if (current->data == right->data) {
                return true;
            }
            current = current->next;

        }
        return false;
    }

    void OperatorTest() {
        std::cout << (head->data == tail->data);
    }

    //Reset (resets the location variable that SeeNext uses so it will return the first item in the list):
    void Reset() {
        location = 0;
    }

    //IsEmpty (returns a boolean indicating whether or not the list is empty):
    bool IsEmpty() const {
        return head == nullptr;
    }

    //AddItem (Adds an item to the list):
    void Insert(const T* item) {
        Node<T>* newNode = new Node<T>(*item);
        if (IsEmpty()) {
            head = tail = newNode;
        }
        else {
            Node<T>* current = head;
            Node<T>* prevNode = nullptr;

            while (current && &(current->data) < item) {
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

    //SeePrev (returns the previous item in the list without removing it):
    T* SeePrev() {
        try {
            if (IsEmpty()) {
                throw 0;
            }
            int count = 0;
            Node<T>* current = head;
            while (count != location) {
                current = current->next;
            }
            location--;
            return head->prev;
        }
        catch (int d) {
            cout << "The List is Empty." << endl;
        }
    }

    //SeeNext (returns the next item in the list without removing it):
    T* SeeNext() {
        try {
            if (IsEmpty()) {
                throw 0;
            }
            int count = 0;
            Node<T>* current = head;
            while (count != location) {
                current = current->next;
            }
            location++;
            return current->data;
        }
        catch (int d) {
            cout << "The List is Empty." << endl;
        }
    }
    // returns the item in the list if one is not found or the list is empty the code will throw an error
    T* SeeAt(const T* item) {
        try {
            if (IsEmpty()) {
                throw 0;
            }
            Node<T>* current = head;
            while (!(current->data == *item || current->next == nullptr)) {
                current = current->next;
            }
            if (current == nullptr) {
                return nullptr;
            }
            return &current->data;
        }
        catch (int num) {
            cout << "The List is Empty please insert something in the list." << endl;
        }
        catch (...) {
            cout << "Item was not found in the list." << endl;
        }
    }



    //GetItem (searches the list for a given item, if found, it returns the item and deletes it):
    //If not found, it returns a null pointer
    int GetCollisions(const T* item,int col) {

        Node<T>* current = head;
        //col += 1;
        while (current != nullptr && !((current->data) == *item)) {
            //col += 1;
            current = current->next;
        }
        return col;
    }
    
    T* GetItem(const T* item) {
        if (IsEmpty()) return nullptr;

        Node<T>* current = head;
        while (current != nullptr && !((current->data) == *item)) {
            current = current->next;
        }
        //Missing the keyword "new" used chatgpt to correct
        //https://chatgpt.com/c/67ffee1d-f508-8008-94db-d784b0958ea5
        T* retVal = new T(current->data);

        if (!current) return nullptr;

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
        return retVal;
    }

    //IsInList (returns true if the item given is in the list, false if it is not):
    bool IsInList(const T& searchItem, T& foundItem) const {
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

    //Size (returns the number of items in the list)
    int Size() {
        Node<T>* current = head;
        int size = 0;
        //Checks if the list is empty, returns zero if it is
        if (IsEmpty()) {
            return size;
        }
        //Traverses through the list and adds one for each item it finds
        while (current) {
            size += 1;
            current = current->next;
        }
        //Returns the size of the list
        return size;
    }

    //Used to Call Display() method in Part class
    void DisplayList() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << endl;
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
        location = 0;
    }
};

#endif
