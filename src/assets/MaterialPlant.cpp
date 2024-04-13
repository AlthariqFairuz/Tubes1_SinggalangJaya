#include "MaterialPlant.hpp"

MaterialPlant::MaterialPlant(string _code) : Plant(_code) {
    
}

ItemType MaterialPlant::get_item_type() {
    return ItemType::Plant;
}

PlantType MaterialPlant::get_plant_type() {
    return PlantType::Material;
}