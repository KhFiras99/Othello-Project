#include <iostream>
#include "Othello.h"
#include <Windows.h>
#include <vector>
using namespace std;


Othello::Othello(int P){

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
	finished = false;
	
	setDebutant(P);

	if (checkDebutant()==true) update_mouvement_legal(1);
	if (checkDebutant()==false) update_mouvement_legal(2);
    printBoard();

}
Othello::~Othello() {
    cout << " \n partie termine" << endl;
}

void Othello::passe_tour() {
	
	for (int n = 0; n < 8; n++)
	{
		for (int m = 0; m < 8; m++) {
			lbord[n][m] = false;
			if (board[n][m].getValue() == 'x') {
				board[n][m].setValue('-');
			}
		}
	}

    if (turn == noir) {
        turn = blanc;
    }
    else {
        turn = noir;
    }
}
void Othello::pass() {
    if (nblegalmoves == 0 ){
        finished = true;
    }
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

	cout << "-----------------//            SCORE            -------------------" << endl;
	cout << "                     Noir:    " << score_noir << "  -  " << score_blanc << "    :Blanc " << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << endl;
	cout << endl;

	
	//for (int n = 0; n < 8; n++)
	//{
	//	for (int m = 0; m < 8; m++) {
	//		cout << lbord[n][m];
	//	}
	//	cout << "\n";
	//}


	cout << "                      0  1  2  3  4  5  6  7" << endl;
	cout << "                    .------------------------." << endl;
	for (int i = 0; i < 8; i++) {
		cout << "                 " << i << "  |";
		for (int j = 0; j < 8; j++) {
			cout << " " << board[i][j] << " ";
		}
		cout << "|";
		cout << "\n";
	}
	cout << "                    '------------------------'" << endl;

	if (turn == noir)
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

void Othello::goBack()
{
	char color, opp_color;

	system("cls");

	int A = 0;
	do {
		cout << "Regrettes-tu ton dernier mouvement?" << endl;
		cout << " 1 : Oui /  0 : Non" << endl;
		cin >> A;
	} while (A != 0 && A != 1);

	if (A == 1) {

		color = turn;
		(color == noir) ? opp_color = blanc : opp_color = noir;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				board[i][j] = board_previous[i][j];
			}
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++) {
				lbord[i][j] = lbord_previous[i][j];
			}
		}

		if (turn == noir) { turn = blanc; }
		else { turn = noir; }

		score_noir = score_noir_previous;
		score_blanc = score_blanc_previous;


		nblegalmoves = nblegalmoves_previous;
	}
}

vector<int> Othello::hint()
{
	int r, c, i, j;
	char color, opp_color;

	color = turn;

	if (color == noir) {
		opp_color = blanc;
	}
	else
		opp_color = noir;

	vector<int> gr;

	for (r = 0; r < 8; r++) {
		for (c = 0; c < 8; c++) {
			//Check that position is open
			if (board[r][c].getValue() != '-') continue;	 //check next (r,c)
			//Check to the left
			if (c - 2 >= 0 && board[r][c - 1].getValue() == opp_color) {
				for (j = c - 2; j > 0 && board[r][j].getValue() == opp_color; j--) { ; } //NO_OP	
				if (board[r][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); gr.push_back(r); gr.push_back(c); continue; }
			}
			//Check to the right
			if (c + 2 <= 7 && board[r][c + 1].getValue() == opp_color) {
				for (j = c + 2; j < 7 && board[r][j].getValue() == opp_color; j++) { ; } //NO_OP	
				if (board[r][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); gr.push_back(r); gr.push_back(c); continue; }
			}
			//Check directly up
			if (r - 2 >= 0 && board[r - 1][c].getValue() == opp_color) {
				for (i = r - 2; i > 0 && board[i][c].getValue() == opp_color; i--) { ; } //NO_OP	
				if (board[i][c].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); gr.push_back(r); gr.push_back(c); continue; }
			}
			//Check directly down
			if (r + 2 <= 7 && board[r + 1][c].getValue() == opp_color) {
				for (i = r + 2; i < 7 && board[i][c].getValue() == opp_color; i++) { ; } //NO_OP	
				if (board[i][c].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); gr.push_back(r); gr.push_back(c); continue; }
			}
			//Check up and to the left
			if (r - 2 >= 0 && c - 2 >= 0 && board[r - 1][c - 1].getValue() == opp_color) {
				for (i = r - 2, j = c - 2; i > 0 && j > 0 && board[i][j].getValue() == opp_color; i--, j--) { ; } //NO_OP	
				if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); gr.push_back(r); gr.push_back(c); continue; }
			}
			//Check up and to the right
			if (r - 2 >= 0 && c + 2 <= 7 && board[r - 1][c + 1].getValue() == opp_color) {
				for (i = r - 2, j = c + 2; i > 0 && j < 7 && board[i][j].getValue() == opp_color; i--, j++) { ; } //NO_OP	
				if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); gr.push_back(r); gr.push_back(c); continue; }
			}
			//Check down and to the left
			if (r + 2 <= 7 && c - 2 >= 0 && board[r + 1][c - 1].getValue() == opp_color) {
				for (i = r + 2, j = c - 2; i < 7 && j>0 && board[i][j].getValue() == opp_color; i++, j--) { ; } //NO_OP	
				if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); gr.push_back(r); gr.push_back(c); continue; }
			}
			//Check down and to the right
			if (r + 2 <= 7 && c + 2 <= 7 && board[r + 1][c + 1].getValue() == opp_color) {
				for (i = r + 2, j = c + 2; i < 7 && j < 7 && board[i][j].getValue() == opp_color; i++, j++) { ; } //NO_OP	
				if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); gr.push_back(r); gr.push_back(c); continue; }
			}
		}
	}
	
	return gr;
	
}



int Othello::move(int r, int c,int P) {
	char color, opp_color;
	int K = 1;
	int i, j, n_flipped = 0;
		

	color = turn;
	(color == noir) ? opp_color =	blanc : opp_color = noir;


	if (!lbord[r][c]) {
		cout << "Illegal move!" << endl;
		K=0;
		//for (int n = 0; n < 8; n++)
		//{
		//	for (int m = 0; m < 8; m++) {
		//		cout << lbord[n][m];
		//	}
		//	cout << "\n";
		//}
	}
	else
	{	
		++K;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				board_previous[i][j] = board[i][j];
			}
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++) {
				lbord_previous[i][j] = lbord[i][j];
			}
		}

		if (P == 1) {

			//board[r][c].getValue() == vide
			if (board[r][c].getValue() == 'x') {
				//Update board
				//Check to the left
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

				board[r][c] = color;

				passe_tour();

				nblegalmoves_previous = nblegalmoves;

				update_mouvement_legal(1);

				pass();

				score_noir_previous = score_noir;
				score_blanc_previous = score_blanc;

				//update number of pieces of each color
				if (color == noir) { score_noir += n_flipped + 1; score_blanc -= n_flipped; }
				else { score_noir -= n_flipped; score_blanc += n_flipped + 1; }
			}
		}
		else {
				if (board[r][c].getValue() == '-') {
					//Update board
					//Check to the left
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

					board[r][c] = color;

					passe_tour();

					nblegalmoves_previous = nblegalmoves;

					update_mouvement_legal(2);

					pass();

					score_noir_previous = score_noir;
					score_blanc_previous = score_blanc;

					//update number of pieces of each color
					if (color == noir) { score_noir += n_flipped + 1; score_blanc -= n_flipped; }
					else { score_noir -= n_flipped; score_blanc += n_flipped + 1; }

				}

		}
	}

	// IF WE WANT TO PLACE THE PION IN A PLACE THATS NOT SUPPOSED TO BE TRUE, IT IS EXECUTED. WHICH IS WRONG.
	//Update turn counter
	return K;
}

void Othello::update_mouvement_legal(int P) {
	int r, c, i, j;
	char color, opp_color;
	int n_moves = 0;

	color = turn;

	if (color == noir) {
		opp_color = blanc;
	}
	else
		opp_color = noir;

	if (P == 1) {
		for (r = 0; r < 8; r++) {
			for (c = 0; c < 8; c++) {
				//Check that position is open
				if (board[r][c].getValue() != '-') continue;	 //check next (r,c)
				//Check to the left
				if (c - 2 >= 0 && board[r][c - 1].getValue() == opp_color) {
					for (j = c - 2; j > 0 && board[r][j].getValue() == opp_color; j--) { ; } //NO_OP	
					if (board[r][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('x'); n_moves++; continue; }
				}
				//Check to the right
				if (c + 2 <= 7 && board[r][c + 1].getValue() == opp_color) {
					for (j = c + 2; j < 7 && board[r][j].getValue() == opp_color; j++) { ; } //NO_OP	
					if (board[r][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('x'); n_moves++; continue; }
				}
				//Check directly up
				if (r - 2 >= 0 && board[r - 1][c].getValue() == opp_color) {
					for (i = r - 2; i > 0 && board[i][c].getValue() == opp_color; i--) { ; } //NO_OP	
					if (board[i][c].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('x'); n_moves++; continue; }
				}
				//Check directly down
				if (r + 2 <= 7 && board[r + 1][c].getValue() == opp_color) {
					for (i = r + 2; i < 7 && board[i][c].getValue() == opp_color; i++) { ; } //NO_OP	
					if (board[i][c].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('x'); n_moves++; continue; }
				}
				//Check up and to the left
				if (r - 2 >= 0 && c - 2 >= 0 && board[r - 1][c - 1].getValue() == opp_color) {
					for (i = r - 2, j = c - 2; i > 0 && j > 0 && board[i][j].getValue() == opp_color; i--, j--) { ; } //NO_OP	
					if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('x'); n_moves++; continue; }
				}
				//Check up and to the right
				if (r - 2 >= 0 && c + 2 <= 7 && board[r - 1][c + 1].getValue() == opp_color) {
					for (i = r - 2, j = c + 2; i > 0 && j < 7 && board[i][j].getValue() == opp_color; i--, j++) { ; } //NO_OP	
					if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('x'); n_moves++; continue; }
				}
				//Check down and to the left
				if (r + 2 <= 7 && c - 2 >= 0 && board[r + 1][c - 1].getValue() == opp_color) {
					for (i = r + 2, j = c - 2; i < 7 && j>0 && board[i][j].getValue() == opp_color; i++, j--) { ; } //NO_OP	
					if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('x'); n_moves++; continue; }
				}
				//Check down and to the right
				if (r + 2 <= 7 && c + 2 <= 7 && board[r + 1][c + 1].getValue() == opp_color) {
					for (i = r + 2, j = c + 2; i < 7 && j < 7 && board[i][j].getValue() == opp_color; i++, j++) { ; } //NO_OP	
					if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('x'); n_moves++; continue; }
				}
			}
		}
	}
	else {
		for (r = 0; r < 8; r++) {
			for (c = 0; c < 8; c++) {
				//Check that position is open
				if (board[r][c].getValue() != '-') continue;	 //check next (r,c)
				//Check to the left
				if (c - 2 >= 0 && board[r][c - 1].getValue() == opp_color) {
					for (j = c - 2; j > 0 && board[r][j].getValue() == opp_color; j--) { ; } //NO_OP	
					if (board[r][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); n_moves++; continue; }
				}
				//Check to the right
				if (c + 2 <= 7 && board[r][c + 1].getValue() == opp_color) {
					for (j = c + 2; j < 7 && board[r][j].getValue() == opp_color; j++) { ; } //NO_OP	
					if (board[r][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); n_moves++; continue; }
				}
				//Check directly up
				if (r - 2 >= 0 && board[r - 1][c].getValue() == opp_color) {
					for (i = r - 2; i > 0 && board[i][c].getValue() == opp_color; i--) { ; } //NO_OP	
					if (board[i][c].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); n_moves++; continue; }
				}
				//Check directly down
				if (r + 2 <= 7 && board[r + 1][c].getValue() == opp_color) {
					for (i = r + 2; i < 7 && board[i][c].getValue() == opp_color; i++) { ; } //NO_OP	
					if (board[i][c].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); n_moves++; continue; }
				}
				//Check up and to the left
				if (r - 2 >= 0 && c - 2 >= 0 && board[r - 1][c - 1].getValue() == opp_color) {
					for (i = r - 2, j = c - 2; i > 0 && j > 0 && board[i][j].getValue() == opp_color; i--, j--) { ; } //NO_OP	
					if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); n_moves++; continue; }
				}
				//Check up and to the right
				if (r - 2 >= 0 && c + 2 <= 7 && board[r - 1][c + 1].getValue() == opp_color) {
					for (i = r - 2, j = c + 2; i > 0 && j < 7 && board[i][j].getValue() == opp_color; i--, j++) { ; } //NO_OP	
					if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); n_moves++; continue; }
				}
				//Check down and to the left
				if (r + 2 <= 7 && c - 2 >= 0 && board[r + 1][c - 1].getValue() == opp_color) {
					for (i = r + 2, j = c - 2; i < 7 && j>0 && board[i][j].getValue() == opp_color; i++, j--) { ; } //NO_OP	
					if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); n_moves++; continue; }
				}
				//Check down and to the right
				if (r + 2 <= 7 && c + 2 <= 7 && board[r + 1][c + 1].getValue() == opp_color) {
					for (i = r + 2, j = c + 2; i < 7 && j < 7 && board[i][j].getValue() == opp_color; i++, j++) { ; } //NO_OP	
					if (board[i][j].getValue() == color) { lbord[r][c] = true; board[r][c].setValue('-'); n_moves++; continue; }
				}
			}
		}
	}

	nblegalmoves = n_moves;


	//return n_moves;
}
