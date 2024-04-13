#include "Item.hpp"
#include <iostream>

using std::cout, std::endl;

Item::Item(string _code) {
    code = _code;
}

Item::~Item() { }

string Item::get_item_type_string(ItemType item_type) {
    if (item_type == ItemType::Animal) {
        return "Animal";
    } else if (item_type == ItemType::Plant) {
        return "Plant";
    } else if (item_type == ItemType::Building) {
        return "Building";
    } else if (item_type == ItemType::Product) {
        return "Product";
    }
    cout << "Invalid Item Type" << endl;
    return "Invalid";
}