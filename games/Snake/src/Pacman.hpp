/*
** EPITECH PROJECT, 2020
** Pacmap.hpp
** File description:
** Pacmap.hpp
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

class Pacman {
    public:
        Pacman();
        ~Pacman();

    protected:
    private:
        int _Food_remening;
        std::vector<std::string> _Map;
        std::vector<std::string> _Pacman;
        std::vector<std::string> _Ghost;
        std::vector<std::string> _Food;
};

#endif /* !PACMAN_HPP_ */
