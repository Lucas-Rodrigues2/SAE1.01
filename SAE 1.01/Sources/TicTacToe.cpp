// Include natif librairies
#include <algorithm>

// Include personal files
#include "../Headers/MiniGames.h"


char hasWinner(const std::vector<std::vector<char>> & Grid) {
    for (unsigned i = 0; i < Grid.size(); ++i) {
        // Win by line
        if (std::equal(Grid[i].begin() + 1, Grid[i].end(), Grid[i].begin()) && Grid[i][0] != '_') {
            return Grid[i][0];
        }

        // Win by column
        if (Grid[0][i] == Grid[1][i] && Grid[1][i] == Grid[2][i]) {
            return Grid[0][i];
        }
    }

    // Win by diagonal
    if ((Grid[0][0] == Grid[1][1] && Grid[1][1] == Grid[2][2])
        || (Grid[0][2] == Grid[1][1] && Grid[1][1] == Grid[2][0])) {
        
        return Grid[1][1];
    }

    // There aren't winner
    return '_';
}

void ticTacToe(Group & group1, Group & group2, std::fstream & logFile) {
    // Variables initialize
    std::vector<std::vector<char>> grid {3, {'_', '_', '_'}};
    std::vector<unsigned short> remainingCase = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    unsigned short groupTurn = rand() % 2;
    unsigned short cpt = 0;

    // Starting Game
    logFile << "Le groupe '" << group1.name << "' va affronter le groupe '" << group2.name << "' au jeu du morpion."
            << std::endl
            << "Le groupe '" << group1.name << "' a le symbole X. Et le groupe '" << group2.name << "' a le symbole O."
            << std::endl;

    
    while (hasWinner(grid) == '_' && cpt < 9) {
        char currentGroup = (groupTurn == 0) ? 'X' : 'O';

        // Chosen of a case
        unsigned short caseChoose = remainingCase[rand() % remainingCase.size()];
        grid[caseChoose / 3][caseChoose % 3] = currentGroup;

        // Remove case
        remainingCase.erase(find(remainingCase.begin(), remainingCase.end(), caseChoose));

        logFile << std::endl
                << "C'est au tour du groupe '" << ((currentGroup == 'X') ? group1.name : group2.name) << "' de jouer."
                << std::endl
                << "Choisissez une case libre : " << caseChoose + 1
                << std::endl;
        
        // Grid display
        for (unsigned i = 0; i < grid.size(); ++i) {
            logFile << std::endl;
            for (unsigned j = 0; j < grid[i].size(); ++j) {
                logFile << grid[i][j] << ' ';
            }
        }

        logFile << std::endl;
        groupTurn = (groupTurn + 1) % 2;
        ++cpt;
    }

    // Game result
    const char winner = hasWinner(grid);
    if (winner == 'X') {
        group1.points += 1;
        logFile << "Victoire du groupe '" << group1.name << "' ! Il remporte 1 point."
                << std::endl;

    } else if (winner == 'O'){
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