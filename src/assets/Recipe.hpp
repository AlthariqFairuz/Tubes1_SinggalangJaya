#ifndef ASSETS_RECIPE_HPP
#define ASSETS_RECIPE_HPP

#include "Plant.hpp"
#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;

// class RecipeMaterial {
//     public:
//     string plant_code;
//     int quantity;
//     RecipeMaterial(string plant_code, int quantity) :
//     plant_code(plant_code), quantity(quantity) {}
// };

class Recipe {
    public:
    int id;
    string code;
    string name;
    int price;
    map<string, int> materials; // plant_code, quantity 
    // vector<RecipeMaterial> materials;

    Item* to_item();
    static map<string, Recipe> recipe_config;
    static map<string, string> name_to_code;
};

#endif