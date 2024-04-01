#ifndef ASSETS_PLANT_HPP
#define ASSETS_PLANT_HPP

#include <string>
#include <map>

using std::string;
using std::map;

class PlantConfig {
    public:
    int id;
    string code;
    string name;
    string type;
    int duration_to_harvest;
    int price;

    PlantConfig() {}
    PlantConfig(const PlantConfig& other) :
    id(other.id), code(other.code), name(other.name), type(other.type), duration_to_harvest(other.duration_to_harvest), price(other.price) {}

    PlantConfig(int id, string code, string name, string type, int duration_to_harvest, int price) :
    id(id), code(code), name(name), type(type), duration_to_harvest(duration_to_harvest), price(price) {}
};

class Plant {
    public:

    static map<string, PlantConfig> plant_config;
};

#endif