#ifndef ASSETS_MAYOR_HPP
#define ASSETS_MAYOR_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"

class Mayor : public Person, public StorageOwner {

};

#endif