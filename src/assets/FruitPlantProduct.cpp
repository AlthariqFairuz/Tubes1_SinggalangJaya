#include "FruitPlantProduct.hpp"
#include <string>

using std::string;

FruitPlantProduct::FruitPlantProduct(string _code) : PlantProduct(_code) {

}

ItemType FruitPlantProduct::get_item_type() {
    return ItemType::Product;
}

ProductType FruitPlantProduct::get_product_type() {
    return ProductType::Plant;
}

PlantProductType FruitPlantProduct::get_plant_product_type() {
    return PlantProductType::Fruit;
}

bool FruitPlantProduct::is_consumable() {
    return true;
}