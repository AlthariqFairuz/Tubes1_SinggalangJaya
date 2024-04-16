#include "LivestockFarmer.hpp"
#include "../commands/commands.hpp"
#include<cmath>


void LivestockFarmer::set_storage(StorageOwner &so) {
    for (int i = 0; i < storage.get_rows(); ++i) {
        for (int j = 0; j < storage.get_cols(); ++j) {
            storage(i, j) = so.storage(i, j);
        }
    }
}

void LivestockFarmer::set_pasture_land(PastureOwner &po) {
    for (int i = 0; i < land.get_rows(); ++i) {
        for (int j = 0; j < land.get_cols(); ++j) {
            land(i, j) = po.land(i, j);
        }
    }
}


string LivestockFarmer::get_username() const {
    return username;
}

int LivestockFarmer::get_gold() const {
    return gold;
}

int LivestockFarmer::get_weight() const {
    return weight;
}

PersonType LivestockFarmer::get_person_type() {
    return PersonType::Peternak;
}

string LivestockFarmer::get_role() const {
    return "Peternak";
}


void LivestockFarmer::next() {
    // Tidak perlu tambah umur tanaman karena tidak ada ladang
}

int LivestockFarmer::calculate_tax() {
    double kkp = double(storage.get_price_total()- 11);

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

void LivestockFarmer::cetak_penyimpanan() const {
    Command::cetak_penyimpanan(*dynamic_cast<StorageOwner const *>(this));
}


void LivestockFarmer::cetak_peternakan() const {
    Command::cetak_peternakan(*dynamic_cast<PastureOwner const *>(this));
}

void LivestockFarmer::makan() {
    Command::makan(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}


void LivestockFarmer::ternak() {
    Command::ternak(*dynamic_cast<StorageOwner*>(this), *dynamic_cast<PastureOwner*>(this));
}

void LivestockFarmer::kasih_makan() {
    Command::kasih_makan(*dynamic_cast<StorageOwner*>(this), *dynamic_cast<PastureOwner*>(this));
}

void LivestockFarmer::panen() {
    Command::panen_peternak(*dynamic_cast<StorageOwner*>(this), *dynamic_cast<PastureOwner*>(this));
}

void LivestockFarmer::beli() {
    Command::beli(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}

void LivestockFarmer::jual() {
    Command::jual(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}
