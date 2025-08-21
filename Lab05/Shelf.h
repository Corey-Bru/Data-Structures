#pragma once
#include <iostream>
#include "Movies.h"
const int max_book = 10;
class Shelf {
private:
	Movie mov[max_book];
	int numOfMov = 0;
public:
	int getNumOfMov() {
		return numOfMov;
	}
	void setNumOfMov(int numMov) {
		numOfMov = numMov;
	}
	Shelf() {
		mov[max_book];
		numOfMov = 0;
	}

	void add(Movie m) {
		try {
			if (numOfMov + 1 >= 10) {
				throw numOfMov;
			}
			else {
				mov[numOfMov] = m;
				numOfMov++;
			}
		}
		catch (int item) {
			cout << "Cannot add more than 10 Movies on the shelf" << endl;
		}

		/*if (numOfMov < 10) {
			mov[numOfMov] = m;
			numOfMov++;
		}
		else {
			throw "Shelf is full";
		}*/
	}

	Movie remove(Movie m[]) {
		int numMov = getNumOfMov();
		Movie placeHolder = m[numMov];
		//balnk movie that clears an existing movie
		Movie const blank;
		//Checks if there is a movie to remove 
		try{
			//Throws an exception if number of movies is 0 or less
			if (numMov - 1 < 0) {
				throw numMov;
			}
			m[numMov] = blank;
			cout << "Removing: " << endl;
			placeHolder.Play();
			cout << "at postion: " << numMov << endl;
			setNumOfMov(numMov - 1);
			return placeHolder;

		}
		catch (int numMovEx) {
			cout << "Error Caught: Cannot remove 0 movies" << endl << endl;
			exit;
		}
		

	};

	//Prints out the title of each movie on the shelf and its position:
	void viewShelf() {
		for (int i = 0; i < numOfMov; i++) {
			cout << "Movie at position: " << i + 1<< " on the Shelf." << endl;
		}
	}
};