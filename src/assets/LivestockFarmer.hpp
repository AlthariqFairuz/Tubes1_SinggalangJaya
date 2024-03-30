#ifndef ASSETS_LIVESTOCK_FARMER_HPP
#define ASSETS_LIVESTOCK_FARMER_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"
#include "owner/PastureOwner.hpp"
#include "../interfaces/Taxable.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

class LivestockFarmer : public Person, public StorageOwner, public PastureOwner, public Taxable {
    
};


#endif