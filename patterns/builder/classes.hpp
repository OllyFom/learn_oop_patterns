#pragma once

#include <iostream>

using std::cout, std::endl, std::string;

//                                  КОНЕЧНЫЙ ПРОДУКТ

class Bag
{
    string shoes_, t_short_, swimsuit_, jacket_;

public:
    void set_shoes(string shoes)
    {
        shoes_ = shoes;
    }
    void set_t_short(string t_short)
    {
        t_short_ = t_short;
    }
    void set_swimsuit(string swimsuit)
    {
        swimsuit_ = swimsuit;
    }
    void set_jacket(string jacket)
    {
        jacket_ = jacket;
    }
    void GetBag() {
        cout << shoes_ << endl;
        cout << t_short_ << endl;
        cout << swimsuit_ << endl;
        cout << jacket_ << endl;  
    };
};

//                                  ВАРИАНТЫ "ПОСТРОЙКИ"

// Интерфейс вариантов постройки
class VariableBag 
{
  
protected:
    Bag bag_;
    VariableBag() = default;
public:
    virtual ~VariableBag() = default;
    virtual void build_shoes() = 0;
    virtual void build_jacket() = 0;
    virtual void build_t_short() = 0;
    virtual void build_swimsuit() = 0;
    virtual Bag build() {
        return bag_;
    }
};

class SummerBag : public VariableBag
{

public:
    void build_shoes()
    {
        bag_.set_shoes("flip-flops");
    };
    void build_jacket()
    {
        bag_.set_jacket("none");
    };
    void build_t_short()
    {
        bag_.set_t_short("red t-short");
    }
    void build_swimsuit()
    {
        bag_.set_swimsuit("blue swimsuit");
    }
};

class WinterBag : public VariableBag
{

public:
    void build_shoes()
    {
        bag_.set_shoes("boots");
    };
    void build_jacket()
    {
        bag_.set_jacket("black jacket");
    };
    void build_t_short()
    {
        bag_.set_t_short("red t-short");
    }
    void build_swimsuit()
    {
        bag_.set_swimsuit("none");
    }
    
};

//                                      ГЛАВНЫЙ СТРОИТЕЛЬ С ИНСТРУКЦИЕЙ, КАК УКЛАДЫВАТЬ БАГАЖ

class BagBuilder
{
public:
    Bag pack_luggage(VariableBag &builder)
    {
        builder.build_shoes();
        builder.build_jacket();
        builder.build_t_short();
        builder.build_swimsuit();
        return builder.build();
    }
};