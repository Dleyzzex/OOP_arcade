/*
** EPITECH PROJECT, 2020
** core
** File description:
** core
*/

#ifndef CORE_HPP
#define CORE_HPP

#define LIBS "./lib/"
#define GAMES "./games/"

#include <memory>
#include <map>
#include <vector>
#include "DLLoader.hpp"
#include "Arcade_interfaces.hpp"
#include "menu.hpp"

class core
{
public:
    core(std::vector<std::string>, std::vector<std::string>);
    ~core();
private:
    // Hold the name and the ptr to a DLLoader
    std::map<std::string, std::unique_ptr<DLLoader<std::unique_ptr<IDisplayModule>>>> glibs;
    std::map<std::string, std::unique_ptr<DLLoader<std::unique_ptr<IGameModule>>>> games;
    // Hold the name of each elements in /lib and /games
    std::vector<std::string> libnames;
    std::vector<std::string> gamenames;
    // Current Game/Lib
    std::unique_ptr<IDisplayModule> lib;
    std::unique_ptr<IGameModule> game;
    // Index of the Current Game/Lib
    int lIndex;
    int gIndex;
    // Menu of the Arcade
    std::unique_ptr<menu> Menu;
    // Determine which needs to be display Menu/Game
    bool isMenu;
    // Load Game/Lib
    void loadLib(void);
    void loadGame(void);
    // Start arcade
    void launch(void);
    // Update Game/Lib
    void playGame();
    void updateLib();
    // Update Menu
    void updateMenu();
    // Get a Game/Lib
    std::unique_ptr<IDisplayModule> getLib(std::string);
    std::unique_ptr<IGameModule> getGame(std::string);
    // Change the Current Lib/Game
    void changeLib(int direction);
    void changeGame(int direction);
};

void checkErrors(int ac, char **av);
std::vector<std::string> getFilenames(std::string path);

#endif