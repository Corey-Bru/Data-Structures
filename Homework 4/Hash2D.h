#pragma once
#include<iostream>
using namespace std;
class Hash2D
{
private:
	const int col = 100;
	const int row = 5;
	int numOfItem = 0;
	int table[100][5];

	int Hash(int item, int c = 0) {
		int index = item % col;
		//negative means null
		/*while (table[index] < 0) {
			index++;
		}*/
		index = (item + c) % col;
		return index;
	}
public:
	Hash2D() {
		for (int i = 0; i < col; i++){
			for (int j = 0; j < row; j++){
				table[i][j] = -1;
			}
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
			while (c < col) {
				for (int i = 0; i < row; i++) {
					if (table[index][i] < 0) {
							table[index][i] = item;
							return c;
					}
				}
				c++;
				index = Hash(item, c);
			}
			throw 'a';
		}
		catch (char a) {
			cout << "item Hash is full " << endl;
		}
		catch (...) {
			cout << "item can not be a negative value" << endl;
		}
		return -1;
	}
	int Remove(int item) {
		try {
			if (item < 0) {
				throw 0;
			}
			int c = 1;
			int index = Hash(item);
			while (c < col) {
				for (int i = 0; i < row; i++) {
					if (table[index][i] == item) {
						table[index][i] = -1;
						return c;
					}
				}
				c++;
				index = Hash(item,c);

			}
			throw 'a';
		}
		catch (char a) {
			cout << "Is Empty";
		}
		catch (...) {
			cout << "item can not be a negitive value" << endl;
		}
		return -1;
	}
	int Find(int item) {
		try {
			if (item < 0) {
				throw 0;
			}
			int c = 1;
			int index = Hash(item);
			while (c < col) {
				for (int i = 0; i < row; i++) {
					if (table[index][i] == item) {
						return c;
					}
				}
				c++;
				index = Hash(item, c);
			}
			throw 'a';
			}
			catch (char a) {
				cout << "Is Empty" << endl;
			}
			catch (...) {
				cout << "item can not be a negitive value" << endl;
			}
			return -1;
	}
	void print() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (table[i][j] >= 0) {
					cout << "Value: " << table[i][j] << " Is stored in location: " << i;
				}
				else {
					cout << "Aviable slot that could be used to store a value is: " << i;
				}
			}
		}
	}

	int findIndex(int modulus , int found = 0){
		for(int i = found; i < col; i++){
			for(int z = 0; z < row; z++){
				if(table[i][z] >= 0 && table[i][z] % modulus == 0){
					return table[i][z];
				}
			}
		}
		return -1;
	}


};

