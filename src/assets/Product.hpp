#ifndef ASSETS_PRODUCT_HPP
#define ASSETS_PRODUCT_HPP

#include <string>
#include <map>

using std::string;
using std::map;

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

class Product {
    public:

    static map<string, ProductConfig> product_config;
};



#endif