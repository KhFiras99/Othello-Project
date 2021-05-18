#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Difficulty.h"

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
	Difficulty D;
	//int debutant;
	//int intermediaire;
	//int expert;
public:
	Othello(int P);
	~Othello();
	int getDiff() { return D.getDiff(); };
	//void setDebutant(int x) { debutant = x; }
	//void setIntermediaire(int x) { intermediaire = x; }
	//void setExpert(int x) { expert = x; }
	//bool checkDebutant() { if (debutant == 1) return true; else return false; }
	//bool checkIntermediaire() { if (intermediaire == 1) return true; else return false; }
	void setBoard(int i, int j) { board[i][j] = '-'; }
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
	void reGetTurn();

};


#endif

