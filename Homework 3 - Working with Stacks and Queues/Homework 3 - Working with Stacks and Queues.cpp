// Homework 3 - Working with Stacks and Queues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Deck.h"
#include "SidePile.h"
#include "String.h"
#include <random>
using namespace std;

bool turn(bool player){
    if(player == true){
        return false;
    }else{
        return true;
    }
}

int main()
{
    //Assume that anything above the number 10 is Jack, Queen, King, and Ace respectively
    //The user may change the number of cards in each deck and the number of rounds they desire
    int cards[13] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int playerDeck = 4;
    int cpuDeck = 4;
    int rounds = 20;
    int playerWins = 0;
    int cpuWins = 0;


    Deck<int> player;
    Deck<int> CPU;
    SidePile<int> sidePile;

    //Assume that the deck does not have a certain number of each type of cards (each draw is completely random)
    //Assuming that the winner is the one who wins the most amount of rounds (regardless of how many cards they have)

    cout << "HOW TO WIN: " << endl;
    cout << "There are " << rounds << " rounds, whoever wins the most rounds wins the game." << endl;
    cout << "Don't run out of cards in both your deck and pile or you lose (the CPU also loses if it runs out of cards)" << endl;

    cout << endl;

    cout << "GAME STARTS:" << endl;

    cout << endl;


    for (int i = 0; i < rounds; i++) {
        if((playerDeck <= 0 && sidePile.length() == 0) || cpuDeck == 0){
            break;
        }
        if (playerDeck <= 0 && sidePile.length() > 0) {
            cout << "Oh no, your deck is empty. Moving all side pile cards to your deck..." << endl;
            playerDeck += sidePile.length();
            while (sidePile.length() > 0) {
                sidePile.pop();
            }
            cout << "You now have " << playerDeck << " cards in your deck and " << sidePile.length() << " cards in your side pile. " << endl;
            cout << "Don't run out of both decks or you lose." << 
            endl;
            cout << endl;
        }
        cout << "Round " << i + 1 << endl;
        int random = rand() % 13;

        //player pulls a card from the deck then the number of cards in the player's deck decrements by 1
        player.enqueue(cards[random]);
        playerDeck--;
        int playerSum = 0;
        string answer = "";
        while (answer != "y" && answer != "n") {
            cout << "Would you like to peek at your card? (y/n)" << endl;
            cin >> answer;
        }
        if (answer == "y") {
            if (player.peek() > 10) {
                if (player.peek() == 11) {
                    cout << "The next card in your pile is: 'Jack'" << endl;
                }
                else if (player.peek() == 12) {
                    cout << "The next card in your pile is: 'Queen'" << endl;
                }
                else if (player.peek() == 13) {
                    cout << "The next card in your pile is: 'King' " << endl;
                }
                else {
                    cout << "The next card in your pile is: 'Ace' " << endl;
                }
            }
            else {
                
                cout << "The next card in your pile is: " << player.peek() << endl;
                cout << "Would you like to pull another card from the pile or put this card into your side pile?" << endl;
            }
            string answer = "";
            while (answer != "a" && answer != "s") {
                cout << "Enter 'a' for another card or 's' for side pile." << endl;
                cin >> answer;
                while (answer == "a" && sidePile.length() == 0) {
                    cout << "There are no cards left in your side pile, enter 's' to put a card in your side pile." << endl;
                    cin >> answer;
                }
            }
            if (answer == "a") {
                playerSum = player.peek() + sidePile.top();
                player.enqueue(sidePile.pop());
                cout << "You pulled a " << player.peek() << "from the deck. " << endl;
            }
            else if(answer == "s" && playerDeck > 0) {
                sidePile.push(player.dequeue());
                random = rand() % 13;
                playerSum = cards[random];
                player.enqueue(cards[random]);
                playerDeck--;
            }
        }
        else {
            playerSum = player.peek();
        }

        random = rand() % 13;
        CPU.enqueue(cards[random]);
        cpuDeck--;

        cout << "PLAYER CARD TOTAL: " << endl;
        cout << playerSum << endl;

        cout << "..." << endl;

        cout << "CPU CARD TOTAL: " << endl;
        cout << CPU.peek() << endl;

        cout << "..." << endl;


        if (CPU.peek() < playerSum) {
            cout << "You win this round! " << endl;
            playerWins++;
            player.enqueue(CPU.dequeue());
            playerDeck++;
        }
        else if (CPU.peek() >= playerSum) {
            cout << "You lost gimme your cards" << endl;
            if (player.length() == 2) {
                player.dequeue();
                player.dequeue();
                cpuDeck += 2;
            }
            else {
                player.dequeue();
                cpuDeck++;
            }
            cpuWins++;
        }

        cout << "You now have " << playerDeck << " cards left in your deck." << endl;
        cout << "You have " << sidePile.length() << " cards in your side pile." << endl;
        cout << "Your opponent has " << cpuDeck << " cards left in their deck." << endl;
        cout << endl << "----------------------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }

    //GAME OVER, calculating who won:

    if (playerDeck <= 0) {
        cout << "hahaha, you ran out of cards, idk how you managed that" << endl;
        cout << "GAME OVER!" << endl;
    }
    if (cpuDeck <= 0) {
        cout << "The CPU managed to run out of cards." << endl;
        cout << "YOU WIN!" << endl;
    }

}