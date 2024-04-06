#ifndef ASSETS_OWNER_CROPLAND_OWNER_HPP
#define ASSETS_OWNER_CROPLAND_OWNER_HPP

#include "../Plant.hpp"
#include <vector>
#include <string>
#include "Matrix.hpp"
#include "../../utils/pcolor.hpp"

using std::vector;
using std::string;


class MatrixPlant : public Matrix<Plant> {
    public:

    MatrixPlant(int rows, int cols) : Matrix<Plant>(rows, cols) {}

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
                if (entry.duration >= Plant::plant_config[entry.code].duration_to_harvest) {
                    print_green(entry_string);
                } else {
                    print_normal(entry_string);
                }
                cout << " ";
            }
            cout << "|\n   ";
            for (int i = 0; i < get_cols(); ++i) {
                cout << "+-----";
            }
            cout << "+\n";
        }
        cout.flush();
    }
};


class CroplandOwner {
    public:
    CroplandOwner(int rows, int cols) : land(rows, cols) {}

    virtual void cetak_ladang() {
        cout << "======" << endl;
        cout << "Ladang" << endl;
        cout << "======" << endl;
        land.print();
    }

    void add_plant(Plant t) {
        for (int i = 0; i < land.get_rows(); ++i) {
            for (int j = 0; j < land.get_cols(); ++j) {
                if (land(i, j) == Plant()) {
                    land(i, j) = t;
                    return;
                }
            }
        }
    }
    void add_plant_at(Plant t, string location) {
        Coordinate c = Matrix<Plant>::location(location);
        land(c.row, c.col) = t;
    }

    private:
    MatrixPlant land;
};

#endif