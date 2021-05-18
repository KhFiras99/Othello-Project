#pragma once
#include <iostream>
#include "Othello.h"

using namespace std;

class Difficulty
{
private:
	int diff;
public:
	Difficulty(int x=1) :diff(x) {};
	int getDiff() { return diff; };
	void setDiff(int d) { diff = d; };;
};

