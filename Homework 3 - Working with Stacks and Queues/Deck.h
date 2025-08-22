#ifndef DECK_H
#define DECK_H
#pragma once
#include <iostream>
#include "Node.h"

template<class T>
class Deck
//Source referenced: https://www.geeksforgeeks.org/queue-linked-list-implementation/
{
private:
	//Pointers for the front and back of the linked list
	Node<T>* front;
	Node<T>* back;
	int count;

public:
	//Constructor (initializes the front and back):
	Deck() {
		front = nullptr;
		back = nullptr;
		count = 0;
	}
	~Deck() {

	}
	//Enqueue adds an item to the end of the list
	void enqueue(T it) {
		//Create a new node for the list 
		Node<T>* newNode = new Node<T>(it);

		//If the queue is empty, the new node will be the front and back of the list
		if (isEmpty()) {
			front = newNode;
			back = newNode;
			count++;
			return;
		}

		//If it's not empty, add the new node to the end of the queue and change the back
		back->next = newNode;
		back = newNode;
		count++;
	}

	//Dequeue removes an item from the queue and returns it
	T dequeue() {
		//If the queue is empty, throws a queue underflow error
		if (isEmpty()) {
			FPE_STACKUNDERFLOW;
			exit;
		}
		else{

		//Store the current front and then move the front one node ahead
		Node<T>* temp = front;
		front = front->next;

		//If the front is now nullptr, change the back to nullptr (the queue is now empty)
		if (front == nullptr) {
			back = nullptr;
		}

		//Returns the previous front of the list (first item in the queue) and then
		//deallocates the memory for it
		T retVal = temp->data;
		count--;
		delete temp;
		return retVal;
		
	}
	}

	//Returns the next item in the queue that would be removed (the front of the list)
	T peek() {
		if (isEmpty()) {
			FPE_STACKUNDERFLOW;
			exit;
		}

		return front->data;
	}

	//returns the number of items in the queue
	int length() {
		return count;
	}

	//isEmpty (returns true if the queue is empty, false if it's not empty):
	bool isEmpty() {
		//If the front and back are both nullptr, then the queue is empty
		if (front == nullptr){
			return true;
		}
		return false;
	}

	//empties the queue
	void makeEmpty() {
		front = nullptr;
		back = nullptr;
		count = 0;
	}
};

#endif