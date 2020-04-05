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
    this->_speed = 0;
    InitSnake();
    MoveSnake();
    InitFood();
}

Snake::~Snake()
{}

std::vector<std::string> Snake::FillMyMap(void)
{
    size_t x_l = 20;
    size_t y_l = 20;
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
    int tmpp = 0;
    for (auto i = this->_Snake.begin(); i != this->_Snake.end(); i++, tmpp++);
    return (tmpp);
}

bool Snake::doesittouch(void)
{
    if (this->_direction == 1) {
        int tmpp = 2;
        for (auto i = this->_Snake.begin(); tmpp < SizeMap(); i++, tmpp++)
            if (this->_Snake.at(1).first == this->_Snake.at(tmpp).first && this->_Snake.at(1).second + 1 == this->_Snake.at(tmpp).second)
                return (FALSE);
    }
    if (this->_direction == 2) {
        int tmpp = 2;
        for (auto i = this->_Snake.begin(); tmpp < SizeMap(); i++, tmpp++)
            if (this->_Snake.at(1).first == this->_Snake.at(tmpp).first && this->_Snake.at(1).second - 1 == this->_Snake.at(tmpp).second)
                return (FALSE);
    }
    if (this->_direction == 3) {
        int tmpp = 2;
        for (auto i = this->_Snake.begin(); tmpp < SizeMap(); i++, tmpp++)
            if (this->_Snake.at(1).first - 1 == this->_Snake.at(tmpp).first && this->_Snake.at(1).second == this->_Snake.at(tmpp).second)
                return (FALSE);
    }
    if (this->_direction == 4) {
        int tmpp = 2;
        for (auto i = this->_Snake.begin(); tmpp < SizeMap(); i++, tmpp++)
            if (this->_Snake.at(1).first + 1 == this->_Snake.at(tmpp).first && this->_Snake.at(1).second == this->_Snake.at(tmpp).second)
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
    int tmp = 1;
    for (auto i = this->_Snake.begin(); tmp < SizeMap(); i++, tmp++) {
        if (this->_Snake.at(tmp).first == nb1 && this->_Snake.at(tmp).second == nb2)
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
        nb2 = (rand() % 17) + 1;
        nb1 = (rand() % 17) + 1;
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
    int tmpp = 1;
    int first = this->_Snake.at(tmpp).first;
    int second = this->_Snake.at(tmpp).second;
    int first1 = this->_Snake.at(tmpp).first;
    int second1 = this->_Snake.at(tmpp).second;
    int tmp = 0;
    if (this->_direction == 1)
        this->_Snake.at(tmpp) = {this->_Snake.at(tmpp).first, this->_Snake.at(tmpp).second + 1};
    if (this->_direction == 2)
        this->_Snake.at(tmpp) = {this->_Snake.at(tmpp).first, this->_Snake.at(tmpp).second - 1};
    if (this->_direction == 3)
        this->_Snake.at(tmpp) = {this->_Snake.at(tmpp).first - 1, this->_Snake.at(tmpp).second};
    if (this->_direction == 4)
        this->_Snake.at(tmpp) = {this->_Snake.at(tmpp).first + 1, this->_Snake.at(tmpp).second};
    for (auto i = this->_Snake.begin(); tmpp < SizeMap(); i++, tmpp++, tmp++) {
        if (tmp % 2 == 0) {
            first1 = this->_Snake.at(tmpp+1).first;
            second1 = this->_Snake.at(tmpp+1).second;
            this->_Snake.at(tmpp+1) = {first, second};
        }
        if (tmp % 2 == 1) {
            first = this->_Snake.at(tmpp+1).first;
            second = this->_Snake.at(tmpp+1).second;
            this->_Snake.at(tmpp+1) = {first1, second1};
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
            if (this->_MapTmp[i][j] == '#') {
                lib.setColor(IDisplayModule::Colors::BLUE);
                lib.putFillRect((20 * j) + XORD, (20 * i) + YORD, 10, 10);
            }
            if (this->_MapTmp[i][j] == 'o') {
                lib.setColor(IDisplayModule::Colors::RED);
                lib.putFillCircle((20 * j) + XORD, (20 * i) + YORD, 10);
            }
            if (this->_MapTmp[i][j] == 'x') {
                lib.setColor(IDisplayModule::Colors::GREEN);
                lib.putFillCircle((20 * j) + XORD, (20 * i) + YORD, 10);
            }
        }
    }
    auto result = this->_name + " : " + std::to_string(this->_score);
    lib.putText("result", 100, 0, 0);

    auto best_result = this->_best_gamer_aff + " : " + std::to_string(this->_best_score_aff );
    lib.putText("result", 100, 0, 0);
}

void Snake::Bestscore()
{
    std::ofstream myfile ("games/.saves/Nibbler", std::ofstream::out | std::ofstream::app);
    if (myfile.is_open())
        myfile.close();
    else
        std::system("touch games/.saves/Nibbler");
    std::ifstream file("games/.saves/Nibbler");
    int count = 1;
    int best_score = -1;
    int best_score_tmp = -1;
    std::string::size_type sz;
    std::string _name_tmp;
    while (!file.eof()) {
        std::string line;
        file >> line;
        if (count % 3 == 1) {
            _name_tmp = line;
        }
        if (count % 3 == 0) {
            best_score_tmp = std::stoi(line, &sz);
            if (best_score_tmp > best_score) {
                best_score = best_score_tmp;
                this->_best_score = {{line, best_score}};
                this->_best_score_aff = best_score;
                this->_best_gamer_aff = line;
            }
        }
        ++count;
    }
}

void Snake::update(const IDisplayModule &lib)
{
    this->_speed += 1;
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::D)) {
        if (this->_direction != 2)
            this->_direction = 1;
    }
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::Q)) {
        if (this->_direction != 1)
            this->_direction = 2;
    }
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::S)) {
        if (this->_direction != 3)
            this->_direction = 4;
    }
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::Z)) {
        if (this->_direction != 4)
            this->_direction = 3;
    }
    if (this->_speed == SPEED) {
        this->_can_go = CanMove(); //FONCTION UPDATE
        if (this->_can_go == FALSE)//FONCTION UPDATE
            reset();//FONCTION UPDATE
        Eat();//FONCTION UPDATE
        RemoveFood();//FONCTION UPDATE
        MoveSnake();//FONCTION UPDATE
        Bestscore();
        this->_speed = 0;
    }
    this->_MapTmp = FillMyMap();
    int tmpp = 1;
    for (auto i = this->_Snake.begin(); i != this->_Snake.end(); i++, tmpp++)
         this->_MapTmp[this->_Snake.at(tmpp).first][this->_Snake.at(tmpp).second] = 'x';
    this->_MapTmp [this->_Food.first][this->_Food.second] = 'o';
    _score = this->_Snake.size() - 3;
}


std::vector<std::pair<std::string, int>> Snake::getBestScores() const
{
    return (this->_best_score);
}

std::pair<std::string, int> Snake::getScore() const
{
    std::pair<std::string, int> str = {this->_name, this->_score};
    return str;
}
void Snake::setPlayerName(const std::string &name)
{
    this->_name = name;
}

void Snake::Stock_score()
{
    std::ofstream myfile ("games/.saves/Nibbler", std::ofstream::out | std::ofstream::app);
    if (myfile.is_open()) {
        auto result = this->_name + " : " + std::to_string(this->_score) + '\n';
        myfile << result;
        myfile.close();
    }
    else {
        std::system("touch games/.saves/Nibbler");
        Stock_score();
    }
}

void Snake::reset()
{
    Stock_score();
    this->_Map = FillMyMap();
    this->_direction = 3;
    this->_can_go = TRUE;
    this->_speed = 0;
    std::map<int, std::pair<int, int>> RemoveSnake;
    this->_Snake = RemoveSnake;
    InitSnake();
    MoveSnake();
    InitFood();
}

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