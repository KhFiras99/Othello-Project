#include <iostream>
#include "Othello.h"
#include <vector>
using namespace std;

int main()
{
    int L, C;
    int A=1;
    int P;
    int test = 0;
    int n_flipped;

    vector<int> gr;

    cout << "----------------------      HELLO USER      ------------------------" << "\n";
    cout << "Tu es invitE, chEre utilisateur A choisir entre:   " << "****      DEBUTANT(1)          ****" << "\n";
    cout << "                                            et:   ****      INTERMEDIAIRE(2)      *****"<<"\n";
    
    do {
        cout << "Entrez votre choix, 1 ou 2:   ";
        cin >> P;
    } while (P != 2 && P!= 1 );
   
    system("cls");

    cout << "----------------------     Board OTHELLO   ------------------------" << endl;
    cout << endl;

    Othello table(P);

    table.setnblegalmove(4);

    if (table.checkDebutant()==true) {
        while (A != 0) {

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
                int* T = table.move(L, C ,1);

                n_flipped = T[1];
                int K = T[0];
                if (K != 0) {
                    table.goBack(n_flipped);
                }

                table.printBoard();
                }
        }
    }
    else {

        while (A != 0) {

            while (!table.jeu_termine()) {
                int M;
                do {
                    cout << " Avez-vous besoin d'un hint?     0: NON / 1: OUI " << endl;
                    cin >> M;
                } while ((M!=0) & (M!=1));
                
                if (M == 1) {
                    gr = table.hint();

                    cout << "Les mouvements possibles sont:";
                    int i = 0;
                    while (i < gr.size() - 1) {
                        cout << "[" << gr[i] << "," << gr[i + 1] << "]";
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
                system("cls");
                
                table.printBoard();

            }

        }
    }
    table.gagnant();
    cout << "Bien jou�, partie termin�e. Voulez-vous refaire une autre partie?" << endl;
    cout << "----Entrez 1 si vous voulez continuer et 0 sinon.----" << endl;
    cin >> A;
    return 0;
}