#ifndef ASSETS_OWNER_PASTURE_OWNER_HPP
#define ASSETS_OWNER_PASTURE_OWNER_HPP

#include "../Animal.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Matrix.hpp"
#include "../../utils/pcolor.hpp"


using std::cout, std::endl;
using std::vector;
using std::string;

class MatrixAnimal : public Matrix<Animal> {
    public:

    MatrixAnimal(int rows, int cols) : Matrix<Animal>(rows, cols) {}

    void print() {
        cout << "   ";
        for (int i = 0; i < get_cols(); ++i) {
            cout << "   " << (char)('A' + i) << "  ";
        }
        cout << '\n';
        cout << "   ";
        for (int i = 0; i < get_cols(); ++i) {
            cout << "+-----";
        }
        cout << "+\n";
        for (int i = 0; i < get_rows(); ++i) {
            std::stringstream ss;
            ss << std::setw(2) << std::setfill('0') << i;
            cout << ss.str() << " ";

            for (int j = 0; j < get_cols(); ++j) {
                auto entry = data[i][j];
                string entry_string;
                if (entry.item_type == ItemType::Null) entry_string = "   ";
                else entry_string = entry.code;

                cout << "| ";
                if (entry.weight >= Animal::animal_config[entry.code].weight_to_harvest) {
                    print_green(entry_string);
                } else {
                    print_normal(entry_string);
                }
                cout << " ";
            }
            cout << "|\n   ";
            for (int i = 0; i < cols; ++i) {
                cout << "+-----";
            }
            cout << "+\n";
        }
        cout.flush();
    }
};


class PastureOwner {
    public:

    PastureOwner(int rows, int cols) : land(rows, cols) {}
    
    virtual void cetak_peternakan() {
        cout << "==========" << endl;
        cout << "Peternakan" << endl;
        cout << "==========" << endl;
        land.print();
    }

    void add_animal(Animal t) {
        for (int i = 0; i < land.get_rows(); ++i) {
            for (int j = 0; j < land.get_cols(); ++j) {
                if (land(i, j) == Animal()) {
                    land(i, j) = t;
                    return;
                }
            }
        }
    }

    void add_animal_at(Animal t, string location) {
        Coordinate c = Matrix<Animal>::location(location);
        land(c.row, c.col) = t;
    }

    private:
    MatrixAnimal land;
};

#endif