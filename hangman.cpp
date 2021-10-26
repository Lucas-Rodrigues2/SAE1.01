#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

unsigned short OccurenceCharInStr(const char & car, const string & str) {
    unsigned short cpt = 0;
    
    for (unsigned i = 0; i < str.size(); ++i) {
        if (car == str[i])
            ++cpt;
    }

    return cpt;
}

void hangman(const unsigned & seed) {
    srand(time(NULL));

    // Variables initialize
    unsigned short life = 8;
    unsigned short charFind = 0;
    unsigned short occurences;
    vector<char> charUsed;
    char currentCharInput;

    string secretWord;
    cout << "Saisir un mot : ";
    cin >> secretWord;

    while (life > 0 && charFind < secretWord.size()) {
        cout << endl;
        currentCharInput = 'a' + (rand() % 26); // const 26 to each letter in alphabet

        // Check if the letter has already choose
        for (unsigned i = 0; i < charFind; ++i) {
            if (currentCharInput == charUsed[i])
                continue;
        }

        occurences = OccurenceCharInStr(currentCharInput, secretWord);

        if (occurences > 0) {
            charUsed.push_back(currentCharInput);
            charFind += occurences;

            cout << "Bien joue ! La lettre " << currentCharInput << " est bien dans le mot." << endl
                 << "Il reste " << secretWord.size() - charFind << " lettre(s) a trouvee(s)." << endl;

        } else {
            --life;

            cout << "La lettre " << currentCharInput << " n'est pas dans le mot !"
                 << endl << "Il vous reste " << life << " point(s) de vie(s)." << endl;
        }
    }

    cout << endl;

    if (life > 0)
        cout << "Bravo vous avez gagne !";
    else
        cout << "Vous avez perdu !";
}