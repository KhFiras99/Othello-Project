#include <iostream>
#include "Othello.h"
#include "Player.h"

using namespace std;

int main()
{
    Othello table;

    while (!table.jeu_termine()){
        table.move('4', '6');
        table.printBoard();
        table.passe_tour();
    }
    table.gagnant();
    return 0;
}