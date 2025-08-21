#pragma once
using namespace std;
#include <string>
#include "Shelf.h"
#include "Movies.h"
class Exception
{ 
public: 

	void add_Exception(int index) {
		try {
			if (index + 1 >= 10) {
				throw index;
			}
		}
		catch (int ind) {
			cout << "FullShelf Exception: cannot add book to a shelf." << endl;
		}
	}

};

