/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <vector>
#include <map>

#define SAVE_PATH "games/.saves/"
#define WIDTH 640
#define HEIGHT 480

class IDisplayModule {
    public:
        __attribute__((destructor)) ~IDisplayModule() = default;

        // Limited to the bash color codes in case colors aren't handled by a library
        enum Colors {
            DEFAULT,
            BLACK,
            RED,
            GREEN,
            YELLOW,
            BLUE,
            MAGENTA,
            CYAN,
            LIGHT_GRAY,
            DARK_GRAY,
            LIGHT_RED,
            LIGHT_GREEN,
            LIGHT_YELLOW,
            LIGHT_BLUE,
            LIGHT_MAGENTA,
            LIGHT_CYAN,
            WHITE,
            END
        };

        // Keys you have to implement, there are enough keys to have multiple keyboard configurations for every game
        // You only need 6 keys for the core and 6 for the games.
        enum Keys {
            LEFT,
            RIGHT,
            UP,
            DOWN,
            Z,
            Q,
            S,
            D,
            A,
            E,
            W,
            X,
            SPACE,
            ESCAPE,
            J,
            K,
            U,
            I,
            M,
            R,
            END
        };

        // For the core
        // Reset the library
        virtual void reset() = 0;
        // Check if the window is open
        virtual bool is_open() = 0;

        // Handle switching libs & games (the names are explicit)
        // Those are all key presses
        // Those must be different than the keys listed in the Keys enum.
        // The keys enum only lists keys used by games, not special keys to switch libraries.
        virtual bool switch_to_next_lib() = 0;
        virtual bool switch_to_previous_lib() = 0;
        virtual bool switch_to_next_game() = 0;
        virtual bool switch_to_previous_game() = 0;
        // From the pdf
        virtual bool should_be_restarted() = 0;
        virtual bool should_go_to_menu() = 0;
        virtual bool should_exit() = 0;

        // Handle Inputs & Events
        virtual bool is_key_pressed(IDisplayModule::Keys) = 0;
        virtual bool is_key_pressed_once(IDisplayModule::Keys) = 0;
        // Get the number of frames that passed between two calls to this function
        // The games should not be frame dependant!! That's why this is here.
        virtual float get_delta() = 0;

        // Handle Loop
        virtual void clear() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        // You don't need all three of them, only one should be enough but we added the three of them
        // in case some of you want to seperate each step
        // Your core (or games) should nonetheless call all of these functions in this specific order :
        // clear -> update -> render

        // Handle Text Input
        // We need to ask for the player's name (check the pdf before complaining and asking about this function)
        virtual std::string get_player_name() = 0;
        virtual void set_player_name(std::string) = 0;

        // Display Stuff
        // Sets the color for all the following draw functions.
        // everything you display after this will have the selected color
        virtual void set_color(IDisplayModule::Colors col) = 0;
        // Display a pixel
        virtual void put_pixel(float x, float y) = 0;
        // Display a line
        virtual void put_line(float x1, float y1, float x2, float y2) = 0;
        // Display an empty rectangle
        virtual void put_rect(float x, float y, float w, float h) = 0;
        // Display a full rectangle
        virtual void put_fill_rect(float x, float y, float w, float h) = 0;
        // Display an empty circle
        virtual void put_circle(float x, float y, float rad) = 0;
        // Display a full circle
        virtual void put_fill_circle(float x, float y, float rad) = 0;
        // Display some text
        virtual void put_text(std::string text, float size, int x, int y) = 0;

        // We chose not to display images because some library can't and it would cause other problems
        // You can still parse a file and display pixel art images by displaying pixels manually if you want.

        // Strictly for debugging purposes, get the library's name (ncurses/sfm/sdl/libcaca etc etc)
        virtual std::string getLibName() const = 0;
};

class IGameModule {
    public:
        ~IGameModule() = default;

        // For the core

        // Reset game at any moment
        virtual void reset() = 0;

        // Load highscores from file and return wether it worked or not
        virtual bool load_from_file(std::string filepath) = 0; // with filename
        virtual bool load_from_file() = 0; // default filename

        // save highscores to file return wether it worked or not
        virtual bool save_to_file(std::string filepath) = 0; // with filename
        virtual bool save_to_file() = 0; // default filename

        // Set the player's name
        virtual void set_player_name(std::string) = 0;
        // get the best score
        virtual std::map<std::string, int> get_highscore() = 0;
        // get the 16 best scores
        virtual std::vector<std::map<std::string, int>> get_latest_scores() = 0;

        // Handle Game
        // update game
        virtual void update() = 0;
        // display stuff using the lib given as an argument.
        virtual void render(IDisplayModule &lib) = 0;
        virtual std::string getGameName() const = 0;
};

// Good luck and have fun.
// If you have a problem with the interface or a question send me a message :
// discord         : Zikoure#0963
// microsoft teams : ghassane.sebai@epitech.eu

#endif /* !CORE_HPP_ */
