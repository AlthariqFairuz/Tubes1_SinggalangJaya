#ifndef ASSETS_ANIMAL_PRODUCT_HPP
#define ASSETS_ANIMAL_PRODUCT_HPP

#include "Product.hpp"

class AnimalProduct : public Product {
    public:
    
    AnimalProduct(string _code);
    ItemType get_item_type() override;
    ProductType get_product_type() override;
    bool is_consumable() override;
};

#endif