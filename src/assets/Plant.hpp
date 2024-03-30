#ifndef ASSETS_PLANT_HPP
#define ASSETS_PLANT_HPP

#include <string>

using std::string;

class Plant {
    int id;
    string code;
    string name;
    string type;
    int duration_to_harvest;
    int price;
};

#endif