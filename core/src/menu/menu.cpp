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

void menu::render(IDisplayModule &lib)
{
    lib.putFillCircle(20, 20, 20);
    lib.putFillRect(30,30,50,20);
    lib.putText(GAMENAME, 50, 40, 40);
    lib.putText(gamename.c_str(), 50, 100, 400);
    lib.render();
}

void menu::update(IDisplayModule &lib, IGameModule &game)
{
    this->gamename = game.getLibName();
    lib.update();
    lib.clear();
    lib.setColor(IDisplayModule::Colors::RED);
}

//         Arkedia->update();

//         Arkedia->clear();
//         Arkedia->setColor(IDisplayModule::Colors::BLUE);
//         Arkedia->putFillCircle(100, 100, 30);
//         Arkedia->setColor(IDisplayModule::Colors::LIGHT_RED);
//         Arkedia->putPixel(200, 100);
//         Arkedia->setColor(IDisplayModule::Colors::LIGHT_GREEN);
//         Arkedia->putRect(300, 100, 50, 50);
//         if (Arkedia->isKeyPressedOnce(IDisplayModule::Keys::A))
//             Arkedia->putText("Arkedia", 30, 400, 100);
//         Arkedia->render();
//     }
//     return 0;
// }