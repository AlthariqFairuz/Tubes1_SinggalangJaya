#ifndef ASSETS_ANIMAL_HPP
#define ASSETS_ANIMAL_HPP

#include "Item.hpp"
#include <string>
#include <map>

using std::string;
using std::map;

enum class AnimalType {
    Herbivore,
    Carnivore,
    Omnivore,
};

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

    Item* to_item();
};

class Animal : public Item {
    public:
    Animal(string _code);
    int weight;
    
    // Animal(string code, AnimalType animal_type);
    // Animal(string code, AnimalType animal_type, int weight);

    string get_name() override;
    int get_price() override;

    virtual AnimalType get_animal_type() = 0;
    virtual bool ready_to_harvest();

    static map<string, AnimalConfig> animal_config;
    static map<string, string> name_to_code;
};


#endif