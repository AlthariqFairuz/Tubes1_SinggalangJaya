#include "FruitPlantProduct.hpp"

ItemType FruitPlantProduct::get_item_type() {
    return ItemType::Product;
}

ProductType FruitPlantProduct::get_product_type() {
    return ProductType::Plant;
}

PlantProductType FruitPlantProduct::get_plant_product_type() {
    return PlantProductType::Fruit;
}