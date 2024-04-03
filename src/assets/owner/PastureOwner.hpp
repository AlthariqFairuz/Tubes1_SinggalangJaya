#ifndef ASSETS_OWNER_PASTURE_OWNER_HPP
#define ASSETS_OWNER_PASTURE_OWNER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Matrix.hpp"

using std::cout, std::endl;
using std::vector;
using std::string;

class PastureOwner {
    public:
    Matrix<string> land;

    PastureOwner(int rows, int cols) : land(rows, cols) {}
    
    virtual void cetak_peternakan() {
        cout << "==========" << endl;
        cout << "Peternakan" << endl;
        cout << "==========" << endl;
        land.print();
    }
};

#endif