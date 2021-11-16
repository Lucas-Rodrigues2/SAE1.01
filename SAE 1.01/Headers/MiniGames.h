#ifndef MINIGAMES_H
#define MINIGAMES_H

#include "Tools.h"


void ticTacToe(Group & group1, Group & group2, std::fstream & logFile);
void headsOrTails(Group & group1, Group & group2, std::fstream & logFile);
void hangman(Group & group1, Group & group2, std::fstream & logFile);
std::string captainAge(Group & group1, Group & group2, std::fstream & logFile);

#endif