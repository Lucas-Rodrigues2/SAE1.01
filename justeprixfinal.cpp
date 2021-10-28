void trouverlejusteprix(const unsigned & min, const unsigned & max)
{
    unsigned Prix;
    unsigned justeprix;
    srand(time(NULL));
    justeprix = rand()%max + min;
    unsigned int i;
    unsigned int j;
    i = 0;
    j = 0;
    cout << " régle du juste prix"<< endl;
    cout << " l'ordinateur  choisit un prix que l'équipe 1 et ensuite l'équipe 2 devront trouver, celle avec le moins de tentative gagne " << endl;


    cout<< " l'équipe 1 choisit un prix : " << endl;
    cin>> Prix;
    while (Prix != justeprix){

        if (Prix < justeprix){
            cout << "C'est plus !" << endl;
            cin>> Prix;
            i = i + 1;
        }
        else if (Prix > justeprix){
            cout << "C'est moins !" << endl;
            cin>> Prix;
            i = i + 1;
        }
    }
    cout << " Bravo, l'équipe 1 a trouvé le juste prix en " <<endl;
    cout << i;

    srand(time(NULL));
    justeprix = rand()%max + min;
    cout<< " l'équipe 2 choisit un prix : " << endl;
    cin>> Prix;
    while (Prix != justeprix){

        if (Prix < justeprix){
            cout << "C'est plus !" << endl;
            cin>> Prix;
            j = j + 1;
        }
        else if (Prix > justeprix){
            cout << "C'est moins !" << endl;
            cin>> Prix;
            j = j + 1;
        }
        }
    }
    if (i > j){
        cout << "l'equipe 1 gagne" <<endl;
    }
    else if (i < j){
        cout <<"l'equipe 2 gagne" <<endl;
    }
    else{
        cout <<"égalité des deux équipe" <<endl;
    }
}
