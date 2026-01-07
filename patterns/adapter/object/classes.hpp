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

//              АДАПТЕР ОБЪЕКТА
class DuckAd : public IBird
{
private:
    Duck duck_; // если нужно использовать конкретный объект, а не только функционал Duck& duck
public:
    //DuckAd(Duck &duck) : duck_(duck) {}; // в дополнение конструктор копирования конкретного экземпляра.
    void Sound()
    {
        duck_.quaq();
    };
};
