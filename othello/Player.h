#pragma once

#include <iostream>

#include "Othello.h"

#include <string>

using namespace std;

#ifndef PLAYER_H 
#define PLAYER_H	
class Player {
private:
	string couleur;
	int score;
public:
	Player(string col);
	~Player();
	string getColor();
	int getScore();
	void setScore(int);
	void affiche();
};
#endif