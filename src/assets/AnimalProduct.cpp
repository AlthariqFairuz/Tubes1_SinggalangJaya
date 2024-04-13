#include "AnimalProduct.hpp"
#include <string>

using std::string;

AnimalProduct::AnimalProduct(string _code) : Product(_code) {
    
}
ItemType AnimalProduct::get_item_type() {
    return ItemType::Product;
}

ProductType AnimalProduct::get_product_type() {
    return ProductType::Animal;
}

bool AnimalProduct::is_consumable() {
    return true;
}