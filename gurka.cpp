#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
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
void deckShuffle(int& fullDeck);

int main() {
	srand(time(0));    
	// Variables
	int startScreenChoice, instChoice;

	// Card values
    int h2 = 1;
    int h3 = 2;
    int h4 = 3;
    int h5 = 4;
    int h6 = 5;
    int h7 = 6;
    int h8 = 7;
    int h9 = 8;
    int h10 = 9;
    int hJ = 10;
    int hQ = 11;
    int hK = 12;
    int hA = 13;
    int d2 = 14;
    int d3 = 15;
    int d4 = 16;
    int d5 = 17;
    int d6 = 18;
    int d7 = 19;
    int d8 = 20;
    int d9 = 21;
    int d10 = 22;
    int dJ = 23;
    int dQ = 24;
    int dK = 25;
    int dA = 26;
    int s2 = 27;
    int s3 = 28;
    int s4 = 29;
    int s5 = 30;
    int s6 = 31;
    int s7 = 32;
    int s8 = 33;
    int s9 = 34;
    int s10 = 35;
    int sJ = 36;
    int sQ = 37;
    int sK = 38;
    int sA = 39;
    int c2 = 40;
    int c3 = 41;
    int c4 = 42;
    int c5 = 43;
    int c6 = 44;
    int c7 = 45;
    int c8 = 46;
    int c9 = 47;
    int c10 = 48;
    int cJ = 49;
    int cQ = 50;
    int cK = 51;
    int cA = 52;

	// Deck vector
	vector<int> fullDeck = {h2, d2, s2, c2, h3, d3, s3, c3, h4, d4, s4, c4, h5, d5, s5, c5, h6, d6, s6, c6, h7, d7, s7, c7, h8, d8, s8, c8, h9, d9, s9, c9, h10, d10, s10, c10, hJ, dJ, sJ, cJ, hQ, dQ, sQ, cQ, hK, dK, sK, cK, hA, dA, sA, cA};

	// Deck shuffle
	int c = 0;
	while (c < 6) {
	int randPos = rand() % fullDeck.size();
	int randCd = fullDeck[randPos];
	
	cout << randCd << "\n";
	c++;
	}

	return 0;

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
	cin >> startScreenChoice;
}

// instruction function
void instructions(int& instChoice) {
	cout << "======================\n";
	cout << "     instructions\n";
	cout << "======================\n";
}
