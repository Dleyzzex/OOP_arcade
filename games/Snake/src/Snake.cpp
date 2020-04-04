/*
** EPITECH PROJECT, 2020
** Lib Snake
** File description:
** fonctions to make a futur lib
*/

#include "Snake.hpp"

Snake::Snake()
{
    this->_name = "Snake";
    this->_Map = FillMyMap();
    this->_direction = 3;
    this->_can_go = TRUE;
    InitSnake();
    MoveSnake();
    InitFood();
}

Snake::~Snake()
{}

std::vector<std::string> Snake::FillMyMap(void)
{
    size_t x_l = 80;
    size_t y_l = 16;
    std::vector<std::string> _map;
    for (size_t y = 0; y < y_l + 1; y++) {
        std::string _Line;
        for  (size_t x = 0; x < x_l + 1; x++) {
            if (y == 0 || y == y_l || x == 0 || x == x_l)
                _Line += '#';
            else
                _Line += ' ';
        }
        _Line += '\n';
        _map.push_back(_Line);
    }
    return (_map);
}

int Snake::SizeMap(void)
{
    int ko = 0;
    for (auto i = this->_Snake.begin(); i != this->_Snake.end(); i++, ko++);
    return (ko);
}

bool Snake::doesittouch(void)
{
    if (this->_direction == 1) {
        int ko = 2;
        for (auto i = this->_Snake.begin(); ko < SizeMap(); i++, ko++)
            if (this->_Snake.at(1).first == this->_Snake.at(ko).first && this->_Snake.at(1).second + 1 == this->_Snake.at(ko).second)
                return (FALSE);
    }
    if (this->_direction == 2) {
        int ko = 2;
        for (auto i = this->_Snake.begin(); ko < SizeMap(); i++, ko++)
            if (this->_Snake.at(1).first == this->_Snake.at(ko).first && this->_Snake.at(1).second - 1 == this->_Snake.at(ko).second)
                return (FALSE);
    }
    if (this->_direction == 3) {
        int ko = 2;
        for (auto i = this->_Snake.begin(); ko < SizeMap(); i++, ko++)
            if (this->_Snake.at(1).first - 1 == this->_Snake.at(ko).first && this->_Snake.at(1).second == this->_Snake.at(ko).second)
                return (FALSE);
    }
    if (this->_direction == 4) {
        int ko = 2;
        for (auto i = this->_Snake.begin(); ko < SizeMap(); i++, ko++)
            if (this->_Snake.at(1).first + 1 == this->_Snake.at(ko).first && this->_Snake.at(1).second == this->_Snake.at(ko).second)
                return (FALSE);
    }
    return (TRUE);
}

bool Snake::CanMove(void)
{
    if (this->_direction == 1)
        if ((this->_Map[this->_Snake.at(1).first][this->_Snake.at(1).second + 1] != ' ' && this->_Map[this->_Snake.at(1).first][this->_Snake.at(1).second + 1] != 'o') || doesittouch() == FALSE)
            return (FALSE);
    if (this->_direction == 2)
        if ((this->_Map[this->_Snake.at(1).first][this->_Snake.at(1).second - 1] != ' ' && this->_Map[this->_Snake.at(1).first][this->_Snake.at(1).second - 1] != 'o') || doesittouch() == FALSE)
            return (FALSE);
    if (this->_direction == 3)
        if ((this->_Map[this->_Snake.at(1).first - 1][this->_Snake.at(1).second] != ' ' && this->_Map[this->_Snake.at(1).first - 1][this->_Snake.at(1).second] != 'o') || doesittouch() == FALSE)
            return (FALSE);
    if (this->_direction == 4)
        if ((this->_Map[this->_Snake.at(1).first + 1][this->_Snake.at(1).second] != ' ' && this->_Map[this->_Snake.at(1).first + 1][this->_Snake.at(1).second] != 'o') || doesittouch() == FALSE)
            return (FALSE);
    return (TRUE);
}

void Snake::InitSnake(void)
{
    this->_Snake.insert({1, {10, 6}});
    this->_Snake.insert({2, {10, 5}});
    this->_Snake.insert({3, {10, 4}});
}

bool Snake::DontTouchSnake(int nb1, int nb2)
{
    int ko = 1;
    for (auto i = this->_Snake.begin(); ko < SizeMap(); i++, ko++) {
        if (this->_Snake.at(ko).first == nb1 && this->_Snake.at(ko).second == nb2)
            return (FALSE);
    }
    return (TRUE);
}

void Snake::InitFood(void)
{
    srand(time(NULL));
    int nb1 = 0;
    int nb2 = 0;
    for (int tmp = 0; tmp != 1;) {
        nb2 = (rand() % 77) + 1;
        nb1 = (rand() % 15) + 1;
        if (this->_Map[nb1][nb2] == ' ' && DontTouchSnake(nb1, nb2) == TRUE)
            tmp = 1;
    }
    this->_Food = {nb1, nb2};
}

void Snake::AddSnake(int size)
{
    this->_Snake.insert({size+1, {this->_Snake.at(size).first, this->_Snake.at(size).second}});
}

void Snake::MoveSnake(void)
{
    int ko = 1;
    int first = this->_Snake.at(ko).first;
    int second = this->_Snake.at(ko).second;
    int first1 = this->_Snake.at(ko).first;
    int second1 = this->_Snake.at(ko).second;
    int tmp = 0;
    if (this->_direction == 1)
        this->_Snake.at(ko) = {this->_Snake.at(ko).first, this->_Snake.at(ko).second + 1};
    if (this->_direction == 2)
        this->_Snake.at(ko) = {this->_Snake.at(ko).first, this->_Snake.at(ko).second - 1};
    if (this->_direction == 3)
        this->_Snake.at(ko) = {this->_Snake.at(ko).first - 1, this->_Snake.at(ko).second};
    if (this->_direction == 4)
        this->_Snake.at(ko) = {this->_Snake.at(ko).first + 1, this->_Snake.at(ko).second};
    for (auto i = this->_Snake.begin(); ko < SizeMap(); i++, ko++, tmp++) {
        if (tmp % 2 == 0) {
            first1 = this->_Snake.at(ko+1).first;
            second1 = this->_Snake.at(ko+1).second;
            this->_Snake.at(ko+1) = {first, second};
        }
        if (tmp % 2 == 1) {
            first = this->_Snake.at(ko+1).first;
            second = this->_Snake.at(ko+1).second;
            this->_Snake.at(ko+1) = {first1, second1};
        }
    }
}

void Snake::Eat(void)
{
    if (this->_direction == 1)
        if (this->_Snake.at(1).first == this->_Food.first && this->_Snake.at(1).second + 1 == this->_Food.second)
            AddSnake(SizeMap());
    if (this->_direction == 2)
        if (this->_Snake.at(1).first == this->_Food.first && this->_Snake.at(1).second - 1 == this->_Food.second)
            AddSnake(SizeMap());
    if (this->_direction == 3)
        if (this->_Snake.at(1).first - 1 == this->_Food.first && this->_Snake.at(1).second == this->_Food.second)
            AddSnake(SizeMap());
    if (this->_direction == 4)
        if (this->_Snake.at(1).first + 1 == this->_Food.first && this->_Snake.at(1).second == this->_Food.second)
            AddSnake(SizeMap());
}

void Snake::RemoveFood(void)
{
    if (this->_direction == 1)
        if (this->_Snake.at(1).first == this->_Food.first && this->_Snake.at(1).second + 1 == this->_Food.second)
            InitFood();
    if (this->_direction == 2)
        if (this->_Snake.at(1).first == this->_Food.first && this->_Snake.at(1).second - 1 == this->_Food.second)
            InitFood();
    if (this->_direction == 3)
        if (this->_Snake.at(1).first - 1 == this->_Food.first && this->_Snake.at(1).second == this->_Food.second)
            InitFood();
     if (this->_direction == 4)
        if (this->_Snake.at(1).first + 1 == this->_Food.first && this->_Snake.at(1).second == this->_Food.second)
            InitFood();
}

void Snake::render(IDisplayModule &lib) const
{
    for (float i = 0; i != this->_MapTmp.size(); i++) {
        for (float j = 0; j != this->_MapTmp[i].size(); j++) {
            std::string str(1, this->_MapTmp[i][j]);
            lib.putText(str, 1, j*16, i*8);
        }
    }
}

void Snake::update(const IDisplayModule &lib)
{
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::LEFT)) {
        if (this->_direction != 1)
            this->_direction = 2;
        else
            this->_direction = 0;
    }
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::RIGHT)) {
        if (this->_direction != 1)
            this->_direction = 2;
        else
            this->_direction = 0;
    }
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::DOWN)) {
        if (this->_direction != 1)
            this->_direction = 2;
        else
            this->_direction = 0;
    }
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::UP)) {
        if (this->_direction != 1)
            this->_direction = 2;
        else
            this->_direction = 0;
    }
    this->_can_go = CanMove(); //FONCTION UPDATE
    if (this->_can_go == FALSE)//FONCTION UPDATE
        exit(0);//FONCTION UPDATE
    Eat();//FONCTION UPDATE
    RemoveFood();//FONCTION UPDATE
    MoveSnake();//FONCTION UPDATE
    this->_MapTmp = FillMyMap();
    int ko = 1;
    for (auto i = this->_Snake.begin(); i != this->_Snake.end(); i++, ko++)
         this->_MapTmp[this->_Snake.at(ko).first][this->_Snake.at(ko).second] = 'x';
     this->_MapTmp [this->_Food.first][this->_Food.second] = 'o';
}

std::vector<std::pair<std::string, int>> Snake::getBestScores() const
{
    std::vector<std::pair<std::string, int>> str;
    return (str);
}

std::pair<std::string, int> Snake::getScore() const
{
    std::pair<std::string, int> str;
    return str;
}
void Snake::setPlayerName(const std::string &name){;}

void Snake::reset(){;}

bool Snake::loadFromFile(const std::string &filepath){return true;}

bool Snake::loadFromFile(){return true;}

bool Snake::saveToFile(const std::string &filepath) const
{return true;}

bool Snake::saveToFile() const{return true;}

const std::string &Snake::getLibName() const
{
    return (this->_name);
}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Snake>();
}