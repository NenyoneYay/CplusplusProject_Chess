#include <iostream>
#include <string>
#include <map> //this library includes dictionaries! Call it with map
#include <vector>
#include <algorithm>
#include "Piece.h"
#include <windows.h>

using namespace std;


//Initialize functions
string switchPlayer(string player) {
    if (player == "white") {
        return "black";
    }
    else
    {
        return "white";
    }
}

bool checkValidMove(string userMove, string player, vector<vector<Piece>>& board) {
    
    if (userMove.size() < 4) {
        throw std::invalid_argument("Invalid move string: '" + userMove + "'");
    }

    //Convert the string into move format "e2 e4"
    std::string startSquare = userMove.substr(0, 2);
    std::string endSquare   = userMove.substr(userMove.length() - 2, 2);

    char startingColumnChar = startSquare[0];
    char startingRowChar    = startSquare[1];

    char endingColumnChar   = endSquare[0];
    char endingRowChar      = endSquare[1];

    int startingRowInt = startingRowChar - '1';
    int endingRowInt = endingRowChar - '1';

    int startingColumnInt = startingColumnChar - 'a';
    int endingColumnInt = endingColumnChar - 'a';

    Piece selectedPiece = board[startingColumnChar][startingRowChar];

    //Check to make sure move is in the bounds of the chess board
    if (startingRowInt < 0 || startingRowInt > 7 ||
    endingRowInt < 0 || endingRowInt > 7 ||
    startingColumnInt < 0 || startingColumnInt > 7 ||
    endingColumnInt < 0 || endingColumnInt > 7) {

        cout << "Move out of bounds!" << endl;
        return false;
    }



    //Check to make sure the selected piece is the right color (don't move black pieces on whites turn)
    if (selectedPiece.type == 'w')
    {
        if (player == "black")
        {
            cout << "Cannot move white piece on black's turn" << endl;
            return false;
        }
    }
    if (selectedPiece.type == 'b')
    {
        if (player == "white")
        {
            cout << "Cannot move black piece on white's turn" << endl;
        }
    }

    return true;
}

/*
    * Prompts the user to input a move,
    * then checks to see if that move is valid
    * by calling checkValidMove with their
    * response as the input of that function.
    Input: none
    Returns: a string in chess notation (kinda)
*/
string getUserMove() {

    string userResponse;
    // bool validMove = true; //TODO: change this to false when we add move logic
    cout << "Type in your desired move and hit enter TESTING" << endl;
    cin >> userResponse;
    // do {
    //     validMove = checkValidMove(userResponse);
    //     cout << endl;
    // } while (!validMove);
    // cout << "Testing: " << userResponse;
    return userResponse;
}

void movePiece(string userMove, vector<vector<Piece>>& board) {

    if (userMove.size() < 4) {
        throw std::invalid_argument("Invalid move string: '" + userMove + "'");
    }



    std::string startSquare = userMove.substr(0, 2);
    std::string endSquare   = userMove.substr(userMove.length() - 2, 2);

    char startingColumnChar = startSquare[0];
    char startingRowChar    = startSquare[1];

    char endingColumnChar   = endSquare[0];
    char endingRowChar      = endSquare[1];

    int startingRowInt = startingRowChar - '1';
    int endingRowInt = endingRowChar - '1';

    int startingColumnInt = startingColumnChar - 'a';
    int endingColumnInt = endingColumnChar - 'a';

    if (startingRowInt < 0 || startingRowInt > 7 ||
    endingRowInt < 0 || endingRowInt > 7 ||
    startingColumnInt < 0 || startingColumnInt > 7 ||
    endingColumnInt < 0 || endingColumnInt > 7) {

        cout << "Move out of bounds!" << endl;
        return;
    }


    Piece selectedPiece = board[startingRowInt][startingColumnInt];
    board[startingRowInt][startingColumnInt] = Piece();
    board[endingRowInt][endingColumnInt] = selectedPiece;
    return;
}

int mainMenu() {

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

void displayHelpMenu(){
    cout << "HELP MENU" << endl;
    cout << "The format for your moves should be similar to this: e2,e4" << endl;
    cout << "The above command moves whatever piece is on e2 onto the square e4." << endl;
    cout << "You can exit the program at any time by typing 'exit'" << endl;
    //TODO: Add instructions for saving and loading
    return;
}

/*
    * sets up the board in the starting position with all pieces on their starting squares.
    * Input: none
    * Output: The board, represented by a vector of vectors [row][column]
*/
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
    cout << endl;
    for (int i = 7; i >= 0; i--) {
        cout << (i + 1) << " ";
        for (int j = 0; j <= 7; j++) {
            bool lightSquare = (i + j) % 2 == 0;

            if (lightSquare)
            {
                std::cout << "\033[48;5;180m"; // light background
            }
            else 
            {
                std::cout << "\033[48;5;94m"; // dark background
            }
            // cout << " ";
            board[i][j].print();
            // cout << " ";
        }
        std::cout << "\033[0m";
        cout << endl;
    }
    cout << "   a  b  c  d  e  f  g  h" << endl;
    cout << endl;

}

//End initialize functions

//Begin main
int main() {
    //Initialize variables at the start of the game
    SetConsoleOutputCP(CP_UTF8);

    int stillPlaying = 1;
    string currentPlayer = "white";
    vector<vector<Piece>> playBoard = initializeBoard();

    //Begin main menu
    int mainMenuUserChoice = mainMenu();
    if (mainMenuUserChoice == 0) 
    {
        cout << "Ending program";

        return 0;
    }
    string userResponse; //TODO: change this to a string to search for valid commands



    while (stillPlaying) { 
        displayBoard(playBoard); //Show the board to the player
        cout << "Current player: " << currentPlayer << endl; //Display the current player who can move next
        userResponse = getUserMove();

        if (userResponse == "0" || userResponse == "exit") //Failsafe: have a way to end the code
        {
            cout << "Ending program" << endl;
            break;
        }
        if (userResponse == "help")
        {
            displayHelpMenu();
            continue;
        }
        if (userResponse.size() < 4) {
            cout << "Invalid move format. Try e2e4 or e2 e4" << endl;
            continue;
        }

        if (!checkValidMove(userResponse, currentPlayer, playBoard))
        {
            continue;
        }

        movePiece(userResponse, playBoard);
        currentPlayer = switchPlayer(currentPlayer);
    }
    return 0;
}

