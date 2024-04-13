#include "Product.hpp"
#include "MaterialPlantProduct.hpp"
#include "FruitPlantProduct.hpp"
#include "AnimalProduct.hpp"


#include <iostream>

map<string, ProductConfig> Product::product_config;
map<string, string> Product::name_to_code;

using std::cout, std::endl;

Item *ProductConfig::to_item() {
    if (type == "PRODUCT_MATERIAL_PLANT") {
        return new MaterialPlantProduct(code);        
    } else if (type == "PRODUCT_FRUIT_PLANT") {
        return new FruitPlantProduct(code);
    } else if (type == "PRODUCT_ANIMAL") {
        return new AnimalProduct(code);
    }
    cout << "Konfigurasi salah. Tipe produk tidak konsisten" << endl;
    std::exit(0);
}

Product::Product(string _code) : Item(_code) {
    
}

string Product::get_name() {
    return Product::product_config.find(code)->second.name;
}

int Product::get_price() {
    return Product::product_config.find(code)->second.price;
}

int Product::get_added_weight() {
    if (Product::product_config.find(code) == Product::product_config.end()) {
        cout << "File konfigurasi tidak valid. Tidak ditemukan produk dengan kode " << code << endl;
        exit(0);
    }
    return Product::product_config.find(code)->second.added_weight;
}