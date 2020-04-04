/*
** EPITECH PROJECT, 2020
** game
** File description:
** game
*/

#include "game.hpp"

game::game()
{
    this->name = "AZE";
}

game::~game()
{
}

void game::reset(void)
{
}

bool game::loadFromFile(const std::string &filepath)
{
    (void) filepath;
    return (true);
}

bool game::loadFromFile(void)
{
    return (true);
}

bool game::saveToFile(const std::string &filepath) const
{
    (void) filepath;
    return (true);
}

bool game::saveToFile(void) const
{
    return (true);
}

std::pair<std::string, int> game::getScore(void) const
{
    return (this->score);
}

std::vector<std::pair<std::string, int>> game::getBestScores(void) const
{
    return (this->bestScores);
}

void game::setPlayerName(const std::string &name)
{
    (void) name;
}

void game::update(const IDisplayModule &lib)
{
    // update les valeurs des joueurs, du score, etc
}

void game::render(IDisplayModule &lib) const
{
    lib.update();
    lib.clear();
    lib.setColor(IDisplayModule::Colors::RED);
    lib.putFillCircle(20,20,20);
    lib.render();
}

const std::string &game::getLibName(void) const
{
    return (this->name);
}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<game>();
}