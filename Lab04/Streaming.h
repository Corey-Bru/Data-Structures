#pragma once
#ifndef _STREAMING_
#define _STREAMING_ 

#include <iostream>
#include <string>
using namespace std;
class Streaming {
	private:
		string Title{ "" };
		string Description{ "" };
	public:
		//Getters
		string getTitle();
		string getDescription();
		//setters
		void setTitle(string title);
		void setDescription(string description);
		//Constructers 
		Streaming();
		Streaming(string title, string description);

		//Functions
		virtual void Play() {};
		void Details();


};
#endif // _STREAMING_

//Derived Classes

//struct called episode that stores the season of the episode, what number it is, and the summary

//
////class definition for TV show, it includes the number of episodes, number of seasons, and each episode
//class TVshow : public Streaming {
//private:
//	int numOfE{ 0 };
//	int numOfS{ 0 };
//	vector<episode> e;

//public:
//	TVshow();
//	TVshow(int numberOfEspisodes, int numberOfSeasons, vector<episode> episodes);
//
//	//Play will override the virtual funciton Play from the base class Streaming
//	void Play() {
//		//Sets the season number and episode number the user inputs to -1 so the while loop runs
//		int inputS = -1;
//		int inputE = -1;
//
//		//asks the user for the season and number of the episode to print the summary for
//		//uses a while loop to verify that the number entered exists
//		while (inputS < 0 || inputS > numOfS) {
//			cout << "Which season?" << endl;
//			cin >> inputS;
//			if (inputS < 0 || inputS > numOfS) {
//				cout << "Season " << inputS << " not found, please enter a valid season number." << endl;
//			}
//		}
//		while (inputE < 0 || inputE > numOfE) {
//			cout << "Which episode?" << endl;
//			cin >> inputE;
//			if (inputE < 0 || inputE > numOfE) {
//				cout << "Season " << inputS << ", Episode " << inputE << " not found, please enter a valid episode number." << endl;
//			}
//		}
//
//		//Searching for the episode by the season and episode entered
//		string outputSummary = "";
//		for (int number = 0; number < e.size(); number++) {
//			if (e[number].season == inputS && e[number].episode == inputE) {
//				outputSummary == e[number].summary;
//			}
//		}
//		//after the program successfully passes through both loops and finds the episode, it prints
//
//		cout << "Title: " << getTitle() << endl;
//		cout << "Season: " << inputS << ", Episode: " << inputE << endl;
//		cout << "Description: " << getDescription() << endl;
//		cout << "Summary: " << outputSummary << endl;
//	}
//};
//	


