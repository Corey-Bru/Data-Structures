// Homework 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.h"
#include "HashTable.h"
#include "Hash2D.h"
#include <random>
#include "Node.h"





int main()
{
    int trail = 100;
    BinaryTree<int> tree;
    HashTable H;
    Hash2D H2D;
    int t = 0;
    int h = 0;
    int h2 = 0;
    int item = 0;

    //INSERTING ITEMS:
    cout << "Testing efficiency when inserting items: " << endl;
    for (int i = 0; i < trail; i++) {

        item = rand() % 100 + 1;
        if (tree.Find(item) != nullptr) {
            continue;
        }
        //need to find a way to return collisions in tree
        t += tree.insert(item);
        h += H.insert(item);
        h2 += H2D.insert(item);
    }

    cout << "Nodes searched for the Binary Tree: " << t << endl;
    cout << "Collisions encountered for Linear Probing Hash Table: " << h << endl;
    cout << "Collisions encountered for 2D Array Hash Table: " << h2 << endl << endl;

    //REMOVING ITEMS:
    t = 0;
    h = 0;
    h2 = 0;
    cout << "Testing efficency when removing an item: " << endl;

    while (tree.findIndex(7) != -1) {
        int item = tree.findIndex(7);
        t += tree.remove(item);
    }

    while (H.findIndex(7) != -1) {
        int item = H.findIndex(7);
        h += H.Remove(item);
    }

    while (H2D.findIndex(7) != -1) {
        int item = H2D.findIndex(7);
        h2 += H2D.Remove(item);
    }

    cout << "Nodes searched for the Binary Tree: " << t << endl;
    cout << "Collisions encountered for Linear Probing Hash Table: " << h << endl;
    cout << "Collisions encountered for 2D Array Hash Table: " << h2 << endl << endl;

    //INSERT REMAINING VALUES AND THEN REMOVE THEM:
    t = 0;
    h = 0;
    h2 = 0;
    cout << "Testing efficiency when inserting and then removing items: " << endl;

    //initializing the random 50 values
    //array to save the index of each item:
    int arr[50];
    //adding the random values to the array to store the index
    for (int i = 0; i < 50; i++) {
        arr[i] = rand() % 100 + 1;

        //assuming they are able to insert the same item twice
        if (tree.Find(arr[i]) == nullptr) {
            t += tree.insert(arr[i]);
        }
        h += H.insert(arr[i]);
        h2 += H2D.insert(arr[i]);
    }

    cout << "Adding efficiency: " << endl;

    cout << "Nodes searched for the Binary Tree : " << t << endl;
    cout << "Collisions encountered for Linear Probing Hash Table: " << h << endl;
    cout << "Collisions encountered for 2D Array Has Table:" << h2 << endl << endl;

    t = 0;
    h = 0;
    h2 = 0;

    for (int i = 0; i < 50; i++) {
      h2 += H2D.Remove(arr[i]);
       t += tree.remove(arr[i]);
       h += H.Remove(arr[i]);
    }
    //for(int i = 0; i < 50; i++) {
    //    //t += tree.remove(arr[i]);
    //    //h += H.Remove(arr[i]);
    //    //h2 += H2D.Remove(arr[i]);

    //};

    cout << "Removing efficiency: " << endl;

    cout << "Nodes searched for the Binary Tree : " << t << endl;
    cout << "Collisions encountered for Linear Probing Hash Table: " << h << endl;
    cout << "Collisions encountered for 2D Array Has Table:" << h2 << endl << endl;

    //FINDING VALUES:
    cout << "Finding efficiency: " << endl;
    t = 0;
    h = 0;
    h2 = 0;
    int count = 0;

    while (true) {
        if (count == 0) {
            item = tree.findIndex(9);
        }
        else {
            item = tree.findIndex(9, item + 1);
        }
        if (item == -1) {
            break;
        }
        t += tree.Find2(item);
        count++;
    }

    count = 0;
    //int find = 0;
    item = 0;
    while (true) {
        if (count == 0) {
           item = H.findIndex(9);
        }
        else {
            item = H.findIndex(9, item + 1);
        }
        if (item == -1) {
            break;
        }
        h += H.Find(item);
        count++;
    }


    count = 0;

    while (true) {
       if (count == 0) {
           item = H2D.findIndex(9);
        }
        else {
            item = H2D.findIndex(9, item + 1);
        }
        if (item == -1) {
            break;
        }
        h2 += H2D.Find(item);
        count++;
    }

    cout << "Nodes searched for the Binary Tree : " << t << endl;
    cout << "Collisions encountered for Linear Probing Hash Table: " << h << endl;
    cout << "Collisions encountered for 2D Array Has Table: " << h2 << endl << endl;
}

