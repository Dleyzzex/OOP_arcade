/*
** EPITECH PROJECT, 2020
** core
** File description:
** core
*/

#include "core.hpp"

core::core(std::vector<std::string> _libnames, std::vector<std::string> _gamenames)
{
    this->libnames = _libnames;
    this->gamenames = _gamenames;
    this->lIndex = 0;
    this->gIndex = 0;
    this->isMenu = true;
    loadLib();
    loadGame();
    launch();
}

core::~core()
{
}

void core::loadLib(void)
{
    for (unsigned int i = 0; i < this->libnames.size(); i++)
        this->glibs[this->libnames.at(i)] = std::make_unique<DLLoader<std::unique_ptr<IDisplayModule>>>(LIBS + this->libnames.at(i));
}

void core::loadGame(void)
{
    for (unsigned int i = 0; i < this->gamenames.size(); i++)
        this->games[this->gamenames.at(i)] = std::make_unique<DLLoader<std::unique_ptr<IGameModule>>>(GAMES + this->gamenames.at(i));
}

std::unique_ptr<IDisplayModule> core::getLib(std::string str)
{
    std::map<std::string, std::unique_ptr<DLLoader<std::unique_ptr<IDisplayModule>>>>::iterator l = glibs.find(str);
    std::unique_ptr<DLLoader<std::unique_ptr<IDisplayModule>>> &tmp = l->second;

    return (tmp->getInstance(LIBS + str));
}

std::unique_ptr<IGameModule> core::getGame(std::string str)
{
    std::map<std::string, std::unique_ptr<DLLoader<std::unique_ptr<IGameModule>>>>::iterator g = games.find(str);
    std::unique_ptr<DLLoader<std::unique_ptr<IGameModule>>> &tmp = g->second;

    return (tmp->getInstance(GAMES + str));
}

void core::launch(void)
{
    lib = getLib(libnames.at(lIndex));
    game = getGame(gamenames.at(gIndex));
    Menu = std::make_unique<menu>(libnames, gamenames);

    lib->open();
    lib->update();
    while (lib->isOpen() == true) {
        updateLib();
        this->isMenu = Menu->isOpen();
        if (isMenu == true) {
           updateMenu();
        } else {
            playGame();
        }
    }
}

void core::playGame(void)
{
    game->update(*lib);
    game->render(*lib);
    lib->render();
}

void core::updateMenu(void)
{
    Menu->update(*lib, *game);
    Menu->render(*lib);
}

void core::updateLib(void)
{
    lib->clear();
    lib->update();
    // Change Lib
    if (lib->switchToPreviousLib())
        changeLib(-1);
    if (lib->switchToNextLib())
        changeLib(1);
    // Change Game
    if (lib->switchToPreviousGame())
        changeGame(-1);
    if (lib->switchToNextGame())
        changeGame(1);
    // Manage Arcade
    if (lib->shouldBeRestarted())
        game->reset();
    if (lib->shouldGoToMenu())
        Menu->setOpen(true);
    // Go to selected Game
    if (lib->isKeyPressedOnce(IDisplayModule::Keys::ENTER))
        Menu->setOpen(false);
    // Exit Arcade
    if (lib->shouldExit())
        lib->close();
}

void core::changeLib(int direction)
{
    int index = this->lIndex + direction;

    if (index < 0)
        index = libnames.size();
    if ((size_t)index > libnames.size() - 1)
        index = 0;
    this->lIndex = index;
    this->lib->close();
    this->lib = getLib(libnames.at(lIndex));
    this->lib->open();
    updateLib();
}

void core::changeGame(int direction)
{
    int index = this->gIndex + direction;

    if (index < 0)
        index = gamenames.size();
    if ((size_t)index > gamenames.size() - 1)
        index = 0;
    this->gIndex = index;
    this->game = getGame(gamenames.at(gIndex));
    playGame();
}