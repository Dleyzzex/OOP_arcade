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
    std::vector<std::string> libnames;
    std::vector<std::string> gamenames;
public:
    menu();
    menu(std::vector<std::string>, std::vector<std::string>);
    ~menu();
    bool isOpen(void);
    void setOpen(bool);
    std::string getOneName(std::string);
    std::vector<std::string> getNames(std::vector<std::string>);
    void render(IDisplayModule &lib);
    void update(IDisplayModule &lib, IGameModule &game);
};

#endif