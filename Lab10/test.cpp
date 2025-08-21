#include <iostream>
#include "Student.h"
#include "Part.h"
#include <limits>
#include "HashTable.h"
#include "LinkedList.h"
#include "Chained.h"
//#include <unordered_set>
//using namespace std;
//int main() {
//	int numOfStudents = 250;
//	Chained<Student> test(numOfStudents);
//	HashTable<Student> test1(numOfStudents);
//	int randomMNum = 0;
//	//This is only used to ensure that a number is not entered twice 
//	Chained<Student> checkUsed(numOfStudents);
//	string mNum;
//	for (int i = 0; i < numOfStudents; i++) {
//		Student* s = new Student;
//		do {
//			randomMNum = 100000000 + (std::rand() % 900000000);
//			mNum = "M" + to_string(randomMNum);
//		} while (checkUsed.GetItem(checkUsed.MNumberSearch(&mNum)) != nullptr);
//		
//		s->setMNumber(mNum);
//		checkUsed.AddItem(s);
//		test.AddItem(s);
//		test1.AddItem(s);
//		s = nullptr;
//
//	}
//	string randomNum = to_string(randomMNum);
//	string* pointer = &mNum;
//	//Gets item from last random num generated 
//	test.GetItem(test.MNumberSearch(pointer));
//	cout << "Num of collisions for Chain: " << test.getCollisions() << endl;
//	test1.GetItem(test1.MNumberSearch(pointer));
//	cout << "Num of collisions for Linear Probing: " << test1.getCollisions() << endl;
//
//
//
//	
//
//
//
//}