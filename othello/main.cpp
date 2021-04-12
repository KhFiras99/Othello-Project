#include <iostream>
#include "Othello.h"
#include "Player.h"

using namespace std;

int main()
{
    Othello table;
    table.move();
    table.printBoard();
    table.passe_tour();
    table.move();
    table.printBoard();
    return 0;
}