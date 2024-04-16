#ifndef ASSETS_MAYOR_HPP
#define ASSETS_MAYOR_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"
#include "../abstracts/GameLogic.hpp"
#include "../abstracts/Taxable.hpp"
#include "../Game.hpp"

#include <string>

using std::string;

class Mayor : public Person, public StorageOwner, public GameLogic {
    public:
    Mayor(string username, int gold, int weight) :
    Person(username, gold, weight), StorageOwner(Game::storage_row, Game::storage_col) {}
    Mayor(string username, int gold, int weight, StorageOwner so) :
    Person(username, gold, weight), StorageOwner(so) {}

    void set_storage(StorageOwner &so);
    // void set_pasture_land(PastureOwner &po);
    // void set_crop_land(CroplandOwner &co);

    void pungut_pajak() override;

    // PersonType get_person_type() override;
    // string get_username() const override;
    string get_username() const override;
    int get_gold() const override;
    int get_weight() const override;
    PersonType get_person_type() override;
    string get_role() const override;
    
    void next() override;

    int calculate_tax() override;

    void cetak_penyimpanan() const override;
    void makan() override;
    void bangun() override;

    void beli() override;
    void jual() override;

    void tambah_pemain() override;
};

#endif