#include "classes.hpp"

int main() {

    std::unique_ptr<IPhone> iphone = std::make_unique<ProxyPhone>();
    iphone->call();
}