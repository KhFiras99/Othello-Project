#include <iostream>
#include "Othello.h"
#include "Player.h"

using namespace std;

int main()
{
    int L, C;
    cout << "----------------------     Board OTHELLO   ------------------------" << endl;
    cout << endl;

    Othello table;

    while (!table.jeu_termine()){
        do {
            cout << "Entrez: la ligne :";
            cin >> L;
        } while (L > 7);
        do {
            cout << "        la colonne :";
            cin >> C;
        } while (C > 7);

        table.move(L, C);
        table.printBoard();

        cout << "Le nombre de mouvements legales pour ce tour est: " << table.getnblegalmove() << endl;
    }
    table.gagnant();

    return 0;
}