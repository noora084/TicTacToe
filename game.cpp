#include <vector>
#include <iostream>
#include "game.hpp"

using namespace std ; 

Game::Game(): currentPlayer('X'){
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                board[i][j] = ' ';
            }
        }
}
void Game::displayBoard() {
    cout << "Current board state:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j){
            cout << board[i][j];
            if (j < 2)
                cout << "|";
        }
        cout << endl;
        if (i < 2)
            cout << "-+-+-\n";
    }
}
bool Game::move(int row, int col){// Check if moves are valid
    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
        cout << "Invalid move! Try again.\n";
        return false;
    }
    board[row-1][col-1] = currentPlayer;
    return true;
}
bool Game::win(){
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][0] == currentPlayer && board[0][1] == currentPlayer && board[0][2] == currentPlayer)
        return true;
    if (board[0][0] == currentPlayer && board[1][0] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    if (board[0][1] == currentPlayer && board[1][1] == currentPlayer && board[2][1] == currentPlayer)
        return true;
    if (board[1][0] == currentPlayer && board[1][1] == currentPlayer && board[1][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    if (board[2][0] == currentPlayer && board[2][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][2] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    return false;
}

bool Game::checkDraw(){
    // Check if all cells are filled = draw
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}
void Game::switchPlayer(){
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
void Game::Play(){
    int row , col ; 
    while (true){
        displayBoard() ; 
        cout << "player " << currentPlayer << " enter your move: " ;
        cin >> row >> col ; 
        if(!move(row , col))
            continue;
        if(win()){
            displayBoard() ; 
            cout << "Player " << currentPlayer << " wins!\n";
            break  ;
        }
        if(checkDraw()){
            displayBoard() ; 
            cout << "its a draw!\n" ; 
            break ; 
        }
        switchPlayer() ; 


    }
    
}






