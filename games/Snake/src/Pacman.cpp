/*
** EPITECH PROJECT, 2020
** Pacmancpp
** File description:
** Pacman
*/

#include "Pacman.hpp"

void Pacman::InitMap(void)
{
    this->_Map.push_back("###############\n");
    this->_Map.push_back("#      #      #\n");
    this->_Map.push_back("# # ## # ## # #\n");
    this->_Map.push_back("#             #\n");
    this->_Map.push_back("# ## #  # # # #\n");
    this->_Map.push_back("#    ## ### ###\n");
    this->_Map.push_back("#### #  # # # #\n");
    this->_Map.push_back("#             #\n");
    this->_Map.push_back("# ## ###   ## #\n");
    this->_Map.push_back("#  #     # ## #\n");
    this->_Map.push_back( "# ## # ### #  #\n");
    this->_Map.push_back( "#             #\n");
    this->_Map.push_back( "###############\n");
}

void Pacman::InitSuperFood(void)
{
    this->_SuperFood.insert({1, {1, 1}});
    this->_SuperFood.insert({2, {1, 13}});
    this->_SuperFood.insert({3, {11, 1}});
    this->_SuperFood.insert({4, {11, 13}});
}

void Pacman::InitGhost(void)
{
    this->_Ghost.insert({1, {3, 1}});
    this->_Ghost.insert({2, {9, 1}});
    this->_Ghost.insert({3, {7, 6}});
    this->_Ghost.insert({4, {4, 13}});
}

void Pacman::Update(void)
{
    std::vector<std::string> _MapTmp = this->_Map;
    for (long unsigned int i = 1; i != this->_Food.size(); i++)
        _MapTmp[this->_Food.at(i).first][this->_Food.at(i).second] = '.';
    for (long unsigned int i = 1; i != this->_Ghost.size() + 1; i++)
        if (this->_Ghost.at(i).first > 0)
           _MapTmp[this->_Ghost.at(i).first][this->_Ghost.at(i).second] = 'W';
    for (long unsigned int i = 1; i < this->_SuperFood.size() + 1; i++)
        if (this->_SuperFood.at(i).first > 0)
           _MapTmp[this->_SuperFood.at(i).first][this->_SuperFood.at(i).second] = '*';
    _MapTmp[this->_Pacman.first][this->_Pacman.second] = 'c';
    std::cout << 95 - _FoodRemaining << '\n';
    for (long unsigned int i = 0; i != this->_Map.size(); i++)
        std::cout << _MapTmp[i];
}

void Pacman::InitFood(void)
{
    this->_FoodRemaining = 0;
    for (int i = 0; i != 12; i++)
        for (int j = 0; j != 14; j++)
            if (_Map[i][j] == ' ') {
                this->_Food.insert({this->_FoodRemaining, {i, j}});
                this->_FoodRemaining += 1;
            }
}

void Pacman::InitPacman(void)
{
    this->_Pacman.first = 9;
    this->_Pacman.second = 6;//({9, 6});
}

Pacman::Pacman()
{
    InitMap();
    InitSuperFood();
    InitGhost();
    InitFood();
    InitPacman();
    Update();
}

Pacman::~Pacman()
{
}

int main(void)
{
    Pacman p;
}