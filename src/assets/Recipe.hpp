#ifndef ASSETS_RECIPE_HPP
#define ASSETS_RECIPE_HPP

#include "Plant.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Recipe {
    int id;
    string code;
    string name;
    int price;
    vector<RecipeMaterial> materials;
};

class RecipeMaterial {
    Plant material;
    int quantity;
};

#endif