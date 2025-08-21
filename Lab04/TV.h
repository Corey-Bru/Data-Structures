#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Streaming.h"
using namespace std;
struct episode {
	public:
		int seasonNumber{ 0 };
		int episodeNumber{ 0 };
		string summary = "";
		int getSeasonNumber() {
			return seasonNumber;
		}
		int getEpisodeNumber() {
			return episodeNumber;
		}
		string getSummary() {
			return summary;
		}
		void setSeasonNumber(int s) {
			seasonNumber = s;
		}
		void setEpisodeNumber(int e) {
			episodeNumber = e;
		}
		void setSummary(string s) {
			summary = s;
		}

};

//class definition for TV show, it includes the number of episodes, number of seasons, and each episode
class TVshow : public Streaming {
private:
	int numOfE{ 0 };
	int numOfS{ 0 };
	vector<episode> e;

public:
	//Setters
	void setNumOfE(int e) {
		numOfE = e;
	}

	void setNumOfS(int s) {
		numOfS = s;
	}

	void setEpisode(vector<episode> ep) {
		e = ep;
	}
	
	void addEpisode(episode ep) {
		e.push_back(ep);
	}

	//Getters
	int getNumOfE(){
		return numOfE;
	}

	int getNumOfS(){
		return numOfS;
	}

	vector<episode> getEpisodes(){
		return e;
	}

	//Constructors
	TVshow() {
		numOfE = 0;
		numOfS = 0;
		e = {};
	};
	TVshow(int numberOfEpisodes, int numberOfSeasons, vector<episode> episodes){
		numOfE = numberOfEpisodes;
		numOfS = numberOfSeasons;
		e = episodes;
	};

	//Play will override the virtual funciton Play from the base class Streaming
	void Play() {
		//Sets the season number and episode number the user inputs to -1 so the while loop runs
		int inputS = -1;
		int inputE = -1;

		//asks the user for the season and number of the episode to print the summary for
		//uses a while loop to verify that the number entered exists
		while (inputS < 0 || inputS > numOfS) {
			cout << "Which season?" << endl;
			cin >> inputS;
			if (inputS < 0 || inputS > numOfS) {
				cout << "Season " << inputS << " not found, please enter a valid season number." << endl;
			}
		}
		while (inputE < 0 || inputE > numOfE) {
			cout << "Which episode?" << endl;
			cin >> inputE;
			if (inputE < 0 || inputE > numOfE) {
				cout << "Season " << inputS << ", Episode " << inputE << " not found, please enter a valid episode number." << endl;
			}
		}

		//Searching for the episode by the season and episode entered
		string outputSummary = "";
		for (int number = 0; number < e.size(); number++) {
			if (e[number].seasonNumber == inputS && e[number].episodeNumber == inputE) {
				outputSummary = e[number].summary;
			}
		}
		//after the program successfully passes through both loops and finds the episode, it prints

		cout << "Season: " << inputS << ", Episode: " << inputE << endl;
		cout << "Summary: " << outputSummary << endl;
	}

	//Overriding Details to print
	void Details(){
		cout << "Title: " << getTitle() << endl;
		cout << "Description: " << getDescription() << endl;
		cout << "Number of Seasons: " << numOfS << endl;
		
	}
};
	