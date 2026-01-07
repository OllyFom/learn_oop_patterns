#include "classes.hpp"

int main() {
    Duck duck;
    // duck.Sound(); - error
    std::cout << "No adapter output" << std::endl;
    duck.quaq();

    DuckAd duckAd;
    std::cout << "Adapter output" << std::endl;
    duckAd.Sound();

    Chicken chicken;
    chicken.Sound();
}