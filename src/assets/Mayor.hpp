#ifndef ASSETS_MAYOR_HPP
#define ASSETS_MAYOR_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"
#include "../abstracts/GameLogic.hpp"
#include "../Game.hpp"

#include "../commands/commands.hpp"

#include <string>

using std::string;

class Mayor : public Person, public StorageOwner, public GameLogic {
    public:
    Mayor(string username, int gold, int weight) :
    Person(username, gold, weight), StorageOwner(Game::storage_row, Game::storage_col) {}
    Mayor(string username, int gold, int weight, StorageOwner so) :
    Person(username, gold, weight), StorageOwner(so) {}

    PersonType get_person_type() override;

    string get_username() const override;
    void next() override;

    void cetak_penyimpanan() const override;

    void bangun() override;

    void beli() override;
};

#endif