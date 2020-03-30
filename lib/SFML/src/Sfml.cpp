/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** [enter description here]
*/

#include "Sfml.hpp"

Sfml::Sfml() {}
// For the core
// Reset the library
void Sfml::reset() {}

void Sfml::open()
{
    sf::ContextSettings settings;

    settings.antialiasingLevel = 8;
    this->window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "- Arkedia -", sf::Style::Default, settings);
    printf("aaaa\n");
    setColor(DEFAULT);
    this->name = "sfml";
    this->font.loadFromFile("04B_30__.TTF");
}
// Check if the window is open

bool Sfml::isOpen() const
{
    return this->window->isOpen();
}
// Handle switching libs & games (the names are explicit)
// Those are all key presses
// Those must be different than the keys listed in the Keys enum.
// The keys enum only lists keys used by games, not special keys to switch libraries.
bool Sfml::switchToNextLib() const
{
    if (this->isKeyPressed(IDisplayModule::UP))
        return true;
    return false;
}

bool Sfml::switchToPreviousLib() const
{
    if (this->isKeyPressed(IDisplayModule::DOWN))
        return true;
    return false;
}

bool Sfml::switchToNextGame() const
{
    if (this->isKeyPressed(IDisplayModule::RIGHT))
        return true;
    return false;
}

bool Sfml::switchToPreviousGame() const
{
    if (this->isKeyPressed(IDisplayModule::LEFT))
        return true;
    return false;
}

// From the pdf
bool Sfml::shouldBeRestarted() const
{
    if (this->isKeyPressed(IDisplayModule::X))
        return true;
    return false;
}

bool Sfml::shouldGoToMenu() const
{
    if (this->isKeyPressed(IDisplayModule::W))
        return true;
    return false;
}

bool Sfml::shouldExit() const
{
    if (this->isKeyPressed(IDisplayModule::BACKSPACE))
        return true;
    return false;
}

// Handle Inputs & Events

bool Sfml::KeySet(IDisplayModule::Keys key) const
{
    switch (key) {
        case LEFT: if (this->event.key.code == sf::Keyboard::Left) { return true; }             break;
        case RIGHT: if (this->event.key.code == sf::Keyboard::Right) { return true; }           break;
        case UP: if (this->event.key.code == sf::Keyboard::Up) { return true; }                 break;
        case DOWN: if (this->event.key.code == sf::Keyboard::Down) { return true; }             break;
        case Z: if (this->event.key.code == sf::Keyboard::Z) { return true; }                   break;
        case Q: if (this->event.key.code == sf::Keyboard::Q) { return true; }                   break;
        case S: if (this->event.key.code == sf::Keyboard::S) { return true; }                   break;
        case D: if (this->event.key.code == sf::Keyboard::D) { return true; }                   break;
        case A: if (this->event.key.code == sf::Keyboard::A) { return true; }                   break;
        case E: if (this->event.key.code == sf::Keyboard::E) { return true; }                   break;
        case W: if (this->event.key.code == sf::Keyboard::W) { return true; }                   break;
        case X: if (this->event.key.code == sf::Keyboard::X) { return true; }                   break;
        case SPACE: if (this->event.key.code == sf::Keyboard::Space) { return true; }           break;
        case J: if (this->event.key.code == sf::Keyboard::J) { return true; }                   break;
        case K: if (this->event.key.code == sf::Keyboard::K) { return true; }                   break;
        case U: if (this->event.key.code == sf::Keyboard::U) { return true; }                   break;
        case I: if (this->event.key.code == sf::Keyboard::I) { return true; }                   break;
        case ENTER: if (this->event.key.code == sf::Keyboard::Return) { return true; }          break;
        case BACKSPACE: if (this->event.key.code == sf::Keyboard::BackSpace) { return true; }   break;
        case KEYS_END: return false;
    }
    return false;
}

bool Sfml::isKeyPressed(IDisplayModule::Keys key) const
{
    if (event.type != sf::Event::KeyPressed)
        return false;
    return KeySet(key);
}

bool Sfml::isKeyPressedOnce(IDisplayModule::Keys key) const
{
    if (event.type != sf::Event::KeyReleased)
        return false;
    return KeySet(key);
}
// Get the number of frames that passed between two calls to this function
// The games should not be frame dependant!! That's why this is here.
float Sfml::getDelta() const
{
    return 1;
}

// Handle Loop
void Sfml::clear() const
{
    this->window->clear();
}

void Sfml::update()
{
    if (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window->close();
        if (this->event.type == sf::Event::TextEntered)
            if (this->event.text.unicode < 128)
                this->lastKey = static_cast<char>(this->event.text.unicode);
    }

}

void Sfml::render() const
{
    this->window->display();
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
char Sfml::getKeyCode() const
{
    return this->lastKey;
}

// Display Stuff
// Sets the color for all the following draw functions.
// everything you display after this will have the selected color
void Sfml::setColor(IDisplayModule::Colors col)
{
    switch (col) {
        case DEFAULT:       this->color = sf::Color::Black;                 break;
        case BLACK:         this->color = sf::Color::Black;                 break;
        case WHITE:         this->color = sf::Color::White;                 break;
        case RED:           this->color = sf::Color::Red;                   break;
        case GREEN:         this->color = sf::Color::Green;                 break;
        case BLUE:          this->color = sf::Color::Blue;                  break;
        case YELLOW:        this->color = sf::Color::Yellow;                break;
        case MAGENTA:       this->color = sf::Color::Magenta;               break;
        case CYAN:          this->color = sf::Color::Cyan;                  break;
        case LIGHT_GRAY:    this->color = sf::Color(192, 192, 192, 255);    break;
        case DARK_GRAY:     this->color = sf::Color(64, 64, 64, 255);       break;
        case LIGHT_RED:     this->color = sf::Color(255, 102, 102, 255);    break;
        case LIGHT_GREEN:   this->color = sf::Color(102, 255, 102, 255);    break;
        case LIGHT_YELLOW:  this->color = sf::Color(255, 255, 102, 255);    break;
        case LIGHT_BLUE:    this->color = sf::Color(102, 102, 255, 255);    break;
        case LIGHT_MAGENTA: this->color = sf::Color(255, 102, 178, 255);    break;
        case LIGHT_CYAN:    this->color = sf::Color(102, 255, 255, 255);    break;
        case COLORS_END:    this->color = sf::Color::Black;                 break;
    }
    return ;
}
// Display a pixel
void Sfml::putPixel(float x, float y) const
{
    putFillRect(x, y, 1, 1);
}

// Display a line
void Sfml::putLine(float x1, float y1, float x2, float y2) const
{
    sf::VertexArray line(sf::Lines, 2);

    line[0].position = sf::Vector2f(x1, y1);
    line[1].position = sf::Vector2f(x2, y2);
    line[0].color = this->color;
    line[1].color = this->color;
    this->window->draw(line);
}
// Display an empty rectangle
void Sfml::putRect(float x, float y, float w, float h) const
{
    sf::RectangleShape rect(sf::Vector2f(w, h));

    rect.setPosition(x, y);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineThickness(1);
    rect.setOutlineColor(this->color);
    this->window->draw(rect);
}
// Display a full rectangle
void Sfml::putFillRect(float x, float y, float w, float h) const
{
    sf::RectangleShape rect(sf::Vector2f(w, h));

    rect.setPosition(x, y);
    rect.setFillColor(this->color);
    this->window->draw(rect);
}
// Display an empty circle
void Sfml::putCircle(float x, float y, float rad) const
{
    sf::CircleShape circle(rad);

    circle.setPosition(x, y);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(1);
    circle.setOutlineColor(this->color);
    this->window->draw(circle);
}
// Display a full circle
void Sfml::putFillCircle(float x, float y, float rad) const
{
    sf::CircleShape circle(rad);

    circle.setPosition(x, y);
    circle.setFillColor(this->color);
    this->window->draw(circle);
}
// Display some text
void Sfml::putText(const std::string &text, unsigned int size, float x, float y) const
{
    sf::Text string(text, this->font);

    string.setCharacterSize(size);
    string.setPosition(x, y);
    string.setFillColor(this->color);
    this->window->draw(string);
}

// We chose not to display images because some library can't and it would cause other problems
// You can still parse a file and display pixel art images by displaying pixels manually if you want.

// Strictly for debugging purposes, get the library's name (ncurses/sfm/sdl/libcaca etc etc)
const std::string &Sfml::getLibName() const
{
    return this->name;
}

extern "C" std::unique_ptr<IDisplayModule> createLib(void)
{
    return std::make_unique<Sfml>();
}
