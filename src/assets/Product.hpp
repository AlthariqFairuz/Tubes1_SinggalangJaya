#ifndef ASSETS_PRODUCT_HPP
#define ASSETS_PRODUCT_HPP

#include "Item.hpp"

#include <string>
#include <map>

using std::string;
using std::map;

enum class ProductType {
    Plant,
    Animal,
};

class ProductConfig {
    public:
    int id;
    string code;
    string name;
    string type;
    string origin;
    int added_weight;
    int price;

    ProductConfig() {}
    ProductConfig(const ProductConfig& other) :
    id(other.id), code(other.code), name(other.name), type(other.type), origin(other.origin), added_weight(other.added_weight), price(other.price) {}

    ProductConfig(int id, string code, string name, string type, string origin, int added_weight, int price) :
    id(id), code(code), name(name), type(type), added_weight(added_weight), price(price) {}
};

class Product : public Item {
    public:

    string get_name() override;
    int get_price() override;
    int get_added_weight();

    virtual ProductType get_product_type() = 0;

    static map<string, ProductConfig> product_config;
    static map<string, string> name_to_code;
};



#endif