#ifndef ASSETS_OWNER_PASTURE_OWNER_HPP
#define ASSETS_OWNER_PASTURE_OWNER_HPP

#include <vector>
#include <string>
#include "Matrix.hpp"

using std::vector;
using std::string;

class PastureOwner {
    public:
    Matrix<string> land;

    PastureOwner(int rows, int cols) : land(rows, cols) {}
    
};

#endif