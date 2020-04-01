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
    // Load the differents librairy
    void loadLib(void);
    void loadGame(void);
    void launch(void);
};

void checkErrors(int ac, char **av);
std::vector<std::string> getFilenames(std::string path);

#endif