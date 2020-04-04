/*
** EPITECH PROJECT, 2020
** LibNurses Of QuentinRemiVictor
** File description:
** Manage Of function of IDisplayModule
*/

#include "Ncurses.hpp"

Ncurses::Ncurses(){}

Ncurses::~Ncurses()
{}

void Ncurses::close()
{
    endwin();
}

void Ncurses::reset()
{
    return;
}

void Ncurses::open()
{
    this->_name = "Ncurses";
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
    // curs_set(0);
    // timeout(100);
}
// Check if the window is open

bool Ncurses::isOpen() const
{
    return (true);
    // return this->window->isOpen();
}
// Handle switching libs & games (the names are explicit)
// Those are all key presses
// Those must be different than the keys listed in the Keys enum.
// The keys enum only lists keys used by games, not special keys to switch libraries.
bool Ncurses::switchToNextLib() const
{
    if (this->isKeyPressed(IDisplayModule::UP))
        return true;
    return false;
}

bool Ncurses::switchToPreviousLib() const
{
    if (this->isKeyPressed(IDisplayModule::DOWN))
        return true;
    return false;
}

bool Ncurses::switchToNextGame() const
{
    if (this->isKeyPressed(IDisplayModule::RIGHT))
        return true;
    return false;
}

bool Ncurses::switchToPreviousGame() const
{
    if (this->isKeyPressed(IDisplayModule::LEFT))
        return true;
    return false;
}

// From the pdf
bool Ncurses::shouldBeRestarted() const
{
    if (this->isKeyPressed(IDisplayModule::X))
        return true;
    return false;
}

bool Ncurses::shouldGoToMenu() const
{
    if (this->isKeyPressed(IDisplayModule::W))
        return true;
    return false;
}

bool Ncurses::shouldExit() const
{
    if (this->isKeyPressed(IDisplayModule::BACKSPACE))
        return true;
    return false;
}

// Handle Inputs & Events

bool Ncurses::KeySet(IDisplayModule::Keys key) const
{
    int ch = getch();
    switch (key) {
        case LEFT: if (ch == KEY_LEFT) { return true; }             break;
        case RIGHT: if (ch == KEY_RIGHT) { return true; }           break;
        case UP: if (ch == KEY_UP) { return true; }                 break;
        case DOWN: if (ch == KEY_DOWN) { return true; }             break;
        case Z: if (ch == 122) { return true; }                   break;
        case Q: if (ch == 113) { return true; }                   break;
        case S: if (ch == 115) { return true; }                   break;
        case D: if (ch == 100) { return true; }                   break;
        case A: if (ch == 97) { return true; }                   break;
        case E: if (ch == 101) { return true; }                   break;
        case W: if (ch == 119) { return true; }                   break;
        case X: if (ch == 120) { return true; }                   break;
        case SPACE: if (ch == 32) { return true; }           break;
        case J: if (ch == 109) { return true; }                   break;
        case K: if (ch == 108) { return true; }                   break;
        case U: if (ch == 117) { return true; }                   break;
        case I: if (ch == 105) { return true; }                   break;
        case ENTER: if (ch == 10) { return true; }          break;
        case BACKSPACE: if (ch == 263) { return true; }   break;
        case KEYS_END: return false;
        default: return false;
    }
    return false;
}

bool Ncurses::isKeyPressed(IDisplayModule::Keys key) const
{
    return KeySet(key);
}

bool Ncurses::isKeyPressedOnce(IDisplayModule::Keys key) const
{
    return KeySet(key);
}

void my_clear()
{
    clear();
}

// Handle Loop
void Ncurses::clear() const
{
    my_clear();
}

void Ncurses::update()
{
    ;
}

float Ncurses::getDelta() const
{
    return 1;
}

void Ncurses::render() const
{
    refresh();
}
// You don't need all three of them, only one should be enough but we added the three of them
// in case some of you want to seperate each step
// Your core (or games) should nonetheless call all of these functions in this specific order :
// clear -> update -> render

// Handle Text Input
// We need to ask for the player's name (check the pdf before complaining and asking about this function)
// Get key Presses.
// returns \n if enter was pressed & \0 if nothing was pressed.
// it returns \b if backspace was pressed (to delete a character from the name).
char Ncurses::getKeyCode() const
{
    return ('e');
    // return this->lastKey;
}

// Display Stuff
// Sets the color for all the following draw functions.
// everything you display after this will have the selected color
void Ncurses::setColor(IDisplayModule::Colors col)
{
    switch (col) {
        case DEFAULT:       {init_pair(1, COLOR_BLACK, COLOR_BLACK);attron(COLOR_PAIR(1));break;}
        case BLACK:         {init_pair(1, COLOR_BLACK, COLOR_BLACK);attron(COLOR_PAIR(1));break;}
        case WHITE:         {init_pair(2, COLOR_WHITE, COLOR_BLACK);attron(COLOR_PAIR(2));break;}
        case RED:           {init_pair(3, COLOR_RED, COLOR_BLACK);attron(COLOR_PAIR(3));break;}
        case GREEN:         {init_pair(4, COLOR_GREEN, COLOR_BLACK);attron(COLOR_PAIR(4));break;}
        case BLUE:          {init_pair(5, COLOR_BLUE, COLOR_BLACK);attron(COLOR_PAIR(5));break;}
        case YELLOW:        {init_pair(6, COLOR_YELLOW, COLOR_BLACK);attron(COLOR_PAIR(6));break;}
        case MAGENTA:       {init_pair(7, COLOR_MAGENTA, COLOR_BLACK);attron(COLOR_PAIR(7));break;}
        case CYAN:          {init_pair(8, COLOR_CYAN, COLOR_BLACK);attron(COLOR_PAIR(8));break;}
        case LIGHT_GRAY:    {init_pair(9, COLOR_BLACK, COLOR_BLACK);attron(COLOR_PAIR(9));break;}
        case DARK_GRAY:     {init_pair(10, COLOR_BLACK, COLOR_BLACK);attron(COLOR_PAIR(10));break;}
        case LIGHT_RED:     {init_pair(11, COLOR_RED, COLOR_BLACK);attron(COLOR_PAIR(11));break;}
        case LIGHT_GREEN:   {init_pair(12, COLOR_GREEN, COLOR_BLACK);attron(COLOR_PAIR(12));break;}
        case LIGHT_YELLOW:  {init_pair(13, COLOR_YELLOW, COLOR_BLACK);attron(COLOR_PAIR(13));break;};
        case LIGHT_BLUE:    {init_pair(14, COLOR_BLUE, COLOR_BLACK);attron(COLOR_PAIR(14));break;}
        case LIGHT_MAGENTA: {init_pair(15, COLOR_MAGENTA, COLOR_BLACK);attron(COLOR_PAIR(15));break;}
        case LIGHT_CYAN:    {init_pair(16, COLOR_CYAN, COLOR_BLACK);attron(COLOR_PAIR(16));break;}
        case COLORS_END:    {init_pair(17, COLOR_BLACK, COLOR_BLACK);attron(COLOR_PAIR(17));break;}
    }
    return ;
}
// Display a pixel
void Ncurses::putPixel(float x, float y) const
{
    mvaddstr(y/8, x/16, "x");
}

// Display a line
void Ncurses::putLine(float x1, float y1, float x2, float y2) const
{
    int tmp = 1;
    while (tmp != 0) {
        mvaddstr(y1/8, x1/16, "x");
        if (x1 != x2) {
            if (x1 < x2)
                x1++;
            else
                x1--;
        }
        if (y1 != y2) {
            if (y1 < y2)
                y1++;
            else
                y1--;
        }
        if (x1 == x2 && y1 == y2)
            tmp = 0;
    }
    mvaddstr(y2/8, x2/16, "x");
    // sf::VertexArray line(sf::Lines, 2);

    // line[0].position = sf::Vector2f(x1, y1);
    // line[1].position = sf::Vector2f(x2, y2);
    // line[0].color = this->color;
    // line[1].color = this->color;
    // this->window->draw(line);
}
// Display an empty rectangle
void Ncurses::putRect(float x, float y, float w, float h) const
{
    float x1 = w;
    float x2 = x;
    float y1 = h;
    float y2 = y;
    for (; x1 != x2 + 1 ; x1++) {
        for (y1 = h; y1 != y2 + 1; y1++) {
            if (x1 == x  || y1 == y || x1 == w || y1 == h)
                mvaddstr(y1/8, x1/16, "x");
        }
    }
}
// Display a full rectangle
void Ncurses::putFillRect(float x, float y, float w, float h) const
{
    float x1 = w;
    float x2 = x;
    float y1 = h;
    float y2 = y;
    for (; x1 != x2 + 1 ; x1++)
        for (y1 = h; y1 != y2 + 1; y1++)
                mvaddstr(y1/8, x1/16, "x");
}
// Display an empty circle
void Ncurses::putCircle(float x, float y, float rad) const
{
    for (int i = 0; i < 1080; i++) {
        for (int j = 0; j < 1920; j++) {
            if ((x - i) * (x - i) + (y - j) * (y - j) == rad * rad)
                mvaddstr(j/8, i/16, "x");
        }
    }
}
// Display a full circle
void Ncurses::putFillCircle(float x, float y, float rad) const
{
    for (int i = 0; i < 1080; i++) {
        for (int j = 0; j < 1920; j++) {
            if ((x - i) * (x - i) + (y - j) * (y - j) <= rad * rad)
                mvaddstr(j/8, i/16, "x");
        }
    }
}
// Display some text
void Ncurses::putText(const std::string &text, unsigned int size, float x, float y) const
{
    size += 2;
    mvaddstr(y/8, x/16, text.c_str());
}

// We chose not to display images because some library can't and it would cause other problems
// You can still parse a file and display pixel art images by displaying pixels manually if you want.

// Strictly for debugging purposes, get the library's name (ncurses/sfm/sdl/libcaca etc etc)
const std::string &Ncurses::getLibName() const
{
    return (this->_name);
}

extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return (std::make_unique<Ncurses>());
}