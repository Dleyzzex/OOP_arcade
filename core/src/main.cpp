/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "core.hpp"
#include <iostream>

std::string getOneName(std::string src)
{
    std::string dest;
    size_t i = src.find_last_of('_') + 1;

    for (size_t j = i; j < src.size() && src[j] != '.'; j++)
        dest.push_back(src[j]);
    return (dest);
}

std::vector<std::string> getNames(std::vector<std::string> src)
{
    std::vector<std::string> dest;

    for (size_t i = 0; i < src.size(); i++) {
        dest.push_back(getOneName(src.at(i)));
    }
    return (dest);
}

int main(int ac, char **av)
{
    std::unique_ptr<core> Core;
    std::string libs(LIBS);
    std::string games(GAMES);
    size_t lIndex = 0;

    (void) ac;
    (void) av;
    std::vector<std::string> libnames = getFilenames(libs);
    std::vector<std::string> gamenames = getFilenames(games);
    if (ac == 2) {
        std::string tmp(av[1]);
        size_t find = tmp.find(".so");
        if (find == std::string::npos)
            exit(84);
        std::string lib = getOneName(tmp);
        std::vector<std::string> names = getNames(libnames);
        for (size_t i = 0; i < names.size(); i++)
            if (names.at(i) == lib) {
                lIndex = i;
            }
        Core = std::make_unique<core>(libnames, gamenames, lIndex);
    } else {
        Core = std::make_unique<core>(libnames, gamenames);
    }
    return (0);
}