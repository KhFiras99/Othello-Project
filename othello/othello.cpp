#include <iostream>

#include "Othello.h"
using namespace std;


Othello::Othello(){

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i == 3 && j == 3) || (i == 4 && j == 4)){
                board[i][j] = 1;
            }
            if ((i == 3 && j == 4) || (i == 4 && j == 3)) {
                board[i][j] = 2;
            }
            else {
                board[i][j] = 0;
            }
            lbord[i][j] = false; // initialistation de la table lbord 
        }
    }
	turn = noir;
	score_blanc = 2;
	score_noir = 2;
	finished = false;
    cout << "La table est: " << endl;
    printBoard();
}
Othello::~Othello() {
    cout << " \n partie termine" << endl;
}
void Othello::passe_tour() {
    if (turn == noir) {
        turn = blanc;
    }
    else {
        turn = noir;
    }
}
bool Othello::pass() {
    passe_tour();
    if (nblegalmoves == 0 ) {
        finished = true;
        return false;
    }
    return true;
}
void Othello::jeu_termine() {
    if (finished == true) {
        cout << "Jeu Terminée  ";
    }
}
void Othello::printBoard() {
    cout << endl << endl;
    cout << "\t                       OTHELLO\n";
    cout << "\n\t     0     1     2     3     4     5     6     7  ";
    cout << "\n\t  -----*-----*-----*-----*-----*-----*-----*-----";
    for (int r = 0; r < 8; r++) {
        cout << "\n\t  |     |     |     |     |     |     |     |     |\n";
        for (int i = 0; i < 8; i++) {
            cout << board[r][i];
        }
        cout << "\n\t  |     |     |     |     |     |     |     |     |";
        cout << "\n\t  -----*-----*-----*-----*-----*-----*-----*-----";

    }
    cout << "\n\t     0     1     2     3     4     5     6     7  \n";
    cout << "\n\t     Black's Score: " << score_noir << "\t\t";
    cout << "White's Score: " << score_blanc << endl << endl << endl;
}