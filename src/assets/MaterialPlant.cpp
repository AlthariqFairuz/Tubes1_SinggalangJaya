#include "MaterialPlant.hpp"

MaterialPlant::MaterialPlant(string _code) : Plant(_code)
{
}

MaterialPlant::MaterialPlant(string _code, int _duration) : Plant(_code, _duration) {

}

ItemType MaterialPlant::get_item_type() {
    return ItemType::Plant;
}

PlantType MaterialPlant::get_plant_type()
{
    return PlantType::Material;
}