#include <iostream>
#include Othello.h
using namespace std;


/*
	int board[8][8];
	int score_noir;
	int score_blanc;
	bool finished;
    */

Othello::Othello(){

    for (int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if (i==4 && j==4) || (i==5 && j==5) {
                board[i][j]=P1;
            }
            if (i==4 && j==5) || (i==5 && j==4) {
                board[i][j]=P2;
            }
            else board[i][j]=vide;
        }
    }
    cout<<"La table est: "<<board;
}
