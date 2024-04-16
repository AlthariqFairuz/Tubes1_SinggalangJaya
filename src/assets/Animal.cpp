#include <iostream>
#include <string>
#include "Animal.hpp"
#include "HerbivoreAnimal.hpp"
#include "CarnivoreAnimal.hpp"
#include "OmnivoreAnimal.hpp"

using std::cout, std::endl;
using std::string;

map<string, AnimalConfig> Animal::animal_config;
map<string, string> Animal::name_to_code;

Animal::Animal(string _code, int _weight) : Item(_code), weight(_weight) {

}

string Animal::get_name() {
    return Animal::animal_config.find(code)->second.name;
}

int Animal::get_price() {
    return Animal::animal_config.find(code)->second.price;
}


Item* AnimalConfig::to_item() {
    if (type == "HERBIVORE") {
        return new HerbivoreAnimal(code);
    } else if (type == "CARNIVORE") {
        return new CarnivoreAnimal(code);
    } else if (type == "OMNIVORE") {
        return new OmnivoreAnimal(code);
    }
    cout << "TO ITEM GAGAL karena file konfigurasi tidak valid" << endl;
    std::exit(0);
}

// Animal::Animal(string code, AnimalType animal_type) : Item(code, ItemType::Animal), animal_type(animal_type) {}
// Animal::Animal(string code, AnimalType animal_type, int weight) : Item(code, ItemType::Animal), animal_type(animal_type), weight(weight) {}

Animal::Animal(string _code) : Item(_code), weight(0) {

}

bool Animal::ready_to_harvest() {
    return weight >= Animal::animal_config[code].weight_to_harvest;
}