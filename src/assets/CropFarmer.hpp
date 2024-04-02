#ifndef ASSETS_CROP_FARMER_HPP
#define ASSETS_CROP_FARMER_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"
#include "owner/CroplandOwner.hpp"
#include "../abstracts/Taxable.hpp"
#include "../abstracts/GameLogic.hpp"
#include "../Game.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

class CropFarmer : public Person, public StorageOwner, public CroplandOwner, public Taxable, public GameLogic {
    public:
    CropFarmer(string username, int gold, int weight) :
    Person(username, gold, weight), StorageOwner(Game::storage_row, Game::storage_col), CroplandOwner(Game::cropland_row, Game::cropland_col) {}

    string get_username() const override {
        return username;
    }
    int calculate_tax() override;

};


#endif