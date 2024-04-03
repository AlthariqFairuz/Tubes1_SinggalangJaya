#ifndef ASSETS_OWNER_STORAGE_OWNER_HPP
#define ASSETS_OWNER_STORAGE_OWNER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Matrix.hpp"

using std::cout, std::endl;
using std::vector;
using std::string;

class StorageOwner {
    public:
    Matrix<string> storage;

    StorageOwner(int rows, int cols) : storage(rows, cols) {}
    
    virtual void cetak_penyimpanan() {
        cout << "===========" << endl;
        cout << "Penyimpanan" << endl;
        cout << "===========" << endl;
        storage.print();
    }
};

#endif