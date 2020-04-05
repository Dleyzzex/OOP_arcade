/*
** EPITECH PROJECT, 2020
** Pacmap.hpp
** File description:
** Pacmap.hpp
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#define XORD 30
#define YORD 5
#define MANSIZE 10
#define GHOSTSIZE 8
#define MANSPEED 1
#define SPEED 10

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>
#include <map>
#include <ostream>
#include "Arcade_interfaces.hpp"

class Pacman : public IGameModule {
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
        void gain_coin(void);

        void movePacman(int);
        void moveGhost(int);

        bool checkDirection(size_t);

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

        // Handle Game
        // update game
        void update(const IDisplayModule &lib);

        // display stuff using the lib given as an argument.
        void render(IDisplayModule &lib) const;
        const std::string &getLibName() const;

    private:
        /*
        bool _can_go;
        bool _can_move;
        int _FoodRemaining;
        int _LifeRemaining;
        int _direction;
        int _powerup;
        std::string _Score;
        std::pair<int, int> _Pacman;
        std::vector<std::string> _MapTmp;
        std::map<int, std::pair<int, int>> _Ghost;
        std::map<int, std::pair<int, int>> _SuperFood;
        */
        class Man
        {
        public:
            Man();
            Man(int, std::pair<int, int>, IDisplayModule::Colors);
            ~Man();
            // Lives
            void setLives(int);
            int getLives() const;
            // Direction
            void setDirection(int);
            int getDirection() const;
            // Position
            void setPosition(std::pair<int, int>);
            std::pair<int, int> getPosition() const;
            // Color
            void setColor(IDisplayModule::Colors);
            IDisplayModule::Colors getColor(void) const;
        private:
            int lives;
            int direction;
            std::pair<int, int> position;
            IDisplayModule::Colors color;
        };

        std::string gameName;
        std::unique_ptr<Man> pacman;
        std::vector<std::unique_ptr<Man>> ghost;
        std::vector<std::string> map;
        std::vector<std::unique_ptr<Man>> getGhosts(void);
        std::vector<std::pair<bool, std::pair<int, int>>> food;
        void checkCollisions(void);
        bool asWon(void);
        bool won;
        bool lost;
        int speed;
        int direction;
        int direct;
};
char *itoa(int value, char * str, int base);

#endif /* !PACMAN_HPP_ */
