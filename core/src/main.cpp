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
    // try {
    //     checkErrors(ac, av);
    // } catch(const std::exception& e) {
    //     std::cerr << e.what() << '\n';
    // }
    std::vector<std::string> libnames = getFilenames(libs);
    std::vector<std::string> gamenames = getFilenames(games);
    for (size_t i = 0; i < gamenames.size(); i++)
        std::cout << gamenames.at(i) << std::endl;
    Core = std::make_unique<core>(libnames, gamenames);
    return (0);
}