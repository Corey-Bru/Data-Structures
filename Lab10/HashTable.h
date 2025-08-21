#pragma once
#include <iostream>
#include "Student.h"
#include <string>
using namespace std;

template<class T>
class HashTable
{
private:
	int Size{ 100 };
	int numOfItems = 0;
	T** table;
	int collisions = 0;
	int Hash(string item, int c = 0) {
		//Add the sum of all ASCII values for the passed in string and modulus by the maximum size of the table
		int sum = 0;
		for (int i{ 0 }; i < item.length(); i++) {
			sum += static_cast<int>(item.at(i));
		}
		sum = (sum + c) % Size;
		return sum;
	}
public:
	//Constructor:
	HashTable() {
		table = new T * [Size];
		for (int i = 0; i < Size; i++) {
			table[i] = nullptr;
		}
	}
	HashTable(int size) {
		Size = size;
		table = new T * [Size];
		for (int i = 0; i < Size; i++) {
			table[i] = nullptr;
		}
	}
	~HashTable() {}
	//Hash(accept a string and return an int)
	

	// 	//AddItem (adds an item from the list)
	void AddItem(T* item) {
		//calculates the hash key using the hash function
		int index = Hash(string(*item));
		try {
			if (index > Size) {
				throw - 1;
			}
			//variable used to specify whether anything should be added to the hash key, used for linear probing with ASCII values
			int c = 0;
			//searches for an empty index using the hash key
			while (table[index] != nullptr && numOfItems != Size && index < Size) {
				c += 1;
				index = Hash(string(*item), c);
			}
			//places the item in an empty index indicated by the hash key
			table[index] = item;
			numOfItems++;
			cout << *table[index] << endl;
		}
		catch (int full) {
			cout << "Hash Table is Full!" << endl;
		}
	}
	//RemoveItem (searches the list for an item, if it's found, return it, if not, nullptr)
	T* RemoveItem(T* item) {
		int index = Hash(string(*item));
		int count = 0;

		while (!(table[index] == item)) {
			count++;
			cout << "Searching a new index..." << endl;
			index = Hash(string(*item), count);
			if (count >= Size) {
				cout << "Item was not found" << endl;
				return nullptr;
			}
		}
		cout << "The student, " << string(*item) << ", was found" << endl;
		T* temp = table[index];
		table[index] = nullptr;
		return temp;
	
	}

	T* MNumberSearch(string* item) {
		int index = Hash(*item);
		int search = 0;
		T* temp = nullptr;
		while (table[index] != nullptr && search < Size) {
			index = Hash(*item, search);
			search++;
			T* temp1 = table[index];
			if (string(*temp1) == *item) {
				temp = table[index];
				return temp;
			}
		}
		return nullptr;
	}
	T* GetItem(T* item) {
		int index = Hash(string(*item));
		int count = 0;

		while (!(table[index] == item)) {
			count++;
			//cout << "Searching a new index..." << endl;
			index = Hash(string(*item), count);
			if (count >= Size) {
				cout << "Item was not found" << endl;
				return nullptr;
			}
			collisions++;

		}
		cout << "The student, " << string(*item) << ", was found" << endl;
		return table[index];
	}
	// 	//GetLength (returns an int indicating the number of items in the table
	int GetLength() {
		return numOfItems;
	}
	void getAllItems() {
		cout << "First\t" << "Last\t\t" << "MNumber\t" << "Major\n";
		for (int i = 0; i < Size; i++) {
			if (table[i] != nullptr) {
				cout << *table[i] << endl;
			}
		}
	}

	bool IsEmpty() {
		if (numOfItems == 0) {
			return true;
		}
		return false;
	}
	void printItem() {
		Student* s = table[50];
	}
	int getCollisions() {
		return collisions;
	}
};
// 	//Destructor
// 	~HashTable();
// };

