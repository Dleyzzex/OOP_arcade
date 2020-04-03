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
        void witch_color(std::string str);
        void Moving(void);
        void nb_zero(int i);
        void nb_one(int i);
        void nb_two(int i);
        void nb_three(int i);
        int GetMove(int _direction);
        bool CanMove(void);
        bool doesittouch(int dir);
        void MovePacman(void);
        void gain_coin(void);
    protected:
    private:
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
};
char *  itoa ( int value, char * str, int base );

#endif /* !PACMAN_HPP_ */
