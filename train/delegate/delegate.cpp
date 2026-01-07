#include "classes.hpp"

int main()
{
    DeleverySrc src;
    std::string transport_name;
    while (1)
    {
        std::cout << "Input transport" << std::endl;
        std::cin >> transport_name;
        src.MakeTransport(transport_name);
        src.StartTransfer();
    }
}