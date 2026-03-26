#include <iostream>
using namespace std;

/* TO DO LIST
1. Start screen
2. Name input
3. Gameplay
4. Bot players
5. Ascii art
*/

void titleCard(int& startScreenChoice);

int main() {
    // Variables
    int startScreenChoice;
    
    
    titleCard(startScreenChoice);
    if (startScreenChoice == )
}

void titleCard(int& startScreenChoice) {
    cout << "==========================================\n";
    cout << "|                                    ### |\n";
    cout << "|  ####  #    # #####  #    #   ##   ### |\n";
    cout << "| #    # #    # #    # #   #   #  #  ### |\n";
    cout << "| #      #    # #    # ####   #    #  #  |\n";
    cout << "| #  ### #    # #####  #  #   ######     |\n";
    cout << "| #    # #    # #   #  #   #  #    # ### |\n";
    cout << "|  ####   ####  #    # #    # #    # ### |\n";
    cout << "==========================================\n\n";
    cout << "1. Start the Game\n";
    cout << "2. How to Play\n";
    cout << "3. Quit\n\n";
    cout << "==========================================\n\n";
    cout << "Choose a number: ";
    cin >> startScreenChoice;
}
