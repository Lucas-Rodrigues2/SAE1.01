#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <vector>
#include <fstream>


// Structures
struct Person {
    std::string lastName;
    std::string FirstName;

    Person(const std::string & _lastName, const std::string & _firstName);
};

struct Group {
    std::vector<Person> members;
    std::vector<Group> groupsFought;
    std::string name;
    float points;
    bool hasOpponent;

    Group(const std::string & groupName);

    void buildGroup(const std::vector<std::string> & fileContent, const unsigned & lineStart);
    bool isPreviousOpponent(const Group & currentGroup);
    Group & findOpponent(std::vector<Group> & allGroups);
};

// Functions
void showAsciiText(std::fstream & logFile, const std::vector<std::string> & text, const std::vector<std::string> & numberturn);
void showRanking(std::fstream & logFile, std::vector<Group> & allGroups, const std::vector<std::string> & text);
bool orderDescendingGroups(const Group & group1, const Group & group2);

#endif