#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>
enum class Commands
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

const std::map<Commands, std::string> commandsToString = {{Commands::mkdir, "mkdir"},
                                                          {Commands::rmdir, "rmdir"},
                                                          {Commands::ls, "ls"},
                                                          {Commands::cat, "cat"},
                                                          {Commands::cd_nested, "cd_nested"},
                                                          {Commands::cd, "cd"},
                                                          {Commands::touch, "touch"},
                                                          {Commands::rm, "rm"},
                                                          {Commands::find, "find"},
                                                          {Commands::exit, "exit"},
                                                          {Commands::mv, "mv"},
                                                          {Commands::vi, "vi"}};

#endif