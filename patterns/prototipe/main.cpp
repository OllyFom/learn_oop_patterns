#include "classes.hpp"

int main() {
    Dragon dragon;
    cout << "Standart Dragon health: " << dragon.GetHealth() << endl;
    auto dragon_boss2 = dragon.clone(1500);
    cout << "New Dragon health: " << dragon_boss2->GetHealth() << endl;

    Ogr ogr;
    cout << "Standart Org health: " << ogr.GetHealth() << endl;
    auto ogr_boss3 = ogr.clone(90);
    cout << "New Ogr health: " << ogr_boss3->GetHealth() << endl;
}