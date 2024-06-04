#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>
enum Commands
{
    mkdir = 1,
    rmdir = 2,
    ls = 3,
    cd = 4,
    touch = 5,
    rm = 6,
    find = 7,
    exit = 8,
    mv = 9,
    vi = 10,
    cat = 11,
    cd_nested = 12
};

std::map<Commands, std::string> commandsToString = {{mkdir, "mkdir"},
                                    {rmdir, "rmdir"},
                                    {ls, "ls"},{cat,"cat"},{cd_nested,"cd_nested"},{cd,"cd"},{touch,"touch"},{rm,"rm"},{find,"find"},{exit,"exit"},{mv,"mv"},{vi,"vi"}};

#endif