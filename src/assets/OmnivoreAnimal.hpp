#ifndef ASSETS_OMNIVORE_ANIMAL_HPP
#define ASSETS_OMNIVORE_ANIMAL_HPP

#include "Animal.hpp"

class OmnivoreAnimal : public Animal {
    public:
    OmnivoreAnimal(string _code) : Animal(_code)  {
        
    }

    ItemType get_item_type() override;
    AnimalType get_animal_type() override;
};

#endif