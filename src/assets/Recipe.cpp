#include "Recipe.hpp"
#include "Building.hpp"

map<string, Recipe> Recipe::recipe_config;
map<string, string> Recipe::name_to_code;

Item* Recipe::to_item() {
    return new Building(code);
}