#include "classes.hpp"

void print_line() {
    cout << "--------------" << endl;
}

int main() {

    std::unique_ptr<IModulePhone> phone = std::make_unique<BasicPhone>();
    phone->ICan();
    print_line();

    phone = std::make_unique<CameraModule>(std::move(phone));
    phone->ICan();
    print_line();

    phone = std::make_unique<AudioModule>(std::move(phone));
    phone->ICan();
    print_line();
    
    phone = std::make_unique<BatteryModule>(std::move(phone));
    phone->ICan();
    print_line();
}