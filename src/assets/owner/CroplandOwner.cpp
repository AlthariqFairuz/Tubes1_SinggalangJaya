#include "CroplandOwner.hpp"
#include <iostream>

using std::cout, std::cin, std::endl;

void CroplandOwner::set_at(int row, int col, Plant *plant) {
    land.set_at(row, col, plant);
}

void CroplandOwner::cetak_ladang() const {
    cout << "======" << endl;
    cout << "Ladang" << endl;
    cout << "======" << endl;
    land.print();
}

void CroplandOwner::tambah_umur_ladang() {
    land.tambah_umur_ladang();
}

Coordinate CroplandOwner::query_empty_slot() {
    while (true) {
        cout << "Pilih slot yang kosong" << endl;
        cetak_ladang();
        cout << "Petak slot: ";
        string slot;
        cin >> slot;

        Coordinate loc = location(slot);
        if (loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= land.get_rows() || loc.col < 0 || loc.col >= land.get_cols()) {
            cout << "Koordinat tidak valid" << endl;
            continue; 
        }
        if (!land.is_empty(loc.row, loc.col)) {
            cout << "Slot sudah ditanami. Ulangi langi." << endl;
            continue;
        }
        return loc;
    }
}