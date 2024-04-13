#ifndef ASSETS_FRUIT_PLANT_PRODUCT_HPP
#define ASSETS_FRUIT_PLANT_PRODUCT_HPP

#include "PlantProduct.hpp"

class FruitPlantProduct : public PlantProduct {
    public:
    FruitPlantProduct(string _code);

    ItemType get_item_type() override;
    ProductType get_product_type() override;
    PlantProductType get_plant_product_type() override;
    bool is_consumable() override;
};

#endif