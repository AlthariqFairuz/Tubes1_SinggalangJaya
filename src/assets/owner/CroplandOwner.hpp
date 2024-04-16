#ifndef ASSETS_OWNER_CROPLAND_OWNER_HPP
#define ASSETS_OWNER_CROPLAND_OWNER_HPP

#include "../Plant.hpp"
#include <vector>
#include <string>
#include "Matrix.hpp"
#include "../../utils/pcolor.hpp"

using std::vector;
using std::string;


class MatrixPlant : public Matrix<Plant*> {
    public:

    MatrixPlant(int rows, int cols) : Matrix<Plant*>(rows, cols) {

    }
    ~MatrixPlant() {

    }

    int get_total_price() {
        int total = 0;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (data[i][j] != 0){
                    total += data[i][j]->get_price();
                }
            }
        }
        return total;
    }

    void print() const {
        cout << "   ";
        for (int i = 0; i < cols; ++i) {
            cout << "   " << (char)('A' + i) << "  ";
        }
        cout << '\n';
        cout << "   ";
        for (int i = 0; i < cols; ++i) {
            cout << "+-----";
        }
        cout << "+\n";
        for (int i = 0; i < rows; ++i) {
            std::stringstream ss;
            ss << std::setw(2) << std::setfill('0') << i;
            cout << ss.str() << " ";

            for (int j = 0; j < cols; ++j) {
                auto entry = data[i][j];
                string entry_string;
                if (entry == 0) entry_string = "   ";
                else entry_string = entry->code;

                cout << "| ";
                if (entry != 0 && entry->ready_to_harvest()) {
                    print_green(entry_string);
                } else {
                    print_red(entry_string);
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
    void tambah_umur_ladang() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] != 0) {
                    data[i][j]->increment_age();
                }
            }
        }
    }
};


class CroplandOwner {
    public:
    CroplandOwner(int rows, int cols) : land(rows, cols) {}

    CroplandOwner(CroplandOwner &other);

    void operator=(CroplandOwner &other);

    void set_at(int row, int col, Plant *plant);

    void cetak_ladang() const;
    void tambah_umur_ladang();
    Coordinate query_empty_slot();
    Coordinate query_specified_plant(string _code);

    MatrixPlant land;
    // private:
    // MatrixPlant land;
};

#endif