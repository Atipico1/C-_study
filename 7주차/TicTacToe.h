#pragma once

class TicTacToe{
    #define COMPUTER 1 
    #define HUMAN 2
    #define LENG 3
    public:
        TicTacToe();
        void Board(char board[][LENG]);
        void showInstructions();
        void init(char board[][LENG]);
        void Winner(int);
        bool rowCrossed(char board[][LENG]);
        bool columnCrossed(char board[][LENG]);
        bool diagonalCrossed(char board[][LENG]);
        bool gameOver(char board[][LENG]);
    
        int minimax(char board[][LENG], int, bool);
        int bestMove(char board[][LENG], int);
        void playTicTacToe(int);

//        char board[][];
};