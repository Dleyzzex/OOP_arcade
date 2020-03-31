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

class Pacman {
    public:
        Pacman();
        ~Pacman();
        void InitMap(void);
        void InitSuperFood(void);
        void InitGhost(void);
        void InitFood(void);
        void InitPacman(void);
        void Update(void);

    protected:
    private:
        int _FoodRemaining;
        int _LifeRemaining;
        std::vector<std::string> _Map;
        std::pair<int, int> _Pacman;
        std::map<int, std::pair<int, int>> _Ghost;
        std::map<int, std::pair<int, int>> _Food;
        std::map<int, std::pair<int, int>> _SuperFood;
};

#endif /* !PACMAN_HPP_ */
