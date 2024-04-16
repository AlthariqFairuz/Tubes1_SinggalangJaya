#include "commands.hpp"
#include "../assets/Product.hpp"
#include <iostream>

using std::cout, std::cin, std::endl;


void panen_plant_loc(int row, int col, StorageOwner &so, CroplandOwner &co) {
    auto plant = co.land(row, col);
    string plant_name = plant->get_name();
    co.land.hard_erase(row, col);

    for (auto &[code, product] : Product::product_config) {
        if (product.origin == plant_name) {
            so += product.to_item();
        }
    }
}


int hasil_panen_plant_size(string plant_code) {
    int size = 0;
    for (auto &[code, product] : Product::product_config) {
        if (product.origin == Plant::plant_config.find(plant_code)->second.name) {
            ++size;
        }
    }
    return size;
}

class HasilPanen {
    public:
    int ready;
    int total;
};

void Command::panen_petani(StorageOwner &so, CroplandOwner &co) {
    co.cetak_ladang();

    map<string, HasilPanen> hasil_panen; // kode, (ready, total)

    for (int i = 0; i < co.land.get_rows(); ++i) {
        for (int j = 0; j < co.land.get_cols(); ++j) {
            auto plant = co.land(i, j);
            if (!co.land.is_empty(i, j)) {
                if (plant->ready_to_harvest()) {
                    ++hasil_panen[plant->code].ready;
                }
                ++hasil_panen[plant->code].total;
            }
        }
    }
    bool is_exists_ready = false;
    for (auto &[code, unit] : hasil_panen) {
        cout << " - " << code << " - " << Plant::plant_config[code].name << "\t\t" << ": " << unit.ready << " dari " << unit.total << endl;
        if (unit.ready != 0) is_exists_ready = true;
    }
    if (!is_exists_ready) {
        cout << "Tidak ada tanaman yang siap dipanen" << endl;
        return;
    }
    
    cout << "Kode dari tanaman yang ingin dipanen: "; cout.flush();
    string code;
    cin >> code;


    if (Plant::plant_config.find(code) == Plant::plant_config.end()) {
        cout << "Kode tanaman tidak valid" << endl;
        return;
    }

    auto specified_plant = hasil_panen.find(code);

    if (specified_plant == hasil_panen.end()) {
        cout << "Tanaman tidak ada di ladang pertanian" << endl;
        return;
    }

    if (specified_plant->second.ready == 0) {
        cout << "Tidak ada tanaman yang siap dipanen" << endl;
        return;
    }

    cout << "Berapa petak yang ingin dipanen: "; cout.flush();
    int total_petak;
    cin >> total_petak;

    if (total_petak > specified_plant->second.ready) {
        cout << "Total petak melebihi jumlah tanaman yang siap dipanen" << endl;
        return;
    }

    if (hasil_panen_plant_size(code) * total_petak > so.count_empty_slots() + total_petak) {
        cout << "Jumlah penyimpanan tidak cukup" << endl;
        return;
    }

    cout << "Pilih petak yang ingin dipanen:" << endl;
    for (int petak_count = 1; petak_count <= total_petak; ++petak_count) {
        cout << "Petak ke-" << petak_count << ": " << endl;
        Coordinate selected_plant_location;
        Plant *selected_plant;
        while (true) {
            selected_plant_location = co.query_specified_plant(code);
            selected_plant = co.land(selected_plant_location.row, selected_plant_location.col);
            if (selected_plant->ready_to_harvest()) {
                break;
            } else {
                cout << "Tanaman belum siap dipanen. Ulangi lagi" << endl;
            }
        }
        panen_plant_loc(selected_plant_location.row, selected_plant_location.col, so, co);
    }
    cout << total_petak << " tanaman " << Plant::plant_config.find(code)->second.name << " berhasil dipanen." << endl;
}