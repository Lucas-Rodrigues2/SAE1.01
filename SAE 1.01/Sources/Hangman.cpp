// Include personal file
#include "../Headers/MiniGames.h"


void displaySecretWord(std::fstream & logFile, const std::string & secretWord, const std::vector<unsigned> & posCharFind) {
    bool isFind;
    
    for (unsigned i = 0; i < secretWord.size(); ++i) {
        isFind = false;

        for (unsigned j = 0; j < posCharFind.size(); ++j) {
            if (i == posCharFind[j]) {
                isFind = true;
                logFile << secretWord[i];
            }
        }

        if (!isFind)
            logFile << '*';
    }
}

void hangman(Group & group1, Group & group2, std::fstream & logFile) {
    // Variables initialize
    std::string secretWord;
    std::vector<char> charUsed;
    std::vector<unsigned> posCharFind;
    unsigned short life = 8;
    char currentRandomChar;
    bool isValidLetter;
    
    // Starting game
    logFile << "Le groupe '" << group1.name << "' va affronter le groupe '" << group2.name << "' au jeu du pendu."
            << std::endl
            << "Le groupe '" << group1.name << "' va choisir un mot et le groupe '" << group2.name
            << "' va devoir le trouver." << std::endl
            << "Saisir le mot a trouver : " << std::endl;
    
    // Random build and display of the secret word
    secretWord = "famille";
    logFile << secretWord << std::endl << std::endl;


    while (life > 0 && posCharFind.size() < secretWord.size()) {
        logFile << "Saisir une lettre : ";
        
        // build random char not already use
        while (true) {
            bool test = true;
            currentRandomChar = 'a' + rand() % 26;

            for (unsigned short i = 0; i < charUsed.size(); ++i) {
                if (currentRandomChar == charUsed[i]) {
                    test = false;
                    break;
                }
            }
            if (test) {
                charUsed.push_back(currentRandomChar);
                break;
            }
        }

        // Check the occurences in the secret word
        isValidLetter = false;
        for (unsigned i = 0; i < secretWord.size(); ++i) {
            if (currentRandomChar == tolower(secretWord[i])) {
                posCharFind.push_back(i);
                isValidLetter = true;
            }
        }

        // Print trace of result
        if (isValidLetter) {
            logFile << "Bien joué ! La lettre '" << currentRandomChar << "' est bien dans le mot." << std::endl;

        } else {
            --life;
            logFile << "Dommage ! La lettre '" << currentRandomChar << "' n'est pas dans le mot." << std::endl
                    << "Il ne vous reste plus que " << life << " point(s) de vie(s)." << std::endl;
        }

        displaySecretWord(logFile, secretWord, posCharFind);
        logFile << std::endl << std::endl;
    }

    // Game Result
    logFile << "Bravo au groupe '";
    
    if (life > 0) {
        group2.points += 1;
        logFile << group2.name;
    } else {
        group1.points += 1;
        logFile << group1.name;
    }

    logFile << "' qui gagne la partie ! Il remporte 1 point" << std::endl;
}