/*
** EPITECH PROJECT, 2020
** Pacmancpp
** File description:
** Pacman
*/

#include "Pacman.hpp"

std::vector<std::pair<std::string, int>> Pacman::getBestScores() const
{
    std::vector<std::pair<std::string, int>> str;
    return (str);
}

std::pair<std::string, int> Pacman::getScore() const
{
    std::pair<std::string, int> str;
    return str;
}

void Pacman::setPlayerName(const std::string &name){;}

void Pacman::reset(){;}

bool Pacman::loadFromFile(const std::string &filepath){return true;}

bool Pacman::loadFromFile(){return true;}

bool Pacman::saveToFile(const std::string &filepath) const
{return true;}

bool Pacman::saveToFile() const{return true;}

const std::string &Pacman::getLibName() const
{
    return (this->_name);
}

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
    this->_Map.push_back("#  #   ##  #  #\n");
    this->_Map.push_back("# ## # ## ## ##\n");
    this->_Map.push_back("#             #\n");
    this->_Map.push_back("###############\n");
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

void Pacman::update(const IDisplayModule &lib)
{
    Moving();
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
    this->_can_go = doesittouch(); //FONCTION UPDATE
    if (this->_can_go == FALSE)//FONCTION UPDATE
        exit(0);
    this->_can_move = CanMove();
    if (this->_can_move == TRUE)
        MovePacman();
    gain_coin();
    if (this->_powerup == 0)
        _MapTmp[this->_Pacman.first][this->_Pacman.second] = 'c';
    else {
        _MapTmp[this->_Pacman.first][this->_Pacman.second] = 'C';
        this->_powerup--;
    }
    this->_MapTmp = this->_Map;
    for (long unsigned int i = 1; i != this->_Food.size(); i++)
        if (this->_Food.at(i).first > 0)
           this->_MapTmp[this->_Food.at(i).first][this->_Food.at(i).second] = '.';
    for (long unsigned int i = 1; i < this->_SuperFood.size() + 1; i++)
        if (this->_SuperFood.at(i).first > 0)
           this->_MapTmp[this->_SuperFood.at(i).first][this->_SuperFood.at(i).second] = '*';
    for (long unsigned int i = 1; i != this->_Ghost.size() + 1; i++)
        if (this->_Ghost.at(i).first > 0)
           this->_MapTmp[this->_Ghost.at(i).first][this->_Ghost.at(i).second] = 'W';
    int jo = 95 - _FoodRemaining;
    this->_Score = std::to_string(jo);
    this->_Score + "\n";
}

void Pacman::render(IDisplayModule &lib) const
{
    float i = 0;
    float j = 0;

    for (i = 0; i != this->_MapTmp.size(); i++) {
        for (j = 0; j != this->_MapTmp[i].size(); j++) {
            std::string str(1, _MapTmp[i][j]);
            lib.putText(str, 1, j*16, i*8);
        }
    }
    lib.putText(this->_Score, 1, j*18, i*8);
    // for (long unsigned int i = 0; i != this->_Map.size(); i++)
    //     std::cout << _MapTmp[i];
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

int get_rand(void)
{
    srand(time(NULL));
    int nb = 0;
    nb = rand() % 4;
    return (nb);
}

void Pacman::nb_zero(int i)
{
    if (this->_Ghost.at(i).first + 1 < 13 && this->_Map[this->_Ghost.at(i).first + 1][this->_Ghost.at(i).second] != '#')
        this->_Ghost.at(i).first += 1;
    else if (this->_Ghost.at(i).first - 1 > 1 && this->_Map[this->_Ghost.at(i).first - 1][this->_Ghost.at(i).second] != '#')
        this->_Ghost.at(i).first -= 1;
    else if (this->_Ghost.at(i).second + 1 < 15 && this->_Map[this->_Ghost.at(i).first][this->_Ghost.at(i).second + 1] != '#')
        this->_Ghost.at(i).second += 1;
    else if (this->_Ghost.at(i).second - 1 > 1 && this->_Map[this->_Ghost.at(i).first][this->_Ghost.at(i).second - 1] != '#')
        this->_Ghost.at(i).second -= 1;
}

void Pacman::nb_one(int i)
{
    if (this->_Ghost.at(i).first - 1 > 1 && this->_Map[this->_Ghost.at(i).first - 1][this->_Ghost.at(i).second] != '#')
        this->_Ghost.at(i).first -= 1;
    else if (this->_Ghost.at(i).second + 1 < 15 && this->_Map[this->_Ghost.at(i).first][this->_Ghost.at(i).second + 1] != '#')
        this->_Ghost.at(i).second += 1;
    else if (this->_Ghost.at(i).second - 1 > 1 && this->_Map[this->_Ghost.at(i).first][this->_Ghost.at(i).second - 1] != '#')
        this->_Ghost.at(i).second -= 1;
    else if (this->_Ghost.at(i).first + 1 < 13 && this->_Map[this->_Ghost.at(i).first + 1][this->_Ghost.at(i).second] != '#')
        this->_Ghost.at(i).first += 1;
}

void Pacman::nb_two(int i)
{
    if (this->_Ghost.at(i).second + 1 < 15 && this->_Map[this->_Ghost.at(i).first][this->_Ghost.at(i).second + 1] != '#')
        this->_Ghost.at(i).second += 1;
    else if (this->_Ghost.at(i).second - 1 > 1 && this->_Map[this->_Ghost.at(i).first][this->_Ghost.at(i).second - 1] != '#')
        this->_Ghost.at(i).second -= 1;
    else if (this->_Ghost.at(i).first + 1 < 13 && this->_Map[this->_Ghost.at(i).first + 1][this->_Ghost.at(i).second] != '#')
        this->_Ghost.at(i).first += 1;
    else if (this->_Ghost.at(i).first - 1 > 1 && this->_Map[this->_Ghost.at(i).first - 1][this->_Ghost.at(i).second] != '#')
        this->_Ghost.at(i).first -= 1;
}

void Pacman::nb_three(int i)
{
    if (this->_Ghost.at(i).second - 1 > 1 && this->_Map[this->_Ghost.at(i).first][this->_Ghost.at(i).second - 1] != '#')
        this->_Ghost.at(i).second -= 1;
    else if (this->_Ghost.at(i).first + 1 < 13 && this->_Map[this->_Ghost.at(i).first + 1][this->_Ghost.at(i).second] != '#')
        this->_Ghost.at(i).first += 1;
    else if (this->_Ghost.at(i).first - 1 > 1 && this->_Map[this->_Ghost.at(i).first - 1][this->_Ghost.at(i).second] != '#')
        this->_Ghost.at(i).first -= 1;
    else if (this->_Ghost.at(i).second + 1 < 15 && this->_Map[this->_Ghost.at(i).first][this->_Ghost.at(i).second + 1] != '#')
        this->_Ghost.at(i).second += 1;
}

bool Pacman::doesittouch(void)
{
    for (long unsigned int i = 1; i != this->_Ghost.size() + 1; i++) {
        if (this->_powerup == 0 && this->_Ghost.at(i).first == this->_Pacman.first && this->_Ghost.at(i).second == this->_Pacman.second)
            return (FALSE);
        if (this->_powerup != 0 && this->_Ghost.at(i).first == this->_Pacman.first && this->_Ghost.at(i).second == this->_Pacman.second) {
            this->_Ghost.at(i).first = 0;
            return (TRUE);
        }
    }
    return (TRUE);
}

bool Pacman::CanMove(void)
{
    if (this->_direction == 1)
        if ((this->_Map[this->_Pacman.first][_Pacman.second + 1] == '#'))
            return (FALSE);
    if (this->_direction == 2)
        if ((this->_Map[this->_Pacman.first][this->_Pacman.second - 1] == '#'))
            return (FALSE);
    if (this->_direction == 3)
        if ((this->_Map[this->_Pacman.first - 1][this->_Pacman.second] == '#'))
            return (FALSE);
    if (this->_direction == 4)
        if ((this->_Map[this->_Pacman.first + 1][this->_Pacman.second] == '#'))
            return (FALSE);
    return (TRUE);
}

void Pacman::Moving(void)
{
    int nb;
    for (long unsigned int i = 1; i != this->_Ghost.size() + 1; i++)
        if (this->_Ghost.at(i).first > 0) {
            nb = get_rand();
            if (nb == 0)
                nb_zero(i);
            if (nb == 1)
                nb_one(i);
            if (nb == 2)
                nb_two(i);
            if (nb == 3)
                nb_three(i);
        }
}

void Pacman::gain_coin(void)
{
    for (long unsigned int i = 1; i != this->_Food.size(); i++)
        if (this->_Food.at(i).first == this->_Pacman.first && this->_Food.at(i).second == this->_Pacman.second) {
            this->_FoodRemaining -= 1;
            this->_Food.at(i).first = 0;
        }
    for (long unsigned int i = 1; i < this->_SuperFood.size() + 1; i++)
        if (this->_SuperFood.at(i).first == this->_Pacman.first && this->_SuperFood.at(i).second == this->_Pacman.second) {
            this->_SuperFood.at(i).first = 0;
            this->_powerup = 30;
        }
    if (this->_FoodRemaining == 0) {
        endwin();
        std::cout << "gg \n";
        exit(0);
    }
}

void Pacman::MovePacman(void)
{
    if (this->_direction == 1)
        this->_Pacman = {this->_Pacman.first, this->_Pacman.second + 1};
    if (this->_direction == 2)
        this->_Pacman = {this->_Pacman.first, this->_Pacman.second - 1};
    if (this->_direction == 3)
        this->_Pacman = {this->_Pacman.first - 1, this->_Pacman.second};
    if (this->_direction == 4)
        this->_Pacman = {this->_Pacman.first + 1, this->_Pacman.second};
}

Pacman::Pacman()
{
    this->_powerup = 0;
    this->_can_go = TRUE;
    this->_can_move = TRUE;
    this->_direction = 0;
    this->_FoodRemaining = 0;
    this->_name = "Pacman";
    InitMap();
    InitSuperFood();
    InitGhost();
    InitFood();
    InitPacman();
}

Pacman::~Pacman()
{
}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Pacman>();
}