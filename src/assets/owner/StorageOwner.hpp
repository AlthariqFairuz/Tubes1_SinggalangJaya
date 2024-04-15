#ifndef ASSETS_OWNER_STORAGE_OWNER_HPP
#define ASSETS_OWNER_STORAGE_OWNER_HPP

#include "../Item.hpp"
#include "../Product.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Matrix.hpp"

using std::cout, std::endl;
using std::vector;
using std::string;

class MatrixItem : public Matrix<Item*> {
    public:

    MatrixItem(int rows, int cols) : Matrix<Item*>(rows, cols) {

    }

    ~MatrixItem() {

    }
    int get_price_total(){  
        int total = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!is_empty(i,j)){
                auto item=dynamic_cast<Item*>(data[i][j]);
                
                total+=item->get_price();
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

    void set_at(int row, int col, Item *item);

    void operator+=(Item *item);

    void cetak_penyimpanan() const;

    int count_empty_slots();

    bool is_exist_specified_item(ItemType item_type);

    Coordinate query_empty_slot();

    Coordinate query_specific_item(ItemType item_type);

    Coordinate query_consumable();

    Coordinate query_consumable(ProductType product_type);

    bool is_exist_consumable();

    bool is_exist_consumable(ProductType product_type);

    

    MatrixItem storage;
    // private:
    // MatrixItem storage;
};

#endif