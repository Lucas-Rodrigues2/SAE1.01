// Include personal files
#include "Headers/MiniGames.h"
#include "Headers/TextASCII.h"


void LaunchRound(std::fstream & logFile, std::vector<Group> & allGroups,
                 const std::vector<std::string> & roundNumber, const std::string & miniGame) {
    
    showAsciiText(logFile, textRound, roundNumber);

    for (unsigned j = 0; j < allGroups.size(); ++j) {
        if (allGroups[j].hasOpponent) continue;
        allGroups[j].hasOpponent = true;

        allGroups[j].groupsFought.push_back(allGroups[j].findOpponent(allGroups));

        showAsciiText(logFile, textMatch, {5, ""});

        if (miniGame == "TicTacToe") {
            ticTacToe(allGroups[j], allGroups[j].groupsFought.back(), logFile);
        } else if (miniGame == "Hangman") {
            hangman(allGroups[j], allGroups[j].groupsFought.back(), logFile);
        } else if (miniGame == "HeadsOrTails") {
            headsOrTails(allGroups[j], allGroups[j].groupsFought.back(), logFile);
        } else if (miniGame == "CaptainAge") {
            captainAge(allGroups[j], allGroups[j].groupsFought.back(), logFile);
        }
    }
    showRanking(logFile, allGroups, textResult);

    for (unsigned i = 0; i < allGroups.size(); ++i) {
        allGroups[i].hasOpponent = false;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 1) {
        std::cout << "Le programme prend que deux parametres (le chemin du fichier d'entree et du fichier de sortie)"
                  << std::endl;
        return 1;
    }

    // Read the "settings file"
    std::fstream fileIn;
    fileIn.open("FileIn1.txt", std::ios::in); // read mod
    
    std::vector<std::string> fileContent;
    std::string whollLine;
    std::string input;

    // build a vector of string which contains 1 string for each line except the line empty and comments "//"
    while (std::getline(fileIn, whollLine)) {
        
        for (unsigned i = 0; i < whollLine.size(); ++i) {
            if (whollLine[i] == '/' && whollLine[i + 1] == '/') break;
            input += whollLine[i];
        }

        if (input.size() == 0) continue;
        fileContent.push_back(input);
        input = "";
    }
    fileIn.close();

    // Set seed to random
    srand(stoul(fileContent[0], nullptr, 0));

    // Building groups and their members
    std::vector<Group> groups;
    for (unsigned i = 3; i < stoul(fileContent[1]) * 11; i += 11) {
        // "i = 3" = first group line ; "i += 11" = lines between two groups ; "fileContent[1]" = number of groups
        Group newGroup = Group(fileContent[i]);
        newGroup.buildGroup(fileContent, i + 1);
        groups.push_back(newGroup);
    }

    // Open and setup to write in the out file
    std::fstream logFile;
    logFile.open("TextFiles/FileOut1.txt", std::ios::out); // write mod


    /* Start Tournament
    *  Round 1
    *  For the 1st round, all groups are 0 point so we don't need to sort and check points them
    */
    LaunchRound(logFile, groups, text1, "CaptainAge");
    for (unsigned i = 0; i < groups.size(); ++i) {
        std::cout << groups[i].name << " : ";
        for (unsigned j = 0; j < groups[i].groupsFought.size(); ++j) {
            std::cout << groups[i].groupsFought[j].name << ", ";
        }
        std::cout << std::endl << std::endl;
    }

    // Round 2
    LaunchRound(logFile, groups, text2, "TicTacToe");

    // Round 3
    LaunchRound(logFile, groups, text3, "HeadsOrTails");

    // Round 4
    LaunchRound(logFile, groups, text4, "Hangman");

    // Result Tournament
    for (unsigned i = 0; i < groups.size(); ++i) {
        std::cout << groups[i].name << " : ";
        for (unsigned j = 0; j < groups[i].groupsFought.size(); ++j) {
            std::cout << groups[i].groupsFought[j].name << ", ";
        }
        std::cout << std::endl << std::endl;
    }
    
    logFile.close();
    return 0;
}