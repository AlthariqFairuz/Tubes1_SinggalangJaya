#ifndef ASSETS_MATERIAL_PLANT_PRODUCT_HPP
#define ASSETS_MATERIAL_PLANT_PRODUCT_HPP

#include "PlantProduct.hpp"

class MaterialPlantProduct : public PlantProduct {
    public:
    MaterialPlantProduct(string _code);

    ItemType get_item_type() override;
    ProductType get_product_type() override;
    PlantProductType get_plant_product_type() override;
    bool is_consumable() override;
};

#endif