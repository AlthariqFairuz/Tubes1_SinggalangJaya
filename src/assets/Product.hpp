#ifndef ASSETS_PRODUCT_HPP
#define ASSETS_PRODUCT_HPP

#include <string>

using std::string;

class Product {
    int id;
    string code;
    string name;
    string type;
    string origin;
    int added_weight;
    int price;
};

#endif