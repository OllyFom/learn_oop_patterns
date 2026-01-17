#pragma once

#include <iostream>

using std::cout, std::endl, std::string;

class Logger
{
private:
    Logger() = default;

public:
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    static void getLogs(string msg)
    {
        cout << "[LOG]: " << msg << endl;
    };
};