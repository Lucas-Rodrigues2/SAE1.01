#ifndef TEXTASCII_H
#define TEXTASCII_H

#include <iostream>
#include <vector>


// Text
const std::vector<std::string> textRound = {     
"██████   ██████  ██    ██ ███    ██ ██████ ",
"██   ██ ██    ██ ██    ██ ████   ██ ██   ██",
"██████  ██    ██ ██    ██ ██ ██  ██ ██   ██",
"██   ██ ██    ██ ██    ██ ██  ██ ██ ██   ██",
"██   ██  ██████   ██████  ██   ████ ██████ "};

const std::vector<std::string> textMatch = {
"┌┐┌┌─┐┬ ┬  ┌┬┐┌─┐┌┬┐┌─┐┬ ┬",
"│││├┤ │││  │││├─┤ │ │  ├─┤",
"┘└┘└─┘└┴┘  ┴ ┴┴ ┴ ┴ └─┘┴ ┴"};

const std::vector<std::string> textResult = {
"┬─┐┌─┐┌─┐┬ ┬┬ ┌┬┐┌─┐┌┬┐",
"├┬┘├┤ └─┐│ ││  │ ├─┤ │",
"┴└─└─┘└─┘└─┘┴─┘┴ ┴ ┴ ┴"};

// Numbers
const std::vector<std::string> text1 = {
"  ██",
"████",
"  ██",
"  ██",
"  ██"};

const std::vector<std::string> text2 = { 
"██████",
"     ██",
" █████",  
"██",
"███████"};

const std::vector<std::string> text3 = {
"██████",
"     ██ ",
" █████",
"     ██",
"██████"};

const std::vector<std::string> text4 = {
"██   ██",
"██   ██",
"███████",
"     ██",
"     ██"};

const std::vector<std::string> text5 = {
"███████",
"██",
"███████",
"     ██",
"███████"};

#endif