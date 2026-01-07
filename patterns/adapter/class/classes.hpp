#pragma once

#include <iostream>
//              ЭТО НЕЛЬЗЯ МЕНЯТЬ, НО НАДО ИСПОЛЬЗОВАТЬ
class Duck
{
private:
public:
    void quaq()
    {
        std::cout << "Quaq" << std::endl;
    }
};

//              ЭТОМУ ИНТЕРФЕЙСУ НАДО СООТВЕТСТВОВАТЬ
class IBird
{
public:
    IBird() {};
    virtual ~IBird() {};
    virtual void Sound() = 0;
};
//              КЛАСС КОТОРЫЙ УЖЕ БЫЛ В ИНТЕРФЕЙСЕ
class Chicken : public IBird
{
public:
    void Sound()
    {
        std::cout << "Tip-Tip-Tip" << std::endl;
    };
};

//              АДАПТЕР КЛАССА
class DuckAd : public IBird, public Duck
{   
    public:
    void Sound()
    {
        this->quaq();
    };
};
