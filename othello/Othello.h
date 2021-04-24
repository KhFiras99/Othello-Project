#pragma once
#include <iostream>
#include <string>
using namespace std;
#define vide '-'
#define noir '1'
#define blanc '2'

#include "Player.h"
#include "Case.h"
#ifndef OTHELLO_H
#define OTHELLO_H

class Othello {
private:
	Case board[8][8]; // position tableau
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
	bool mouvement_legal(int, int);
	int update_mouvement_legal();
	int move(char,char);
	bool jeu_termine(); // declencher la fin du jeu 
	void printBoard();
	void gagnant();
};


#endif

