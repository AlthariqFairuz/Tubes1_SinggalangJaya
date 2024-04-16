#include "commands.hpp"
#include <iostream>
#include "../assets/Shop.hpp"

using std::cout, std::cin, std::endl;

void Command::jual(Person &p, StorageOwner &so) {
    int total_gold = 0;


    while (true) {
        if (so.storage.is_empty_matrix()) {
            cout << "Anda tidak memiliki barang sehingga tidak bisa berjualan" << endl;
            return;
        }

        Coordinate loc = so.query_any_item();
        auto item = so.storage(loc.row, loc.col);
        if (item->get_item_type() == ItemType::Building && p.get_person_type() != PersonType::Walikota) {
            cout << "Hanya walikota yang dapat menjual bangunan" << endl;
            continue;
        }

        total_gold += item->get_price();
        if (item->get_item_type() != ItemType::Animal && item->get_item_type() != ItemType::Plant) {
            auto shop_item_it = Shop::other_offers.find(item->code);
            if (shop_item_it == Shop::other_offers.end()) {
                ShopItem shop_item;
                shop_item.items.push_back(item);
                shop_item.stock = 1;
                Shop::other_offers.emplace(item->code, shop_item);
            } else {
                auto &shop_item = shop_item_it->second;
                shop_item.items.push_back(item);
                ++shop_item.stock;
            }
            so.storage.soft_erase(loc.row, loc.col);
        } else {
            so.storage.hard_erase(loc.row, loc.col);
        }

        cout << "Apakah anda masih ingin memilih petak lagi untuk dijual secara berbarengan? (y/n) "; cout.flush();
        string response;
        cin >> response;
        if (response != "y") {
            break;
        }
    }
    cout << "Barang anda berhasil dijual! Uang anda bertambah " << total_gold << " gulden!" << endl;
    p.gold += total_gold;
}