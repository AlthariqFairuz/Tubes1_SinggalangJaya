#ifndef ASSETS_BUILDING_HPP
#define ASSETS_BUILDING_HPP

#include "Item.hpp"

class Building : public Item {
    public:
    Building(string _code);

    ItemType get_item_type() override;
    string get_name() override;
    int get_price() override;
};

#endif