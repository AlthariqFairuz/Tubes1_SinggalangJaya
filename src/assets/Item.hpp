#ifndef ASSETS_ITEM_HPP
#define ASSETS_ITEM_HPP

#include <map>
#include <string>

using std::string;

enum class ItemType {
    Animal,
    Plant,
    Product,
    Building,
};

class Item {
    public:
    string code;

    Item(string _code);
    virtual ~Item();

    virtual ItemType get_item_type() = 0;
    virtual string get_name() = 0;
    virtual int get_price() = 0;

    static string get_item_type_string(ItemType item_type);
};

#endif