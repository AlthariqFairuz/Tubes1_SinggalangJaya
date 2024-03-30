#ifndef ASSETS_CROP_FARMER_HPP
#define ASSETS_CROP_FARMER_HPP

#include "Person.hpp"
#include "owner/StorageOwner.hpp"
#include "owner/CroplandOwner.hpp"
#include "../interfaces/Taxable.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

class CropFarmer : public Person, public StorageOwner, public CroplandOwner, public Taxable {
};


#endif