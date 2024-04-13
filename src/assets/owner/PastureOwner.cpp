#include "PastureOwner.hpp"
#include <iostream>

using std::cout, std::cin, std::endl;

void PastureOwner::set_at(int row, int col, Animal *animal) {
    land.set_at(row, col, animal);
}

Coordinate PastureOwner::query_animal() {
    while (true) {
        cout << "Pilih slot:" << endl;
        cetak_peternakan();
        cout << "Petak slot: ";
        string slot;
        cin >> slot;

        Coordinate loc = location(slot);
        if (loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= land.get_rows() || loc.col < 0 || loc.col >= land.get_cols()) {
            cout << "Koordinat tidak valid" << endl;
            continue; 
        }
        if (land.is_empty(loc.row, loc.col)) {
            cout << "Slot merupakan slot kosong. Ulangi langi." << endl;
            continue;
        }
        return loc;
    }
}

Coordinate PastureOwner::query_empty_slot() {
    while (true) {
        cout << "Pilih slot yang kosong" << endl;
        cetak_peternakan();
        cout << "Petak slot: ";
        string slot;
        cin >> slot;

        Coordinate loc = location(slot);
        if (loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= land.get_rows() || loc.col < 0 || loc.col >= land.get_cols()) {
            cout << "Koordinat tidak valid" << endl;
            continue; 
        }
        if (!land.is_empty(loc.row, loc.col)) {
            cout << "Slot sudah ditempati oleh hewan. Ulangi langi." << endl;
            continue;
        }
        return loc;
    }
}

Coordinate PastureOwner::query_specified_animal(string _code) {
    while (true) {
        cout << "Pilih slot:" << endl;
        cetak_peternakan();

        cout << "Petak slot: ";
        string slot;
        cin >> slot;

        Coordinate loc = location(slot);
        if (loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= land.get_rows() || loc.col < 0 || loc.col >= land.get_cols()) {
            cout << "Koordinat tidak valid" << endl;
            continue; 
        }
        if (land.is_empty(loc.row, loc.col)) {
            cout << "Slot merupakan slot kosong. Ulangi langi." << endl;
            continue;
        }
        if (land(loc.row, loc.col)->code != _code) {
            cout << "Hewan tidak memiliki kode yang sesuai dengan yang ditentukan sebelumnya" << endl;
            continue;
        }
        return loc;
    }
}

void PastureOwner::cetak_peternakan() const {
    cout << "==========" << endl;
    cout << "Peternakan" << endl;
    cout << "==========" << endl;
    land.print();
}

