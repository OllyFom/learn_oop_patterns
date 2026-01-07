#include "classes.hpp"

int main()
{
    std::string choice = "airplain";
    std::unique_ptr<ITransport> transport;
    if (choice == "car") {
        transport = std::make_unique<Car>();
    } else {
        transport = std::make_unique<Airplane>();
    }
    DeleverySrc src(std::move(transport));
    src.StartTransfer();
}