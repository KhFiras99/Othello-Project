#pragma once
#include <iostream>


class Score
{
protected:
	int score_noir, S1;
	int score_blanc, S2;
public:

	Score() { score_noir = 2; score_blanc = 2; S1 = 0; S2 = 0; };
	int getScore_noir() { return score_noir; }
	int getScore_blanc() { return score_blanc; }
	void setScore_noir_previous(int x) { S1 = x; }
	void setScore_blanc_previous(int x) { S2 = x; }
	void setScore_noir(int x) { score_noir = x; }
	void setScore_blanc(int x) { score_blanc = x; }
	int getScore_noir_previous() { return S1; }
	int getScore_blanc_previous() { return S2; }

};

