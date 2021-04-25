#include <iostream>
#include "Othello.h"
#include "Player.h"

using namespace std;

int main()
{
    int L, C;
    Othello table;

    while (!table.jeu_termine()){
        cout << "Entrez la ligne :";
        cin >> L;
        cout << "\nEntrez la colonne :";
        cin >> C;
        table.move(--L,--C);
        table.update_mouvement_legal();
        table.printBoard();
        cout << "Le nombre de mouvements legales pour ce tour est: " << table.getnblegalmove() << endl;
    }
    table.gagnant();
    return 0;
}