#ifndef ASSETS_OWNER_STORAGE_OWNER_HPP
#define ASSETS_OWNER_STORAGE_OWNER_HPP

#include "../Item.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Matrix.hpp"

using std::cout, std::endl;
using std::vector;
using std::string;

class MatrixItem : public Matrix<Item> {
    public:

    MatrixItem(int rows, int cols) : Matrix<Item>(rows, cols) {}

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
                cout << "| " << entry_string << " ";
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

class StorageOwner {
    public:

    StorageOwner(int rows, int cols) : storage(rows, cols) {}
    

    virtual void cetak_penyimpanan() {
        cout << "===========" << endl;
        cout << "Penyimpanan" << endl;
        cout << "===========" << endl;
        storage.print();
    }

    void add_item(Item t) {
        for (int i = 0; i < storage.get_rows(); ++i) {
            for (int j = 0; j < storage.get_cols(); ++j) {
                if (storage(i, j) == Item()) {
                    storage(i, j) = t;
                    return;
                }
            }
        }
    }


    private:
    MatrixItem storage;
};

#endif