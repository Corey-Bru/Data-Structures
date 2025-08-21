#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string firstName;
	string lastName;
	string mNumber;
	string major;
public:
    //constructor
    Student(){
		firstName = "N/A";
		lastName = "N/A";
		mNumber = "N/A";
		major = "N/A";
    }
	Student(string first, string last, string num, string maj) {
		firstName = first;
		lastName = last;
		mNumber = num;
		major = maj;
	}
	//setters and getters:
	string getFirstName() {
		return firstName;
	}

	string getLastName() {
		return lastName;
	}

	string getMNumber() {
		return mNumber;
	}
	
	string getMajor() {
		return major;
	}

	void setFirstName(string name) {
		firstName = name;
	}

	void setLastName(string name) {
		lastName = name;
	}

	void setMNumber(string number) {
		mNumber = number;
	}

	void setMajor(string maj) {
		major = maj;
	}

	operator string() const{
		return mNumber;
	}
	bool operator ==(Student right) {
		return right.mNumber == mNumber;
	}
	bool operator ==(string right){
		try {
			return right == mNumber;
		}
		catch(...){
			return false;
		}
	}
	//Used in last lab see for source 
	friend ostream& operator<<(ostream& os,  Student& s) {
		os << s.firstName << "\t" << s.lastName << "\t\t" << s.mNumber << "\t" << s.major;
		return os;
	}

};

