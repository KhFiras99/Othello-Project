#include <iostream>
#include "Othello.h"
#include "Player.h"
using namespace std;

int main()
{
    int L, C;
    int A=1;
    int n_flipped;
    cout << "----------------------     Board OTHELLO   ------------------------" << endl;
    cout << endl;

    Othello table;

    while (A != 0) {

        while (!table.jeu_termine()) {
            cout << "Le nombre de mouvements legales pour ce tour est: " << table.getnblegalmove() << endl;

            do {
                cout << "Entrez: la ligne :";
                cin >> L;
            } while (L > 7);
            do {
                cout << "        la colonne :";
                cin >> C;
            } while (C > 7);
            table.printBoard();

            n_flipped=table.move(L, C);

            table.goBack(n_flipped);
        }
        table.gagnant();
        cout << "Bien joué, partie terminée. Voulez-vous refaire une autre partie?" << endl;
        cout << "----Entrez 1 si vous voulez continuer et 0 sinon.----" << endl;
        cin >> A;
    }
    return 0;
}