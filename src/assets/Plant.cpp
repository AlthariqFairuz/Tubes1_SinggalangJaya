#include "Plant.hpp"
#include "MaterialPlant.hpp"
#include "FruitPlant.hpp"

#include <iostream>

map<string, PlantConfig> Plant::plant_config;
map<string, string> Plant::name_to_code;

// PlantConfig

PlantConfig::PlantConfig() {}
PlantConfig::PlantConfig(const PlantConfig &other) : id(other.id), code(other.code), name(other.name), type(other.type), duration_to_harvest(other.duration_to_harvest), price(other.price) {}
PlantConfig::PlantConfig(int id, string code, string name, string type, int duration_to_harvest, int price) : id(id), code(code), name(name), type(type), duration_to_harvest(duration_to_harvest), price(price) {}

using std::cout, std::endl;

Item* PlantConfig::to_item() {
    if (type == "MATERIAL_PLANT") {
        return new MaterialPlant(code);
    } else if (type == "FRUIT_PLANT") {
        return new FruitPlant(code);
    }
    cout << "TO ITEM GAGAL karena file konfigurasi tidak valid" << endl;
    std::exit(0);
}

// Plant

Plant::Plant(string _code) : Item(_code), duration(0) {

}

Plant::Plant(string _code, int _duration) : Item(_code), duration(_duration) {
    
}

string Plant::get_name() {
    return Plant::plant_config.find(code)->second.name;
}

int Plant::get_price() {
    return Plant::plant_config.find(code)->second.price;
}


void Plant::increment_age() {
    ++duration;
}

bool Plant::ready_to_harvest() {
    return duration >= Plant::plant_config[code].duration_to_harvest;
}

// Plant::Plant(string code, PlantType plant_type) : Item(code, ItemType::Plant), plant_type(plant_type) {}
// Plant::Plant(string code, PlantType plant_type, int duration) : Item(code, ItemType::Plant), plant_type(plant_type), duration(duration) {}