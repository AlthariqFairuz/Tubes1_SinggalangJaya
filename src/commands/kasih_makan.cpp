#include "commands.hpp"
#include <iostream>

using std::cout, std::cin, std::endl;

void Command::kasih_makan(StorageOwner &so, PastureOwner &po) {
    // Cek kosong atau tidak peternakannya
    if(po.land.is_empty_matrix()) {
        // Throw exception
        cout << "Tidak ada hewan yang bisa diberi makan." << endl;
        return;
    }

    cout << "Pilih petak kandang yang akan ditinggali" << endl;

    auto loc = po.query_animal();
    auto animal = po.land(loc.row, loc.col);

    cout << "Kamu memilih " << animal->get_name() << " untuk diberi makan." << endl;

    Coordinate food_loc;
    if (animal->get_animal_type() == AnimalType::Omnivore) {
        if (!so.is_exist_consumable()) {
            cout << "Tidak ada makanan yang dapat dimakan oleh hewan" << endl;
            return;
        }
        cout << "Pilih pangan yang akan diberikan (produk hewan atau produk tumbuhan): " << endl; 
        food_loc = so.query_consumable();
    } else if (animal->get_animal_type() == AnimalType::Herbivore) {
        if (!so.is_exist_consumable(ProductType::Plant)) {
            cout << "Tidak ada makanan yang dapat dimakan oleh hewan" << endl;
            return;
        }
        cout << "Pilih pangan yang akan diberikan (produk tumbuhan): " << endl;
        food_loc = so.query_consumable(ProductType::Plant);
    } else if (animal->get_animal_type() == AnimalType::Carnivore) {
        if (!so.is_exist_consumable(ProductType::Animal)) {
            cout << "Tidak ada makanan yang dapat dimakan oleh hewan" << endl;
            return;
        }
        cout << "Pilih pangan yang akan diberikan (produk hewan): " << endl;
        food_loc = so.query_consumable(ProductType::Animal);
    } else {
        cout << "Tipe hewan tidak valid" << endl;
        std::exit(0);
    }

    auto food = so.storage(food_loc.row, food_loc.col);
    so.storage.soft_erase(food_loc.row, food_loc.col);

    int old_weight = animal->weight;
    animal->weight += dynamic_cast<Product*>(food)->get_added_weight();
    cout << animal->get_name() << " sudah diberi makan dan beratnya bertambah dari " << old_weight << " menjadi " << animal->weight << endl;
    delete food;
}