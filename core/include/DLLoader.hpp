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
        this->data = dlopen(path.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    }

    ~DLLoader()
    {
        if (data)
            dlclose(data);
    }

    T getInstance(std::string path)
    {
        T (*creator)();

        if (!data) {
            this->data = dlopen(path.c_str(), RTLD_LAZY | RTLD_GLOBAL);
            if (!data) {
                std::cerr << dlerror() << std::endl;
                exit(84);
            }
        }
        creator = (T (*)())dlsym(this->data, "createLib");
        return ((creator)());
    }

    private:
    void *data;
    int *iptr;
    int (*fptr)(int);
};

#endif