#include <iostream>
#include "Student.h"
#include "Part.h"
#include <limits>
#include "HashTable.h"
#include "Chained.h"

using namespace std;

void DisplayMenu() {
    cout << "\n=== STUDENT INVENTORY SYSTEM ===\n";
    cout << "1. Add a Student\n";
    cout << "2. Remove a Student\n";
    cout << "3. Search for a STUDENT\n";
    cout << "4. Display All STUDENT\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}


int main() {
    Chained<Student> inventory;
    //Student s;
    int choice;
    choice = -1;
    //Student* s = new Student;

    //inventory.OperatorTest();

    while (choice != 5) {
        DisplayMenu();
        //https://www.geeksforgeeks.org/how-to-validate-user-input-in-cpp/
        //Used this to verify whether the input is an integer or not
        while (!(std::cin >> choice)) {
            std::cout << "Enter an integer: " << std::endl;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: { // Add a Student
            Student* s = new Student;
            string firstName, lastName, mNumber, major;
            cout << "Student First Name: ";
            cin >> firstName;
            s->setFirstName(firstName);
            cout << "Student Last Name: ";
            cin >> lastName;
            s->setLastName(lastName);
            cout << "Student mNumber: ";
            cin >> mNumber;
            s->setMNumber(mNumber);
            cout << "Student Major: ";
            cin >> major;
            s->setMajor(major);
            //s = Student(firstName, lastName, mNumber, major);

            inventory.AddItem(s);
            s = nullptr;
            cout << "Student added successfully!\n";
            break;
        }
        case 2: { // Remove a Student
            string mNumber;
            cout << "What student would you like to remove? (Enter their mNumber): " << endl;
            cin >> mNumber;

            inventory.RemoveItem(inventory.MNumberSearch(&mNumber));
           
            if (inventory.MNumberSearch(&mNumber) == nullptr) {
                cout << "Student removed successfully!\n";
            }

            break;
        }

        case 3: { // Search for a Student

            string mNumber;
            cout << "What student would you like to find? (Enter their mNumber): " << endl;
            cin >> mNumber;

            if (inventory.MNumberSearch(&mNumber) == nullptr) {
                cout << "Student not found" << endl;
            } else {
                if (inventory.GetItem(inventory.MNumberSearch(&mNumber)) == nullptr) {
                    cout << "Student not found" << endl;
                }
                else {
                    cout << "Student found!" << endl;
                }
            }

            break;
        }

        case 4: { // Display all Students

            if (inventory.GetLength() == 0) {
                cout << "The inventory is empty.\n";
            }
            else {
                cout << "Displaying all parts:\n";
               inventory.getAllItems();
            }
            break;
        }

        case 5: // Exit
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
   /* HashTable<Student> inventory;
    Student s = { "Corey", "Brun", "123", "cs"};
    Student* point;
    inventory.AddItem(&s);
    inventory.GetItem(&s);
    string st = "123";
    inventory.MNumberSearch(&st);*/
}