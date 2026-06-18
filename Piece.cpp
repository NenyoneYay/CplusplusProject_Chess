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
    cout << color << type;
}
