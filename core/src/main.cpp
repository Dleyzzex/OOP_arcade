/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "core.hpp"
#include <iostream>

int main(int ac, char **av)
{
    std::unique_ptr<core> Core;
    std::string libs(LIBS);
    std::string games(GAMES);

    (void) ac;
    (void) av;
    std::vector<std::string> libnames = get_filenames(libs);
    std::vector<std::string> gamenames = get_filenames(libs);
    Core = std::make_unique<core>(libnames, gamenames);
    return (0);
}