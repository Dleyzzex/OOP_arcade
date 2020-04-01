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
        this->data = dlopen(path.c_str(), RTLD_LOCAL | RTLD_LAZY);
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
        std::cout << std::endl;
        return ((creator)());
    }

    private:
    void *data;
    int *iptr;
    int (*fptr)(int);
};

/*
T* (*creator)();

(void) path;
creator = (T* (*)())dlsym(this->data, "createLib");
        return ((*creator)());



void    *handle;
int     *iptr, (*fptr)(int);

/* open the needed object */
//handle = dlopen("/usr/home/me/libfoo.so", RTLD_LOCAL | RTLD_LAZY);

/* find the address of function and data objects */
//fptr = (int (*)(int))dlsym(handle, "my_function");
//iptr = (int *)dlsym(handle, "my_object");

/* invoke function, passing value of integer as a parameter */
//(*fptr)(*iptr);

#endif