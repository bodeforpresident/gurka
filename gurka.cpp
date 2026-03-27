#include <iostream>
#include <vector>
using namespace std;

/* TO DO LIST
1. Start screen (COMPLETED)
2. Name input 
3. Gameplay 
4. Bot players 
5. Ascii art 
*/

void titleCard(int& startScreenChoice); // Title screen function
void instructions(int& instChoice); // Instruction function

int main() {
    // Variables
    int startScreenChoice, instChoice;
    
    // Card values
    int h2, d2, s2, c2 = 2;
    int h3, d3, s3, c3 = 3;
    int h4, d4, s4, c4 = 4;
    int h5, d5, s5, c5 = 5;
    int h6, d6, s6, c6 = 6;
    int h7, d7, s7, c7 = 7;
    int h8, d8, s8, c8 = 8;
    int h9, d9, s9, c9 = 9;
    int h10, d10, s10, c10 = 10;
    int hJ, dJ, sJ, cJ = 11;
    int hQ, dQ, sQ, cQ = 12;
    int hK, dK, sK, cK = 13;
    int hA, dA, sA, cA = 14;
    
    // actual everything
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
    cout << "======================\n";
    cout << "1. Start the Game\n";
    cout << "2. How to Play\n";
    cout << "3. Quit\n";
    cout << "======================\n";
    cout << "Choose a number: ";
    cin >> startScreenChoice;}

// instruction function
void instructions(int& instChoice) {
    cout << "======================\n";
    cout << "     instructions\n";
    cout << "======================\n";
}
