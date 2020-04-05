/*
** EPITECH PROJECT, 2020
**
** File description:
** menu
*/

#include "menu.hpp"

menu::menu()
{
    this->open = true;
}

menu::menu(std::vector<std::string> _libnames, std::vector<std::string> _gamenames)
{
    this->open = true;
    this->libnames = getNames(_libnames);
    this->gamenames = getNames(_gamenames);
}

menu::~menu()
{
}

bool menu::isOpen(void)
{
    return (this->open);
}

void menu::setOpen(bool _open)
{
    this->open = _open;
}

std::string menu::getOneName(std::string src)
{
    std::string dest;
    size_t i = src.find_last_of('_') + 1;

    for (size_t j = i; j < src.size() && src[j] != '.'; j++)
        dest.push_back(src[j]);
    return (dest);
}

std::vector<std::string> menu::getNames(std::vector<std::string> src)
{
    std::vector<std::string> dest;

    for (size_t i = 0; i < src.size(); i++) {
        dest.push_back(getOneName(src.at(i)));
    }
    return (dest);
}

void menu::render(IDisplayModule &lib)
{
    lib.setColor(IDisplayModule::Colors::WHITE);
    lib.putFillRect(20,20,20,20);
}

void menu::update(IDisplayModule &lib, IGameModule &game)
{
    this->gamename = game.getLibName();
}