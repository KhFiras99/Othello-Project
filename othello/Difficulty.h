#pragma once
#include <iostream>

using namespace std;

class Difficulty
{
protected:
	int diff;
public:
	Difficulty(int x = 1) :diff(x) {};
	int getDiff() { return diff; };
	void setDiff(int d) { diff = d; };;
};

