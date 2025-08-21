#include <iostream>
#include "Streaming.h"
#include "Movies.h"
#include "TV.h"
#include <string>
#include<vector>
using namespace std;

void printInfo(Streaming &show){
	show.Play();
	show.Details();
}

//void printInfo(TVshow show) {
//	show.Play();
//	show.Details();
//}

int main() {
    
	while (true) {
		int userInput = -1;
		while (userInput < 1 || userInput > 5) {
			cout << "Press 1 for an instance of Show" << endl;
			cout << "Press 2 for an instance of Movie" << endl;
			cout << "Press 3 for an instance of TV Show" << endl;
			cout << "Press 4 for an instance of a MOVIE declared as a Show" << endl;
			cout << "Press 5 for an instance of a TV Show declared as a Show" << endl;
			cin >> userInput;
			if (userInput < 1 || userInput > 5) {
				cout << "Please enter a valid input 1-5" << endl;
			}
		}

		if (userInput == 1) {
			string title;
			string description;
			cout << "What is the title of the show?: " << endl;
			cin.ignore();
			getline(cin, title, '\n');
			cout << "What is the description for your show?: " << endl;
			getline(cin, description, '\n');
			Streaming s1(title, description);
			printInfo(s1);

		}
		else if (userInput == 2) {
			Movie m1;
			string credits = "";
			double rating = 0;
			int runTime = 0;
			cout << "Please enter the Intro Credits:" << endl;
			cin.ignore();
			getline(cin, credits, '\n');
			m1.setCredits(credits);
			cout << "Please enter the Rating. (1-5 stars): ";
			cin >> rating;
			m1.setRating(rating);
			cout << "Please enter the Run Time. (In minutes): ";
			cin >> runTime;
			m1.setRunTime(runTime);
			printInfo(m1);
			//create a Movie

		}
		else if (userInput == 3) {
			TVshow t1;
			string title;
			string description;
			int numberOfSeasons;
			int numberOfEpisodes;
			cout << "How many season does your show have?: " << endl;
			cin >> numberOfSeasons;
			t1.setNumOfS(numberOfSeasons);
			cout << "How many episodes total does your show have?: " << endl;
			cin >> numberOfEpisodes;
			t1.setNumOfE(numberOfEpisodes);

			int seasonCounter = numberOfSeasons;
			int episodeCounter = numberOfEpisodes;
			for (int i = 1; i < numberOfSeasons + 1; i++) {
				int number = 0;
				while (true) {
					cout << "How many episodes does Season " << i << " have?: " << endl;
					cin >> number;
					if (number < numberOfEpisodes) {
						episodeCounter = episodeCounter - number;
						break;
					}
					else {
						cout << "You only have " << episodeCounter << " episodes left, please enter a valid number." << endl;
					}
				}
				for (int j = 1; j < number + 1; j++) {
					episode p;
					p.setEpisodeNumber(j);
					p.setSeasonNumber(i);
					string sum;
					cout << "Enter the summary for Season " << i << ", Episode " << j << ": " << endl;
					if (j == 1) {
						cin.ignore();
					}
					getline(cin, sum, '\n');
					p.setSummary(sum);
					t1.addEpisode(p);
				}
			}
			while (episodeCounter > 0) {
				cout << "You have " << episodeCounter << " episodes remaining" << endl;
				cout << "These will be added to season: " << seasonCounter + 1 << endl;
				t1.setNumOfS(seasonCounter + 1);
				for (int j = 1; j < episodeCounter + 1; j++) {
					episode p;
					p.setEpisodeNumber(j);
					p.setSeasonNumber(seasonCounter + 1);
					string sum;
					cout << "Enter the summary for Season " << seasonCounter + 1 << ", Episode " << j << ": " << endl;
					cin.ignore();
					getline(cin, sum, '\n');
					p.setSummary(sum);
					t1.addEpisode(p);
				}
				episodeCounter -= 1;
			}
			printInfo(t1);

			//create a TVshow
		}
		else if (userInput == 4) {

			Streaming* s1 = new Movie;

			Movie m1;
			string credits;
			double rating;
			int runTime;
			string title;
			string description;
			cout << "Please enter title of movie: ";
			cin.ignore();
			getline(cin, title, '\n');
			m1.setTitle(title);
			cout << "Please enter description of the movie:" << endl;
			getline(cin, description, '\n');
			m1.setDescription(description);
			cout << "Please enter the Intro Credits:" << endl;
			getline(cin, credits, '\n');
			m1.setCredits(credits);
			cout << "Please enter the Rating. (1-5 stars): ";
			cin >> rating;
			m1.setRating(rating);
			cout << "Please enter the Run Time. (In minutes): ";
			cin >> runTime;
			m1.setRunTime(runTime);
			s1 = &m1;
			printInfo(*s1);
			/*delete m1;
			delete s1;*/
		}
		else {
			Streaming* s1 = new TVshow;
			TVshow t1;
			string title;
			string description;
			int numberOfSeasons;
			int numberOfEpisodes;
			cout << "Input the title of the TVshow: ";
			cin.ignore();
			getline(cin, title, '\n');
			t1.setTitle(title);
			cout << "Input the Description of the TVshow: " << endl;
			getline(cin, description, '\n');
			t1.setDescription(description);
			cout << "How many season does your show have?: " << endl;
			cin >> numberOfSeasons;
			t1.setNumOfS(numberOfSeasons);
			cout << "How many episodes total does your show have?: " << endl;
			cin >> numberOfEpisodes;
			t1.setNumOfE(numberOfEpisodes);

			int seasonCounter = numberOfSeasons;
			int episodeCounter = numberOfEpisodes;

			for (int i = 1; i < numberOfSeasons + 1; i++) {
				int number = 0;
				while (true) {
					cout << "How many episodes does Season " << i << " have?: " << endl;
					cin >> number;
					int place = number;
					if (place < numberOfEpisodes) {
						episodeCounter = episodeCounter - place;
						break;
					}
					else {
						cout << "You only have " << episodeCounter << " episodes left, please enter a valid number." << endl;
					}
				}
				for (int j = 1; j < number + 1; j++) {
					episode p;
					p.setEpisodeNumber(j);
					p.setSeasonNumber(i);
					string sum;
					cout << "Enter the summary for Season " << i << ", Episode " << j << ": " << endl;
					if (j == 1) {
						cin.ignore();
					}
					getline(cin, sum, '\n');
					p.setSummary(sum);
					t1.addEpisode(p);
				}
			}
			while (episodeCounter > 0) {
				cout << "You have " << episodeCounter << " episodes remaining" << endl;
				cout << "These will be added to season: " << seasonCounter + 1 << endl;
				t1.setNumOfS(seasonCounter + 1);
				for (int j = 1; j < episodeCounter + 1; j++) {
					episode p;
					p.setEpisodeNumber(j);
					p.setSeasonNumber(seasonCounter + 1);
					string sum;
					cout << "Enter the summary for Season " << seasonCounter + 1 << ", Episode " << j << ": " << endl;
					cin.ignore();
					getline(cin, sum, '\n');
					p.setSummary(sum);
					t1.addEpisode(p);
				}
				episodeCounter -= 1;
			}
			s1 = &t1;
			printInfo(*s1);
		}
		string answer = "";
		cout << "Would you like to enter another Show? Enter (y/n)";
		cin >> answer;
		if (answer == "n") {
			cout << endl;
			break;
		}
	}
}