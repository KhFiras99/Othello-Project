#pragma once
#include <iostream>
using namespace std;
#define vide '0'
#define noir '1'
#define blanc '2'

#include "Player.h"
#ifndef OTHELLO_H
#define OTHELLO_H

class Othello {
private:
	char board[8][8]; // position tableau
	bool lbord[8][8];
	int score_noir; // score du joueur noir 
	int score_blanc; // score du joueur blanc
	bool finished;  // partie terminé
	char turn;  // tour du joueur 
	int nblegalmoves; // nombre de mouvements legals
public:
	Othello();
	~Othello();
	void passe_tour();  // tour de role 
	bool pass(); // forcer le passage de tour de role (return true si le joueur doit passer et false si le jeu est fini )
	bool mouvement_legal(char x, char y) { return lbord[x][y]; } 
	int update_mouvement_legal();
	void jeu_termine(); // declencher la fin du jeu 
	void printBoard();
	//Player gagnant();
};


#endif

