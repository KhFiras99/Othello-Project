#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
	string couleur;
	int score;
public:
	Player();
	~Player();
	string getColor();
	int getScore();
	void setScore(int score);
	void affiche();
	void choisir();
	void move();
	bool blocage();
	bool mouvement_permis();
	friend bool jeu_termine();
};
