#ifndef ASSETS_MAYOR_HPP
#define ASSETS_MAYOR_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"
#include "../abstracts/GameLogic.hpp"
#include "../Game.hpp"

#include <string>

using std::string;

class Mayor : public Person, public StorageOwner, public GameLogic {
    public:
    Mayor(string username, int gold, int weight) :
    Person(username, gold, weight), StorageOwner(Game::storage_row, Game::storage_col) {}
    
    string get_username() const;
};

#endif