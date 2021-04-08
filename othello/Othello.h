#pragma once
#include <iostream>
using namespace std;
#include "Player.h"

class Othello {
private:
	int pos_actuel[8][8];
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
