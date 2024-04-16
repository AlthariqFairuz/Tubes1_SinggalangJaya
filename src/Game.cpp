#include "Game.hpp"
#include "assets/Plant.hpp"
#include "assets/Animal.hpp"
#include "assets/Product.hpp"
#include "assets/Recipe.hpp"

#include "assets/CropFarmer.hpp"
#include "assets/LivestockFarmer.hpp"
#include "assets/Mayor.hpp"

#include "assets/owner/StorageOwner.hpp"
#include "assets/owner/PastureOwner.hpp"
#include "assets/owner/CroplandOwner.hpp"

#include "assets/Shop.hpp"

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

using std::cout, std::cin, std::endl;
using std::string;
using std::map;
using std::ifstream;
using std::stringstream;

// row = Vertical, col = Horizontal
int Game::winning_money;
int Game::winning_weight;
int Game::storage_row, Game::storage_col;
int Game::cropland_row, Game::cropland_col;
int Game::pasture_row, Game::pasture_col;

set<GameLogic*, CompareUsername> Game::players;
set<GameLogic*, CompareUsername>::iterator Game::current_player;

void Game::next() {
    // Lakukan next sesuai dengan role:
    // - Jika current_player adalah petani, maka tumbuhan di ladang pertanian akan bertambah satu.
    (*current_player)->next();

    // Pindah ke player selanjutnya
    ++current_player;
    if (current_player == players.end()) {
        current_player = players.begin();
    }
    cout << "Sekarang giliran " << (*current_player)->get_username() << endl;
}


void Game::muat_konfigurasi() {
    // konfigurasi/plant.txt
    ifstream plant_file("konfigurasi/plant.txt");
    while (plant_file.good()) {
        int id;
        string code;
        string name;
        string type;
        int duration_to_harvest;
        int price;

        plant_file >> id >> code >> name >> type >> duration_to_harvest >> price;
        PlantConfig plant(id, code, name, type, duration_to_harvest, price);
        
        // Plant::plant_config[code] = plant;
        Plant::plant_config.emplace(code, plant);
        // Plant::name_to_code[name] = code;
        Plant::name_to_code.emplace(name, code);
    }
    plant_file.close();

    // konfigurasi/animal.txt
    ifstream animal_file("konfigurasi/animal.txt");
    while (animal_file.good()) {
        int id;
        string code;
        string name;
        string type;
        int weight_to_harvest;
        int price;

        animal_file >> id >> code >> name >> type >> weight_to_harvest >> price;
        AnimalConfig animal(id, code, name, type, weight_to_harvest, price);
        
        // Animal::animal_config[code] = animal;
        Animal::animal_config.emplace(code, animal);
        // Animal::name_to_code[name] = code;
        Animal::name_to_code.emplace(name, code);
    }
    animal_file.close();

    // konfigurasi/product.txt
    ifstream product_file("konfigurasi/product.txt");
    while (product_file.good()) {
        int id;
        string code;
        string name;
        string type;
        string origin;
        int weight_to_harvest;
        int price;

        product_file >> id >> code >> name >> type >> origin >> weight_to_harvest >> price;
        ProductConfig product(id, code, name, type, origin, weight_to_harvest, price);
        
        // Product::product_config[code] = product;
        Product::product_config.emplace(code, product);
        // Product::name_to_code[name] = code;
        Product::name_to_code.emplace(name, code);
    }
    product_file.close();

    // konfigurasi/recipe.txt
    ifstream recipe_file("konfigurasi/recipe.txt");
    string line;
    while (getline(recipe_file, line)) {
        stringstream ss(line);
        Recipe r;
        ss >> r.id >> r.code >> r.name >> r.price;
        
        string plant_name;
        int quantity;
        while (ss >> plant_name >> quantity) {
            // r.materials[Plant::name_to_code[plant_name]] = quantity;
            r.materials.emplace(Product::name_to_code[plant_name], quantity);
        }
        
        // Recipe::recipe_config[r.code] = r;
        Recipe::recipe_config.emplace(r.code, r);
        // Recipe::name_to_code[r.name] = r.code;
        Recipe::name_to_code.emplace(r.name, r.code);
    }
    recipe_file.close();
    
    // konfigurasi/misc.txt
    ifstream misc_file("konfigurasi/misc.txt");
    while (misc_file.good()) {
        misc_file >> winning_money;
        misc_file >> winning_weight;
        misc_file >> storage_row >> storage_col;
        misc_file >> cropland_row >> cropland_col;
        misc_file >> pasture_row >> pasture_col;
    }
    misc_file.close();

}

void Game::muat() {
    cout << "Apakah anda ingin memuat state? (y/n) ";
    cout.flush();

    char response;
    cin >> response;
    if (response != 'y') {
        cout << "State tidak dimuat. Game dimulai dari awal menggunakan state default sesuai spesifikasi." << endl;
        CropFarmer* petani= new CropFarmer("Petani1", 50, 40);
        LivestockFarmer* peternak = new LivestockFarmer("Peternak1", 50, 40);
        Mayor* walikota = new Mayor("Walikota", 150, 40);

        players.insert(petani);
        players.insert(peternak);
        players.insert(walikota);

        current_player = players.begin();
    } else {
        // string file_location;
        // cout << "Masukkan lokasi berkas state: ";
        // cout.flush();
        // cin.ignore();
        // getline(cin, file_location);
        // ifstream file(file_location);
        // if (!file.is_open()) {
        //     cout << "File state tidak ada\n";
        //     Game::muat(); 
        //     return;
        // }

        // int players_count;
        // file >> players_count;
        // for (int i = 0; i < players_count; ++i) {
        //     string username, role; int gold, weight;

        //     StorageOwner so(Game::storage_row, Game::storage_col);            

        //     file >> username >> role >> gold >> weight;
            
        //     int total_storage_items;
        //     file >> total_storage_items;
        //     for (int j = 0; j < total_storage_items; ++j) {
        //         string name;
        //         file >> name;
        //         if (Animal::name_to_code.find(name) != Animal::name_to_code.end()) {
        //             // so.add_item(Item(Animal::name_to_code[name], ItemType::Animal));
        //         } else if (Plant::name_to_code.find(name) != Plant::name_to_code.end()) {
        //             so.add_item(Item(Plant::name_to_code[name], ItemType::Plant));
        //         } else if (Product::name_to_code.find(name) != Product::name_to_code.end()) {
        //             so.add_item(Item(Product::name_to_code[name], ItemType::Product));
        //         } else if (Recipe::name_to_code.find(name) != Recipe::name_to_code.end()) {
        //             so.add_item(Item(Recipe::name_to_code[name], ItemType::Building));
        //         } else {
        //             cout << "File muat tidak valid karena ada barang yang tidak dikenal kodenya." << endl;
        //             std::exit(0);
        //         }
        //     }

        //     if (role == "Petani") {
        //         CroplandOwner co(Game::cropland_row, Game::cropland_col);
        //         int total_plants;
        //         file >> total_plants;
        //         for (int j = 0; j < total_plants; ++j) {
        //             string location, name; int duration;
        //             file >> location >> name >> duration;
        //             if (Plant::name_to_code.find(name) == Plant::name_to_code.end()) {
        //                 cout << "Terdapat tumbuhan dengan nama yang tidak tercatat di file konfigurasi." << endl;
        //                 std::exit(0);
        //             }
        //             co.add_plant_at(Plant(Plant::name_to_code[name], duration), location);
        //         }
        //         players.insert(new CropFarmer(username, gold, weight, so, co));

        //     } else if (role == "Peternak") {
        //         PastureOwner po(Game::pasture_row, Game::pasture_col);
        //         int total_animals;
        //         file >> total_animals;
        //         for (int j = 0; j < total_animals; ++j) {
        //             string location, name; int weight;
        //             file >> location >> name >> weight;
        //             if (Animal::name_to_code.find(name) == Animal::name_to_code.end()) {
        //                 cout << "Terdapat binatang dengan nama yang tidak tercatat di file konfigurasi." << endl;
        //                 std::exit(0);
        //             }
        //             po.add_animal_at(Animal(Animal::name_to_code[name], weight), location);
        //         }
        //         players.insert(new LivestockFarmer(username, gold, weight, so, po));
        //     } else if (role == "Walikota") {
        //         players.insert(new Mayor(username, gold, weight, so));
        //     } else {
        //         cout << "File muat tidak valid karena ada role yang tidak dikenal." << endl;
        //         std::exit(0);
        //     }
        // }
        
        // int total_items;
        // file >> total_items;
        // for (int j = 0; j < total_items; ++j) {
        //     string name; int stock;
        //     file >> name >> stock;

        //     if (Product::name_to_code.find(name) != Product::name_to_code.end()) {
        //         ProductConfig pc = Product::product_config[Product::name_to_code[name]];
        //         ShopItem si(pc.name, ItemType::Product, pc.price, stock);
        //         Shop::other_offers.push_back(si);
        //     } else if (Recipe::name_to_code.find(name) != Recipe::name_to_code.end()) {
        //         Recipe rc = Recipe::recipe_config[Recipe::name_to_code[name]];
        //         ShopItem si(rc.name, ItemType::Building, rc.price, stock);
        //         Shop::other_offers.push_back(si);
        //     } else {
        //         cout << "File muat tidak valid karena ada barang yang tidak dikenal kodenya." << endl;
        //         std::exit(0);
        //     }
        // }
    }
}

void Game::simpan() {
    
}


void Game::exit() {
    while (players.empty()) {
        auto it = players.begin();
        delete *it;
        players.erase(it);
    }
    cout << "Program keluar!" << endl;
    std::exit(0);
}