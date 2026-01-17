#include "classes.hpp"

int main() {
    
    cout << "_____Summer Bag_____" << endl;

    SummerBag summer_bag;
    BagBuilder bag_builder;
    auto my_season_bag = bag_builder.pack_luggage(summer_bag);
    my_season_bag.GetBag();

    cout << "_____Winter Bag_____" << endl;
    
    WinterBag winter_bag;
    auto my_season_bag2 = bag_builder.pack_luggage(winter_bag);
    my_season_bag2.GetBag();

}