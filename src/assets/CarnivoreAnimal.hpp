#ifndef ASSETS_CARNIVORE_ANIMAL_HPP
#define ASSETS_CARNIVORE_ANIMAL_HPP

#include "Animal.hpp"

class CarnivoreAnimal : public Animal {
    public:
    CarnivoreAnimal(string _code) : Animal(_code)  {
        
    }

    ItemType get_item_type() override;
    AnimalType get_animal_type() override;
};

#endif