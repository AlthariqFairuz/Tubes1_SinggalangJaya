#include "CropFarmer.hpp"

PersonType CropFarmer::get_person_type() {
    return PersonType::Petani;
}

string CropFarmer::get_username() const {
    return username;
}

void CropFarmer::next() {
    tambah_umur_ladang();
    cout << "Umur tumbuhan di ladang pertanian " << username << " telah bertambah 1" << endl;
}

int CropFarmer::calculate_tax() {
    return 0;
}

void CropFarmer::cetak_penyimpanan() const {
    Command::cetak_penyimpanan(*dynamic_cast<StorageOwner const *>(this));
}

void CropFarmer::cetak_ladang() const {
    Command::cetak_ladang(*dynamic_cast<CroplandOwner const *>(this));
}

void CropFarmer::tanam() {
    Command::tanam(*dynamic_cast<StorageOwner*>(this), *dynamic_cast<CroplandOwner*>(this));
}

void CropFarmer::makan() {
    Command::makan(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}

void CropFarmer::beli() {
    Command::beli(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}
