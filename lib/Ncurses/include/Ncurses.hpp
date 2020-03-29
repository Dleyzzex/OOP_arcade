/*
** EPITECH PROJECT, 2020
** Class of Ncurses lib
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "../include/Arcade_interfaces.hpp"
#include <ncurses.h>
#include <memory>

#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iterator>
#include <unistd.h>
#include <bits/stdc++.h>

class Ncurses : public IDisplayModule {
    private:
    public:
        Ncurses();
        ~Ncurses();
        // For the core
        // Reset the library
        void reset();
        //open / inits window
        virtual void open();
        // Check if the window is open
        bool isOpen() const;

        // Handle switching libs & games (the names are explicit)
        // Those are all key presses
        // Those must be different than the keys listed in the Keys enum.
        // The keys enum only lists keys used by games, not special keys to switch libraries.
        bool switchToNextLib() const;
        bool switchToPreviousLib() const;
        bool switchToNextGame() const;
        bool switchToPreviousGame() const;
        // From the pdf
        bool shouldBeRestarted() const;
        bool shouldGoToMenu() const;
        bool shouldExit() const;

        // Handle Inputs & Events
        bool KeySet(IDisplayModule::Keys key) const;
        bool isKeyPressed(IDisplayModule::Keys) const;
        bool isKeyPressedOnce(IDisplayModule::Keys) const;
        // Get the number of frames that passed between two calls to this function
        // The games should not be frame dependant!! That's why this is here.
        float getDelta() const;

        // // Handle Loop
        void clear() const;
        void update();
        void render() const;
        // // You don't need all three of them, only one should be enough but we added the three of them
        // in case some of you want to seperate each step
        // Your core (or games) should nonetheless call all of these functions in this specific order :
        // clear -> update -> render

        // Handle Text Input
        // We need to ask for the player's name (check the pdf before complaining and asking about this function)
        // Get key Presses.
        // returns \n if enter was pressed & \0 if nothing was pressed.
        // it returns \b if backspace was pressed (to delete a character from the name).
        char getKeyCode() const;

        // Display Stuff
        // Sets the color for all the following draw functions.
        // everything you display after this will have the selected color
        void setColor(IDisplayModule::Colors col);
        // Display a pixel
        void putPixel(float x, float y) const;
        // Display a line
        void putLine(float x1, float y1, float x2, float y2) const;
        // Display an empty rectangle
        void putRect(float x, float y, float w, float h) const;
        // Display a full rectangle
        void putFillRect(float x, float y, float w, float h) const;
        // Display an empty circle
        void putCircle(float x, float y, float rad) const;
        // Display a full circle
        void putFillCircle(float x, float y, float rad) const;
        // Display some text
        void putText(const std::string &text, unsigned int size, float x, float y) const;

        // We chose not to display images because some library can't and it would cause other problems
        // You can still parse a file and display pixel art images by displaying pixels manually if you want.

        // Strictly for debugging purposes, get the library's name (ncurses/sfm/sdl/libcaca etc etc)
        const std::string &getLibName() const;
};

#endif /*NCURSES_HPP*/