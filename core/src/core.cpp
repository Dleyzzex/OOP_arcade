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
        this->games[this->gamenames.at(i)] = std::make_unique<DLLoader<IGameModule>>(GAMES + this->gamenames.at(i));
}

void core::launch(void)
{
    std::map<std::string, std::unique_ptr<DLLoader<std::unique_ptr<IDisplayModule>>>>::iterator j = this->glibs.begin();

    std::unique_ptr<IDisplayModule> &s = (*j->second.get()->getInstance("az"));
    s->open();
    s->update();
    printf("ééé\n");
    while (s->isOpen()) {
        s->update();
        s->clear();
        s->setColor(IDisplayModule::Colors::BLUE);
        s->putFillCircle(100, 100, 30);
        s->setColor(IDisplayModule::Colors::LIGHT_RED);
        s->putPixel(200, 100);
        s->setColor(IDisplayModule::Colors::LIGHT_GREEN);
        s->putRect(300, 100, 50, 50);
        if (s->isKeyPressedOnce(IDisplayModule::Keys::A))
            s->putText("s", 30, 400, 100);
        s->render();
    }
}

/*
    MAP -> ne stocke que des DLLoader, lorsque le core appelle un circuit celui ci lui envoie loaderGame->GetInstance et loaderLib->GetInstance
    Cela permet de conserver les dlloader afin de les close plus tard
    --> Encapsulation
*/
