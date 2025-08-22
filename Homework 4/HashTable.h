#pragma once
#include<iostream>
#include<string>
using namespace std;
class HashTable
{
private:
	const int size = 500;
	int numOfItem = 0;
	int table[500];

	int Hash(int item, int c = 0) {
		
	
		int index = (item + c) % size;
		return index;
	}
public:
	HashTable() {
		for (int i = 0; i < size; i++) {
			table[i] = -1;
		}
	}
	int insert(int item) {
		try {
			if (item < 0) {
				throw 0;
			}
			int index = Hash(item);
			//assume collisions start at one 
			int c = 1;
			while (table[index] > -1 && table[index] != item) {
				index = Hash(item, c);
				c++;
				if (c >= size) {
					throw 'a';
				}
			}
			table[index] = item;
			numOfItem++;
			return c;
		}
		catch (char a) {
			cout << "Item can not inserted hash is full!" << endl;
		}
		catch (...) {
			cout << "item can not be a negative value" << endl;
		}

	}
	int Find(int item) {
		int c = 1;
		try {
			if (item < 0) {
				throw 0;
			}

			int index = Hash(item);
		
			while (table[index] != -1 && table[index] != item) {
				if (table[index] == item) {
					return c;
				}
				c++;
				index = Hash(item);
				if (c + 1 > size) {
					throw 'a';
				}
			}
		}
		catch (char a) {
			cout << "Value not found in Hash!" << endl;
		}
		catch (...) {
			cout << "item can not be a negitive value" << endl;
		}
		return c;
	}
	int Remove(int item) {
		try {
			if (item < 0) {
				throw 0;
			}

			int index = Hash(item);
			int c = 1;
			while (table[index] != -1) {
				if (table[index] == item) {
					table[index] = -1;
					numOfItem--;
					return c;
				}
				c++;
				index = Hash(item);
				if (numOfItem == 0) {
					throw 'a';
				}
			}
		}
		catch (char a) {
			cout << "Value not found in Hash!" << endl;
		}
		catch (...) {
			cout << "item can not be a negative value" << endl;
		}
		return -1;
	}
	void print() {
		for (int i = 0; i < size; i++) {
			if (table[i] >= 0) {
				cout << "Value: " << table[i] << " Is stored in location: " << i;
			}
			else {
				cout << "Available slot that could be used to store a value is: " << i;
			}
		}
	}

	int findIndex(int modulus, int found = 0) {
		int returnItem = -1;
		for (int i = found; i < size; i++) {
			if (table[i] != -1 && table[i] % modulus == 0) {
			 returnItem = table[i];
			 break;
			}
		}
		return returnItem;
	}

};

