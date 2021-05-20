#include <iostream>
#include "Othello.h"

using namespace std;

int main()
{
    int L, C;
    int A = 1;
    int P;
    vector<int> gr;

    int test = 0;
    int n_flipped;

    while (A != 0) {
        system("cls");

        cout << "----------------------      Bienvenue a Othello !      ------------------------" << "\n";
        cout << "\n";
        cout << "\n";
        cout << "Vous etes invite, cher utilisateur a choisir entre:   " << endl;
        cout << "      ****                         DEBUTANT(1)                             ****" << "\n";
        cout << ",     ****                       INTERMEDIAIRE(2)                          ****" << "\n";
        cout << "et:   ****                          EXPERT(3)                              ****" << "\n";
        cout << "\n";
        cout << "\n";
        do {
            cout << "Entrez votre choix, 1 ou 2 ou 3:   ";
            cin >> P;
        } while (P != 3 && P != 2 && P!= 1);

        system("cls");

        cout << "----------------------     Board OTHELLO   ------------------------" << endl;
        cout << endl;

        Othello table(P);

        table.setnblegalmove(4);

        if (table.getDifficulty() == 1) {

            while (!table.jeu_termine()) {
                if (test == 0) cout << "Le nombre de mouvements legales pour ce tour est: " << table.getnblegalmove() << endl;
                else cout << "Le nombre de mouvements legales pour ce tour est: " << table.getnblegalmove_previous() << endl;

                do {
                    cout << "Entrez: la ligne :";
                    cin >> L;
                } while (L > 7);
                do {
                    cout << "        la colonne :";
                    cin >> C;
                } while (C > 7);
                int* T = table.move(L, C, 1);

                n_flipped = T[1];
                int K = T[0];
                if (K != 0) {
                    table.goBack(n_flipped);
                }

                table.printBoard();

            }

        }

        else {
            if (table.getDifficulty() == 2) {

                while (!table.jeu_termine()) {

                    int M;

                    do {
                        cout << " Avez-vous besoin d'aide ?     0: NON / 1: OUI " << endl;
                        cin >> M;
                    } while ((M != 0) & (M != 1));

                    if (M == 1) {
                        gr = table.hint();

                        cout << "Les mouvements possibles sont:";
                        int i = 0;
                        while (i < gr.size() - 1) {
                            cout << "[" << gr[i] << "," << gr[i+1] << "]";
                            i += 2;
                        }
                        cout << "\n";
                    }

                    do {
                        cout << "Entrez: la ligne :";
                        cin >> L;
                    } while (L > 7);
                    do {
                        cout << "        la colonne :";
                        cin >> C;
                    } while (C > 7);

                    int* T = table.move(L, C, 2);
                    int K = T[0];
                    if (K != 0) {
                        system("cls");
                    }

                    table.printBoard();
                }
            }
            else {
                while (!table.jeu_termine()) {

                    do {
                        cout << "Entrez: la ligne :";
                        cin >> L;
                    } while (L > 7);
                    do {
                        cout << "        la colonne :";
                        cin >> C;
                    } while (C > 7);

                    int* T = table.move(L, C, 2);
                    int K = T[0];
                    if (K != 0) {
                        system("cls");
                    }

                    table.printBoard();
                }
            }
        }
       
        table.gagnant();
        cout << endl;
        cout << "Bien joue . Voulez-vous refaire une autre partie ?" << endl;
        cout << endl;
        cout << endl;

        // fin du jeu ou reprendre une nouvelle partie 
        do {
            cout << "---- Taper : 1 si oui ----" << endl;
            cout << "----       : 0 sinon  ----" << endl;
            cin >> A;
        } while ((A != 0) && (A != 1));

        if (A == 1) {    // pour recommancer une nouvelle partie 
            table.setfinished(false);
        }

        while (!gr.empty()) {
            gr.pop_back();
        }

    }




    return 0;
}