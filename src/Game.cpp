#include "Game.hpp"

#include "assets/Plant.hpp"
#include "assets/FruitPlant.hpp"
#include "assets/MaterialPlant.hpp"

#include "assets/Animal.hpp"
#include "assets/HerbivoreAnimal.hpp"
#include "assets/CarnivoreAnimal.hpp"
#include "assets/OmnivoreAnimal.hpp"

#include "assets/Product.hpp"

#include "assets/Recipe.hpp"

#include "assets/CropFarmer.hpp"
#include "assets/LivestockFarmer.hpp"
#include "assets/Mayor.hpp"

#include "assets/owner/StorageOwner.hpp"
#include "assets/owner/PastureOwner.hpp"
#include "assets/owner/CroplandOwner.hpp"

#include "assets/Shop.hpp"

#include "utils/directory-check.hpp"

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <filesystem>

using std::cout, std::cin, std::endl, std::flush;
using std::ifstream, std::ofstream;
using std::map;
using std::string;
using std::stringstream;

// row = Vertical, col = Horizontal
int Game::winning_money;
int Game::winning_weight;
int Game::storage_row, Game::storage_col;
int Game::cropland_row, Game::cropland_col;
int Game::pasture_row, Game::pasture_col;

set<GameLogic *, CompareUsername> Game::players;
set<GameLogic *, CompareUsername>::iterator Game::current_player;

void Game::next()
{
    // Lakukan next sesuai dengan role:
    // - Jika current_player adalah petani, maka tumbuhan di ladang pertanian akan bertambah satu.
    (*current_player)->next();

    // Pindah ke player selanjutnya
    ++current_player;
    if (current_player == players.end())
    {
        current_player = players.begin();
    }
    cout << "Sekarang giliran " << (*current_player)->get_username() << endl;
}

void Game::muat_konfigurasi()
{
    // konfigurasi/plant.txt
    ifstream plant_file("konfigurasi/plant.txt");
    while (plant_file.good())
    {
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
    while (animal_file.good())
    {
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
    while (product_file.good())
    {
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
    while (getline(recipe_file, line))
    {
        stringstream ss(line);
        Recipe r;
        ss >> r.id >> r.code >> r.name >> r.price;

        string plant_name;
        int quantity;
        while (ss >> plant_name >> quantity)
        {
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
    while (misc_file.good())
    {
        misc_file >> winning_money;
        misc_file >> winning_weight;
        misc_file >> storage_row >> storage_col;
        misc_file >> cropland_row >> cropland_col;
        misc_file >> pasture_row >> pasture_col;
    }
    misc_file.close();
}

void Game::muat()
{
    cout << "Apakah anda ingin memuat state? (y/n) " << flush;

    // Input & validasi response
    char response;
    cin >> response;
    while (response != 'y' && response != 'n')
    {
        cout << "Masukkan tidak valid. Mohon masukkan 'y' atau 'n'." << endl;
        cout << "Apakah anda ingin memuat state? (y/n) " << flush;
        cin >> response;
    }

    // TIDAK MUAT STATE
    if (response == 'n')
    {
        // Mulai dari default state:
        // - 3 pemain: Petani1, Peternak1, Walikota
        // - Masing-masing pemain memiliki uang 50 gulden dan berat badan 40 kg
        // - Dimulai dari leksikografis username pemain

        // Message
        cout << "State tidak dimuat. Game dimulai dari awal menggunakan default state sesuai spesifikasi." << endl;

        // Create players
        CropFarmer *petani = new CropFarmer("Petani1", 50, 40);
        LivestockFarmer *peternak = new LivestockFarmer("Peternak1", 50, 40);
        Mayor *walikota = new Mayor("Walikota", 50, 40);

        // Insert players
        players.insert(petani);
        players.insert(peternak);
        players.insert(walikota);

        // Set current_player
        current_player = players.begin();

        return;
    }

    // MUAT STATE

    // Dapatkan lokasi file
    string file_location;
    cout << "Masukkan lokasi berkas state: " << flush;
    cin >> file_location;

    // Input & validasi file_location
    // - Jika file tidak ditemukan, ulangi input
    ifstream file;
    file.open(file_location);
    while (!file.is_open())
    {
        cout << "File state tidak ada. Mohon masukkan lokasi berkas state yang valid." << endl;
        cout << "Masukkan lokasi berkas state: " << flush;
        cin >> file_location;
        file.open(file_location);
    }

    // Status message
    cout << "Loading... memulai memuat state dari berkas" << endl;

    // Read file

    // Player count
    int players_count;
    file >> players_count;

    // Player state
    for (int i = 0; i < players_count; ++i)
    {
        // Username, role, weight, gold
        string username, role;
        int weight, gold;
        file >> username >> role >> weight >> gold;

        // Jumlah item di inventory
        int total_inventory_items;
        file >> total_inventory_items;

        // Inventory items
        StorageOwner so(Game::storage_row, Game::storage_col);
        for (int j = 0; j < total_inventory_items; j++)
        {
            // Read item name
            string item_name;
            file >> item_name;

            // New item
            Item *new_item;

            if (Plant::name_to_code.find(item_name) != Plant::name_to_code.end())
            {

                // Find plant type
                auto plant_code = Plant::name_to_code.find(item_name);
                auto plant_conf = Plant::plant_config.find(plant_code->second);

                PlantConfig pc = plant_conf->second;
                new_item = pc.to_item();
            }
            else if (Animal::name_to_code.find(item_name) != Animal::name_to_code.end())
            {

                // Find animal type
                auto animal_code = Animal::name_to_code.find(item_name);
                auto animal_conf = Animal::animal_config.find(animal_code->second);

                AnimalConfig ac = animal_conf->second;
                new_item = ac.to_item();
            }
            else if (Product::name_to_code.find(item_name) != Product::name_to_code.end())
            {
                // Find product type
                auto product_code = Product::name_to_code.find(item_name);
                auto product_conf = Product::product_config.find(product_code->second);

                ProductConfig pc = product_conf->second;
                new_item = pc.to_item();
            }
            else if (Recipe::name_to_code.find(item_name) != Recipe::name_to_code.end())
            {
                auto recipe_code = Recipe::name_to_code.find(item_name);
                auto recipe_conf = Recipe::recipe_config.find(recipe_code->second);

                Recipe r = recipe_conf->second;
                new_item = r.to_item();
            }
            else
            {
                cout << username << " " << role << " " << weight << " " << gold << endl;
                cout << item_name << endl;
                cout << "File muat tidak valid karena ada barang yang tidak dikenal kodenya." << endl;
                std::exit(0);
            }

            // Insert item to storage
            so += (new_item);
        }

        // Role specific state
        if (role == "Petani")
        {
            // Cropland state
            CroplandOwner co(Game::cropland_row, Game::cropland_col);

            // Jumlah tanaman di ladang
            int total_plants;
            file >> total_plants;

            // Plant state
            for (int j = 0; j < total_plants; j++)
            {
                // Location, name, duration
                string loc, name;
                int age;
                file >> loc >> name >> age;

                // Find & validate name and add to cropland
                if (Plant::name_to_code.find(name) == Plant::name_to_code.end())
                {
                    cout << "Terdapat tumbuhan dengan nama yang tidak tercatat di file konfigurasi." << endl;
                    std::exit(0);
                }

                // Get coordinate from location
                Coordinate cords = location(loc);

                // Add plant to cropland
                Plant *newPlant;

                PlantConfig pc = Plant::plant_config[Plant::name_to_code[name]];
                if (pc.type == "MATERIAL_PLANT")
                {
                    // Create new material plant
                    newPlant = new MaterialPlant(Plant::name_to_code[name], age);
                }
                else if (pc.type == "FRUIT_PLANT")
                {
                    // Create new fruit plant
                    newPlant = new FruitPlant(Plant::name_to_code[name], age);
                }
                else
                {
                    cout << "Terdapat tumbuhan dengan tipe yang tidak sesuai dengan spesifikasi" << endl;
                    std::exit(0);
                }

                // Insert plant
                co.set_at(cords.row, cords.col, newPlant);
            }

            // Insert player
            CropFarmer *cf = new CropFarmer(username, gold, weight);
            cf->set_storage(so);
            cf->set_crop_land(co);
            players.insert(cf);
        }
        else if (role == "Peternak")
        {
            // Pasture state
            PastureOwner po(Game::pasture_row, Game::pasture_col);

            // Jumlah hewan di peternakan
            int total_animals;
            file >> total_animals;

            // Animal state
            for (int j = 0; j < total_animals; j++)
            {
                // Location, name, weight
                string loc, name;
                int weight;
                file >> loc >> name >> weight;

                // Find & validate name and add to pasture
                if (Animal::name_to_code.find(name) == Animal::name_to_code.end())
                {
                    cout << "Terdapat hewan dengan nama yang tidak tercatat di file konfigurasi." << endl;
                    std::exit(0);
                }

                // Get coordinate from location
                Coordinate cords = location(loc);

                // Add animal to pasture
                Animal *newAnimal;
                AnimalConfig ac = Animal::animal_config[Animal::name_to_code[name]];
                if (ac.type == "CARNIVORE")
                {
                    // Create new carnivore animal
                    newAnimal = new CarnivoreAnimal(Animal::name_to_code[name], weight);
                }
                else if (ac.type == "HERBIVORE")
                {
                    // Create new herbivore animal
                    newAnimal = new HerbivoreAnimal(Animal::name_to_code[name], weight);
                }
                else if (ac.type == "OMNIVORE")
                {
                    // Create new omnivore animal
                    newAnimal = new OmnivoreAnimal(Animal::name_to_code[name], weight);
                }
                else
                {
                    cout << "Terdapat hewan dengan tipe yang tidak sesuai dengan spesifikasi" << endl;
                    return;
                }

                // Insert animal
                po.set_at(cords.row, cords.col, newAnimal);
            }

            // Insert player
            LivestockFarmer *lf = new LivestockFarmer(username, gold, weight);
            lf->set_storage(so);
            lf->set_pasture_land(po);
            players.insert(lf);
        }
        else if (role == "Walikota")
        {
            // Insert player
            Mayor *my = new Mayor(username, gold, weight);
            my->set_storage(so);
            players.insert(my);
        }
        else
        {
            cout << "File muat tidak valid karena ada role yang tidak dikenal." << endl;
            std::exit(0);
        }
    }

    // Shop
    // Total items
    int total_items;
    file >> total_items;

    // Shop items
    for (int j = 0; j < total_items; j++)
    {
        string name, code;
        int stock;
        file >> name >> stock;

        // Check if name is a plant or an animal (unlimited stocks)
        if (Plant::name_to_code.find(name) != Plant::name_to_code.end() || Animal::name_to_code.find(name) != Animal::name_to_code.end())
        {
            cout << "Warning: Hewan dan tumbuhan memiliki jumlah tak hingga di toko sehingga tidak perlu ada di file state bagian toko" << endl;
            continue;
        }

        // Find item and add to shop
        vector<Item *> items;
        for (int k = 0; k < stock; k++)
        {
            // Initialize new item
            Item *newItem;

            if (Product::name_to_code.find(name) != Product::name_to_code.end())
            {
                // Product
                ProductConfig pc = Product::product_config[Product::name_to_code[name]];
                newItem = pc.to_item();
                code = pc.code;
            }
            else if (Recipe::name_to_code.find(name) != Recipe::name_to_code.end())
            {
                // Building
                Recipe r = Recipe::recipe_config[Recipe::name_to_code[name]];
                newItem = r.to_item();
                code = r.code;
            }
            else if (Plant::name_to_code.find(name) != Plant::name_to_code.end())
            {
                // cout << "CATATAN: Toko memiliki tanaman yang berjumlah tak hingga sehingga tidak perlu dicatat di file muat bagian toko" << endl;
                // continue;

                // Plant
                // PlantConfig pc = Plant::plant_config[Plant::name_to_code[name]];
                // newItem = pc.to_item();
                // code = pc.code;
            }
            else if (Animal::name_to_code.find(name) != Animal::name_to_code.end())
            {
                // cout << "CATATAN: Toko memiliki hewan yang berjumlah tak hingga sehingga tidak perlu dicatat di file muat bagian toko" << endl;
                // continue;

                // Animal
                // AnimalConfig ac = Animal::animal_config[Animal::name_to_code[name]];
                // newItem = ac.to_item();
                // code = ac.code;
            }
            else
            {
                cout << "File muat tidak valid karena ada barang yang tidak dikenal kodenya." << endl;
                std::exit(0);
            }

            // Add item to vector
            items.push_back(newItem);
        }

        // Add to shop
        ShopItem si(items, stock);
        Shop::other_offers.emplace(code, si);
    }

    // Message Status berhasil
    file.close();
    Game::current_player = Game::players.begin();
    cout << "Berhasil memuat state dari berkas!" << endl;
}

void Game::simpan()
{
    // Read file & validate location
    string file_location;
    cout << "Masukkan lokasi berkas state: " << flush;
    cin >> file_location;

    // Gak boleh buat folder, tapi boleh buat/nimpa file (directory harus valid)
    while (!isParentDirValid(file_location))
    {
        cout << "Lokasi berkas tidak valid. Mohon masukkan lokasi berkas state yang valid." << endl;
        cout << "Masukkan lokasi berkas state: " << flush;
        cin >> file_location;
    }

    ofstream file;
    file.open(file_location);

    // Write player count
    file << players.size() << endl;

    // Write player state
    for (auto player = players.begin(); player != players.end(); player++)
    {
        // Username, role, weight, gulden
        Person *user = dynamic_cast<Person *>(*player);
        string username = (user)->get_username();
        int gold = (user)->get_gold();
        int weight = (user)->get_weight();
        string role = (user)->get_role();
        file << username << " " << role << " " << weight << " " << gold << endl;

        // Inventory items
        StorageOwner *so = dynamic_cast<StorageOwner *>(*player);
        int total_items = so->storage.count_total_items();
        file << total_items << endl;
        for (int i = 0; i < Game::storage_row; i++)
        {
            for (int j = 0; j < Game::storage_col; j++)
            {
                if (so->storage(i, j))
                {
                    Item *item = so->storage(i, j);
                    string item_name = item->get_name();
                    file << item_name << endl;
                }
            }
        }

        // Role specific state
        if (role == "Petani")
        {
            // Cropland state
            CroplandOwner *co = dynamic_cast<CroplandOwner *>(*player);

            // Jumlah tanaman di ladang
            int total_plants = co->land.count_total_items();
            file << total_plants << endl;

            // Plant data
            for (int i = 0; i < Game::cropland_row; i++)
            {
                for (int j = 0; j < Game::cropland_col; j++)
                {
                    if (co->land(i, j))
                    {
                        Plant *plant = co->land(i, j);
                        string name = plant->get_name();
                        int age = plant->get_duration();
                        Coordinate cords(i, j);
                        string loc = cords.to_string();
                        file << loc << " " << name << " " << age << endl;
                    }
                }
            }
        }
        else if (role == "Peternak")
        {
            // Pasture state
            PastureOwner *po = dynamic_cast<PastureOwner *>(*player);

            // Jumlah hewan di peternakan
            int total_animals = po->land.count_total_items();
            file << total_animals << endl;

            // Animal data
            for (int i = 0; i < Game::pasture_row; i++)
            {
                for (int j = 0; j < Game::pasture_col; j++)
                {
                    if (po->land(i, j))
                    {
                        Animal *animal = po->land(i, j);
                        string name = animal->get_name();
                        int weight = animal->get_weight();
                        Coordinate cords(i, j);
                        string loc = cords.to_string();
                        file << loc << " " << name << " " << weight << endl;
                    }
                }
            }
        }
        else if (role == "Walikota")
        {
            // Do nothing
        }
        else
        {
            cout << "File muat tidak valid karena ada role yang tidak dikenal." << endl;
            std::exit(0);
        }
    }

    // Shop state
    int total_item_types = Shop::other_offers.size();
    file << total_item_types << endl;

    // Write shop state
    for (auto shop_item = Shop::other_offers.begin(); shop_item != Shop::other_offers.end(); shop_item++)
    {
        // Item code, stock
        string code = shop_item->first;
        int stock = shop_item->second.stock;

        // Get name

        // Check if code is from animal
        string name;
        if (Animal::animal_config.find(code) != Animal::animal_config.end())
        {
            // Animal
            name = Animal::animal_config[code].name;
        }
        else if (Plant::plant_config.find(code) != Plant::plant_config.end())
        {
            // Plant
            name = Plant::plant_config[code].name;
        }
        else if (Product::product_config.find(code) != Product::product_config.end())
        {
            // Product
            name = Product::product_config[code].name;
        }
        else if (Recipe::recipe_config.find(code) != Recipe::recipe_config.end())
        {
            // Recipe
            name = Recipe::recipe_config[code].name;
        }
        else
        {
            // Invalid code
            cout << "File muat tidak valid karena ada barang yang tidak dikenal kodenya." << endl;
            std::exit(0);
        }

        file << name << " " << stock << endl;
    }
}

void Game::exit()
{
    while (players.empty())
    {
        auto it = players.begin();
        delete *it;
        players.erase(it);
    }
    cout << "Program keluar!" << endl;
    std::exit(0);
}