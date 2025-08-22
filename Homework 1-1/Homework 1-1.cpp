

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//1. Ask the user for the name of the file to be processed.
//2. Attempt to open the file of the given name.If unsuccessful, it should output an error
//message and prompt the user to enter another file name.
//3. With the file open, read into a Structure :
//a.Title
//b.Author full name(the name is stored in the file as First and Last name with a
//	space between)
//	c.Word Count(total number of words in the book contents.A word is one or more
//		letters(not counting punctuation) separated by a space so ice cream is considered
//		2 words)
//	d.Letter frequency(this is the number of times each letter has been encountered in
//		the book contents)
//	e.Line Count(count of new line characters in the contents section)
//	4. Save this information in the file CardCatalog.txt
//	a.If the file doesn’t exist, create it.
//	b.If the file does exist, append to it.
//	c.Leave a blank line between each card catalog entry.
//	d.The file should be human readable such as(is should be similar but not
//		necessarily the same as the followingi) :
//Title: Moby Dick
//Full Author : Herman Melville
//Author First Name : Herman
//Author Last Name : Melville
//Word count : 375
//Line count : 17
//5. Ask the user if they want to see the letter frequency.If they agree, it should look likeii :
//Moby Dick letter frequency :
//a: 0.0762 %
//b : 0.0 %
//c : 0.0253 %
//d : 0.0405 %
//6. Ask the user if they wish to process another book.If they do, repeat requirement 2. If
//they don’t, program should quit.This should not add to previous results.
struct cardCatalog
{
	string Title;
	string Author;
	int wordCount;
	int lineCount;
	int letterFrequency;

};
int numOfLines(ifstream &file) {
	int count = 0;
	string words = "";
	int countEmptySpaces = 0;
	while (true) {
		file >> words;
		if (words == "Contents:") {
			break;
		}  
	}
	while (getline(file, words)) {
		if (words == "." || words == "," || words == "?" || words == "!" || words == "-" || words == "'" || words == "\"") {
			continue;
		}
		if (words != " ") {
			count += 1;
			continue;
		}
	}
	return count - 1; 
}

int numOfWords(ifstream& file) {
	int count = 0;
	string words = "";
	while (true) {
		file >> words;
		if (words == "Contents:") {
			break;
		}
	}
	while (file >> words) {
		if (words == "." || words == "," || words == "?" || words == "!" || words == "-" || words == "'" || words == "\"") {
			continue;
		}
		for (int iterate = 1; iterate < words.size(); iterate++) {
			
			if (words.at(iterate - 1) == '-') {
				if (words.at(iterate) == '-') {
					
					count += 1;
					break; 
				}
			}
		}
		if (words != " ") {
			count += 1;
		}
	}
	return count;
}
void letterFreq(ifstream& file, cardCatalog Info, string answer) {
	int characterCount = 0;
	char letter = '0';
	string word = "";
	char alphabet[26];
	vector <double> appearance;
	appearance.resize(26,0);

	int numberSpace = 0;
	//https://stackoverflow.com/questions/18152136/iterate-alphabet-in-c-c
	for (int i = 0; i < 26; ++i) {
		alphabet[i] = 'a' + i;
		//cout << alphabet[i] << endl;
	}

	while (file >> word) {
		if (word == "Contents:") {
			break;
		}
	}
	char placeHolder = '0';
	while (file >> word) {
		for (int i = 0; i < word.size(); i++) {
			characterCount += 1;
		}
	}

	//cout << "Over here" << charactertCount << endl;
	file.clear();
	file.seekg(0);
	while (file >> word) {
		if (word == "Contents:") {
			break;
		}
	}
	string thing = "";
	while(file.get(placeHolder)){
		if (placeHolder < 'a' || placeHolder > 'z') {
			if (placeHolder == '\n' || placeHolder == '-') {
				continue;
			}
			placeHolder = placeHolder + 32;
		}
		for (int i = 0; i < 26; i++) {
			//cout << alphabet[i] << endl;
			if (placeHolder == alphabet[i]) {
				appearance[i] = appearance[i] + 1;
				break;
			}
		}
	}

	if (answer == "y") {
		for (int i = 0; i < appearance.size(); i++) {
			cout << alphabet[i] << ": " << (appearance[i] / characterCount) * 100 << endl;
		}
	}

}
int main()
{

	cardCatalog fileInfo;
	
	string userFileName = "";
	ifstream InputData;
	while (true) {
		cout << "Please enter the name of the file: ";
		while (true) {
			cin >> userFileName;
			InputData.open(userFileName);
			if (InputData.fail() == false) {
				break;
			}
			cout << "Please enter a valid file name: ";
		}
		ofstream OutputData;
		OutputData.open("CardCatelog.txt", ios::app);
		if (OutputData.fail() == true) {
			cout << "Error could not open file";
			return 0;
		}
		fileInfo.lineCount = numOfLines(InputData);
		//https://stackoverflow.com/questions/5343173/returning-to-beginning-of-file-after-getline
		InputData.clear();
		InputData.seekg(0);
		
		getline(InputData, fileInfo.Title);
		getline(InputData, fileInfo.Author);
		
		InputData.clear();
		InputData.seekg(0);
		
		fileInfo.wordCount = numOfWords(InputData);
		
		InputData.clear();
		InputData.seekg(0);

		string answer = "";
		cout << "Would you like to see letter frequency (y/n): ";
		cin >> answer;

		letterFreq(InputData, fileInfo, answer);


		OutputData << "Title: " << fileInfo.Title << endl;
		OutputData << "Full Author: " << fileInfo.Author << endl;
		char getSpace = '0';
		for (int i = 0; i < fileInfo.Author.size(); i++) {
			getSpace = fileInfo.Author.at(i);
			if (getSpace == ' ') {
				OutputData << "Author First Name: " << fileInfo.Author.substr(0, i) << endl;
				OutputData << "Author Last Name: " << fileInfo.Author.substr(i + 1, fileInfo.Author.length()) << endl;
			}

		}
		OutputData << "Word Count: " << fileInfo.wordCount << endl;
		OutputData << "Line Count: " << fileInfo.lineCount << endl;
		OutputData << "---------------------------------------" << endl;

		cout << "Would you like to process another book (y/n): ";
		string process = "";
		cin >> process;
		if (process == "n") {
			InputData.close();
			OutputData.close();
			break;
		}
		InputData.close();
	}
	
}
