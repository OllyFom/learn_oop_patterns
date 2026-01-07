#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Algorithm
{
public:
    Algorithm() = default;
    virtual ~Algorithm() = default;
    void StepHi()
    {
        cout << "Hi" << endl;
    }
    virtual void StepOutput()
    {
        cout << "Some standart output" << endl;
    };
    void StepByu()
    {
        cout << "Byu" << endl;
    }

    void GoAlgo()
    {
        StepHi();
        StepOutput();
        StepByu();
    }
};

class CustomStepAlgo : public Algorithm
{
public:
    void StepOutput()
    {
        cout << "Custom output" << endl;
    }
};