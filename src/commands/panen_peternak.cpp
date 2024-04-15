#include "commands.hpp"
#include "../assets/Product.hpp"
#include <iostream>

using std::cout, std::cin, std::endl;


void panen_animal_loc(int row, int col, StorageOwner &so, PastureOwner &po) {
    auto animal = po.land(row, col);
    string animal_name = animal->get_name();
    po.land.hard_erase(row, col);


    for (auto &[code, product] : Product::product_config) {
        if (product.origin == animal_name) {
            so += product.to_item();
        }
    }
}


int hasil_panen_animal_size(string code) {
    int size = 0;
    for (auto &[code, product] : Product::product_config) {
        if (product.origin == Animal::animal_config.find(code)->second.name) {
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

void Command::panen_peternak(StorageOwner &so, PastureOwner &po) {
    po.cetak_peternakan();

    map<string, HasilPanen> hasil_panen; // kode, (ready, total)

    for (int i = 0; i < po.land.get_rows(); ++i) {
        for (int j = 0; j < po.land.get_cols(); ++j) {
            auto animal = po.land(i, j);
            if (!po.land.is_empty(i, j)) {
                if (animal->ready_to_harvest()) {
                    ++hasil_panen[animal->code].ready;
                }
                ++hasil_panen[animal->code].total;
            }
        }
    }
    bool is_exists_ready = false;
    for (auto &[code, unit] : hasil_panen) {
        cout << " - " << code << " - " << Animal::animal_config[code].name << "\t\t" << ": " << unit.ready << " dari " << unit.total << endl;
        if (unit.ready != 0) is_exists_ready = true;
    }
    if (!is_exists_ready) {
        cout << "Tidak ada hewan yang siap dipanen" << endl;
        return;
    }
    
    cout << "Kode dari hewan yang ingin dipanen: "; cout.flush();
    string code;
    cin >> code;


    if (Animal::animal_config.find(code) == Animal::animal_config.end()) {
        cout << "Kode hewan tidak valid" << endl;
        return;
    }

    auto specified_animal = hasil_panen.find(code);

    if (specified_animal == hasil_panen.end()) {
        cout << "Hewan tidak ada di ladang pertanian" << endl;
        return;
    }

    if (specified_animal->second.ready == 0) {
        cout << "Tidak ada hewan yang siap dipanen" << endl;
        return;
    }

    cout << "Berapa petak yang ingin dipanen: "; cout.flush();
    int total_petak;
    cin >> total_petak;

    if (total_petak > specified_animal->second.ready) {
        cout << "Total petak melebihi jumlah hewan yang siap dipanen" << endl;
        return;
    }

    if (hasil_panen_animal_size(code) * total_petak > so.count_empty_slots() + total_petak) {
        cout << "Jumlah penyimpanan tidak cukup" << endl;
        return;
    }

    cout << "Pilih petak yang ingin dipanen:" << endl;
    for (int petak_count = 1; petak_count <= total_petak; ++petak_count) {
        cout << "Petak ke-" << petak_count << ": " << endl;
        Coordinate selected_animal_location;
        Animal *selected_animal;
        while (true) {
            selected_animal_location = po.query_specified_animal(code);
            selected_animal = po.land(selected_animal_location.row, selected_animal_location.col);
            if (selected_animal->ready_to_harvest()) {
                break;
            } else {
                cout << "Hewan belum siap dipanen. Ulangi lagi" << endl;
            }
        }
        panen_animal_loc(selected_animal_location.row, selected_animal_location.col, so, po);
    }
    cout << total_petak << " hewan " << Animal::animal_config.find(code)->second.name << " berhasil dipanen." << endl;
}