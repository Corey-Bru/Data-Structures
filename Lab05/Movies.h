#pragma once
#include <iostream>
#include <string>
using namespace std;
class Movie{
	private:
		string Title = "";
		string Description = "";
		string Credits = "";
		double Rating = 0;
		//assume run time is an int and in minutes
		int RunTime = 0;
	public:
		//Getters 
		string getTitle() { 
			return Title;
		}
		string getDescription() {
			return Description;
		}
		string getCredits() {
			return Credits;
		}
		double rating() {
			return Rating;
		}
		int runTime() {
			return RunTime;
		}
		//Setters 
		void setTitle(string title) {
			Title = title;
		}
		void setDescription(string description) {
			Description = description;
		}
		void setCredits(string credits) {
			Credits = credits;
		}
		void setRating(double rating) {
			Rating = rating;
		}
		void setRunTime(int runTime) {
			RunTime = runTime;
		}
		
		//Overriding Play
		void Play() {
			
			cout << "Rating: " << Rating << endl;
			cout << "Run Time: " << RunTime << endl;
			cout << "Credits: " << Credits << endl;
			
		}	
		
	};