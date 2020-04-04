/*
** EPITECH PROJECT, 2020
** Pacmap.hpp
** File description:
** Pacmap.hpp
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_


#include <ncurses.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
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
#include <Arcade_interfaces.hpp>

class Pacman : public IGameModule{
    public:
        Pacman();
        ~Pacman();
        void InitMap(void);
        void InitSuperFood(void);
        void InitGhost(void);
        void InitFood(void);
        void InitPacman(void);
        void Moving(void);
        void nb_zero(int i);
        void nb_one(int i);
        void nb_two(int i);
        void nb_three(int i);
        bool CanMove(void);
        bool doesittouch();
        void MovePacman(void);
        void gain_coin(void);
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
        // get the best score
        std::tuple<std::string, int> getHighscore() const;
        // get the 16 best scores
        std::vector<std::tuple<std::string, int>> getLatestScores() const;

        // Handle Game
        // update game
        void update(const IDisplayModule &lib);
        // display stuff using the lib given as an argument.
        void render(IDisplayModule &lib) const;
        const std::string &getGameName() const;
    protected:
    private:
        std::vector<std::string> _MapTmp;
        int _FoodRemaining;
        int _LifeRemaining;
        std::vector<std::string> _Map;
        std::pair<int, int> _Pacman;
        std::map<int, std::pair<int, int>> _Ghost;
        std::map<int, std::pair<int, int>> _Food;
        std::map<int, std::pair<int, int>> _SuperFood;
        int _direction;
        int _powerup;
        bool _can_go;
        bool _can_move;
        std::string _name;
        std::string _Score;
};
char *  itoa ( int value, char * str, int base );

#endif /* !PACMAN_HPP_ */
