/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/

#ifndef MENU_HPP
#define MENU_HPP

#define GAMENAME "Arkédia"

#include "Arcade_interfaces.hpp"
#include <memory>

class menu
{
private:
    bool open;
    std::string gamename;
public:
    menu();
    ~menu();
    bool isOpen(void);
    void setOpen(bool);
    void render(IDisplayModule &lib);
    void update(IDisplayModule &lib, IGameModule &game);
};

#endif
