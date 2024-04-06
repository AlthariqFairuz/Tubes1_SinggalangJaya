#ifndef ASSETS_ANIMAL_HPP
#define ASSETS_ANIMAL_HPP

#include "Item.hpp"
#include <string>
#include <map>

using std::string;
using std::map;

class AnimalConfig {
    public:
    int id;
    string code;
    string name;
    string type;
    int weight_to_harvest;
    int price;

    AnimalConfig() {}

    AnimalConfig(const AnimalConfig &other) :
    id(other.id), code(other.code), name(other.name), type(other.type), weight_to_harvest(other.weight_to_harvest), price(other.price) {}

    AnimalConfig(int id, string code, string name, string type, int weight_to_harvest, int price) :
    id(id), code(code), name(name), type(type), weight_to_harvest(weight_to_harvest), price(price) {}
};

class Animal : public Item {
    public:
    int weight;

    Animal() : Item() {}
    Animal(string code) : Item(code, ItemType::Animal) {}
    Animal(string code, int weight) : Item(code, ItemType::Animal), weight(weight) {}

    static map<string, AnimalConfig> animal_config;
    static map<string, string> name_to_code;
};


#endif