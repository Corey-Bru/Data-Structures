// Lab 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "LinkedList.h"
using namespace std;

void printMenu(int arrows) {
	cout << "**********************************************" << endl;
	cout << "Please select from the following menu" << endl;
	cout << "1: Move To Another Room" << endl;
	cout << "2: Shoot an arrow: Arrows left = " << arrows << endl;
	cout << "3: Observe tunnels" << endl;
	cout << "**********************************************" << endl;
	cout << "Please Enter (1-3): ";
}


int main()
{
	static const int rooms = 20;
	//game initialization
	Graph game;
	int connections;
	for (int i = 0; i < rooms; i++) {
		//this will add the nodes using ascii values
		game.AddNode(NodeGraph(65 + i));
	}
	for (int i = 0; i < rooms; i++) {
		//this is to ensure there are atleast 2 to 5 connections
		connections = rand() % 4 + 2;
		int numAdded = 0;

		while (numAdded < connections) {
			int col = rand() % 20;
			if (col != i && !game.hasEdge(i, col)) {
				game.AddEdge(i, col);
				numAdded++;
			}
		}
	}


	//This is used to test if there are the proper number of connections going out of nodes.
	/*game.printGraph();
	for (int i = 0; i < rooms; i++) {
		LinkedList<char> list = game.OutEdges(NodeGraph(65 + i));
		list.DisplayList();

	}*/

	//Assume the player starts in room 'A'
	bool WumpusHunted = 0;
	char playerRoom = 'A';
	char pitLoc = rand() % 20 + 66;
	char batLoc = rand() % 20 + 66;
	char WumpusLoc = rand() % 20 + 66;
	
	do {
		pitLoc = rand() % 20 + 66;
		batLoc = rand() % 20 + 66;
		WumpusLoc = rand() % 20 + 66;
	}
	while (pitLoc == batLoc || pitLoc == WumpusLoc || WumpusLoc == batLoc);
	int arrows = 3;
	int menuAnswer = 0;
	char arrowLoc = ' ';
	cout << "Welcome to Hunt the Wumpus!" << endl;
	while (WumpusHunted != 1 && arrows != 0) {
		int menuAnswer = 0;
		while (menuAnswer < 1 || menuAnswer > 3) {
			printMenu(arrows);
			cin >> menuAnswer;
			if (menuAnswer < 1 || menuAnswer > 3) {
				cout << "Invalid Answer: Please enter a valid answer!" << endl;
			}
		}
		LinkedList<char> list = game.OutEdges(NodeGraph(playerRoom));;
		// LinkedList<char> *list = new LinkedList<char>;
		// LinkedList<char> l;
		//list = game.OutEdges(NodeGraph(playerRoom));

		if (menuAnswer == 1) {
			cout << "The following rooms you may enter are: ";
			char placeHolder = playerRoom;
			list.DisplayList();
			cin >> playerRoom;
			if (list.SeeAt(&playerRoom) != nullptr) {
				if (playerRoom == pitLoc) {
					cout << "You have fallen into a bottomless pit: YOU LOSE!" << endl;
					break;
				}
				else if (playerRoom == batLoc) {
					cout << "You have ran into a room full of bats and now will move into a random location!" << endl;
					LinkedList<char> list3 = game.OutEdges(NodeGraph(playerRoom));
					playerRoom = list3.RandomLocation();
				}
				else if (WumpusLoc == playerRoom) {
					arrows--;
					cout << "You have found Wumpus but he attacks and steals an arrow! You have " << arrows << " arrows left!" << endl;
				
					do {
						WumpusLoc = rand() % 20 + 66;
					} while (pitLoc == batLoc || pitLoc == WumpusLoc || WumpusLoc == batLoc);
					if (arrows == 0) {
						cout << "You ran out of arrows you LOSE!" << endl;
						break;
					}
				}
				else {
					cout << "You have moved to the location: " << playerRoom << endl;
					if (playerRoom == arrowLoc) {
						cout << "You found your old arrow!!!" << endl;
						arrows++;

					}
				}
			}
			else {
				cout << "Please choose another option." << endl;
				playerRoom = placeHolder;
			}
		}
		else if (menuAnswer == 2) {
			
			cout << "Where would you like to fire an Arrow?" << endl;
			list.DisplayList();
			cout << "Pick a Valid Location: ";
			char placeArrow = arrowLoc;
			cin >> arrowLoc;
			if (list.SeeAt(&arrowLoc) != nullptr) {
				int random = rand() % 2 + 4;
				arrows--;
				for (int i = 0; i < random; i++) {
					if (WumpusLoc == arrowLoc) {
						cout << "You hit Wumpus!!" << endl << "You win!!!!!" << endl;
						WumpusHunted = 1;
						break;
					}
					else if (pitLoc == arrowLoc) {
						arrowLoc = 193;
						break;
					}
					else if (batLoc == arrowLoc) {
						batLoc = 192;
						arrowLoc = 193;
						break;
					}
					LinkedList<char> list2 = game.OutEdges(NodeGraph(arrowLoc));
					arrowLoc = list2.RandomLocation();
					while (arrowLoc == placeArrow) {
						arrowLoc = list2.RandomLocation();
					}
				}
				if(WumpusLoc == arrowLoc) {
				
					break;
				}
				if (arrows == 0) {
					cout << "You ran out of arrows you LOSE!" << endl;
					break;
				}
				do {
					WumpusLoc = rand() % 20 + 66;
				} while (pitLoc == batLoc || pitLoc == WumpusLoc || WumpusLoc == batLoc);
			}
			else {
				cout << "Pick a valid spot!" << endl;
			}
		}
		else if(menuAnswer == 3){
			cout << "You observe the room around you this is what you hear......" << endl;
			char *allLoc = list.getAllData();
			int count = 0;
			bool heardSomething = false;
			while (count != list.Size()) {
				if (allLoc[count] == WumpusLoc) {
					cout << "You hear a wild scream almost sounds like a WUMPUS!" << endl;
					heardSomething = true;
				}
				if (allLoc[count] == pitLoc) {
					cout << "You hear the sounds of an ominous pit!" << endl;
					heardSomething = true;
				}
				if (allLoc[count] == batLoc) {
					cout << "You hear the screeching almost sounds like a group of bats! " << endl;
					heardSomething = true;
				}
				count++;
			}
			if (!heardSomething) {
				cout << "You don't hear anything its almost too silent....." << endl;
			}
			delete[] allLoc;
		}
				



	}

}

