#pragma once

#include <memory>
#include <iostream>

using std::string;

#define SWORD "sword"
#define GUN "gun"
#define NONE "none"

class Weapon
{
public:
    Weapon() {};
    virtual ~Weapon() = default;

    virtual void Attack()
    {
        std::cout << "Attack by hand. No Weapon were selected" << std::endl;
    };
};
class Sword : public Weapon
{
public:
    Sword()
    {
        std::cout << "Sword activate" << std::endl;
    }
    ~Sword()
    {
        std::cout << "Sword deactivate" << std::endl;
    }
    void Attack()
    {
        std::cout << "Attack by Sword" << std::endl;
    }
};

class Gun : public Weapon
{
public:
    Gun()
    {
        std::cout << "Gun activate" << std::endl;
    }
    ~Gun()
    {
        std::cout << "Gun deactivate" << std::endl;
    }
    void Attack()
    {
        std::cout << "Attack by Gun" << std::endl;
    }
};

class GamePerson
{
private:
    std::unique_ptr<Weapon> weapon_;

public:
    void MakeWeapon(string armor_name)
    {

        if (armor_name == SWORD)
        {
            weapon_ = std::make_unique<Sword>();
        }
        else if (armor_name == GUN)
        {
            weapon_ = std::make_unique<Gun>();
        }
        else
        {
            std::cout << "No Weapon" << std::endl;
            weapon_ = std::make_unique<Weapon>();
        }
    };
    GamePerson()
    {
        std::cout << "GamePerson activate" << std::endl;
    }
    ~GamePerson()
    {
        std::cout << "GamePerson deactivate" << std::endl;
    }
    void Attack()
    {
        std::cout << "GamePerson take his weapon and ..." << std::endl;
        weapon_->Attack();
    }
};