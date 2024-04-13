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
    ShopItem(vector<Item*> _items, int _stock) : items(_items), stock(_stock) {} 

    vector<Item*> items;
    int stock;
};


// Hanya tanaman dan tumbuhan yang tak hingga.

class Shop {
    public:
    static map<string, ShopItem> other_offers;

    static void print_shop() {
        for (auto item : other_offers) {
            cout << item.second.items.back()->get_name() << " - " << item.second.items.back()->code << " - " << item.second.items.back()->get_price() << " (" << item.second.stock << ")" << endl;
        }
        for (auto &[name, ac] : Animal::animal_config) {
            cout << ac.name << " - " << ac.code << " - " << ac.price << '\n';
        }
        for (auto &[name, pc] : Plant::plant_config) {
            cout << pc.name << " - " << pc.code << " - " << pc.price << '\n';
        }
        cout << endl;
    }
};

#endif
