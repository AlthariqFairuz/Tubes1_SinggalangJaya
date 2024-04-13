#include "StorageOwner.hpp"
#include "../Product.hpp"
#include <iostream>

using std::cout, std::cin, std::endl;

void StorageOwner::cetak_penyimpanan() const {
    cout << "===========" << endl;
    cout << "Penyimpanan" << endl;
    cout << "===========" << endl;
    storage.print();
}

void StorageOwner::set_at(int row, int col, Item *item) {
    storage.set_at(row, col, item);
}

void StorageOwner::operator+=(Item *item) {
    storage.set(item);
}



int StorageOwner::count_empty_slots() {
    int count = 0;
    for (int i = 0; i < storage.get_rows(); ++i) {
        for (int j = 0; j < storage.get_cols(); ++j) {
            if (storage(i, j) == 0) {
                ++count;
            }
        }
    }
    return count;
}

bool StorageOwner::is_exist_specified_item(ItemType item_type) {
    for (int i = 0; i < storage.get_rows(); ++i) {
        for (int j = 0; j < storage.get_cols(); ++j) {
            if (!storage.is_empty(i, j) && storage(i, j)->get_item_type() == item_type) {
                return true;
            }
        }
    }
    return false;
}

Coordinate StorageOwner::query_empty_slot() {
    while (true) {
        cout << "Pilih slot yang kosong" << endl;
        cetak_penyimpanan();
        cout << "Petak slot: ";
        string slot;
        cin >> slot;

        Coordinate loc = location(slot);
        if (loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= storage.get_rows() || loc.col < 0 || loc.col >= storage.get_cols()) {
            cout << "Koordinat tidak valid" << endl;
            continue; 
        }
        if (!storage.is_empty(loc.row, loc.col)) {
            cout << "Slot sudah terpakai. Ulangi langi." << endl;
            continue;
        }
        return loc;
    }
}

Coordinate StorageOwner::query_specific_item(ItemType item_type) {
    while (true) {
        cout << "Pilih slot:" << endl;
        cetak_penyimpanan();
        cout << "Petak slot: ";
        string slot;
        cin >> slot;

        Coordinate loc = location(slot);
        if (loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= storage.get_rows() || loc.col < 0 || loc.col >= storage.get_cols()) {
            cout << "Koordinat tidak valid" << endl;
            continue; 
        }
        if (storage.is_empty(loc.row, loc.col)) {
            cout << "Slot merupakan slot kosong. Ulangi langi." << endl;
            continue;
        }
        if (storage(loc.row, loc.col)->get_item_type() != item_type) {
            cout << "Item tidak berjenis " << Item::get_item_type_string(item_type) << ". Ulangi lagi." << endl;
            continue;
        }
        return loc;
    }
}

Coordinate StorageOwner::query_consumable() {
    while (true) {
        cout << "Pilih slot:" << endl;
        cetak_penyimpanan();
        cout << "Petak slot: ";
        string slot;
        cin >> slot;

        Coordinate loc = location(slot);
        if (loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= storage.get_rows() || loc.col < 0 || loc.col >= storage.get_cols()) {
            cout << "Koordinat tidak valid" << endl;
            continue; 
        }
        if (storage.is_empty(loc.row, loc.col)) {
            cout << "Slot merupakan slot kosong. Ulangi langi." << endl;
            continue;
        }
        if (storage(loc.row, loc.col)->get_item_type() != ItemType::Product) {
            cout << "Item tidak bukan merupakan produk. Ulangi lagi." << endl;
            continue;
        }
        if (!dynamic_cast<Product*>(storage(loc.row, loc.col))->is_consumable()) {
            cout << "Produk tidak dapat dikonsum. Ulangi lagi." << endl;
            continue;
        }
        return loc;
    }
}

Coordinate StorageOwner::query_consumable(ProductType product_type) {
    while (true) {
        cout << "Pilih slot:" << endl;
        cetak_penyimpanan();
        cout << "Petak slot: ";
        string slot;
        cin >> slot;

        Coordinate loc = location(slot);
        if (loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= storage.get_rows() || loc.col < 0 || loc.col >= storage.get_cols()) {
            cout << "Koordinat tidak valid" << endl;
            continue; 
        }
        if (storage.is_empty(loc.row, loc.col)) {
            cout << "Slot merupakan slot kosong. Ulangi langi." << endl;
            continue;
        }
        if (storage(loc.row, loc.col)->get_item_type() != ItemType::Product) {
            cout << "Item tidak bukan merupakan produk. Ulangi lagi." << endl;
            continue;
        }
        if (!dynamic_cast<Product*>(storage(loc.row, loc.col))->is_consumable()) {
            cout << "Produk tidak dapat dikonsum. Ulangi lagi." << endl;
            continue;
        }
        if (dynamic_cast<Product*>(storage(loc.row, loc.col))->get_product_type() != product_type) {
            cout << "Produk bukan tipe yang dapat dikonsum oleh yang bersangkutan" << endl;
            continue;
        }
        return loc;
    }
}

bool StorageOwner::is_exist_consumable() {
    for (int i = 0; i < storage.get_rows(); ++i) {
        for (int j = 0; j < storage.get_cols(); ++j) {
            if (!storage.is_empty(i, j) && storage(i, j)->get_item_type() == ItemType::Product && dynamic_cast<Product*>(storage(i, j))->is_consumable()) {
                return true;
            }
        }
    }
    return false;
}

bool StorageOwner::is_exist_consumable(ProductType product_type) {
    for (int i = 0; i < storage.get_rows(); ++i) {
        for (int j = 0; j < storage.get_cols(); ++j) {
            if (!storage.is_empty(i, j) && storage(i, j)->get_item_type() == ItemType::Product && dynamic_cast<Product*>(storage(i, j))->is_consumable() && dynamic_cast<Product*>(storage(i, j))->get_product_type() == product_type) {
                return true;
            }
        }
    }
    return false;
}