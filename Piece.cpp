#include <iostream>
#include "Piece.h"

using namespace std;

Piece::Piece() {
    type = ' ';
    color = ' ';
}

Piece::Piece(char t, char c) {
    type = t;
    color = c;
}

void Piece::print() {
    if (type == ' ') {
        std::cout << "   ";
        return;
    }

    if (color == 'w') {
        switch (type) {
        case 'p': std::cout << "\033[38;5;231m ♙  "; break;
        case 'r': std::cout << "\033[38;5;231m ♖  "; break;
        case 'n': std::cout << "\033[38;5;231m ♘  "; break;
        case 'b': std::cout << "\033[38;5;231m ♗  "; break;
        case 'q': std::cout << "\033[38;5;231m ♕  "; break;
        case 'k': std::cout << "\033[38;5;231m ♔  "; break;
        }
    }
    else {
        switch (type) {
        case 'p': std::cout << "\033[38;5;17m ♟  "; break;
        case 'r': std::cout << "\033[38;5;17m ♜  "; break;
        case 'n': std::cout << "\033[38;5;17m ♞  "; break;
        case 'b': std::cout << "\033[38;5;17m ♝  "; break;
        case 'q': std::cout << "\033[38;5;17m ♛  "; break;
        case 'k': std::cout << "\033[38;5;17m ♚  "; break;
        }
    }
}

