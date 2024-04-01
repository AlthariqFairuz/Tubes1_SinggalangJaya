#include "Game.hpp"
#include "assets/Plant.hpp"
#include "assets/Animal.hpp"
#include "assets/Product.hpp"
#include "assets/Recipe.hpp"

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using std::cout, std::endl;
using std::string;
using std::map;
using std::ifstream;
using std::stringstream;

// Width = Vertical, length = Horizontal
int Game::winning_money;
int Game::winning_weight;
int Game::storage_width, Game::storage_length;
int Game::cropland_width, Game::cropland_length;
int Game::pasture_width, Game::pasture_length;

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
        Plant::plant_config[code] = plant;
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
        Animal::animal_config[code] = animal;
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
        Product::product_config[code] = product;
    }
    product_file.close();

    // konfigurasi/recipe.txt
    ifstream recipe_file("konfigurasi/recipe.txt");
    string line;
    while (getline(recipe_file, line)) {
        stringstream ss(line);
        Recipe r;
        ss >> r.id >> r.code >> r.name >> r.price;
        
        string plant_code;
        int quantity;
        while (ss >> plant_code >> quantity) {
            r.materials.push_back(RecipeMaterial(plant_code, quantity));
        }
        Recipe::recipe_config[r.code] = r;
    }
    recipe_file.close();
    
    // konfigurasi/misc.txt
    ifstream misc_file("konfigurasi/misc.txt");
    while (misc_file.good()) {
        misc_file >> winning_money;
        misc_file >> winning_weight;
        misc_file >> storage_width >> storage_length;
        misc_file >> cropland_width >> cropland_length;
        misc_file >> pasture_width >> pasture_length;
    }
    misc_file.close();
}

void Game::muat() {
    cout << "Apakah anda ingin memuat state? (y/n) ";
    cout.flush();

    char response;
    if (response != 'y') {
        cout << "State tidak dimuat. Game dimulai dari awal menggunakan state default sesuai spesifikasi." << endl;
        // TODO
    }
}