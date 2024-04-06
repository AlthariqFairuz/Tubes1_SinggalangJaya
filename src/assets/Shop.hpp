#ifndef ASSETS_SHOP_HPP
#define ASSETS_SHOP_HPP

#include "Animal.hpp"
#include "Plant.hpp"
#include "Product.hpp"

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout, std::endl;
using std::map;
using std::string;
using std::vector;

class ShopItem {
    public:
    ShopItem(string name, ItemType item_type, int price, int stock) : name(name), item_type(item_type), price(price), stock(stock) {} 

    string name;
    ItemType item_type;
    int price;
    int stock;
};

class Shop {
    public:
    static map<string, AnimalConfig> animal_config;
    static map<string, PlantConfig> plant_config;
    static map<string, ProductConfig> product_config;
    static vector<ShopItem> other_offers;

    void print_shop() {
        for (auto item : other_offers) {
            cout << item.name << " - " << item.price << " (" << item.stock << ")\n";
        }
        for (auto &[name, ac] : animal_config) {
            cout << name << " - " << ac.price << '\n';
        }
        for (auto &[name, pc] : plant_config) {
            cout << name << " - " << pc.price << '\n';
        }
        cout << endl;
    }
};

#endif
