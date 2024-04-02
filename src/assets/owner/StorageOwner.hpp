#ifndef ASSETS_OWNER_STORAGE_OWNER_HPP
#define ASSETS_OWNER_STORAGE_OWNER_HPP

#include <vector>
#include <string>
#include "Matrix.hpp"

using std::vector;
using std::string;

class StorageOwner {
    public:
    Matrix<string> storage;

    StorageOwner(int rows, int cols) : storage(rows, cols) {}
};

#endif