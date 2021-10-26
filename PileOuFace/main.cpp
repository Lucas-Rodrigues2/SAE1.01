#include <iostream>
using namespace std;

void PileOuFace() {
    int min, max, Valeurpiece;
    string ChoixJoueur;
    int ChoixJoueurPiece;
    ChoixJoueurPiece = -1;

    min = 1;
    max = 2;
    while (ChoixJoueur != "Pile" && ChoixJoueur != "Face") {

        cout << "Choisir Pile ou Face : ";
        cin >> ChoixJoueur;
    }
    srand(time(NULL));
    Valeurpiece = rand()%max + min;
    if (ChoixJoueur == "Face")
    {
        ChoixJoueurPiece = 1;
    }
    else if (ChoixJoueur == "Pile")
    {
        ChoixJoueurPiece = 2;
    }
    if (ChoixJoueurPiece == Valeurpiece)
    {
        cout << "C'est gagné " << endl << endl;
    }
    if (ChoixJoueurPiece != Valeurpiece)
    {
        cout << "C'est perdu" << endl << endl;
    }
}

#include <iostream>

using namespace std;

void test ()
{
    int min, max, Valeurpiece, CptDefaite, CptVictoire;
    string ChoixJoueur;
    int ChoixJoueurPiece;
    ChoixJoueurPiece = 0;
    CptDefaite = 0;
    CptVictoire = 0;
    min = 1;
    max = 2;
    while (CptVictoire != 3 && CptDefaite !=3) {
        while (ChoixJoueur != "Pile" && ChoixJoueur != "Face") {

            cout << "Choisir Pile ou Face : ";
            cin >> ChoixJoueur;
        }
        srand(time(NULL)+ CptDefaite + CptVictoire);
        Valeurpiece = rand()%max + min;
        if (ChoixJoueur == "Pile")
        {
            ChoixJoueurPiece = 1;
        }
        else if (ChoixJoueur == "Face")
        {
            ChoixJoueurPiece = 2;
        }
          if (ChoixJoueurPiece == Valeurpiece)
        {
            cout << "L'equipe 1 gagne" << endl << endl;
            CptVictoire += 1;
        }
        if (ChoixJoueurPiece != Valeurpiece)
        {
            cout << "L'equipe 2 gagne" << endl << endl;
            CptDefaite += 1;
        }
        ChoixJoueur = "";
    }
    if (CptVictoire == 3)
    {
        cout << "L'equipe 1 a gagné" << endl;
    }
    if (CptDefaite == 3)
    {
        cout << "L'equipe 2 a gagné" << endl;
    }
}


int main()
{
    test();
}
