#pragma once
#include "HashTable.h"
#include "LinkedList.h"
#include <string>
#include "Student.h"
using namespace std;
template <class T>
class Chained : public HashTable<T>
{
private:
	LinkedList<T>* chain;
	int maxSize = 100;
	int numOfItem = 0;
	int collisions;
	
public: 
	Chained() {
		chain = new LinkedList<T>[maxSize];
	}
	Chained(int size) {
		maxSize = size;
		chain = new LinkedList<T>[maxSize];
	}
	~Chained(){}
	//Source referenced: https://www.youtube.com/watch?v=y_xnyjs9gcc&list=PLTxllHdfUq4f7-uHOpxXnBUbsuLiI9pmb&index=4
    int ChainHash(string item, int c = 0) {
		int index;
		int sum = 0;

		//Adding ASCII values from each letter together
		for (int i{0}; i < item.length(); i++){
			sum += int(item[i]);
		}

		//Modulus by the maximum size of the hash table
		index = (sum + c) % maxSize;

		//Returning the index
		return index;
	}

	void AddItem(T* item) {
		int index = ChainHash(string(*item));
		int c = 0;
		while(!chain[index].IsEmpty()) {
			c += 1;
			index = ChainHash(string(*item),c);
		}
		chain[index].Insert(item);

		numOfItem++;
		cout << "First\t" << "Last\t\t" << "MNumber\t" << "Major\n";
		cout << *chain[index].SeeAt(item) << endl;
	}

	T* GetItem(T* item) {
		if (item == nullptr) {
			return nullptr;
		}
		int index = ChainHash(string(*item));
		T* returnItem = chain[index].SeeAt(item);
		int c = 0;
		collisions += chain[index].GetCollisions(item, collisions);
		returnItem = chain[index].SeeAt(item);
		if (returnItem != nullptr) {
			cout << "First\t" << "Last\t\t" << "MNumber\t" << "Major\n";
			cout << *returnItem << endl;
		}
		else {
			return nullptr;
		}
		return returnItem;
	}

	//Uses a string key to find the item in the hash table
	T* MNumberSearch(string* number) {
		//finds the index for the item
		int index = ChainHash(*number);
		int c = 0;
		collisions++;
		while (chain[index].getData() != nullptr && !(*chain[index].getData() == *number) ) {
			c++;
			index = ChainHash(string(*number),c);
			collisions++;
		}
		//storing the linked list at that index
		LinkedList<T>& list = chain[index];

		//T* item;
		T* returnItem = nullptr;
		//going through the linked list to find the item with the key
		//for (int i{ 0 }; i < maxSize; i++) {
		
			if (list.getData() != nullptr && *list.getData() == *number ) {
				return list.getData();
			}
			else {
				return nullptr;
			}
		//}
		//making a pointer to the item so that the function returns a pointer
		//returnItem = &item;
		
		//returning the item with the key
	}

	T* RemoveItem(T* item) {
		int index = ChainHash(string(*item));
		if (chain[index].SeeAt(item) != nullptr) {
			numOfItem--;
		}
		return chain[index].GetItem(item);
	}

	int GetLength() {
		return numOfItem;
	}

	int getCollisions() {
		return collisions;
	}
	void getAllItems() {
		cout << "First\t" << "Last\t\t" << "MNumber\t" << "Major\n";
		for (int i = 0; i < maxSize; i++) {
			chain[i].DisplayList();
		}
	}
	
	
	//Student* Remove(Student* item) {
	//	int index = ChainHash(string(*item));
	//	int collistions = 0; 
	//	/*T* del;
	//	T* pt1;
	//	T* pt2;
	//	T* temp;*/
	//	if (chain[index] == nullptr ) {
	//		cout << " Item Not Found!" << endl;
	//	}
	//	else if (chain[index] == item && numOfItem == 1) {
	//		temp = chain[index];
	//		delete chain[index];
	//		return temp;
	//	}
	//}

	
};

