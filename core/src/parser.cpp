/*
** EPITECH PROJECT, 2020
** parser
** File description:
** parser
*/

#include <iostream>
#include <dirent.h>
#include <vector>

std::vector<std::string> getFilenames(std::string path)
{
    DIR *dir = NULL;
    struct dirent *dirent = NULL;
    std::vector<std::string> names;
    size_t find = 0;

    dir = opendir(path.c_str());
    if (dir == NULL)
        exit(84);
    while ((dirent = readdir(dir)) != NULL) {
        std::string tmp(dirent->d_name);
        find = tmp.find(".so");
        if (find != std::string::npos)
            names.push_back(tmp);
    }
    return (names);
}
