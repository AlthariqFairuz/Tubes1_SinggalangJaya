#include "LivestockFarmer.hpp"

string LivestockFarmer::get_username() const {
    return username;
}

void LivestockFarmer::cetak_penyimpanan() {
    StorageOwner::cetak_penyimpanan();
}

void LivestockFarmer::cetak_peternakan() {
    PastureOwner::cetak_peternakan();
}

int LivestockFarmer::calculate_tax() {
    return 0;
}
void LivestockFarmer::ternak() {
    cout << "Pilih hewan dari penyimpanan" << endl;

    cetak_penyimpanan();
    
}

