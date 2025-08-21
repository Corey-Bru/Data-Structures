#include <ioStream>
#include "Shelf.h"
#include "Movies.h"
using namespace std;
int main() {
    Movie mov[max_book];
	Shelf h;

    while (true) {
        //Grabs the index position of the shelf
        int index = h.getNumOfMov();
        int userInput = 0;

        while (userInput < 1 || userInput > 4) {
            cout << "Press 1 to add a movie to the shelf." << endl;
            cout << "Press 2 remove a movie from the shelf." << endl;
            cout << "Press 3 see how many movies are currently on the shelf." << endl;
            cout << "Press 4 to quit." << endl;
            cin >> userInput;            
        }

        if (userInput == 1) {
            try {
                h.add(mov[index]);
            } catch (int error) {
                cout << "Exited with Error " << error << ", shelf is full" << endl;
            }
        }
        else if (userInput == 2) {
            h.remove(mov);
        }
        else if (userInput == 3) {
            cout << "There are " << h.getNumOfMov() + 1 << " movies on the shelf." << endl;
        }
        else {
            break;
        }
    }
    h.viewShelf();
}