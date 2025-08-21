#include <iostream>
#include "LinkedList.h"
#include "Part.h"

using namespace std;

void DisplayMenu() {
    cout << "\n=== PARTS INVENTORY SYSTEM ===\n";
    cout << "1. Add a Part\n";
    cout << "2. Remove a Part\n";
    cout << "3. Search for a Part\n";
    cout << "4. Display All Parts\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    LinkedList<Part> inventory;
    int choice;

    do {
        DisplayMenu();
        cin >> choice;

        switch (choice) {
        case 1: { // Add a Part
            int sku, qty, leadTime;
            string desc, uom;
            double price;

            cout << "Enter SKU: ";
            cin >> sku;
            cout << "Enter Description: ";
            cin.ignore();
            getline(cin, desc);
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Unit of Measure: ";
            cin.ignore();
            getline(cin, uom);
            cout << "Enter Quantity On Hand (default 0): ";
            cin >> qty;
            cout << "Enter Lead Time in Days (default 0): ";
            cin >> leadTime;

            inventory.Insert(Part(sku, desc, price, uom, qty, leadTime));
            cout << "Part added successfully!\n";
            break;
        }

        case 2: { // Remove a Part
            int sku;
            cout << "Enter SKU of part to remove: ";
            cin >> sku;

            Part searchPart(sku, "", 0.0, "");  // Only SKU matters for comparison
            if (inventory.Delete(searchPart)) {
                cout << "Part removed successfully!\n";
            }
            else {
                cout << "Part not found.\n";
            }
            break;
        }

        case 3: { // Search for a Part
            int sku;
            cout << "Enter SKU to search: ";
            cin >> sku;

            Part searchPart(sku, "", 0.0, "");
            Part foundPart(0, "", 0.0, "");
            if (inventory.GetItem(searchPart, foundPart)) {
                cout << "Part found:\n";
                foundPart.Display();
            }
            else {
                cout << "Part not found.\n";
            }
            break;
        }

        case 4: { // Display all Parts
            if (inventory.IsEmpty()) {
                cout << "The inventory is empty.\n";
            }
            else {
                cout << "Displaying all parts:\n";
                inventory.DisplayList();
            }
            break;
        }

        case 5: // Exit
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
