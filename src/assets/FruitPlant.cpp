#include "FruitPlant.hpp"

FruitPlant::FruitPlant(string _code) : Plant(_code) {

}

ItemType FruitPlant::get_item_type() {
    return ItemType::Plant;
}

PlantType FruitPlant::get_plant_type() {
    return PlantType::Fruit;
}
