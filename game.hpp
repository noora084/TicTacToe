#ifndef GAME
#define GAME

#include <vector>

class Game{
    private:
    char board[3][3] ; 
    char currentPlayer ; 
    public:
        Game() ;
        void displayBoard() ; 
        bool move(int row , int cel) ; 
        bool win() ; 
        bool checkDraw() ; 
        void switchPlayer() ; 
        void Play() ; 
};


















#endif