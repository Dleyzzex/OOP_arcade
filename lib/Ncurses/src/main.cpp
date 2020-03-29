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
    Ncurses Arkedia;// std::unique_ptr<IDisplayModule> Arkedia = std::make_unique<Ncurses>();
    Arkedia.open();
    while (Arkedia.isOpen()) {
        //    Arkedia.clear();
           Arkedia.setColor(IDisplayModule::Colors::BLUE);
    //     // Arkedia->putFillCircle(100, 100, 30);
    //     // Arkedia->setColor(IDisplayModule::Colors::LIGHT_RED);
            init_pair(3, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(3));
        printw("Ccccccccccccccgb");
            //Arkedia.putPixel(20, 10);
    //     // Arkedia->setColor(IDisplayModule::Colors::LIGHT_GREEN);
    //     // Arkedia->putRect(300, 100, 50, 50);
    //     // Arkedia->putText("Arkedia", 30, 400, 100);
    //     // Arkedia->render();
    //     // if (Arkedia->isKeyPressed(IDisplayModule::Keys::A))
    //     //     printf("yes\n");
    }
    return 0;
}