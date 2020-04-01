/*
** EPITECH PROJECT, 2020
** Lib Ncurses
** File description:
** fonctions to make a futur lib
*/

#include "Ncurses.hpp"

Ncurses::Ncurses()
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
    this->_name = "Snake";
    this->_Map = FillMyMap();
    this->_direction = 3;
    this->_can_go = TRUE;
    InitSnake();
    MoveSnake();
    InitFood();
}

Ncurses::~Ncurses()
{
    EndWindows();
}

std::vector<std::string> Ncurses::FillMyMap(void)
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

int Ncurses::GetMove(int _direction)
{
    int ch = getch();
    switch (ch) {
        case KEY_LEFT:
            if (_direction != 1)
                return 2;
            else
                return (_direction);
        case KEY_RIGHT:
            if (_direction != 2)
                return 1;
            else
                return (_direction);
        case KEY_DOWN:
            if (_direction != 3)
                return 4;
            else
                return (_direction);
        case KEY_UP:
            if (_direction != 4)
                return 3;
            else
                return (_direction);
        default:
            return _direction;
    }
}

int Ncurses::SizeMap(void)
{
    int ko = 0;
    for (auto i = this->_Snake.begin(); i != this->_Snake.end(); i++, ko++);
    return (ko);
}

bool Ncurses::doesittouch(void)
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

bool Ncurses::CanMove(void)
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

void Ncurses::InitSnake(void)
{
    this->_Snake.insert({1, {10, 6}});
    this->_Snake.insert({2, {10, 5}});
    this->_Snake.insert({3, {10, 4}});
}

bool Ncurses::DontTouchSnake(int nb1, int nb2)
{
    int ko = 1;
    for (auto i = this->_Snake.begin(); ko < SizeMap(); i++, ko++) {
        if (this->_Snake.at(ko).first == nb1 && this->_Snake.at(ko).second == nb2)
            return (FALSE);
    }
    return (TRUE);
}

void Ncurses::InitFood(void)
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

void Ncurses::AddSnake(int size)
{
    this->_Snake.insert({size+1, {this->_Snake.at(size).first, this->_Snake.at(size).second}});
}

void Ncurses::MoveSnake(void)
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

void Ncurses::Eat(void)
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

void Ncurses::RemoveFood(void)
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

void Ncurses::EndWindows(void)
{
    endwin();
    exit(0);
}

void Ncurses::ClearWindows(void)
{
    refresh();
    clear();
}

void Ncurses::witch_color(std::string str)
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

void Ncurses::PrintGame(void)
{
    std::vector<std::string> _map = FillMyMap();
    int ko = 1;
    for (auto i = this->_Snake.begin(); i != this->_Snake.end(); i++, ko++)
        _map[this->_Snake.at(ko).first][this->_Snake.at(ko).second] = 'x';
    _map[this->_Food.first][this->_Food.second] = 'o';
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    for (size_t i = 0; i != _map.size(); i++) {
        for (size_t j = 0; j != _map[i].size(); j++) {
            std::string str(1, _map[i][j]);
            witch_color(str);
        }
    }
}

void Ncurses::update(void)
{
    //Initialisation de l'affichage en NCURSES
    // while (1) {
        PrintGame(); //Print Game en NCURSES //FONCTION UPDATE
        this->_direction = GetMove(this->_direction); //FONCTION MOUVEMENT
        this->_can_go = CanMove(); //FONCTION UPDATE
        if (this->_can_go == FALSE)//FONCTION UPDATE
            EndWindows();//FONCTION UPDATE
        Eat();//FONCTION UPDATE
        RemoveFood();//FONCTION UPDATE
        MoveSnake();//FONCTION UPDATE
        ClearWindows(); // Refresh + clear en NCURSES // FONCTION CLEAR
    // }
    //Fin de Windows en NCURSES
    // return 0;
}

void Ncurses::render(IDisplayModule &lib) const
{
    int key = lib.getKeyCode();

    if (key == lib.LEFT)
        printf("left");
}

std::vector<std::tuple<std::string, int>> Ncurses::getLatestScores() const
{
    std::vector<std::tuple<std::string, int>> str;
    return (str);
}
std::tuple<std::string, int> Ncurses::getHighscore() const
{
    std::tuple<std::string, int> str;
    return str;
}
void Ncurses::setPlayerName(const std::string &name){;}
void Ncurses::reset(){;}

bool Ncurses::loadFromFile(const std::string &filepath){return true;}
bool Ncurses::loadFromFile(){return true;}
bool Ncurses::saveToFile(const std::string &filepath) const
{return true;}
bool Ncurses::saveToFile() const{return true;}

const std::string &Ncurses::getGameName() const{
    return (this->_name);
}
// int main(int ac, char **av)
// {
//     Ncurses N;
//     N.Snake(ac, av);
//     return (0);
// }