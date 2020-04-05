/*
** EPITECH PROJECT, 2020
** LibNurses Of QuentinRemiVictor
** File description:
** Manage Of function of IDisplayModule
*/

#include "Ncurses.hpp"

Ncurses::Ncurses(){}

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
    wresize(stdscr, HEIGHT, WIDTH);
    cbreak();
    timeout(0);
    nodelay(stdscr, TRUE);
    curs_set(0);
    keypad(stdscr, TRUE);
    if(has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    start_color();
}
// Check if the window is open

bool Ncurses::isOpen() const
{
    if (stdscr != NULL)
        return true;
    return false;
}
// Handle switching libs & games (the names are explicit)
// Those are all key presses
// Those must be different than the keys listed in the Keys enum.
// The keys enum only lists keys used by games, not special keys to switch libraries.
bool Ncurses::switchToNextLib() const
{
    if (this->isKeyPressedOnce(IDisplayModule::UP))
        return true;
    return false;
}

bool Ncurses::switchToPreviousLib() const
{
    if (this->isKeyPressedOnce(IDisplayModule::DOWN))
        return true;
    return false;
}

bool Ncurses::switchToNextGame() const
{
    if (this->isKeyPressedOnce(IDisplayModule::RIGHT))
        return true;
    return false;
}

bool Ncurses::switchToPreviousGame() const
{
    if (this->isKeyPressedOnce(IDisplayModule::LEFT))
        return true;
    return false;
}

// From the pdf
bool Ncurses::shouldBeRestarted() const
{
    if (this->isKeyPressedOnce(IDisplayModule::X))
        return true;
    return false;
}

bool Ncurses::shouldGoToMenu() const
{
    if (this->isKeyPressedOnce(IDisplayModule::W))
        return true;
    return false;
}

bool Ncurses::shouldExit() const
{
    if (this->isKeyPressedOnce(IDisplayModule::BACKSPACE))
        return true;
    return false;
}

// Handle Inputs & Events

bool Ncurses::KeySet(IDisplayModule::Keys key) const
{
    switch (key) {
        case LEFT: if (this->ch == KEY_LEFT) { return true; }             break;
        case RIGHT: if (this->ch == KEY_RIGHT) { return true; }           break;
        case UP: if (this->ch == KEY_UP) { return true; }                 break;
        case DOWN: if (this->ch == KEY_DOWN) { return true; }             break;
        case Z: if (this->ch == 122) { return true; }                   break;
        case Q: if (this->ch == 113) { return true; }                   break;
        case S: if (this->ch == 115) { return true; }                   break;
        case D: if (this->ch == 100) { return true; }                   break;
        case A: if (this->ch == 97) { return true; }                   break;
        case E: if (this->ch == 101) { return true; }                   break;
        case W: if (this->ch == 119) { return true; }                   break;
        case X: if (this->ch == 120) { return true; }                   break;
        case SPACE: if (this->ch == 32) { return true; }           break;
        case J: if (this->ch == 106) { return true; }                   break;
        case K: if (this->ch == 107) { return true; }                   break;
        case U: if (this->ch == 117) { return true; }                   break;
        case I: if (this->ch == 105) { return true; }                   break;
        case ENTER: if (this->ch == 10) { return true; }          break;
        case BACKSPACE: if (this->ch == KEY_BACKSPACE) { return true; }   break;
        case KEYS_END: return false;
    }
    return false;
}

bool Ncurses::isKeyPressed(IDisplayModule::Keys key) const
{
    if (this->CurrentKey == 1 && this->KeySet(key))
        return true;
    return false;
}

bool Ncurses::isKeyPressedOnce(IDisplayModule::Keys key) const
{
    if ((this->CurrentKey == 1 && this->KeySet(key)) && this->prevKey == 0)
        return true;
    return false;
}

void my_clear()
{
    usleep(15000);
    wclear(stdscr);
}

// Handle Loop
void Ncurses::clear() const
{
    my_clear();
}

void Ncurses::update()
{
    noecho();
    this->ch = getch();
    this->prevKey = this->CurrentKey;
    if (ch == ERR)
        this->CurrentKey = 0;
    else {
        this->CurrentKey = 1;
    }
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
    return this->ch;
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
    mvprintw(y / 16, x / 8, ".");
}

// Display a line
void Ncurses::putLine(float x1, float y1, float x2, float y2) const
{
    x1 /= 8;
    x2 /= 8;
    y1 /= 16;
    y2 /= 16;

    if (x1 < x2 && y1 == y2) {
        mvhline(y1, x1, '-', x2 - x1);
        return;
    }
    if (x1 > x2 && y1 == y2) {
        mvhline(y1, x2, '-', x1 - x2);
        return;
    }
    if (y1 < y2 && x1 == x2) {
        mvhline(y1, x1, '-', y2 - y1);
        return;
    }
    if (y1 > y2 && x1 == x2) {
        mvhline(y2, x1, '-', y1 - y2);
        return;
    }

}
// Display an empty rectangle
void Ncurses::putRect(float x, float y, float w, float h) const
{
    w /= 8;
    x /= 8;
    h /= 16;
    y /= 16;
    mvhline(y, x, 'X', w);
    mvhline(y + h - 1, x, 'X', w);
    mvvline(y, x, 'X', h);
    mvvline(y, x + w - 1, 'X', h);
}
// Display a full rectangle
void Ncurses::putFillRect(float x, float y, float w, float h) const
{
    w /= 8;
    x /= 8;
    h /= 16;
    y /= 16;

    for (float y1 = y; y1 < y + h - 1; y1++)
        mvhline(y1, x, 'X', w);
}
// Display an empty circle
void Ncurses::putCircle(float x, float y, float rad) const
{
    static const double PI = 3.1415926535;
    double x1, y1;

    x += rad;
    y += rad;

    for(double i = 0; i < 360; i += 0.1) {
        x1 = rad * cos(i * PI / 180);
        y1 = rad * sin(i * PI / 180);
        mvprintw((y + y1) / 16, (x + x1) / 8, "o");
    }
}
// Display a full circle
void Ncurses::putFillCircle(float x, float y, float rad) const
{
    x += rad;
    y += rad;
    int h = 0;
    for (int x1 = -rad; x1 < rad ; x1++) {
        h = (int)sqrt(rad * rad - pow(x1, 2));
        for (int y1 = -h; y1 < h; y1++)
             mvprintw((y + y1) / 16, (x + x1) / 8, "o");
    }
}
// Display some text
void Ncurses::putText(const std::string &text, unsigned int size, float x, float y) const
{
    (void)size;
    mvprintw(y/16, x/8, text.c_str());
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
