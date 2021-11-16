// Include personal files
#include "../Headers/MiniGames.h"


std::string captainAge(Group & group1, Group & group2, std::fstream & logFile) {
    // Variables Initialize
    unsigned short randomCaptainAge = 1 + rand() % 100;
    unsigned short tries = 8;
    unsigned short min = 1;
    unsigned short max = 100;

    // Starting Game
    logFile << "Le groupe '" << group1.name << "' va affronter le groupe '" << group2.name
            << "' au jeu de l'âge du capitaine." << std::endl
            << "Que le groupe '" << group1.name << "' saisisse l'âge du capitaine (entre 1 et 100) : " << randomCaptainAge
            << std::endl << std::endl;
    
    while (tries > 0) {
        // Build random age input "clever"
        unsigned short currentAgeInput;
        if (max - min == 0)
            currentAgeInput = randomCaptainAge;
        else
            currentAgeInput = min + rand() % (max - min);

        logFile << "Que le groupe '" << group2.name << "' saisissie un âge : " << currentAgeInput << std::endl;

        // Turn's result
        if (currentAgeInput > randomCaptainAge) {
            --tries;
            max = currentAgeInput - 1;
            logFile << "Dommage, c'est moins !";

        } else if (currentAgeInput < randomCaptainAge) {
            --tries;
            min = currentAgeInput + 1;
            logFile << "Dommage, c'est plus !";

        // Group 2 win
        } else {
            logFile << "Bien joué ! Vous avez trouvé l'âge du capitaine." << std::endl << std::endl
                    << "Le groupe '" << group2.name << "' remporte 1 point." << std::endl;
            return group2.name;
        }

        logFile << " Il vous reste " << tries << " essais." << std::endl << std::endl;
    }
    
    // exit loop, Group 1 win
    logFile << "Le groupe '" << group1.name << "remporte 1 point." << std::endl;
    return group1.name;
}