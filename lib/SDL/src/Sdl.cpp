/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** [enter description here]
*/

#include "Sdl.hpp"
#include <iostream>

Sdl::Sdl() {}
// For the core
// Reset the library
void Sdl::reset()
{
    setColor(DEFAULT);
    this->clear();
}

void Sdl::open()
{
    this->name = "Sdl";
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &this->window, &this->renderer);
    this->clos = false;
    setColor(DEFAULT);
    memset(this->prevKey, 0, sizeof(Uint8)*SDL_NUM_SCANCODES);
    memcpy(this->CurrentKey, SDL_GetKeyboardState(NULL), sizeof(Uint8)*SDL_NUM_SCANCODES);
}
// Check if the window is open
void Sdl::close()
{
    if (this->clos == false) {
        SDL_DestroyRenderer(this->renderer);
        SDL_DestroyWindow(this->window);
        TTF_Quit();
        SDL_Quit();
        this->clos = true;
    }
}

bool Sdl::isOpen() const
{
    if (this->clos == true) {
        SDL_DestroyRenderer(this->renderer);
        SDL_DestroyWindow(this->window);
        TTF_Quit();
        SDL_Quit();
    }
    return !this->clos;
}
// Handle switching libs & games (the names are explicit)
// Those are all key presses
// Those must be different than the keys listed in the Keys enum.
// The keys enum only lists keys used by games, not special keys to switch libraries.
bool Sdl::switchToNextLib() const
{
    if (this->isKeyPressedOnce(IDisplayModule::UP))
        return true;
    return false;
}

bool Sdl::switchToPreviousLib() const
{
    if (this->isKeyPressedOnce(IDisplayModule::DOWN))
        return true;
    return false;
}

bool Sdl::switchToNextGame() const
{
    if (this->isKeyPressedOnce(IDisplayModule::RIGHT))
        return true;
    return false;
}

bool Sdl::switchToPreviousGame() const
{
    if (this->isKeyPressedOnce(IDisplayModule::LEFT))
        return true;
    return false;
}

// From the pdf
bool Sdl::shouldBeRestarted() const
{
    if (this->isKeyPressedOnce(IDisplayModule::X))
        return true;
    return false;
}

bool Sdl::shouldGoToMenu() const
{
    if (this->isKeyPressedOnce(IDisplayModule::W))
        return true;
    return false;
}

bool Sdl::shouldExit() const
{
    if (this->isKeyPressedOnce(IDisplayModule::BACKSPACE))
        return true;
    return false;
}

// Handle Inputs & Events

bool Sdl::KeySet(IDisplayModule::Keys key, const Uint8 *state) const
{
    switch (key) {
        case LEFT: return state[SDL_SCANCODE_LEFT];
        case RIGHT: return state[SDL_SCANCODE_RIGHT];
        case UP: return state[SDL_SCANCODE_UP];
        case DOWN: return state[SDL_SCANCODE_DOWN];
        case Z: return state[SDL_SCANCODE_W];
        case Q: return state[SDL_SCANCODE_A];
        case S: return state[SDL_SCANCODE_S];
        case D: return state[SDL_SCANCODE_D];
        case A: return state[SDL_SCANCODE_Q];
        case E: return state[SDL_SCANCODE_E];
        case W: return state[SDL_SCANCODE_Z];
        case X: return state[SDL_SCANCODE_X];
        case SPACE: return state[SDL_SCANCODE_SPACE];
        case J: return state[SDL_SCANCODE_J];
        case K: return state[SDL_SCANCODE_K];
        case U: return state[SDL_SCANCODE_U];
        case I: return state[SDL_SCANCODE_I];
        case ENTER: return state[SDL_SCANCODE_RETURN];
        case BACKSPACE: return state[SDL_SCANCODE_BACKSPACE];
        case KEYS_END: return false;
    }
    return false;
}

bool Sdl::isKeyPressed(IDisplayModule::Keys key) const
{
    return KeySet(key, this->CurrentKey);
}

bool Sdl::isKeyPressedOnce(IDisplayModule::Keys key) const
{
    if (KeySet(key, this->CurrentKey) == true && KeySet(key, this->prevKey) == false)
        return true;
    return false;
}
// Get the number of frames that passed between two calls to this function
// The games should not be frame dependant!! That's why this is here.
float Sdl::getDelta() const
{
    return 1;
}

// Handle Loop
void Sdl::clear() const
{
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
}

void Sdl::update()
{
    Uint32 current = SDL_GetTicks();

    this->timeRange += (Uint32)(1000 / 60);
    if (current < timeRange)
        SDL_Delay(timeRange - current);
    memcpy(this->prevKey, this->CurrentKey, sizeof(Uint8)*SDL_NUM_SCANCODES);
    memcpy(this->CurrentKey, SDL_GetKeyboardState(NULL), sizeof(Uint8)*SDL_NUM_SCANCODES);
    SDL_PollEvent(&this->event);
    if (this->event.type == SDL_QUIT)
        this->clos = true;
    if (this->event.type != SDL_KEYDOWN)
        if (this->event.key.keysym.sym < 128)
            this->lastKey = static_cast<char>(this->event.key.keysym.sym);
}

void Sdl::render() const
{
    SDL_RenderPresent(this->renderer);
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
char Sdl::getKeyCode() const
{
    return this->lastKey;
}

// Display Stuff
// Sets the color for all the following draw functions.
// everything you display after this will have the selected color
void Sdl::setColor(IDisplayModule::Colors col)
{
    switch (col) {
        case DEFAULT:       SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);           break;
        case BLACK:         SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);           break;
        case WHITE:         SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);     break;
        case RED:           SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);         break;
        case GREEN:         SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 255);         break;
        case BLUE:          SDL_SetRenderDrawColor(this->renderer, 0, 0, 255, 255);         break;
        case YELLOW:        SDL_SetRenderDrawColor(this->renderer, 255, 255, 0, 255);       break;
        case MAGENTA:       SDL_SetRenderDrawColor(this->renderer, 255, 0, 255, 255);       break;
        case CYAN:          SDL_SetRenderDrawColor(this->renderer, 0, 255, 255, 255);       break;
        case LIGHT_GRAY:    SDL_SetRenderDrawColor(this->renderer, 192, 192, 192, 255);     break;
        case DARK_GRAY:     SDL_SetRenderDrawColor(this->renderer, 64, 64, 64, 255);        break;
        case LIGHT_RED:     SDL_SetRenderDrawColor(this->renderer, 255, 102, 102, 255);     break;
        case LIGHT_GREEN:   SDL_SetRenderDrawColor(this->renderer, 102, 255, 102, 255);     break;
        case LIGHT_YELLOW:  SDL_SetRenderDrawColor(this->renderer, 255, 255, 102, 255);     break;
        case LIGHT_BLUE:    SDL_SetRenderDrawColor(this->renderer, 102, 102, 255, 255);     break;
        case LIGHT_MAGENTA: SDL_SetRenderDrawColor(this->renderer, 255, 102, 178, 255);     break;
        case LIGHT_CYAN:    SDL_SetRenderDrawColor(this->renderer, 102, 255, 255, 255);     break;
        case COLORS_END:    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);           break;
    }
}
// Display a pixel
void Sdl::putPixel(float x, float y) const
{
    SDL_RenderDrawPoint(this->renderer, x, y);
}

// Display a line
void Sdl::putLine(float x1, float y1, float x2, float y2) const
{
    SDL_RenderDrawLine(this->renderer, x1, y1, x2, y2);
}
// Display an empty rectangle
void Sdl::putRect(float x, float y, float w, float h) const
{
    SDL_Rect rect = {(int)x, (int)y, (int)w, (int)h};

    SDL_RenderDrawRect(this->renderer, &rect);
}
// Display a full rectangle
void Sdl::putFillRect(float x, float y, float w, float h) const
{
    SDL_Rect rect = {(int)x, (int)y, (int)w, (int)h};

    SDL_RenderFillRect(this->renderer, &rect);
}
// Display an empty circle
void Sdl::putCircle(float x, float y, float rad) const
{

    static const double PI = 3.1415926535;
    double x1, y1;
    x += rad;
    y += rad;

    for(double i = 0; i < 360; i += 0.1) {
        x1 = rad * cos(i * PI / 180);
        y1 = rad * sin(i * PI / 180);
        putPixel(x + x1, y + y1);
    }
}
// Display a full circle
void Sdl::putFillCircle(float x, float y, float rad) const
{
    x += rad;
    y += rad;
    int h = 0;
    for (int x1 = -rad; x1 < rad ; x1++) {
        h = (int)sqrt(rad * rad - pow(x1, 2));
        for (int y1 = -h; y1 < h; y1++)
            putPixel(x + x1, y + y1);
    }
}
// Display some text
void Sdl::putText(const std::string &text, unsigned int size, float x, float y) const
{
    SDL_Color color;
    SDL_Rect pos{(int)x, (int)y, 0, 0};
    TTF_Font *font = TTF_OpenFont("./assets/arial.ttf", size);

    SDL_GetRenderDrawColor(this->renderer, &color.r, &color.g, &color.b, &color.a);
    SDL_Surface *texte = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
    SDL_Rect pos2 = {pos.x, pos.y, pos.w, pos.h};
    SDL_RenderCopy(this->renderer, texture, NULL, &pos2);
    SDL_FreeSurface(texte);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

// We chose not to display images because some library can't and it would cause other problems
// You can still parse a file and display pixel art images by displaying pixels manually if you want.

// Strictly for debugging purposes, get the library's name (ncurses/sfm/sdl/libcaca etc etc)
const std::string &Sdl::getLibName() const
{
    return this->name;
}

extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return std::make_unique<Sdl>();
}
