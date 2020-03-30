/*
** EPITECH PROJECT, 2020
** DLLoader
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP
#define DLLOADER_HPP

#include <dlfcn.h>
#include <iostream>

/*  Get the name of the lib,
return a constructor of the lib */
template<typename T>
class DLLoader {
    public:

    DLLoader()
    {
        this->data = NULL;
    }

    DLLoader(std::string path)
    {
        this->data = dlopen(path.c_str(), RTLD_LAZY);
    }

    ~DLLoader()
    {
        if (data)
            dlclose(data);
    }

    T *getInstance(std::string path)
    {
        T* (*creator)();

        (void) path;
        creator = (T* (*)())dlsym(this->data, "createLib");
        return ((*creator)());
    }

    private:
    void *data;
};

/*
T* (*creator)();

(void) path;
creator = (T* (*)())dlsym(this->data, "createLib");
*/

#endif