#include "FruitPlant.hpp"

FruitPlant::FruitPlant(string _code) : Plant(_code) {

}


FruitPlant::FruitPlant(string _code, int _duration) : Plant(_code, _duration) {

}


ItemType FruitPlant::get_item_type() {
    return ItemType::Plant;
}

PlantType FruitPlant::get_plant_type() {
    return PlantType::Fruit;
}