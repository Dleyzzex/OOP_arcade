/*
** EPITECH PROJECT, 2020
** Snake.hpp
** File description:
** Class lib Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

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
#include "Arcade_interfaces.hpp"

class Snake : public IGameModule {
    public:
        Snake();
        ~Snake();
        void RemoveFood(void);
        void Eat(void);
        void MoveSnake(void);
        void AddSnake(int size);
        void InitFood(void);
        bool DontTouchSnake(int nb1, int nb2);
        void InitSnake(void);
        bool CanMove(void);
        bool doesittouch(void);
        int SizeMap(void);
        void PrintGame(void);
        std::vector<std::string> FillMyMap(void);
        void update(const IDisplayModule &lib);
        void render(IDisplayModule &lib) const;
        enum Keys {
            LEFT,
            RIGHT,
            UP,
            DOWN,
            Z,
            Q,
            S,
            D,
            A,
            E,
            W,
            X,
            SPACE,
            ESCAPE,
            J,
            K,
            U,
            I,
            M,
            R,
            ENTER,
            BACKSPACE,
            KEYS_END
        };

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

    const std::string &getLibName() const;

    private:
        std::vector<std::string> _Map;
        std::map<int, std::pair<int, int>> _Snake;
        std::pair<int, int> _Food;
        int _direction;
        bool _can_go;
        std::string _name;
        std::vector<std::string> _MapTmp;
};

#endif /* !Snake_HPP_ */
