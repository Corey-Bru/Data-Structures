
#include "Wheel.h"
#include "Player.h"
#include <iostream>
using namespace std;
bool betting(double bet, Player p1) {

    if (p1.getMoney() >= bet && bet > 0) {
        return true;
    }
    else {
        return false;
    }
}


int main()
{
    //STARTING THE GAME (settings):

        //A variable to track whether the user has cashed out
    bool cashOut = false;

    //Creates a player/wheel for the user and a wheel for the house (player unecessary as house does not track money)
    Wheel house;
    Player user;
    //Insures that the user inputs a value between 6 and 20 for the amount of values on the wheel
    int userValues = -1;
    while (userValues < 6 || userValues > 20) {
        cout << "How many values would you like on the wheel?" << endl;
        cout << "You can have between 6 and 20 values on the wheel or Enter (-9) to use a defualt value." << endl;
        cin >> userValues;
        if (userValues == -9) {
            Wheel house();
            break;
        }
        else if (userValues < 6 || userValues > 20) {
            cout << "Invalid value entered, please input a value between 6 and 20." << endl;
        }
    }
    if (userValues != -9) {
        //Set the number of values on both the house's and user's wheel to the user input
        user.setMaxNum(userValues);
        Wheel house(userValues);
    }
    //Asks the user for how much money they would like to start out with
    double money = -1;
    while (money <= 0) {
        cout << "Please enter how much money you would like to start out with (Minimum starting value must be $1): Enter (-9) to set defualt value to $1000: " << endl;
        cin >> money;
        if (money == -9) {
            break;
        }
        else if (money <= 0) {
            cout << "Please enter a valid number. Number must be greater than 0." << endl;
        }
    }
    if (money > 0) {
        //Overloaded constructer sets money to a value
        user.setMoney(money);
    }
    //Set the number of values on both the house's and user's wheel to the user input
    user.setMaxNum(userValues);
    house.setMaxNum(userValues);


    double userBet = 0;

    //ensures that the user doesn't bet more money than they have      
    do {
        cout << "What is your starting bet?" << endl;
        cin >> userBet;

        if (betting(userBet, user)) {
            break;
        }
        cout << "You cannot bet $" << userBet << ", you only have $" << user.getMoney() << " left." << endl;
    } while (betting(userBet, user) == false);



    //PLAYING THE GAME user cashes out or runs out of money :
    while (cashOut == false && user.getMoney() > 0) {
        cout << "The player has $" << user.getMoney() << " left." << endl;

        //The player releases the ball
        int userSpin = user.spin();
        cout << endl;
        cout << "The ball landed on this number: " << userSpin << endl << endl;

        cout << "Would you like to change your bet? Enter (y/n): ";
        char changeBet = '\n';
        int houseSpin0 = house.spin();
        int houseSpin1 = 0;
        cin >> changeBet;
        char newBet = '\n';

        if (changeBet == 'y') {
            while (true) {
                cout << "To halve the bet enter (h) or to double the bet enter (d) or enter (e) to exit: ";
                cin >> newBet;
                if (newBet == 'h') {
                  
                    userBet = userBet / 2;
                    houseSpin1 = house.spin();
                    break;
                   
                }
                else if (newBet == 'd') {
                    if (betting(userBet * 2, user) == false) {
                        cout << "Cannot double bet: user doesn't have enough money." << endl;
                        continue;
                    }
                    else {
                        userBet = userBet * 2;
                        houseSpin1 = house.spin();
                        break;
                    }
                }
                else if (newBet == 'e') {
                    newBet = '\n';
                    break;
                }
                cout << "Invalid input: Must input 'h','d' or 'e'." << endl;
            }
        }
        if (newBet == 'd') {
            cout << "The House rolled: " << houseSpin0 << " and rolled: " << houseSpin1 << endl;
            if (houseSpin0 >= userSpin || houseSpin1 >= userSpin) {
                
                cout << "House won, you lose $" << userBet << endl;
                user.setMoney(user.getMoney() - userBet);
            }
            else {
                cout << "Player won, you win $" << userBet << endl;
                user.setMoney(user.getMoney() + userBet);
            }
        }
        else if (newBet == 'h') {
            cout << "The House rolled: " << houseSpin0 << " and rolled: " << houseSpin1 << endl;
            if (houseSpin0 >= userSpin && houseSpin1 >= userSpin) {
                cout << "House won, you lose $" << userBet << endl;
                user.setMoney(user.getMoney() - userBet);
            }
            else {
                cout << "User Won, no value is added." << endl;
            }
        }
        else {
            cout << "The House rolled: " << houseSpin0 << endl;
            if (houseSpin0 >= userSpin) {
                cout << "House won, you lose $" << userBet << endl;
                user.setMoney(user.getMoney() - userBet);
            }
            else {
                cout << "Player won, you win $" << userBet << endl;
                user.setMoney(user.getMoney() + userBet);
            }
        }

        if (user.getMoney() <= 0) {
            cout << "Yo you're out of money GET OUT." << endl;
            break;
        }
        //assuming the user will enter a 'y' or 'n' value.
        char quitGame = '\n';
        cout << "Would you like to cash out with $" << user.getMoney() << " left? Enter (y/n): ";
        cin >> quitGame;
        if (quitGame == 'y') {
            cout << "You cashed out with: $" << user.getMoney() << endl;
            break;
        }
    }

}
  
    
   

