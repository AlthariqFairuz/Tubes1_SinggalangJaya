#include "CropFarmer.hpp"
#include <cmath>


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

string CropFarmer::get_username() const
{
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
    double kkp = double(storage.get_price_total()- 13);

    double tax  = 0;

    if(kkp<=6){
        tax = 5/100;
    }else if(kkp <= 25){
        tax = 15/100;
    }else if(kkp<=50){
        tax = 25/100;
    }else if(kkp<=500){
        tax = 30/100;
    }else{
        tax = 35/100;
    }

    int val =0;
    int pre_tax = round(tax*kkp);
    if(this->gold<pre_tax){
        this->gold = 0;
        val += gold;
    }else{
        this->gold-=pre_tax;
        val += pre_tax;    
    }
    return val;
}

void CropFarmer::cetak_penyimpanan() const
{
    Command::cetak_penyimpanan(*dynamic_cast<StorageOwner const *>(this));
}

void CropFarmer::cetak_ladang() const
{
    Command::cetak_ladang(*dynamic_cast<CroplandOwner const *>(this));
}

void CropFarmer::makan()
{
    Command::makan(*dynamic_cast<Person *>(this), *dynamic_cast<StorageOwner *>(this));
}

void CropFarmer::tanam()
{
    Command::tanam(*dynamic_cast<StorageOwner *>(this), *dynamic_cast<CroplandOwner *>(this));
}

void CropFarmer::panen()
{
    Command::panen_petani(*dynamic_cast<StorageOwner *>(this), *dynamic_cast<CroplandOwner *>(this));
}

void CropFarmer::beli() {
    Command::beli(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}

void CropFarmer::jual() {
    Command::jual(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}
