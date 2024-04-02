#ifndef ASSETS_OWNER_CROPLAND_OWNER_HPP
#define ASSETS_OWNER_CROPLAND_OWNER_HPP

#include <vector>
#include <string>
#include "Matrix.hpp"

using std::vector;
using std::string;

class CroplandOwner {
    public:
    Matrix<string> land;

    CroplandOwner(int rows, int cols) : land(rows, cols) {}
};

#endif