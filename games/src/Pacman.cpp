/*
** EPITECH PROJECT, 2020
** Pacmancpp
** File description:
** Pacman
*/

#include "Pacman.hpp"

std::vector<std::tuple<std::string, int>> Pacman::getLatestScores() const
{
    std::vector<std::tuple<std::string, int>> str;
    return (str);
}
std::tuple<std::string, int> Pacman::getHighscore() const
{
    std::tuple<std::string, int> str;
    return str;
}
void Pacman::setPlayerName(const std::string &name){;}
void Pacman::reset(){;}

bool Pacman::loadFromFile(const std::string &filepath){return true;}
bool Pacman::loadFromFile(){return true;}
bool Pacman::saveToFile(const std::string &filepath) const
{return true;}
bool Pacman::saveToFile() const{return true;}

const std::string &Pacman::getGameName() const{
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

void Pacman::witch_color(std::string str)
{
    if (str == "#") {
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        printw(str.c_str());
    }
    else if (str == "c" || str == "C") {
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(3));
        printw(str.c_str());
    }
    else if (str == "W") {
        init_pair(4, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(4));
        printw(str.c_str());
    }
    else
        printw(str.c_str());
}


int Pacman::GetMove(int _direction)
{
    int ch = getch();
    switch (ch) {
        case KEY_LEFT:
            if (_direction != 1)
                return 2;
            else
                return (0);
        case KEY_RIGHT:
            if (_direction != 2)
                return 1;
            else
                return (0);
        case KEY_DOWN:
            if (_direction != 3)
                return 4;
            else
                return (0);
        case KEY_UP:
            if (_direction != 4)
                return 3;
            else
                return (0);
        default:
            return 0;
    }
}

void Pacman::update()
{
    clear();
    Moving();
    this->_direction = GetMove(this->_direction); //FONCTION MOUVEMENT
    this->_can_go = doesittouch(); //FONCTION UPDATE
    if (this->_can_go == FALSE) {//FONCTION UPDATE
        endwin();
        exit(0);
    }
    this->_can_move = CanMove();
    if (this->_can_move == TRUE)
        MovePacman();
    gain_coin();
    my_print(); //affichage
    refresh();
}

void Pacman::my_print(void)
{
    std::vector<std::string> _MapTmp = this->_Map;
    for (long unsigned int i = 1; i != this->_Food.size(); i++)
        if (this->_Food.at(i).first > 0)
           _MapTmp[this->_Food.at(i).first][this->_Food.at(i).second] = '.';
    for (long unsigned int i = 1; i < this->_SuperFood.size() + 1; i++)
        if (this->_SuperFood.at(i).first > 0)
           _MapTmp[this->_SuperFood.at(i).first][this->_SuperFood.at(i).second] = '*';
    for (long unsigned int i = 1; i != this->_Ghost.size() + 1; i++)
        if (this->_Ghost.at(i).first > 0)
           _MapTmp[this->_Ghost.at(i).first][this->_Ghost.at(i).second] = 'W';
    if (this->_powerup == 0)
        _MapTmp[this->_Pacman.first][this->_Pacman.second] = 'c';
    else {
        _MapTmp[this->_Pacman.first][this->_Pacman.second] = 'C';
        this->_powerup--;
    }
    for (size_t i = 0; i != _MapTmp.size(); i++) {
        for (size_t j = 0; j != _MapTmp[i].size(); j++) {
            std::string str(1, _MapTmp[i][j]);
            printw(str.c_str());
            //witch_color(str);
            //std::cout << _MapTmp[i][j];
        }
    }
    int jo = 95 - _FoodRemaining;
    std::string tmpp = std::to_string(jo);
    tmpp + "\n";
    printw(tmpp.c_str());
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
    initscr();
    if(has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(100);
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
    endwin();
}