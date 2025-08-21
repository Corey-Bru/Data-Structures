#pragma once
#include <iostream>
#include "Streaming.h"
using namespace std;
//getters
string Streaming::getTitle() {
	return Title;
};
string Streaming::getDescription() {
	return Description;
};
//setters
void Streaming::setTitle(string title) {
	Title = title;
};

void Streaming::setDescription(string description) {
	Description = description;
};

//Constructors
Streaming::Streaming() {
	Title = "N/A";
	Description = "N/A";
};
Streaming::Streaming(string title, string description) {
	Title = title;
	Description = description;
};

//Play virtual function


//Details function that prints the title and description
void Streaming::Details() {
	cout << "Title: " << Title << endl;
	cout << "Description:\n" << Description << endl;
};