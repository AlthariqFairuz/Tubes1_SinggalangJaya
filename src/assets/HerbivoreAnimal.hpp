#ifndef ASSETS_HERBIVORE_ANIMAL_HPP
#define ASSETS_HERBIVORE_ANIMAL_HPP

#include "Animal.hpp"
#include "Item.hpp"

class HerbivoreAnimal : public Animal {
    public:
    HerbivoreAnimal(string _code) : Animal(_code)  {
        
    }
    
    ItemType get_item_type() override;
    AnimalType get_animal_type() override;

};

#endif