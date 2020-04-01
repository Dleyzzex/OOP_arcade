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

void core::launch(void)
{
    std::map<std::string, std::unique_ptr<DLLoader<std::unique_ptr<IDisplayModule>>>>::iterator l = this->glibs.begin();
    //std::map<std::string, std::unique_ptr<DLLoader<std::unique_ptr<IGameModule>>>>::iterator g = this->games.begin();
    std::unique_ptr<IDisplayModule> &lib = (*l->second.get()->getInstance("Lib"));
    // l->second.get()->getInstance("Lib");
    //std::unique_ptr<IGameModule> &game = (*g->second.get()->getInstance("Game"));

    //std::cout << lib->getLibName() << std::endl;

    lib->open();
    lib->update();
    while (lib->isOpen()) {
        lib->clear();
        lib->update();
        lib->setColor(IDisplayModule::Colors::BLUE);
        lib->putRect(10, 10, 40, 40);
        // lib->setColor(IDisplayModule::Colors::GREEN);
        // lib->putFillRect(100, 10, 10, 30);
        // lib->setColor(IDisplayModule::Colors::YELLOW);
        // lib->putPixel(200, 10);
        // lib->setColor(IDisplayModule::Colors::RED);
        // lib->putCircle(300, 300, 60);
        // lib->setColor(IDisplayModule::Colors::MAGENTA);
        // lib->putLine(100, 200, 100, 150);
        // if (lib->isKeyPressed(IDisplayModule::RIGHT))
        lib->render();
    }
}

/*
    MAP -> ne stocke que des DLLoader, lorsque le core appelle un circuit celui ci lui envoie loaderGame->GetInstance et loaderLib->GetInstance
    Cela permet de conserver les dlloader afin de les close plus tard
    --> Encapsulation
*/