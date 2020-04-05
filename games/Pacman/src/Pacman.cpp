/*
** EPITECH PROJECT, 2020
** Pacmancpp
** File description:
** Pacman
*/

#include "Pacman.hpp"

Pacman::Pacman()
{
    this->gameName = "Pacman";
    this->speed = 0;
    this->pacman = std::make_unique<Man>();
    this->ghost = getGhosts();
    InitMap();
    srand(time(0));
}

Pacman::~Pacman()
{
}

std::vector<std::unique_ptr<Pacman::Man>> Pacman::getGhosts(void)
{
    std::vector<std::unique_ptr<Pacman::Man>> ret;

    ret.push_back(std::make_unique<Man>(1, (std::pair<int, int>){14, 10}, IDisplayModule::Colors::LIGHT_YELLOW));
    ret.push_back(std::make_unique<Man>(1, (std::pair<int, int>){14, 12}, IDisplayModule::Colors::LIGHT_BLUE));
    ret.push_back(std::make_unique<Man>(1, (std::pair<int, int>){12, 10}, IDisplayModule::Colors::LIGHT_RED));
    ret.push_back(std::make_unique<Man>(1, (std::pair<int, int>){12, 12}, IDisplayModule::Colors::LIGHT_MAGENTA));
    return ret;
}

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

void Pacman::setPlayerName(const std::string &name)
{
    (void) name;
}

void Pacman::reset()
{
    this->pacman->~Man();
    this->speed = 0;
    this->pacman = std::make_unique<Man>();
    InitMap();
}

bool Pacman::loadFromFile(const std::string &filepath)
{
    return true;
}

bool Pacman::loadFromFile()
{
    return true;
}

bool Pacman::saveToFile(const std::string &filepath) const
{
    return true;
}

bool Pacman::saveToFile() const
{
    return true;
}

const std::string &Pacman::getLibName() const
{
    return (this->gameName);
}

void Pacman::update(const IDisplayModule &lib)
{
    int old = this->pacman->getDirection();
    std::pair<int, int> pacmanPosition = this->pacman->getPosition();

    if (lib.isKeyPressedOnce(IDisplayModule::Keys::Z))
        this->pacman->setDirection(1);
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::S))
        this->pacman->setDirection(2);
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::Q))
        this->pacman->setDirection(3);
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::D))
        this->pacman->setDirection(4);
    direction = this->pacman->getDirection();
    if (speed == SPEED) {
        movePacman(old);
        moveGhost(old);
        checkCollisions();
        speed = 0;
        for (size_t i = 0; i < food.size(); i++) {
            if (food.at(i).first == true && pacmanPosition.first == food.at(i).second.second && pacmanPosition.second == food.at(i).second.first)
                food.at(i).first = false;
        }
        if (pacman->getLives() <= 0) {
            reset();
            lost = true;
        }
        if (asWon() == true) {
            won = true;
            reset();
        }
    }
    if ((lost == true || won == true) && lib.isKeyPressedOnce(IDisplayModule::Keys::ENTER)) {
        won = false;
        lost = false;
    }
    speed++;
}

void Pacman::checkCollisions(void)
{
    std::pair<int, int> pacmanPosition = pacman->getPosition();
    std::pair<int, int> ghostPosition;

    for (size_t i = 0; i < ghost.size(); i++) {
        ghostPosition =  ghost.at(i)->getPosition();
        if (ghostPosition.first == pacmanPosition.first && ghostPosition.second == pacmanPosition.second)
            pacman->setLives(pacman->getLives() - 1);
    }
}

bool Pacman::asWon(void)
{
    for (size_t i = 0; i < food.size(); i++) {
        if (food.at(i).first == true)
            return (false);
    }
    return (true);
}

int get(int old)
{
    int tmp = rand() % 4;

    if (tmp == old)
        return (-1);
    return (tmp);
}

void Pacman::moveGhost(int old)
{
    std::pair<int, int> ghostPosition;

    for (size_t i = 0; i < this->ghost.size(); i++) {
        int direct = this->ghost.at(i)->getDirection();
        ghostPosition = this->ghost.at(i)->getPosition();
        if (checkDirection(i) == true)
            if ((direct = get(direct)) == -1)
                direct = this->pacman->getDirection();
        if (direct == 0) {
            if (this->map[ghostPosition.second - MANSPEED][ghostPosition.first] != '#') // Avance
                this->ghost.at(i)->setPosition((std::pair<int, int>){ghostPosition.first, ghostPosition.second - MANSPEED});
        }
        if (direct == 1) {
            if (this->map[ghostPosition.second + MANSPEED][ghostPosition.first] != '#') // Recule
               this->ghost.at(i)->setPosition((std::pair<int, int>){ghostPosition.first, ghostPosition.second + MANSPEED});
        }
        if (direct == 2) {
            if (this->map[ghostPosition.second][ghostPosition.first - MANSPEED] != '#') // Gauche
                this->ghost.at(i)->setPosition((std::pair<int, int>){ghostPosition.first - MANSPEED, ghostPosition.second});
        }
        if (direct == 3) {
            if (this->map[ghostPosition.second][ghostPosition.first + MANSPEED] != '#') // Droite
                this->ghost.at(i)->setPosition((std::pair<int, int>){ghostPosition.first + MANSPEED, ghostPosition.second});
        }
        if (ghostPosition.first == -1 && ghostPosition.second == 11)
            this->ghost.at(i)->setPosition((std::pair<int, int>){27, 11});
        if (ghostPosition.first == 28 && ghostPosition.second == 11)
            this->ghost.at(i)->setPosition((std::pair<int, int>){0, 11});
    }
}

bool Pacman::checkDirection(size_t i)
{
    std::pair<int, int> ghostPosition = this->ghost.at(i)->getPosition();
    int direct = this->ghost.at(i)->getDirection();

    if (direct == 0) {
        if (this->map[ghostPosition.second - MANSPEED][ghostPosition.first] == '#') // Avance
            return (true);
    }
    if (direct == 1) {
        if (this->map[ghostPosition.second + MANSPEED][ghostPosition.first] == '#') // Recule
            return (true);
    }
    if (direct == 2) {
        if (this->map[ghostPosition.second][ghostPosition.first - MANSPEED] == '#') // Gauche
            return (true);
    }
    if (direct == 3) {
        if (this->map[ghostPosition.second][ghostPosition.first + MANSPEED] == '#') // Droite
            return (true);
    }
    return (false);
}

void Pacman::movePacman(int old)
{
    std::pair<int, int> pacmanPosition = this->pacman->getPosition();

    if (direction == 1) {
        if (this->map[pacmanPosition.second - MANSPEED][pacmanPosition.first] != '#') // Avance
            this->pacman->setPosition((std::pair<int, int>){pacmanPosition.first, pacmanPosition.second - MANSPEED});
    }
    if (direction == 2) {
        if (this->map[pacmanPosition.second + MANSPEED][pacmanPosition.first] != '#') // Recule
           this->pacman->setPosition((std::pair<int, int>){pacmanPosition.first, pacmanPosition.second + MANSPEED});
    }
    if (direction == 3) {
        if (this->map[pacmanPosition.second][pacmanPosition.first - MANSPEED] != '#') // Gauche
            this->pacman->setPosition((std::pair<int, int>){pacmanPosition.first - MANSPEED, pacmanPosition.second});
    }
    if (direction == 4) {
        if (this->map[pacmanPosition.second][pacmanPosition.first + MANSPEED] != '#') // Droite
            this->pacman->setPosition((std::pair<int, int>){pacmanPosition.first + MANSPEED, pacmanPosition.second});
    }
    if (pacmanPosition.first == -1 && pacmanPosition.second == 11)
        this->pacman->setPosition((std::pair<int, int>){27, 11});
    if (pacmanPosition.first == 28 && pacmanPosition.second == 11)
        this->pacman->setPosition((std::pair<int, int>){0, 11});
}

void Pacman::render(IDisplayModule &lib) const
{
    std::pair<int, int> pacmanPosition = this->pacman->getPosition();
    std::pair<int, int> ghostPosition;

    for (size_t i = 0; i < this->map.size(); i++) {
        for (size_t j = 0; j < this->map.at(i).size(); j++) {
            if (this->map.at(i).at(j) == '#') {
                lib.setColor(IDisplayModule::Colors::BLUE);
                lib.putFillRect((20 * j) + XORD, (20 * i) + YORD, 17, 17);
            }
        }
    }
    lib.setColor(this->pacman->getColor());
    lib.putFillCircle((20 * pacmanPosition.first) + 30, (20 * pacmanPosition.second) + 5, MANSIZE);
    for (size_t i = 0; i < this->ghost.size(); i++) {
        ghostPosition = this->ghost.at(i)->getPosition();
        lib.setColor(this->ghost.at(i)->getColor());
        lib.putFillCircle((20 * ghostPosition.first) + XORD, (20 * ghostPosition.second) + YORD, GHOSTSIZE);
    }
    for (size_t i = 0; i < food.size(); i++) {
        if (food.at(i).first == true) {
            lib.setColor(IDisplayModule::Colors::YELLOW);
            lib.putPixel((20 * food.at(i).second.second) + XORD + 7, (20 * food.at(i).second.first) + YORD + 7);
            // lib.putFillRect((20 * food.at(i).second.second) + XORD + 5, (20 * food.at(i).second.first) + YORD + 5, 2, 2);
        }
    }
    if (won == true)
        lib.putText("Well done ! You won !", 20, 250, 200);
    if (lost == true)
        lib.putText("gAmE OvEr", 20, 250, 200);
    lib.putText("Lives : ", 12, 35, 170);
    lib.putText(std::to_string(pacman->getLives()), 12, 100, 170);
}

void Pacman::InitMap(void)
{
    this->map.push_back("#############################\n");
    this->map.push_back("#............###............#\n");
    this->map.push_back("#.####.#####.###.#####.####.#\n");
    this->map.push_back("#...........................#\n");
    this->map.push_back("#.####.##.#########.##.####.#\n");
    this->map.push_back("#......##....###....##.####.#\n");
    this->map.push_back("#......#####.###.#####......#\n");
    this->map.push_back("######.##...........##.######\n");
    this->map.push_back("     #.##.###   ###.##.#     \n");
    this->map.push_back("     #.##.##     ##.##.#     \n");
    this->map.push_back("######.##.##HHHHH##.##.######\n");
    this->map.push_back("..........##HHHHH##..........\n");
    this->map.push_back("######.##.##HHHHH##.##.######\n");
    this->map.push_back("     #.##.#########.##.#     \n");
    this->map.push_back("     #.##.....O.....##.#     \n");
    this->map.push_back("######.## ######### ##.######\n");
    this->map.push_back("#............###............#\n");
    this->map.push_back("#.####.#####.###.#####.####.#\n");
    this->map.push_back("#...##.................##...#\n");
    this->map.push_back("###.##.##.#########.##.##.###\n");
    this->map.push_back("#......##....###....##......#\n");
    this->map.push_back("#.##########.###.##########.#\n");
    this->map.push_back("#...........................#\n");
    this->map.push_back("#############################\n");
    for (size_t i = 0; i < this->map.size(); i++) {
        for (size_t j = 0; j < this->map.at(i).size(); j++) {
            if (map[i][j] == '.')
                this->food.push_back((std::pair<bool, std::pair<int, int>>){true, (std::pair<int, int>(i, j))});
        }
    }
}

Pacman::Man::Man()
{
    this->lives = 3;
    this->color = IDisplayModule::Colors::YELLOW;
    this->position = {14, 14};
}

Pacman::Man::Man(int _live, std::pair<int, int> _position, IDisplayModule::Colors _color)
{
    this->lives = _live;
    this->color = _color;
    this->position = _position;
    this->direction = 0;
}

Pacman::Man::~Man()
{
}

void Pacman::Man::setLives(int _lives)
{
    this->lives = _lives;
}

int Pacman::Man::getLives(void) const
{
    return (this->lives);
}

void Pacman::Man::setDirection(int _direction)
{
    this->direction = _direction;
}

int Pacman::Man::getDirection(void) const
{
    return (this->direction);
}

void Pacman::Man::setPosition(std::pair<int, int> _position)
{
    this->position = _position;
}

std::pair<int, int> Pacman::Man::getPosition(void) const
{
    return (this->position);
}

void Pacman::Man::setColor(IDisplayModule::Colors _color)
{
    this->color = _color;
}

IDisplayModule::Colors Pacman::Man::getColor(void) const
{
    return (this->color);
}

extern "C" std::unique_ptr<IGameModule> createLib(void)
{
    return std::make_unique<Pacman>();
}