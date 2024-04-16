#include "CroplandOwner.hpp"
#include <iostream>

using std::cout, std::cin, std::endl;

CroplandOwner::CroplandOwner(CroplandOwner &other) : CroplandOwner(other.land.get_rows(), other.land.get_cols()) {
    for (int i = 0; i < land.get_rows(); ++i) {
        for (int j = 0; j < land.get_cols(); ++j) {
            land(i, j) = other.land(i, j);
        }
    }
}

void CroplandOwner::operator=(CroplandOwner &other) {
    cout << "calling croplandowner = operator" << endl;
    for (int i = 0; i < land.get_rows(); ++i) {
        for (int j = 0; j < land.get_cols(); ++j) {
            land(i, j) = other.land(i, j);
        }
    }
}

void CroplandOwner::set_at(int row, int col, Plant *plant) {
    land.set_at(row, col, plant);
}

void CroplandOwner::cetak_ladang() const
{
    cout << "======" << endl;
    cout << "Ladang" << endl;
    cout << "======" << endl;
    land.print();
}

int CroplandOwner::count_total_plants()
{
    int count = 0;
    for (int i = 0; i < land.get_rows(); ++i)
    {
        for (int j = 0; j < land.get_cols(); ++j)
        {
            if (land(i, j) != 0)
            {
                ++count;
            }
        }
    }
    return count;
}

void CroplandOwner::tambah_umur_ladang()
{
    land.tambah_umur_ladang();
}

Coordinate CroplandOwner::query_empty_slot()
{
    while (true)
    {
        cout << "Pilih slot yang kosong" << endl;
        cetak_ladang();
        cout << "Petak slot: ";
        string slot;
        cin >> slot;

        Coordinate loc = location(slot);
        if (loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= land.get_rows() || loc.col < 0 || loc.col >= land.get_cols())
        {
            cout << "Koordinat tidak valid" << endl;
            continue;
        }
        if (!land.is_empty(loc.row, loc.col))
        {
            cout << "Slot sudah ditanami. Ulangi langi." << endl;
            continue;
        }
        return loc;
    }
}

Coordinate CroplandOwner::query_specified_plant(string _code)
{
    while (true)
    {
        cout << "Pilih slot:" << endl;
        cetak_ladang();

        cout << "Petak slot: ";
        string slot;
        cin >> slot;

        Coordinate loc = location(slot);
        if (loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= land.get_rows() || loc.col < 0 || loc.col >= land.get_cols())
        {
            cout << "Koordinat tidak valid" << endl;
            continue;
        }
        if (land.is_empty(loc.row, loc.col))
        {
            cout << "Slot merupakan slot kosong. Ulangi langi." << endl;
            continue;
        }
        if (land(loc.row, loc.col)->code != _code)
        {
            cout << "Tumbuhan tidak memiliki kode yang sesuai dengan yang ditentukan sebelumnya" << endl;
            continue;
        }
        return loc;
    }
}