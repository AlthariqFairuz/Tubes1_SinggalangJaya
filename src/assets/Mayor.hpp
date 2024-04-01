#ifndef ASSETS_MAYOR_HPP
#define ASSETS_MAYOR_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"
#include "../abstracts/GameLogic.hpp"

class Mayor : public Person, public StorageOwner, public GameLogic {

};

#endif