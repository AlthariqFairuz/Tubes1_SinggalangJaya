#ifndef ASSETS_PLANT_PRODUCT_HPP
#define ASSETS_PLANT_PRODUCT_HPP

#include "Product.hpp"

enum class PlantProductType {
    Material,
    Fruit,
};

class PlantProduct : public Product {
    public:
    virtual PlantProductType get_plant_product_type() = 0;
};

#endif