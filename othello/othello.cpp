#include <iostream>
#include "Othello.h"
using namespace std;


Othello::Othello(){

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i == 3 && j == 3) || (i== 4 && j == 4)){
                board[i][j].setValue('1');
            }
            else if ((i == 3 && j == 4) || (i == 4 && j == 3)) {
                board[i][j].setValue('2');
            }
            else {
                board[i][j].setValue('-');
            }
            lbord[i][j] = false; // initialistation de la table lbord 

        }
    }
	turn = noir;
	score_blanc = 2;
	score_noir = 2;

	cout << "----------------------SCORE----------------------" << endl;
	cout << "Score noir: " << score_noir << " //   Score blanc: " << score_blanc << endl;
	cout << "-------------------------------------------------" << endl;

	finished = false;
    printBoard();
	update_mouvement_legal();

}
Othello::~Othello() {
    cout << " \n partie termine" << endl;
}

void Othello::passe_tour() {
    if (turn == noir) {
        turn = blanc;
    }
    else {
        turn = noir;
    }
}
bool Othello::pass() {
    passe_tour();
	update_mouvement_legal();
    if (nblegalmoves == 0 ){
        finished = true;
        return false;
    }
    return true;

}
bool Othello::mouvement_legal(int i, int j)
{
	return lbord[i][j];
}


bool Othello::jeu_termine() {
    if (finished == true) {
        cout << "Jeu Terminée";
		return true;
	}
	return false;
}
void Othello::printBoard() {
    cout << "************************   Board OTHELLO   ************************" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
	if (turn==noir)
		cout << "Maintenant, c'est au noir (" << turn << ") de jouer!" << endl;
	else
		cout << "Maintenant, c'est au blanc (" << turn << ") de jouer!" << endl;


}

void Othello::gagnant()
{
	if (score_noir > score_blanc)
		cout << "Le joueur noir a gagné avec un score de: " << score_noir << endl;
	else
		cout << "Le joueur blanc a gagné avec un score de: " << score_blanc << endl;
}

void Othello::move(int r, int c) {
	char color, opp_color;
	int i, j, n_flipped = 0;

	color = turn;
	(color == noir) ? opp_color = blanc : opp_color = noir;

	if (!lbord[r][c]) {
		cout << "Illegal move!" << endl;
	}
	if (board[r][c].getValue() == vide)
	{
		//Update board
		//Check to the left
		board[r][c] = color;
		if (c - 2 >= 0 && board[r][c - 1].getValue() == opp_color) {
			for (j = c - 2; j > 0 && board[r][j].getValue() == opp_color; j--) { ; } //NO_OP	
			if (board[r][j].getValue() == color) { while (++j < c) { board[r][j] = color; n_flipped++; } }
		}
		//Check to the right
		if (c + 2 <= 7 && board[r][c + 1].getValue() == opp_color) {
			for (j = c + 2; j < 7 && board[r][j].getValue() == opp_color; j++) { ; } //NO_OP	
			if (board[r][j].getValue() == color) { while (--j > c) { board[r][j] = color; n_flipped++; } }
		}
		//Check directly up
		if (r - 2 >= 0 && board[r - 1][c].getValue() == opp_color) {
			for (i = r - 2; i > 0 && board[i][c].getValue() == opp_color; i--) { ; } //NO_OP	
			if (board[i][c].getValue() == color) { while (++i < r) { board[i][c] = color; n_flipped++; } }
		}
		//Check directly down
		if (r + 2 <= 7 && board[r + 1][c].getValue() == opp_color) {
			for (i = r + 2; i < 7 && board[i][c].getValue() == opp_color; i++) { ; } //NO_OP	
			if (board[i][c].getValue() == color) { while (--i > r) { board[i][c] = color; n_flipped++; } }
		}
		//Check up and to the left
		if (r - 2 >= 0 && c - 2 >= 0 && board[r - 1][c - 1].getValue() == opp_color) {
			for (i = r - 2, j = c - 2; i > 0 && j > 0 && board[i][j].getValue() == opp_color; i--, j--) { ; } //NO_OP	
			if (board[i][j].getValue() == color) { while (++i < r) { board[i][++j] = color; n_flipped++; } }
		}
		//Check up and to the right
		if (r - 2 >= 0 && c + 2 <= 7 && board[r - 1][c + 1].getValue() == opp_color) {
			for (i = r - 2, j = c + 2; i > 0 && j < 7 && board[i][j].getValue() == opp_color; i--, j++) { ; } //NO_OP	
			if (board[i][j].getValue() == color) { while (++i < r) { board[i][--j] = color; n_flipped++; } }
		}
		//Check down and to the left
		if (r + 2 <= 7 && c - 2 >= 0 && board[r + 1][c - 1].getValue() == opp_color) {
			for (i = r + 2, j = c - 2; i < 7 && j>0 && board[i][j].getValue() == opp_color; i++, j--) { ; } //NO_OP	
			if (board[i][j].getValue() == color) { while (--i > r) { board[i][++j] = color; n_flipped++; } }
		}
		//Check down and to the right
		if (r + 2 <= 7 && c + 2 <= 7 && board[r + 1][c + 1].getValue() == opp_color) {
			for (i = r + 2, j = c + 2; i < 7 && j < 7 && board[i][j].getValue() == opp_color; i++, j++) { ; } //NO_OP	
			if (board[i][j].getValue() == color) { while (--i > r) { board[i][--j] = color; n_flipped++; } }
		}

		//update number of pieces of each color
		if (color == noir) { score_noir += n_flipped + 1; score_blanc -= n_flipped; }
		else { score_noir -= n_flipped; score_blanc += n_flipped + 1; }

		cout << "----------------------SCORE----------------------" << endl;
		cout << "Score noir: " << score_noir << " //   Score blanc: " << score_blanc << endl;
		cout << "-------------------------------------------------" << endl;

	}

	// IF WE WANT TO PLACE THE PION IN A PLACE THATS NOT SUPPOSED TO BE TRUE, IT IS EXECUTED. WHICH IS WRONG.


	//Update turn counter
	passe_tour();
	
	//turn = opp_color;



}

void Othello::update_mouvement_legal() {
	int r, c, i, j;
	char color, opp_color;
	int n_moves = 0;

	color = turn; //noir
	(color == noir) ? opp_color = blanc : opp_color = vide;

	for (r = 0; r < 8; r++) {
		for (c = 0; c < 8; c++) {
			lbord[r][c] = false;
			//Check that position is open
			if (board[r][c].getValue() != '-') continue;	 //check next (r,c)
			//Check to the left
			if (c - 2 >= 0 && board[r][c - 1].getValue() == opp_color) {
				for (j = c - 2; j > 0 && board[r][j].getValue() == opp_color; j--) { ; } //NO_OP	
				if (board[r][j].getValue() == color) { lbord[r][c] = true;  n_moves++; continue; }
			}
			//Check to the right
			if (c + 2 <= 7 && board[r][c + 1].getValue() == opp_color) {
				for (j = c + 2; j < 7 && board[r][j].getValue() == opp_color; j++) { ; } //NO_OP	
				if (board[r][j].getValue() == color) { lbord[r][c] = true;  n_moves++; continue; }
			}
			//Check directly up
			if (r - 2 >= 0 && board[r - 1][c].getValue() == opp_color) {
				for (i = r - 2; i > 0 && board[i][c].getValue() == opp_color; i--) { ; } //NO_OP	
				if (board[i][c].getValue() == color) { lbord[r][c] = true;  n_moves++; continue; }
			}
			//Check directly down
			if (r + 2 <= 7 && board[r + 1][c].getValue() == opp_color) {
				for (i = r + 2; i < 7 && board[i][c].getValue() == opp_color; i++) { ; } //NO_OP	
				if (board[i][c].getValue() == color) { lbord[r][c] = true;  n_moves++; continue; }
			}
			//Check up and to the left
			if (r - 2 >= 0 && c - 2 >= 0 && board[r - 1][c - 1].getValue() == opp_color) {
				for (i = r - 2, j = c - 2; i > 0 && j > 0 && board[i][j].getValue() == opp_color; i--, j--) { ; } //NO_OP	
				if (board[i][j].getValue() == color) { lbord[r][c] = true;  n_moves++; continue; }
			}
			//Check up and to the right
			if (r - 2 >= 0 && c + 2 <= 7 && board[r - 1][c + 1].getValue() == opp_color) {
				for (i = r - 2, j = c + 2; i > 0 && j < 7 && board[i][j].getValue() == opp_color; i--, j++) { ; } //NO_OP	
				if (board[i][j].getValue() == color) { lbord[r][c] = true;  n_moves++; continue; }
			}
			//Check down and to the left
			if (r + 2 <= 7 && c - 2 >= 0 && board[r + 1][c - 1].getValue() == opp_color) {
				for (i = r + 2, j = c - 2; i < 7 && j>0 && board[i][j].getValue() == opp_color; i++, j--) { ; } //NO_OP	
				if (board[i][j].getValue() == color) { lbord[r][c] = true;  n_moves++; continue; }
			}
			//Check down and to the right
			if (r + 2 <= 7 && c + 2 <= 7 && board[r + 1][c + 1].getValue() == opp_color) {
				for (i = r + 2, j = c + 2; i < 7 && j < 7 && board[i][j].getValue() == opp_color; i++, j++) { ; } //NO_OP	
				if (board[i][j].getValue() == color) { lbord[r][c] = true;  n_moves++; continue; }
			}
		}
	}
	nblegalmoves = n_moves;
	//return n_moves;
}