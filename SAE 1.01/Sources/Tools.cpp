// Include natif librairies
#include <algorithm>

// Include personal files
#include "../Headers/Tools.h"


// Structures constructors and methods defines
Person::Person(const std::string & _lastName, const std::string & _firstName) {
    lastName = _lastName;
    FirstName = _firstName;
}


Group::Group(const std::string & groupName) {
    name = groupName;
    points = 0.0;
    hasOpponent = false;
}

void Group::buildGroup(const std::vector<std::string> & fileContent, const unsigned & lineStart) {
    std::string currentLastName;
    std::string currentFirstName;
    unsigned posDelimeter;
    
    for (unsigned i = 0; i < std::stoul(fileContent[2]); ++i) { //"fileContent[2]" = nombre de membres par groupes
        posDelimeter = fileContent[lineStart + i].find_first_of(' ');
        currentLastName = fileContent[lineStart + i].substr(0, posDelimeter);
        currentFirstName = fileContent[lineStart + i].substr(posDelimeter + 1);

        members.push_back(Person(currentLastName, currentFirstName));
    }
}

bool Group::isPreviousOpponent(const Group & currentGroup) {
    for (unsigned short i = 0; i < groupsFought.size(); ++i) {
        if (currentGroup.name == groupsFought[i].name)
            return true;
    }
    
    return false;
}

Group & Group::findOpponent(std::vector<Group> & allGroups) {
    unsigned indexMatch = allGroups.size();
    
    for (unsigned i = 0; i < allGroups.size(); ++i) {
        if (allGroups[i].hasOpponent || isPreviousOpponent(allGroups[i])) continue;

        if (indexMatch == allGroups.size()) {
            indexMatch = i;
            continue;
        }

        if (abs(points - allGroups[i].points) < abs(points - allGroups[indexMatch].points)) {
            indexMatch = i;
        }
    }

    allGroups[indexMatch].hasOpponent = true;
    allGroups[indexMatch].groupsFought.push_back(*this);
    return allGroups[indexMatch];
}

// Functions
void showAsciiText(std::fstream & logFile, const std::vector<std::string> & text,
                   const std::vector<std::string> & numberturn) {
    for (unsigned short i = 0; i < text.size(); ++i) {
        logFile << std::endl << text[i] << "\t\t" << numberturn[i];
    }

    logFile << std::endl;
}

void showRanking(std::fstream & logFile, std::vector<Group> & allGroups, const std::vector<std::string> & text) {
    std::sort(allGroups.begin(), allGroups.end(), orderDescendingGroups);
    showAsciiText(logFile, text, {5, ""});

    logFile << "Classement  -  Groupe  -  Points" << std::endl;

    for (unsigned i = 0; i < allGroups.size(); ++i) {
        logFile << i + 1 << ":\t" << allGroups[i].name << '\t' << allGroups[i].points
                << std::endl;
    }
}

bool orderDescendingGroups(const Group & group1, const Group & group2) {
    return group1.points > group2.points;
}