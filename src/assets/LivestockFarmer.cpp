#include "LivestockFarmer.hpp"
#include "../commands/commands.hpp"

PersonType LivestockFarmer::get_person_type() {
    return PersonType::Peternak;
}

string LivestockFarmer::get_username() const {
    return username;
}

void LivestockFarmer::next() {
    // Tidak perlu tambah umur tanaman karena tidak ada ladang
}

int LivestockFarmer::calculate_tax() {
    int kkp = storage.get_price_total()- 11;

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
    if(this->gold<(int)tax*kkp){
        val += gold;
        this->gold = 0;
        
    }else{
        this->gold-=(int)tax*kkp;
        val += (int)tax*kkp;    
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

