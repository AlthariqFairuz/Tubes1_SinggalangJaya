#include "commands.hpp"
#include "../assets/Shop.hpp"

#include "../assets/Recipe.hpp"

#include <iostream>

using std::cin, std::cout, std::endl;

void Command::beli(Person &p, StorageOwner &so) {
    Shop::print_shop();

    cout << "Uang anda: " << p.gold << endl;
    cout << "Slot penyimpanan tersedia: " << so.count_empty_slots() << endl;

    cout << "Kode barang yang ingin dibeli: "; cout.flush();
    string item_code;
    cin >> item_code;

    if (p.get_person_type() == PersonType::Walikota && Recipe::recipe_config.find(item_code) != Recipe::recipe_config.end()) {
        cout << "Walikita tidak dapat membeli bangunan" << endl;
        return;
    }

    cout << "Kuantitas: "; cout.flush();
    int quantity;
    cin >> quantity;


    int available = INT32_MAX;
    Item *selected_item = 0;

    if (Animal::animal_config.find(item_code) != Animal::animal_config.end()) {
        selected_item = Animal::animal_config.find(item_code)->second.to_item();
    } else if (Plant::plant_config.find(item_code) != Plant::plant_config.end()) {
        selected_item = Plant::plant_config.find(item_code)->second.to_item();
    } else if (Shop::other_offers.find(item_code) != Shop::other_offers.end()) {
        selected_item = Shop::other_offers.find(item_code)->second.items.back();
        available = Shop::other_offers.find(item_code)->second.stock;
    }

    // } else if (Recipe::recipe_config.find(item_code) != Recipe::recipe_config.end()) {
    //     selected_item = Recipe::recipe_config.find(item_code)->second.to_item();
    // }

    if (selected_item == 0) {
        cout << "Tidak ada barang dengan kode " << item_code << endl;
        return;
    }

    if (quantity > available) {
        cout << "Kuantitas melebihi stock yang ada" << endl;
        return;
    }

    if (quantity * selected_item->get_price() > p.gold) {
        cout << "Uang tidak cukup" << endl;
        return;
    }

    if (quantity > so.count_empty_slots()) {
        cout << "Tempat penyimpanan tidak cukup" << endl;
        return;
    }


    p.gold -= quantity * selected_item->get_price();
    cout << "Anda berhasil membeli " << quantity << " " << selected_item->get_name() << ". Uang anda tersisa " << p.gold << " gulden." << endl;
    cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;

    for (int placed = 0; placed < quantity; ++placed) {
        Coordinate loc = so.query_empty_slot();
        so.set_at(loc.row, loc.col, selected_item);

        if (selected_item->get_item_type() == ItemType::Animal) {
            selected_item = Animal::animal_config.find(item_code)->second.to_item();
        } else if (selected_item->get_item_type() == ItemType::Plant) {
            selected_item = Plant::plant_config.find(item_code)->second.to_item();
        } else {
            auto shop_item = Shop::other_offers.find(item_code);
            shop_item->second.items.pop_back();
            if (!shop_item->second.items.empty()) {
                selected_item = shop_item->second.items.back();
                --shop_item->second.stock; 
            }
        }
    }

    // Jika stock sudah habis, hapus dari toko.
    if (selected_item->get_item_type() != ItemType::Animal && selected_item->get_item_type() != ItemType::Plant) {
        auto shop_item = Shop::other_offers.find(item_code);
        if (shop_item->second.stock == 0) {
            Shop::other_offers.erase(shop_item);
        }
    }
}