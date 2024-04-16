#ifndef ASSETS_CROP_FARMER_HPP
#define ASSETS_CROP_FARMER_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"
#include "owner/CroplandOwner.hpp"
#include "../abstracts/Taxable.hpp"
#include "../abstracts/GameLogic.hpp"
#include "../Game.hpp"

#include "../commands/commands.hpp"

#include <vector>
#include <string>

using std::string;
using std::vector;

class CropFarmer : public Person, public StorageOwner, public CroplandOwner, public Taxable, public GameLogic {
    public:
    CropFarmer(string username, int gold, int weight) :
    Person(username, gold, weight), StorageOwner(Game::storage_row, Game::storage_col), CroplandOwner(Game::cropland_row, Game::cropland_col) {}
    CropFarmer(string username, int gold, int weight, StorageOwner so, CroplandOwner co) :
    Person(username, gold, weight), StorageOwner(so), CroplandOwner(co) {}
    
    void set_storage(StorageOwner &so);
    // void set_pasture_land(PastureOwner &po);
    void set_crop_land(CroplandOwner &co);

    // PersonType get_person_type() override;
    // string get_username() const;

    string get_username() const override;
    int get_gold() const override;
    int get_weight() const override;
    PersonType get_person_type() override;
    string get_role() const override;

    void next() override;

    int calculate_tax() override;

    void cetak_penyimpanan() const override;
    void cetak_ladang() const override;
    void makan() override;
    void tanam() override;
    void panen() override;

    void beli() override;
    void jual() override;
};

#endif