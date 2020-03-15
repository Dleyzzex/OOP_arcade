/*
** EPITECH PROJECT, 2020
** ma
** File description:
** main
*/

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

std::vector<std::string> FillMyMap(char **av)
{
    std::vector<std::string> _map;
    std::string _Line;
    std::ifstream myfile(av[1], std::ifstream::in);
    if (myfile.is_open()) {
        for  (size_t i = 0; getline(myfile, _Line); i++) {
            _Line += '\n';
            _map.push_back(_Line);
        }
    }
    return (_map);
}

void witch_color(std::string str)
{
    if (str == "#") {
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        printw(str.c_str());
    }
    else if (str == "x") {
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(3));
        printw(str.c_str());
    }
    else if (str == "o") {
        init_pair(4, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(4));
        printw(str.c_str());
    }
    else
        printw(str.c_str());
}

void PrintMap(std::vector<std::string> _map)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
    for (size_t i = 0; i != _map.size(); i++) {
        for (size_t j = 0; j != _map[i].size(); j++) {
            std::string str(1, _map[i][j]);
            witch_color(str);
        }
    }
}

void PrintGame(char *av, std::map<int , std::pair<int, int>> _Snake)
{
    std::vector<std::string> _map;
    std::string _Line;
    std::ifstream myfile(av, std::ifstream::in);
    if (myfile.is_open()) {
        for  (size_t i = 0; getline(myfile, _Line); i++) {
            _Line += '\n';
            _map.push_back(_Line);
        }
    }
    int ko = 1;
    for (auto i = _Snake.begin(); i != _Snake.end(); i++, ko++) {
        _map[_Snake.at(ko).first][_Snake.at(ko).second] = 'x';
    }
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(1));
    for (size_t i = 0; i != _map.size(); i++) {
        for (size_t j = 0; j != _map[i].size(); j++) {
            std::string str(1, _map[i][j]);
            witch_color(str);
        }
    }
}

int GetMove(int _direction)
{
    int ch = getch();
    switch (ch) {
        case KEY_LEFT:
            return 2;
        case KEY_RIGHT:
            return 1;
        case KEY_DOWN:
            return 4;
        case KEY_UP:
            return 3;
        default:
            return _direction;
    }
}

bool CanMove(std::vector<std::string> _map, std::map<int, std::pair<int, int>> _Snake, int _direction)
{
    if (_direction == 1)
        if (_map[_Snake.at(1).first][_Snake.at(1).second + 1] != ' ' && _map[_Snake.at(1).first][_Snake.at(1).second + 1] != 'o')
            return (FALSE);
    if (_direction == 2)
        if (_map[_Snake.at(1).first][_Snake.at(1).second - 1] != ' ' && _map[_Snake.at(1).first][_Snake.at(1).second - 1] != 'o')
            return (FALSE);
    if (_direction == 3)
        if (_map[_Snake.at(1).first - 1][_Snake.at(1).second] != ' ' && _map[_Snake.at(1).first - 1][_Snake.at(1).second] != 'o')
            return (FALSE);
    if (_direction == 4)
        if (_map[_Snake.at(1).first + 1][_Snake.at(1).second] != ' ' && _map[_Snake.at(1).first + 1][_Snake.at(1).second] != 'o')
            return (FALSE);
    return (TRUE);
}

int SizeMap(std::map<int, std::pair<int, int>> _Snake)
{
    int ko = 0;
    for (auto i = _Snake.begin(); i != _Snake.end(); i++, ko++);
    return (ko);
}

std::map<int , std::pair<int, int>> InitSnake(std::map<int , std::pair<int, int>> _Snake)
{
    _Snake.insert({1, {10, 6}});
    _Snake.insert({2, {10, 5}});
    _Snake.insert({3, {10, 4}});
    return (_Snake);
}

std::map<int, std::pair<int, int>> AddSnake(std::map<int, std::pair<int, int>> _Snake, int size)
{
    _Snake.insert({size+1, {_Snake.at(size).first, _Snake.at(size).second}});
    return (_Snake);
}

std::map<int, std::pair<int, int>> MoveSnake(std::map<int, std::pair<int, int>> _Snake, int _direction)
{
    int ko = 1;
    int first = _Snake.at(ko).first;
    int second = _Snake.at(ko).second;
    int first1 = _Snake.at(ko).first;
    int second1 = _Snake.at(ko).second;
    int tmp = 0;
    if (_direction == 1)
        _Snake.at(ko) = {_Snake.at(ko).first, _Snake.at(ko).second + 1};
    if (_direction == 2)
        _Snake.at(ko) = {_Snake.at(ko).first, _Snake.at(ko).second - 1};
    if (_direction == 3)
        _Snake.at(ko) = {_Snake.at(ko).first - 1, _Snake.at(ko).second};
    if (_direction == 4)
        _Snake.at(ko) = {_Snake.at(ko).first + 1, _Snake.at(ko).second};
    for (auto i = _Snake.begin(); ko < SizeMap(_Snake); i++, ko++, tmp++) {
        if (tmp % 2 == 0) {
            first1 = _Snake.at(ko+1).first;
            second1 = _Snake.at(ko+1).second;
            _Snake.at(ko+1) = {first, second};

        }
        if (tmp % 2 == 1) {
            first = _Snake.at(ko+1).first;
            second = _Snake.at(ko+1).second;
            _Snake.at(ko+1) = {first1, second1};
        }
    }
    return (_Snake);
}

std::map<int, std::pair<int, int>> Eat(std::vector<std::string> _map, std::map<int, std::pair<int, int>> _Snake, int _direction)
{
    if (_direction == 1)
        if (_map[_Snake.at(1).first][_Snake.at(1).second + 1] == 'o')
            _Snake = AddSnake(_Snake, SizeMap(_Snake));
    if (_direction == 2)
        if (_map[_Snake.at(1).first][_Snake.at(1).second - 1] == 'o')
            _Snake = AddSnake(_Snake, SizeMap(_Snake));
    if (_direction == 3)
        if (_map[_Snake.at(1).first - 1][_Snake.at(1).second] == 'o')
            _Snake = AddSnake(_Snake, SizeMap(_Snake));
    if (_direction == 4)
        if (_map[_Snake.at(1).first + 1][_Snake.at(1).second] == 'o')
            _Snake = AddSnake(_Snake, SizeMap(_Snake));
    return (_Snake);
}

int Ncurses(int ac, char **av)
{
    initscr();
    if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    std::vector<std::string> _map = FillMyMap(av);
    PrintMap(_map);
    timeout(100);
    int _direction = 1;
    bool _can_go = TRUE;
    std::map<int , std::pair<int, int>> _Snake;
    _Snake = InitSnake(_Snake);
    // int ko = 1;
    // for (auto i = _Snake.begin(); i != _Snake.end(); i++, ko++) {
    //     std::cout << "first -> " << _Snake.at(ko).first << "  second -> " << _Snake.at(ko).second << std::endl;
    // }
    // std::cout << "\n\n\n";
    _Snake = MoveSnake(_Snake, _direction);
    // ko = 1;
    // for (auto i = _Snake.begin(); i != _Snake.end(); i++, ko++) {
    //     std::cout << "first -> " << _Snake.at(ko).first << "  second -> " << _Snake.at(ko).second << std::endl;
    // }
    while (1) {
        PrintGame(av[1], _Snake);
        _direction = GetMove(_direction);
        _can_go = CanMove(_map, _Snake, _direction);
        _Snake = Eat(_map, _Snake, _direction);
        //_Snake = AddSnake(_Snake, SizeMap(_Snake));
        _Snake = MoveSnake(_Snake, _direction);
        if (_can_go == FALSE)
            break;
        refresh();
        clear();
    }
    endwin();
    return 0;
}

int main(int ac, char **av)
{
    Ncurses(ac, av);
    return (0);
}