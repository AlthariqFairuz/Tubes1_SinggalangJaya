#ifndef ASSETS_ITEM_HPP
#define ASSETS_ITEM_HPP

#include <string>

using std::string;

enum class ItemType {
    Animal,
    Plant,
    Product,
    Building,
    Null,
};

class Item {
    public:
    string code;
    ItemType item_type;

    Item() : code(""), item_type(ItemType::Null) {}
    Item(string code, ItemType item_type) : code(code), item_type(item_type) {}

    

    bool operator==(const Item &other) { return code == other.code && item_type == other.item_type; }
};

#endif