#pragma once
#include <iostream>

const int max_size{ 5 };
template<class T>
class SidePile
{
private:
	T items[max_size];
	int indexItem = 0;

public:
	SidePile() {
	}
	//Accepts a pointer and adds that pointer to the top of the stack
	void push(T it) {
		try {
			//checks to make sure the array is not already full
			if (indexItem + 1 > max_size) {
				throw indexItem;
			}
			//Adds the pointer to the array of pointers at the next available index
			indexItem++;
			items[indexItem - 1] = it;
			//increases the index by one
			//std::cout << "IndexItem address: " << items[indexItem] << std::endl;
			//std::cout << "indexItem: " << items[indexItem - 1] << std::endl;

			//std::cout << "Index counter: " << indexItem - 1 << std::endl;
		}
		catch (int dex) {
			std::cout << "error caught" << std::endl;
			FPE_STACKOVERFLOW;
		}


	}
	//
	T pop() {

		//T *blank;
		T placeHolder;
		T blank;
		try {
			if (indexItem - 1 < 0) {
				throw indexItem;
			}

			//Removes last item in the stack
			//sets a blank stack to the removed stack index
			//std::cout << "Removing address index: " << items[indexItem] << std::endl;
			//std::cout << "Removing index: " << items[indexItem - 1] << std::endl;
			placeHolder = items[indexItem - 1];
			indexItem--;
			//Lowers the index
			return placeHolder;
		}
		catch (int dex) {
			FPE_STACKUNDERFLOW;
		}
	}

	//returns a pointer to the item at the top of the stack without removing it
	T top() {
		try {
			if (indexItem == 0) {
				throw indexItem;
			}
			return items[indexItem - 1];
		}
		catch (int dex) {
			FPE_STACKUNDERFLOW;
		}
		return 0;
	}

	//returns the length of the array
	int length() {
		return (indexItem);
	}

	void empty() {
		for (int i{ 0 }; i < max_size; i++) {
			items[i] = nullptr;
			delete items[i];
		}
		indexItem = 0;
	}


};



