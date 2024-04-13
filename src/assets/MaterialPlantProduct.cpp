#include "MaterialPlantProduct.hpp"
#include <string>

using std::string;

MaterialPlantProduct::MaterialPlantProduct(string _code) : PlantProduct(_code) {

}

ItemType MaterialPlantProduct::get_item_type() {
    return ItemType::Product;
}

ProductType MaterialPlantProduct::get_product_type() {
    return ProductType::Plant;
}

PlantProductType MaterialPlantProduct::get_plant_product_type() {
    return PlantProductType::Material;
}

bool MaterialPlantProduct::is_consumable() {
    return false;
}
