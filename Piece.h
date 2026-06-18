#ifndef PIECE_H
#define PIECE_H

class Piece {
public: 
    char type;
    char color;

    Piece();
    Piece(char t, char c);

    void print();
};

#endif