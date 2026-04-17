#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printCard(int val, string suit); // prints correct suit & card vaues
void dealHand(vector<int>& hand, vector<string>& suits); // deals hands
int findLowest(vector<int>& hand); // finds the lowest card for when bot/player can't match or play higher
int findPlayable(vector<int>& hand, int highest); // finds the highest card if the user can play it
void playGame(); // entire game function
void instructions(); // instructions function
void credits(); // credits function

int main() {

	// variables
	int startScreenChoice;
	srand(time(0));

	// startscreen
	cout << "=======================\n";
	cout << "gurka!\n";
	cout << "=======================\n";
	cout << "[1] begin game\n";
	cout << "[2] read instructions\n";
	cout << "[3] read credits\n";
	cout << "=======================\n";

	cin >> startScreenChoice;
	cout << "=======================\n";

	// input validation
	while (cin.fail() || startScreenChoice < 1 || startScreenChoice > 3) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "try again: ";
		cin >> startScreenChoice;
		cout << "=======================\n";
	}
    
	// user input section
	if (startScreenChoice == 2) {
		instructions();
	} else if (startScreenChoice == 3) {
		credits();
	}
	playGame();
}

void instructions() {
	cout << "instructions\n";
	cout << "=============================\n";
	cout << "The game is played using a standard deck of 52\n";
	cout << "cards. there can be from 3 to 8 players per game\n";
	cout << "a hand of 6 cards is dealt to each player one\n"; // wow
	cout << "at a time. Play is clockwise and begins with\n";
	cout << "the player to the dealers left. Any card may be\n"; // these sure are
	cout << "led. Other players in turn must either play\n";
	cout << "a card that is at least as high as the highest\n";  // instructions
	cout << "card so far played to the trick, or play their lowest\n";
	cout << "card. The trick is won by the highest card played to it\n";  // to play gurka
	cout << "and if several equally high cards are played, by the last\n";
	cout << "of those. Whoever has the highest card in the last\n";
	cout << "trick scores that many penalty points (J=11, Q=12,\n";
	cout << "K=13, A=14). If two or more players have equally high\n";
	cout << "cards in the last trick they score that number of penelty\n";
	cout << "points. Any player who reaches a cumulative score of 30 points\n";
	cout << "is out of the game: the player is said to be a cucumber\n";
	cout << "=============================\n";
}

void credits() {
	cout << "credits\n";
	cout << "=============================\n";
	cout << "coded by ryan and bode\n";
	cout << "=============================\n";
}

void playGame() {
	// player point variables
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	
	// names
	string userName;
	string bot1Name;
	string bot2Name;
	int botNameValue;
	
	// names input
    cout << "enter your name: ";
    cin >> userName;
    cout << "type 1 to use custom names for bots, type 2 to use default: ";
    cin >> botNameValue;
    if (botNameValue == 1) {
        cout << "enter bot 1's name: ";
        cin >> bot1Name;
        cout << "enter bot 2's name: ";
        cin >> bot2Name;
    } else if (botNameValue == 2) {
        bot1Name = "bot 1";
        bot2Name = "bot 2";
    }
    

	// loop game while score is under 30
	while (p1 < 30 && p2 < 30 && p3 < 30) {

		// hands and suits
		vector<int> h1, h2, h3;
		vector<string> s1, s2, s3;

		// dealing
		dealHand(h1, s1);
		dealHand(h2, s2);
		dealHand(h3, s3);

		// round value
		int round = 0;

		// rounds 1-5
		while (round < 6) {

			cout << "ROUND " << round + 1 << "\n";
			cout << "=======================\n";

			int highest = 0;

			// display hand
			cout << userName << "'s hand\n";
			cout << "=======================\n";
			for (int i = 0; i < h1.size(); i++) {
				cout << "[" << i << "] ";
				printCard(h1[i], s1[i]);
			}

			// player choice
			int choice;
			cout << "=======================\nchoose a card: ";
			cin >> choice;
			cout << "=======================\n";

			// input validation
			while (cin.fail() || choice < 0 || choice >= h1.size()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "try again: ";
				cin >> choice;
			}

			int userCard = h1[choice];
			cout << userName << " played: ";
			printCard(userCard, s1[choice]);

			highest = userCard;

			// erase used cards from array
			h1.erase(h1.begin() + choice);
			s1.erase(s1.begin() + choice);


			int i2 = findPlayable(h2, highest);
			int c2 = h2[i2];

			//  bot actions
			cout << bot1Name << " played: ";
			printCard(c2, s2[i2]);

			if (c2 > highest) highest = c2;

			h2.erase(h2.begin() + i2);
			s2.erase(s2.begin() + i2);

			int i3 = findPlayable(h3, highest);
			int c3 = h3[i3];

			cout << bot2Name << " played: ";
			printCard(c3, s3[i3]);

			if (c3 > highest) highest = c3;

			h3.erase(h3.begin() + i3);
			s3.erase(s3.begin() + i3);

			// special round 6
			if (round == 5) {
				cout << "=======================\n";

				if (userCard == highest) {
					cout << userName << " takes " << highest << " points\n";
					p1 += highest;
				}
				if (c2 == highest) {
					cout << bot1Name << " takes " << highest << " points\n";
					p2 += highest;
				}
				if (c3 == highest) {
					cout << bot2Name << " takes " << highest << " points\n";
					p3 += highest;
				}
			}

			// add to round counter
			round++;
		}

		// output scores
		cout << "=======================\n";
		cout << "SCORES\n";
		cout << "=======================\n";
		cout << userName << ": " << p1 << "\n";
		cout << bot1Name << ": " << p2 << "\n";
		cout << bot2Name << ": " << p3 << "\n";
	}

	// cucumber!
	if (p1 >= 30) cout << userName << " are a cucumber!\n";
	if (p2 >= 30) cout << bot1Name << " is a cucumber!\n";
	if (p3 >= 30) cout << bot2Name << " is a cucumber!\n";
}

void printCard(int val, string suit) {
	if (val < 11) cout << val << suit; // if under 11 normal output
	else if (val == 11) cout << "jack" << suit;
	else if (val == 12) cout << "queen" << suit;
	else if (val == 13) cout << "king" << suit;
	else if (val == 14) cout << "ace" << suit;
}

void dealHand(vector<int>& hand, vector<string>& suits) {
	for (int i = 0; i < 6; i++) { // do while less than six cards
		int v = rand() % 13 + 2;
		int s = rand() % 4;
		string suit;

		if (s == 0) suit = " of diamonds\n";
		if (s == 1) suit = " of hearts\n";
		if (s == 2) suit = " of clubs\n";
		if (s == 3) suit = " of spades\n";

		hand.push_back(v);
		suits.push_back(suit);
	}
}

int findLowest(vector<int>& hand) {
	int n1 = 0;
	for (int i = 1; i < hand.size(); i++) {
		if (hand[i] < hand[n1]) n1 = i;
	}
	return n1;
}

int findPlayable(vector<int>& hand, int highest) {
	int n2 = -1;

	for (int i = 0; i < hand.size(); i++) {
		if (hand[i] >= highest) { // if hand has any card greater than or equal to, play
			if (n2 == -1 || hand[i] < hand[n2]) {
				n2 = i;
			}
		}
	}

	if (n2 == -1) n2 = findLowest(hand); // if no card is found, find lowest

	return n2; // output lowest
}
