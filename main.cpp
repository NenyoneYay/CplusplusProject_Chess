#include <iostream>
#include <string>
#include <map> //this library includes dictionaries! Call it with map
#include <vector>
#include "Piece.h"
using namespace std;


// { 
//     {1, ['a', 'b', 'c', 'd', 'e', 'f', 'g']},
//     {2, ['a', 'b', 'c', 'd', 'e', 'f', 'g']},
//     {1, ['a', 'b', 'c', 'd', 'e', 'f', 'g']},
//     {1, ['a', 'b', 'c', 'd', 'e', 'f', 'g']},
//     {1, ['a', 'b', 'c', 'd', 'e', 'f', 'g']},
//     {1, ['a', 'b', 'c', 'd', 'e', 'f', 'g']},
//     {1, ['a', 'b', 'c', 'd', 'e', 'f', 'g']},
//     {1, ['a', 'b', 'c', 'd', 'e', 'f', 'g']}
// }; 





string switchPlayer(string player) {
    if (player == "white") {
        return "black";
    }
    else
    {
        return "white";
    }
}

bool checkValidMove(string userResponse) {
    return true;
}

string getUserMove() {
    string userResponse;
    bool validMove = false;
    
    do {
        validMove = checkValidMove(userResponse);
        cout << endl;
    } while (!validMove);
}

int mainMenu() {
    // cout << "Testing" << rows[1] << endl;
    
    string userResponse;
    while(1) {
        int userResponseInt;
        string userResponse;
        //Display the main menu
        cout << "Main Menu" << endl;
        cout << "Enter a number to continue: " << endl;
        cout << "0: quit program" << endl;
        cout << "1: Start game: Hotseat" << endl;
        cout << "2: Start game: CPU (coming soon)" << endl;
        cout << "3: Load game from file (coming soon)" << endl;
        cin >> userResponse;
        //Make sure they put in a number
        try {
            userResponseInt = stoi(userResponse);
        }
        catch (invalid_argument) {
            cout << "Error: " << userResponse << " is not a number. Please try again." << endl;
            cin;
            continue;
        }
        //Turn the users response into an int and return that int
        userResponseInt = stoi(userResponse);
        return userResponseInt;
    }
}

vector<vector<Piece>> initializeBoard() {
    vector<vector<Piece>> board(8, vector<Piece>(8));
    //White side
    board[0][0] = Piece('r', 'w');
    board[0][1] = Piece('n', 'w');
    board[0][2] = Piece('b', 'w');
    board[0][3] = Piece('q', 'w');
    board[0][4] = Piece('k', 'w');
    board[0][5] = Piece('b', 'w');
    board[0][6] = Piece('n', 'w');
    board[0][7] = Piece('r', 'w');
    board[1][0] = Piece('p', 'w');
    board[1][1] = Piece('p', 'w');
    board[1][2] = Piece('p', 'w');
    board[1][3] = Piece('p', 'w');
    board[1][4] = Piece('p', 'w');
    board[1][5] = Piece('p', 'w');
    board[1][6] = Piece('p', 'w');
    board[1][7] = Piece('p', 'w');
    //Black side
    board[7][0] = Piece('r', 'b');
    board[7][1] = Piece('n', 'b');
    board[7][2] = Piece('b', 'b');
    board[7][3] = Piece('q', 'b');
    board[7][4] = Piece('k', 'b');
    board[7][5] = Piece('b', 'b');
    board[7][6] = Piece('n', 'b');
    board[7][7] = Piece('r', 'b');
    board[6][0] = Piece('p', 'b');
    board[6][1] = Piece('p', 'b');
    board[6][2] = Piece('p', 'b');
    board[6][3] = Piece('p', 'b');
    board[6][4] = Piece('p', 'b');
    board[6][5] = Piece('p', 'b');
    board[6][6] = Piece('p', 'b');
    board[6][7] = Piece('p', 'b');

    return board;
}

void displayBoard(vector<vector<Piece>> board) {
    cout << "[bR] [bN] [bB] [bQ] [bK] [bB] [bN] [bR]" << endl;
    cout << "[bP] [bP] [bP] [bP] [bP] [bP] [bP] [bP]" << endl;
    cout << "[  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    cout << "[  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    cout << "[  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    cout << "[  ] [  ] [  ] [  ] [  ] [  ] [  ] [  ]" << endl;
    cout << "[wP] [wP] [wP] [wP] [wP] [wP] [wP] [wP]" << endl;
    cout << "[wR] [wN] [wB] [wQ] [wK] [wB] [wN] [wR]" << endl;

    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            Piece currentPiece = board[i][j];
            currentPiece.print();
        }
        cout << endl;
    }
}


int main() {
    //Initialize variables at the start of the game

    int stillPlaying = 1;
    string currentPlayer = "white";
    vector<vector<Piece>> playBoard = initializeBoard();
    displayBoard(playBoard);
    // //They call their dictionaries maps in C++, weird.
    // map<int, vector<char>> rows = {
    //     { {1}, {'a', 'b', 'c', 'd', 'e', 'f', 'g'} }, 
    //     { {2}, {'a', 'b', 'c', 'd', 'e', 'f', 'g'} }, 
    //     { {3}, {'a', 'b', 'c', 'd', 'e', 'f', 'g'} }, 
    //     { {4}, {'a', 'b', 'c', 'd', 'e', 'f', 'g'} }, 
    //     { {5}, {'a', 'b', 'c', 'd', 'e', 'f', 'g'} }, 
    //     { {6}, {'a', 'b', 'c', 'd', 'e', 'f', 'g'} }, 
    //     { {7}, {'a', 'b', 'c', 'd', 'e', 'f', 'g'} }, 
    //     { {8}, {'a', 'b', 'c', 'd', 'e', 'f', 'g'} },   
    // };


    
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

