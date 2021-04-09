#pragma once
#include <iostream>
using namespace std;
#ifndef Othello.h
#define Othello.h

#define P1 "1" // blanc
#define P2 "2" // noir
#define vide "0"

class Othello {
private:
	int board[8][8];
	int score_noir;
	int score_blanc;
	bool finished;
public:
	Othello();
	~Othello();
	friend bool mouvemnt_permis();
	void tourner_pierce();
	friend void blocage();
	bool jeu_termine();
	Player gagnant();
};


#endif