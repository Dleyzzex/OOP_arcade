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
    this->cursorPos = std::make_pair(30, 300);
    this->idx = std::make_pair(0, 0);
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
    size_t j = 0;
    lib.setColor(IDisplayModule::Colors::CYAN);
    lib.putText("Arkedia",45,WIDTH / 2 - 102,HEIGHT / 2 - 26);
    lib.setColor(IDisplayModule::Colors::MAGENTA);
    lib.putText("Arkedia",45,WIDTH / 2 - 100,HEIGHT / 2 - 25);
    lib.setColor(IDisplayModule::Colors::WHITE);
    for (size_t i = 0; i < this->gamenames.size(); i++) {
        lib.putText(this->gamenames[i],15, 50, 295 + j);
        j += 20;
    }
    j = 0;
    for (size_t i = 0; i < this->libnames.size(); i++) {
        lib.putText(this->libnames[i],15, 450, 295 + j);
        j += 20;
    }
    if (this->selected == 0)
        lib.putRect(this->cursorPos.first, this->cursorPos.second, 8, 8);
    else
        lib.putFillRect(this->cursorPos.first, this->cursorPos.second, 8, 8);
}

void menu::update(IDisplayModule &lib, IGameModule &game, int *gIndex)
{
    int maxGame = this->gamenames.size();
    int maxLib = this->libnames.size();
    lib.clear();
    lib.update();
    this->idxGame = -1;
    this->idxLib = -1;
    this->selected = 0;
    this->gamename = game.getLibName();
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::UP)) {
        this->cursorPos.second -= 20;
        this->idx.second--;
    }
    else if (lib.isKeyPressedOnce(IDisplayModule::Keys::DOWN)) {
        this->cursorPos.second += 20;
        this->idx.second++;
    }
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::RIGHT)) {
        this->cursorPos.first -= 400;
        this->idx.first--;
    }
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::LEFT)) {
        this->cursorPos.first += 400;
        this->idx.first++;
    }
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::ENTER)) {
        if (this->idx.first == 1) {
            this->idxLib = this->idx.second;
            this->selected = 1;
        }
        if (this->idx.first == 0) {
            *gIndex = idx.second;
            this->selected = 1;
            this->open = false;
        }
    }
    if (lib.shouldExit())
        lib.close();
    if (this->idx.first >= 2) {
        this->cursorPos.first = 30;
        this->idx.first = 0;
    } else if (this->idx.first < 0) {
        this->idx.first = 1;
        this->cursorPos.first = 430;
    } else { ; }
    if (this->idx.first == 0) {
        if (this->idx.second >= maxGame) {
            this->cursorPos.second = 300;
            this->idx.second = 0;
        } else if (this->idx.second < 0) {
            this->idx.second = maxGame - 1;
            this->cursorPos.second = 300 + this->idx.second * 20;
        } else { ; }
    }
    if (this->idx.first == 1) {
        if (this->idx.second >= maxLib) {
            this->cursorPos.second = 300;
            this->idx.second = 0;
        } else if (this->idx.second < 0) {
            this->idx.second = maxLib - 1;
            this->cursorPos.second = 300 + this->idx.second * 20;
        } else { ; }
    }
}

int menu::changeLib(void)
{
    return this->idxLib;
}
