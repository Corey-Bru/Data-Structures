#pragma once
#include <iostream>
template<class T>
class Node
{
public:
	//members:
	T data;
	Node* left;
	Node* right;
	int height;

	//Constructors:
	Node() {
		left = nullptr;
		right = nullptr;
	}
	Node(T value) {
		data = value;
		left = nullptr;
		right = nullptr;
		height = 1;
	}

	//Deconstructor:
	~Node() {
		
	}

	void makeEmpty() {
		delete right;
			delete left;
	}

	//Getters:
	int getHeight() {
		return height;
	}
};

