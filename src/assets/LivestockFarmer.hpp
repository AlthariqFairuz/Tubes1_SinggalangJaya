#ifndef ASSETS_LIVESTOCK_FARMER_HPP
#define ASSETS_LIVESTOCK_FARMER_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"
#include "owner/PastureOwner.hpp"
#include "../abstracts/Taxable.hpp"
#include "../abstracts/GameLogic.hpp"
#include "../Game.hpp"

#include <vector>
#include <string>

using std::string;
using std::vector;

class LivestockFarmer : public Person, public StorageOwner, public PastureOwner, public Taxable, public GameLogic
{
public:
    LivestockFarmer(string username, int gold, int weight);
    LivestockFarmer(string username, int gold, int weight, const StorageOwner &so, const PastureOwner &po);

    PersonType get_person_type() override;

    string get_username() const override;
    void next() override;

    int calculate_tax() override;

    void cetak_penyimpanan() const override;
    void cetak_peternakan() const override;
    void makan() override;
    void ternak() override;
    void kasih_makan() override;
    void panen() override;

    void beli() override;
};

#endif