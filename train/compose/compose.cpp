#include <iostream>

#include "classes.hpp"

int main()
{
    GamePerson boy;
    string armor;
    while (1)
    {
        std::cout << "Input weapon (sword, gun, none)" << std::endl;
        std::cin >> armor;
        boy.MakeWeapon(armor);
        boy.Attack();
    }
}