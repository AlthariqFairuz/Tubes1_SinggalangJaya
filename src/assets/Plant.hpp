#ifndef ASSETS_PLANT_HPP
#define ASSETS_PLANT_HPP

#include "Item.hpp"
#include <string>
#include <map>

using std::string;
using std::map;

enum class PlantType {
    Material,
    Fruit,
};

class PlantConfig {
    public:
    int id;
    string code;
    string name;
    string type;
    int duration_to_harvest;
    int price;

    PlantConfig();
    PlantConfig(const PlantConfig& other);
    PlantConfig(int id, string code, string name, string type, int duration_to_harvest, int price);


    Item* to_item();
};

class Plant : public Item {
    public:
    // PlantType plant_type;
    int duration;

    Plant(string _code);
    // Plant(string code, PlantType plant_type);
    // Plant(string code, PlantType plant_type, int duration);

    string get_name() override;
    int get_price() override;

    virtual PlantType get_plant_type() = 0;
    virtual void increment_age();
    virtual bool ready_to_harvest();
    

    static map<string, PlantConfig> plant_config;
    static map<string, string> name_to_code;
};

#endif