#ifndef ASSETS_ANIMAL_PRODUCT_HPP
#define ASSETS_ANIMAL_PRODUCT_HPP

#include "Product.hpp"

class AnimalProduct : public Product {
    ItemType get_item_type() override;
    ProductType get_product_type() override;
};

#endif