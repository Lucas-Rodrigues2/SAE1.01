// Include personal files
#include "../Headers/MiniGames.h"


void headsOrTails(Group & group1, Group & group2, std::fstream & logFile) {
    // Variables initialize
    unsigned short scoreGroup1 = 0;
    unsigned short scoreGroup2 = 0;
    unsigned short resultIssue;

    // Starting game
    logFile << "Le groupe '" << group1.name << "' va affronter le groupe '" << group2.name << "' au jeu du pile ou face."
            << std::endl
            << "La partie se déroulera sur 5 manches, le groupe '" << group1.name << "' a le côté pile et le groupe '"
            << group2.name << "' a pour côté face." << std::endl << std::endl;

    for (unsigned i = 1; i < 5; ++i) { // "i < 5" pour le nombre de manches (4).
        logFile << "Manche n°" << i << ":" << std::endl;
        resultIssue = rand() % 10;

        logFile << '\t';
        if (resultIssue < 5) { // case of resultIssue is equal to 0, 1, 2, 3 or 4
            ++scoreGroup1;

            logFile << "Le résultat du lancée est pile, manche gagnée par le groupe '" << group1.name << "'."
                    << std::endl;

        } else { // case of resultIssue is equal to 5, 6, 7, 8 or 9
            ++scoreGroup2;

            logFile << "Le résultat du lancée est face, manche gagnée par le groupe '" << group2.name << "'."
                    << std::endl;
        }

        logFile << '\t' << "Score : " << scoreGroup1 << '(' << group1.name << ")  -  "
                << scoreGroup2 << '(' << group2.name << ')'
                << std::endl;
    }

    // Game result
    logFile << std::endl;
    if (scoreGroup1 > scoreGroup2) {
        group1.points += 1;
        logFile << "Victoire du groupe '" << group1.name << "' ! Il remporte 1 point."
                << std::endl;

    } else if (scoreGroup1 < scoreGroup2) {
        group2.points += 1;
        logFile << "Victoire du groupe '" << group2.name << "' ! Il remporte 1 point." 
                << std::endl;

    } else {
        group1.points += 0.5;
        group2.points += 0.5;

        logFile << "Les deux équipes sont à égalité, ils remportent par conséquent 0,5 point chacun."
                << std::endl;
    }
}