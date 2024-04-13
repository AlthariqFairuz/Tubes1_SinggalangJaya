#include "Building.hpp"
#include "Recipe.hpp"

Building::Building(string _code) : Item(_code) {

}

ItemType Building::get_item_type() {
    return ItemType::Building;
}

string Building::get_name() {
    return Recipe::recipe_config.find(code)->second.name;
}

int Building::get_price() {
    return Recipe::recipe_config.find(code)->second.price;
}