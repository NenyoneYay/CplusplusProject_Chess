#include <iostream>
#include <string>
using namespace std;

//Initialize variables at the start of the game

int stillPlaying = 1;
string currentPlayer = "white";

void displayBoard() {
    cout << "[bR] [bN] [bB] [bQ] [bK] [bB] [bN] [bR]" << endl;
    cout << "[bP] [bP] [bP] [bP] [bP] [bP] [bP] [bP]" << endl;
    cout << "[  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    cout << "[  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    cout << "[  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    cout << "[  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    cout << "[wP] [wP] [wP] [wP] [wP] [wP] [wP] [wP]" << endl;
    cout << "[wR] [wN] [wB] [wQ] [wK] [wB] [wN] [wR]" << endl;
}

string switchPlayer(string player) {
    if (player == "white") {
        return "black";
    }
    else
    {
        return "white";
    }
}

int mainMenu() {
    string userResponse;
    while(1) {
        int userResponseInt;
        cout << "Main Menu" << endl;
        cout << "Enter a number to continue: " << endl;
        cout << "0: quit program" << endl;
        cout << "1: Start game: Hotseat" << endl;
        cout << "2: Start game: CPU (coming soon)" << endl;
        cout << "3: Load game from file (coming soon)" << endl;
        cin >> userResponse;
        try {
            userResponseInt = stoi(userResponse);
        }
        catch (invalid_argument) {
            cout << "Error: " << userResponse << " is not a number. Please try again." << endl;
            cin;
            continue;
        }
        userResponseInt = stoi(userResponse);
        return userResponseInt;
    }
}

int main() {
    int mainMenuUserChoice = mainMenu();
    if (mainMenuUserChoice == 0) 
    {
        cout << "Ending program";
        return 0;
    }
    string userResponse; //TODO: change this to a string to search for valid commands
    while (stillPlaying) { 
        displayBoard(); //Show the board to the player
        cout << "Current player: " << currentPlayer << endl; //Display the current player who can move next
        cin >> userResponse;

        if (userResponse == "0") //Failsafe: have a way to end the code
        {
            cout << "Ending program" << endl;
            break;
        }
        currentPlayer = switchPlayer(currentPlayer);
    }
    return 0;
}

