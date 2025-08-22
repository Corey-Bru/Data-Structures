#pragma once
#pragma once
#include "Node.h"
#include <iostream>
#include <cctype>
#include <iomanip>
#include <vector>
/*
Sources Referenced:
https://www.geeksforgeeks.org/cpp-program-to-implement-avl-tree/
https://www.youtube.com/watch?v=otiDcwZbCo4&msockid=63d1c4d510e811f0ac36b0bbadb6cdd9
*/
using namespace std;
template <class T>
class BinaryTree
{
private:
	Node<T>* root = nullptr;
	int size = 0;


	//Getters:
	int getHeight(Node<T>* node) {
		if (node == nullptr) {
			return 0;
		}
		else {
			return node->height;
		}
	}

	int getBalanceFactor(Node<T>* node) {
		if (node == nullptr) {
			return 0;
		}
		else {
			return (getHeight(node->left) - getHeight(node->right));
		}
	}

	//Rotation Functions:

	//Right Rotation (used when a node becomes unbalanced with an insertion into the right
	//subtree of its right child, leading to a left imbalance):
	//It takes a pointer to a node as a parameter and returns the new root
	Node<T>* rightRotate(Node<T>* y) {
		//y is the "top" node on the basic diagram example, the parent node of x
		//x is the left child of y
		Node<T>* x = y->left;
		//T2 is the right child of x (in the basic diagram example, T2 will point to nullptr
		Node<T>* T2 = x->right;

		//ROTATION:
		//The right child of x will now be equal to y (moving y to the right)
		x->right = y;

		//The left child of y will now be equal to T2 (in the basic diagram example, this means
		//the left child of y is now equal to nullptr)
		y->left = T2;

		//Updating heights:
		y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
		x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

		//x is now the root
		//returning the new root
		return x;
	}

	//Left Rotation:
	//
	Node<T>* leftRotate(Node<T>* x) {
		//y is the right child of x
		Node<T>* y = x->right;
		//T2 is the left child of y
		Node<T>* T2 = y->left;

		//ROTATION:
		//
		y->left = x;
		//
		x->right = T2;

		//Update heights:
		x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
		y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

		//The new root is now y
		//Returning the new root
		return y;
	}

	//Other functions:

	//Minimum Value Node (used in Remove):
	//Finds the node with the minimum key value
	Node<T>* minValueNode(Node<T>* node) {
		Node<T>* current = node;
		//finds the left most bottom node on the tree
		while (current->left != nullptr) {
			//moves current left on the tree
			current = current->left;
		}
		return current;
	}

	//Insert:
	Node<T>* insert(Node<T>* node, T key, int &i) {
		i++;
		if (node == nullptr) {
			return new Node<T>(key);
		}

		if (key < node->data) {
			node->left = insert(node->left, key, i);
		}
		else if (key > node->data) {
			node->right = insert(node->right, key, i);
		}
		else {
			return node;
		}


		//Update heights:
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		//Get the balance factor of the node:
		int balance = getBalanceFactor(node);

		//4 cases to handle imbalances:

		//LL Case:
		if (balance > 1 && key < node->left->data) {
			return rightRotate(node);
		}

		//RR Case:
		if (balance < -1 && key > node->right->data) {
			return leftRotate(node);
		}

		//LR Case:
		if (balance > 1 && key > node->left->data) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		//RL Case:
		if (balance < -1 && key < node->right->data) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}

	//Remove:
	//
	Node<T>* remove(Node<T>* node, T key, int &i) {
		i++;
		if (node == nullptr) {
			return node;
		}
		if (node->data > key) {
			node->left = remove(node->left, key, i);
		}
		else if (node->data < key) {
			node->right = remove(node->right, key, i);
		}
		else {
			//
			if ((node->left == nullptr) || (node->right == nullptr)) {
				Node<T>* temp;
				if (node->left) {
					temp = node->left;
				}
				else {
					temp = node->right;
				}
				if (temp == nullptr) {
					/*temp = node;
					node = nullptr;*/
					delete node;
					node = nullptr;
				}
				else {
					Node<T>* oldVal = node;
					node = temp;
					delete oldVal;
				}
			}
			else {
				Node<T>* temp = minValueNode(node->right);
				node->data = temp->data;
				node->right = remove(node->right, temp->data, i);
			}
		}
		if (node == nullptr) {
			return node;
		}

		//Update heights:
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));

		//Get the balance factor of the node:
		int balance = getBalanceFactor(node);


		//LL Case:
		if (balance > 1 && getBalanceFactor(node->left) >= 0) {
			return rightRotate(node);
		}

		//LR Case:
		if (balance > 1 && getBalanceFactor(node->left) < 0) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		//RR Case:
		if (balance < -1 && getBalanceFactor(node->right) <= 0) {
			return leftRotate(node);
		}

		//RL Case:
		if (balance < -1 && getBalanceFactor(node->right) > 0) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}

	//Takes a T as a parameter, searches the BST for the T, and returns a pointer to the node of the T g


	//Source: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

	Node<T>* Find(T item, Node<T>* r, int &i) {
		i++;
		int c = 1;
		//If the root is empty or points to the key, return it
		if (r == nullptr || r->data == item) {
			return r;
		}

		//If the root is greater than the key, move the root to the left
		if (r->data > item) {
			return Find(item, r->left, i);
		}

		//If the root is less than the key, move the root to the right
		return Find(item, r->right, i);
	}

	Node<T>* EmptyTree(Node<T>* node) {
		if (node == nullptr) {
			return nullptr;
		}
		EmptyTree(node->left);
		EmptyTree(node->right);
		size = 0;
		delete node;
		return nullptr;
	}

	void orderFuncAscending(Node<T>* node, vector<Node<T>*>& arr, int& dex) {
		if (node == nullptr) {
			return;
		}
		orderFuncAscending(node->left, arr, dex);
		arr.push_back(node);
		orderFuncAscending(node->right, arr, dex);
	}
	void orderFuncDecending(Node<T>* node, vector<Node<T>*>& arr, int& dex) {
		if (node == nullptr) {
			return;
		}
		orderFuncDecending(node->right, arr, dex);
		arr[dex] = node;
		orderFuncDecending(node->left, arr, dex);
		dex++;
	}

	vector<Node<T>*> sort(Node<T>* node, int choice, int count = 0) {
		int Size = size;
		vector<Node<T>*> val;
		int dex = 0;
		if (choice == 1) {
			orderFuncAscending(node, val, dex);
		}
		else {
			orderFuncDecending(node, val, dex);
		}
		
		
		return val;
	}


public:
	//Constructor:
	BinaryTree() {
		root = nullptr;
	}
	~BinaryTree() {}

	//insert function:
	int insert(T key) {
		int c = 0;
		size++;
		root = insert(root, key, c);
		return c;
	}

	//remove function:
	int remove(T key) {
		int c = 0;
		root = remove(root, key, c);
		size--;
		return c;
	}

	int Find2(T key) {
		int i = 0;
		Find(key, root, i);
		return i;
	}

	//find function:
	Node<T>* Find(T key) {
		int i = 0;
		return Find(key, root, i);
	}

	//size function:
	int getSize() {
		return size;
	}

	//empty tree function:
	int EmptyTree() {
		root = EmptyTree(root);
		return 0;
	}

	//
	int getColFind(T item) {
		return Find(item, root);
	}

	//ascending function:
	vector<Node<T>*> GetAllAscending() {

		vector<Node<T>*> node = sort(root, 1);
		return node;
	}

	//descending function:
	Node<T>* GetAllDescending() {
		Node<T>* node = sort(root, 0);
		return node;
	}

	//Assumption: Since binary trees do not have an index for their items, we are instead returning all values
	//in the binary tree that meet the test case (ex: mod % 7 == 0)
	//Another assumption is that this function will only be called if the tree is storing integers
	int findIndex(int modulus, int found = 0){
		vector<Node<T>*> node = GetAllAscending();
		for(int i = found; i < node.size(); i++){
			/*if (node[i] == nullptr) {
				continue;
			}*/
			if(node[i] && node[i]->data % modulus == 0){
				int retVal = node[i]->data;
				return retVal;
			}
		}
		return -1;
		}

	//print descending function:
	void printDescending() {
		vector<Node<T>*> node = GetAllAscending();
		cout << endl;
		cout << "Word: " << "Count: " << "Height: " << "Balance Factor: " << endl << endl;
		for (int i = 0; i < size; i++) {
			cout << node[i].data << "\t" << node[i].getHeight() << "\t" << getBalanceFactor(&node[i]) << endl;
		}
	}

	//print ascending function:
	void printAscending() {
		vector<Node<T>*> node = GetAllDescending();
		cout << endl;
		cout << "Word: " << "Count: " << "Height: " << "Balance Factor: " << endl << endl;
		for (int i = 0; i < size; i++) {
			cout << node[i].data << "\t" << node[i].getHeight() << "\t" << getBalanceFactor(&node[i]) << endl;
		}
	}
	T getWordCount(T key) {
		Node<T>* temp = Find(key);
		return temp->data;
	}
};

