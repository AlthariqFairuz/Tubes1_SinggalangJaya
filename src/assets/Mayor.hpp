#ifndef ASSETS_MAYOR_HPP
#define ASSETS_MAYOR_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"
#include "../abstracts/GameLogic.hpp"
#include "../Game.hpp"

#include "../commands/commands.hpp"

#include <string>

using std::string;

class Mayor : public Person, public StorageOwner, public GameLogic
{
public:
    Mayor(string username, int gold, int weight);
    Mayor(string username, int gold, int weight, const StorageOwner &so);

    string get_username() const override;
    int get_gold() const override;
    int get_weight() const override;
    PersonType get_person_type() override;
    string get_role() const override;

    void next() override;

    void cetak_penyimpanan() const override;
    void makan() override;
    void bangun() override;

    void beli() override;
};

#endif