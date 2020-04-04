/*
** EPITECH PROJECT, 2020
** game
** File description:
** game
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <memory>
#include "Arcade_interfaces.hpp"

class game : public IGameModule
{
private:
    std::string name;
    std::pair<std::string, int> score;
    std::vector<std::pair<std::string, int>> bestScores;
public:
    game();
    ~game();
    // Reset game at any moment
    void reset();

    // Load highscores from file and return wether it worked or not
    bool loadFromFile(const std::string &filepath); // with filename
    bool loadFromFile(); // default filename

    // save highscores to file return wether it worked or not
    bool saveToFile(const std::string &filepath) const; // with filename
    bool saveToFile() const; // default filename

    // Highscores are stored as such :
    // "name:value\n
    // name2:value2\nEOF"
    // Set the player's name for the highscore
    void setPlayerName(const std::string &name);
    // get the current score
    std::pair<std::string, int> getScore() const;

    // get the 16 best scores
    std::vector<std::pair<std::string, int>> getBestScores() const;

    // Handle Game
    // update game
    void update(const IDisplayModule &lib);

    // display stuff using the lib given as an argument.
    void render(IDisplayModule &lib) const;
    const std::string &getLibName() const;
};

#endif