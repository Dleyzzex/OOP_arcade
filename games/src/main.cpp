/*
** EPITECH PROJECT, 2020
** ma
** File description:
** main
*/

#include "Arcade_interfaces.hpp"
#include "Ncurses.hpp"
#include <memory>

int main(int argc, char const *argv[])
{
    Pacman n;
    while (1) {
        n.update();
    }
    return 0;
}