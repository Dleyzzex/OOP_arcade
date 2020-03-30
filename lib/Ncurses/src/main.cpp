/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "Arcade_interfaces.hpp"
#include "Ncurses.hpp"
#include <memory>

int main(int argc, char const *argv[])
{
    std::unique_ptr<IDisplayModule> Arkedia = std::make_unique<Ncurses>();
    Arkedia->open();
    while (Arkedia->isOpen()) {
        Arkedia->clear();
          Arkedia->setColor(IDisplayModule::Colors::BLUE);
        Arkedia->putFillCircle(330, 110, 100);
       Arkedia->putPixel(80, 320);
       Arkedia->putLine(100, 50, 400, 50);
        Arkedia->setColor(IDisplayModule::Colors::LIGHT_GREEN);
     Arkedia->putFillRect(300, 100, 50, 50);
        Arkedia->putText("Arkedia", 30, 400, 100);
    // //     // if (Arkedia->isKeyPressed(IDisplayModule::Keys::A))
    // //     //     printf("yes\n");
        Arkedia->render();
        getch();
}
    return 0;
}