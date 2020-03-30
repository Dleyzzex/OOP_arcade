/*
** EPITECH PROJECT, 2020
** myclass
** File description:
** myclass
*/

#include "myclass.h"
#include <iostream>

using namespace std;

extern "C" std::unique_ptr<Arcade::Display::IDisplayModule> createLib(void)
{
    return std::make_unique<Arcade::Display::SFML>();
}

extern "C" MyClass* create_object()
{
  return new MyClass;
}

extern "C" void destroy_object( MyClass* object )
{
  delete object;
}

MyClass::MyClass()
{
  x = 20;
}

void MyClass::DoSomething()
{
  cout<<x<<endl;
}