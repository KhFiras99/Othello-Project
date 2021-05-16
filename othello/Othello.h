#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define vide '-'
#define noir '1'
#define blanc '2'

#include "Case.h"
#ifndef OTHELLO_H
#define OTHELLO_H

class Othello {
private:
	Case board[8][8]; // position tableau
	Case board_previous[8][8]; // derniere position des cases sur tableau
	bool lbord[8][8];
	bool lbord_previous[8][8];
	int score_noir; // score du joueur noir 
	int score_noir_previous;
	int score_blanc; // score du joueur blanc
	int score_blanc_previous;
	bool finished;  // partie terminé
	char turn;  // tour du joueur 
	int nblegalmoves; // nombre de mouvements legals
	int nblegalmoves_previous;
	int debutant;
public:
	Othello(int P);
	~Othello();
	void setDebutant(int x) { debutant = x; }
	bool checkDebutant() { if (debutant == 1) return true; else return false; }
	void setBoard(int i, int j) { board[i][j]='-'; }
	int getnblegalmove() {return nblegalmoves; }
	void setnblegalmove(int x) { nblegalmoves = x; }
	int getnblegalmove_previous() { return nblegalmoves_previous; }
	void passe_tour();  // tour de role 
	void pass(); // forcer le passage de tour de role (return true si le joueur doit passer et false si le jeu est fini )
	bool mouvement_legal(int, int);
	void update_mouvement_legal(int);
	int* move(int,int,int);
	bool jeu_termine(); // declencher la fin du jeu 
	void printBoard();
	void gagnant();
	void goBack(int);
	vector<int> hint();
};


#endif

