#pragma once

#include <iostream>
#include <memory>

using std::cout, std::endl;

class IEnemy
{
private:
    int health_;
    // IEnemy(int health): health_(health) {};
public:
    IEnemy() = default;
    virtual ~IEnemy() = default;
    virtual std::unique_ptr<IEnemy> clone(int health) = 0;
    virtual int GetHealth() = 0;
};

class Dragon : public IEnemy
{
private:
    int health_ = 1000;
    Dragon(int health) : health_(health) {};

public:
    Dragon() = default;
    ~Dragon() = default;
    int GetHealth() {
        return health_;
    }
    std::unique_ptr<IEnemy> clone(int health)
    {
        cout << "Copy of Dragon was made health " << health << endl;
        return std::unique_ptr<Dragon>(new Dragon(health));
    }
};

class Ogr : public IEnemy
{
private:
    int health_ = 140;
    Ogr(int health) : health_(health) {};

public:
    Ogr()  = default;
    ~Ogr() = default;
    int GetHealth() {
        return health_;
    }
    std::unique_ptr<IEnemy> clone(int health)
    {
        cout << "Copy of Ogr was made with health " << health << endl;
        return std::unique_ptr<Ogr>(new Ogr(health));
    }
};