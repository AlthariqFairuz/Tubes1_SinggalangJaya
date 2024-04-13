#include "Product.hpp"

map<string, ProductConfig> Product::product_config;
map<string, string> Product::name_to_code;


string Product::get_name() {
    return Product::product_config.find(code)->second.name;
}

int Product::get_price() {
    return Product::product_config.find(code)->second.price;
}

int Product::get_added_weight() {
    return Product::product_config.find(code)->second.added_weight;
}