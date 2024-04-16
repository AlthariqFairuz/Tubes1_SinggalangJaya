#include "commands.hpp"
#include <iostream>
#include "../assets/Recipe.hpp"
#include "../assets/Building.hpp"

using std::cout, std::cin, std::endl;

void Command::bangun(Person &p, StorageOwner &so) {
    cout << "Resep bangunan yang ada adalah sebagai berikut:" << endl;
    
    for (auto &[code, r] : Recipe::recipe_config) {
        cout << code << " - " << r.name << " (" << r.price << " gulden) ";
        for (auto material : r.materials) {
            auto quantity = material.second;
            auto product_code = material.first;
            cout << "(" << quantity << " " << Product::product_config[product_code].name << ") ";
        }
        cout << '\n';
    }
    cout << "Masukkan kode dari bangunan yang ingin dibangun: "; cout.flush();
    string code;
    cin >> code;
    while (Recipe::recipe_config.find(code) == Recipe::recipe_config.end()) {
        cout << "Kode tidak valid. Ulangi lagi" << endl;
        cout << "Masukkan kode dari bangunan yang ingin dibangun: "; cout.flush();
        cin >> code;
    }

    auto recipe = Recipe::recipe_config.find(code)->second;

    if (recipe.price > p.gold) {
        cout << "Kamu p̶e̶r̶l̶u̶ p̶i̶n̶j̶o̶l̶  tidak memiliki gulden yang cukup. Gulden yang kurang: " << recipe.price - p.gold << endl;
        return;
    }

    for (auto material : recipe.materials) {
        auto quantity = material.second;
        auto product_code = material.first;
        auto current_stock = so.count_items(product_code);
        if (quantity > current_stock) {
            cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan " << quantity - current_stock << " " << Product::product_config[product_code].name << endl;
            return;
        }
    }

    p.gold -= recipe.price;
    for (auto material : recipe.materials) {
        auto quantity = material.second;
        auto product_code = material.first;
        so.remove_item(product_code, quantity);
    }

    Building *building = new Building(recipe.code);
    so += building;
    cout << recipe.name << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
}