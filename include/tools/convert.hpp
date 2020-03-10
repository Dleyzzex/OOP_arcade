/*
** EPITECH PROJECT, 2020
** convert
** File description:
** convert
*/

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <sstream>

template<typename T>
T convert(std::string str)
{
    T ret = 0;
    std::istringstream tmp(str);

    tmp>>ret;
    return (ret);
}

#endif
