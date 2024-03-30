#ifndef ASSETS_ANIMAL_HPP
#define ASSETS_ANIMAL_HPP

#include <string>
using std::string;

class Animal {
    int id;
    string code;
    string name;
    string type;
    int weight_to_harvest;
    int price;
};

#endif