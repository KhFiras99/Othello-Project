#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
	string coul;
	int score;
public:
	Player(string c) { coul = c; score = 2; };
	string getColor() { return coul; };
	int getScore() { return score; };
};