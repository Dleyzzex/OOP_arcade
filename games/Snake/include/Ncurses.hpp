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
#include <Arcade_interfaces.hpp>

class Ncurses : public IGameModule {
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
    void update();
    // display stuff using the lib given as an argument.
    void render(IDisplayModule &lib) const;
    const std::string &getGameName() const;
    protected:
    private:
        std::vector<std::string> _Map;
        std::map<int, std::pair<int, int>> _Snake;
        std::pair<int, int> _Food;
        int _direction;
        bool _can_go;
        std::string _name;
};

#endif /* !NCURSES_HPP_ */
