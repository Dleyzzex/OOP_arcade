/*
** EPITECH PROJECT, 2020
** Ncurses.hpp
** File description:
** Class lib Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

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

class Ncurses {
    public:
        Ncurses();
        ~Ncurses();
        int Snake(int ac, char **av);
        void EndWindows(void);
        void ClearWindows(void);
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
        int GetMove(int _direction);
        void PrintGame(void);
        void witch_color(std::string str);
        std::vector<std::string> FillMyMap(void);

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
    protected:
    private:
        std::vector<std::string> _Map;
        std::map<int, std::pair<int, int>> _Snake;
        std::pair<int, int> _Food;
        int _direction;
        bool _can_go;
};

#endif /* !NCURSES_HPP_ */