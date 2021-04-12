#include <iostream>
#include <stdlib.h>
#include "Othello.h"
using namespace std;


Othello::Othello(){

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i == 3 && j == 3) || (i== 4 && j == 4)){
                board[i][i] = noir
                    ;
            }
            else if ((i == 3 && j == 4) || (i == 4 && j == 3)) {
                board[i][j] = blanc
                    ;
            }
            else {
                board[i][j] = vide;
            }
            lbord[i][j] = true; // initialistation de la table lbord 

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
    cout << "Board OTHELLO" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}
void Othello::move(){
    char lg;
    char col;
    int i;
    int j;
    cout << "tour du pion " << turn << endl;
    cout << "entrez la ligne: ";
    cin >> lg;
    cout << "entre la colonne: ";
    cin >> col;
    i = lg - 49;
    j = col - 49;
    if (mouvement_legal(i,j)) {
        board[i][j] = turn;
    }
}