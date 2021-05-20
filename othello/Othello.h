#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Case.h"
#include "Score.h"
#include "Difficulty.h"
#ifndef OTHELLO_H
#define OTHELLO_H

using namespace std;
#define vide '-'
#define noir '1'
#define blanc '2'

class Othello {
private:
	Case board[8][8]; // position tableau
	Case board_previous[8][8]; // derniere position des cases sur tableau
	Score S;
	Difficulty D;
	bool lbord[8][8];
	bool lbord_previous[8][8];
	bool finished;  // partie terminé
	char turn;  // tour du joueur 
	int nblegalmoves; // nombre de mouvements legals
	int nblegalmoves_previous;
	
public:
	Othello(int P);
	~Othello();
	int getDifficulty() { return D.getDiff(); }
	int getnblegalmove() { return nblegalmoves; }
	void setnblegalmove(int x) { nblegalmoves = x; }
	int getnblegalmove_previous() { return nblegalmoves_previous; }
	void setfinished(bool B) { finished = B; }

	void passe_tour();  // tour de role 
	void pass(); // forcer la fin du jeu 
	bool mouvement_legal(int, int);
	void update_mouvement_legal(int);
	int* move(int, int, int);
	bool jeu_termine(); // declencher la fin du jeu 
	void printBoard();
	void gagnant();
	void goBack(int);
	vector<int> hint();
};

#endif

