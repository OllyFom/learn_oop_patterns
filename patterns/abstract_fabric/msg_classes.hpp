#pragma once

#include <iostream>

using std::cout, std::endl, std::string;

//                              MESSAGES INTERFACES

class IEmail
{
public:
    virtual ~IEmail() = default;
    virtual void send(string message) = 0;
};

class ISms
{
public:
    virtual ~ISms() = default;
    virtual void send(string message) = 0;
};

//                                          FORMAL
class FormalSms : public ISms
{
    void send(string message)
    {
        cout << "For Information: " << message << endl;
    }
};

class FormalEmail : public IEmail
{
    void send(string message)
    {
        cout << "Dear client, " << message << endl;
    }
};
//                                          CASUAL
class CasualSms : public ISms
{
    void send(string message)
    {
        cout << "Hi! Look at this: " << message << endl;
    }
};

class CasualEmail : public IEmail
{
    void send(string message)
    {
        cout << "Hi! We have some news for you: " << message << endl;
    }
};