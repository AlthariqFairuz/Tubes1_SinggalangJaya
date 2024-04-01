#ifndef ASSETS_LIVESTOCK_FARMER_HPP
#define ASSETS_LIVESTOCK_FARMER_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"
#include "owner/PastureOwner.hpp"
#include "../abstracts/Taxable.hpp"
#include "../abstracts/GameLogic.hpp"


#include <vector>
#include <string>

using std::vector;
using std::string;

class LivestockFarmer : public Person, public StorageOwner, public PastureOwner, public Taxable, public GameLogic {
    
};


#endif