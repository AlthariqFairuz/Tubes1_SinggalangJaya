#ifndef ASSETS_FRUIT_PLANT_HPP
#define ASSETS_FRUIT_PLANT_HPP

#include "Plant.hpp"

class FruitPlant : public Plant {
    public:
    FruitPlant(string _code);

    ItemType get_item_type() override;
    PlantType get_plant_type() override;
};

#endif