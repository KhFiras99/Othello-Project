#include "Player.h"
#include "Othello.h"

#include <string>

using namespace std;

Player::Player(string col) :couleur(col) {
	score = 0;
}

Player::~Player() {}

string Player::getColor() {
	return couleur;
}

int Player::getScore() {
	return score;
}
void Player::setScore(int scr) {
	score = scr;
}

void Player::affiche() {
	cout << "votre status actuelle est : " << endl;
	cout << "Couleur :" << getColor() << "& Score " << getScore() << endl;
}