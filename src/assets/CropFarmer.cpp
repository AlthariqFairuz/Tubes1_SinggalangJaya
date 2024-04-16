#include "CropFarmer.hpp"
#include <cmath>
#include <algorithm>

using std::max, std::min;


void CropFarmer::set_storage(StorageOwner &so) {
    for (int i = 0; i < storage.get_rows(); ++i) {
        for (int j = 0; j < storage.get_cols(); ++j) {
            storage(i, j) = so.storage(i, j);
        }
    }
}

void CropFarmer::set_crop_land(CroplandOwner &co) {
    for (int i = 0; i < land.get_rows(); ++i) {
        for (int j = 0; j < land.get_cols(); ++j) {
            land(i, j) = co.land(i, j);
        }
    }
}

string CropFarmer::get_username() const {
    return username;
}

int CropFarmer::get_gold() const {
    return gold;
}

int CropFarmer::get_weight() const {
    return weight;
}

PersonType CropFarmer::get_person_type() {
    return PersonType::Petani;
}

string CropFarmer::get_role() const {
    return "Petani";
}




void CropFarmer::next() {
    tambah_umur_ladang();
    cout << "Umur tumbuhan di ladang pertanian " << username << " telah bertambah 1" << endl;
}

int CropFarmer::calculate_tax() {
    int kkp = std::max(storage.get_total_price() + land.get_total_price() - 13, 0);
    
    double tarif  = 0;
    if (kkp <= 6){
        tarif = 5.0 / 100;
    } else if (kkp <= 25){
        tarif = 15.0 / 100;
    } else if (kkp <= 50){
        tarif = 25.0 / 100;
    } else if (kkp <= 500){
        tarif = 30.0 / 100;
    } else {
        tarif = 35.0 / 100;
    }

    int tax = round(tarif * kkp);
    int paid = min(gold, tax);
    gold -= paid;

    return paid;
}

void CropFarmer::cetak_penyimpanan() const {
    Command::cetak_penyimpanan(*dynamic_cast<StorageOwner const *>(this));
}

void CropFarmer::cetak_ladang() const {
    Command::cetak_ladang(*dynamic_cast<CroplandOwner const *>(this));
}

void CropFarmer::makan() {
    Command::makan(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}

void CropFarmer::tanam() {
    Command::tanam(*dynamic_cast<StorageOwner*>(this), *dynamic_cast<CroplandOwner*>(this));
}

void CropFarmer::panen() {
    Command::panen_petani(*dynamic_cast<StorageOwner*>(this), *dynamic_cast<CroplandOwner*>(this));
}

void CropFarmer::beli() {
    Command::beli(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}

void CropFarmer::jual() {
    Command::jual(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}