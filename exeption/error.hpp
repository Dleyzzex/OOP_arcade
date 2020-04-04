/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include <exception>

class error : std::exception
{
private:
public:
    ~error() = default;
    virtual void what(char const *e) = 0;
};