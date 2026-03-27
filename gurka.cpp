#include <iostream>
using namespace std;

/* TO DO LIST
1. Start screen (COMPLETED)
2. Name input 
3. Gameplay 
4. Bot players 
5. Ascii art 
*/

void titleCard(int& startScreenChoice); // Title screen function
void instructions(int& instChoice);

int main() {
    // Variables
    int startScreenChoice, instChoice;
    
    
    titleCard(startScreenChoice);
    if (startScreenChoice == 1) {
        cout << "Game here eventually"; // game
    } else if (startScreenChoice == 2) {
        instructions(instChoice);
    } else if (startScreenChoice == 3) {
        cout << "Goodbye!";
        return 0;
    }
}

// title function
void titleCard(int& startScreenChoice) {
    cout << "======================\n";
    cout << "   g  u  r  k  a  !   \n";
    cout << "======================\n\n";
    cout << "1. Start the Game\n";
    cout << "2. How to Play\n";
    cout << "3. Quit\n\n";
    cout << "======================\n\n";
    cout << "Choose a number: ";
    cin >> startScreenChoice;}

// instruction function
void instructions(int& instChoice) {
    cout << "\n";
    cout << "======================\n";
    cout << "instructions\n";
    cout << "======================\n";
    cout << ""
}
