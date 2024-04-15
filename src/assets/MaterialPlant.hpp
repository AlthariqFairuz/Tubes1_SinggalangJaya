#ifndef ASSETS_MATERIAL_PLANT_HPP
#define ASSETS_MATERIAL_PLANT_HPP

#include "Plant.hpp"

class MaterialPlant : public Plant
{
public:
    MaterialPlant(string _code);
    MaterialPlant(string _code, int _duration);

    ItemType get_item_type() override;
    PlantType get_plant_type() override;
};

#endif