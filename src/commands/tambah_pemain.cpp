#include "commands.hpp"
#include "../assets/CropFarmer.hpp"
#include "../assets/LivestockFarmer.hpp"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void Command::tambah_pemain(Person &m) {
    cout << "Masukkan jenis pemain: ";
    string jenis_pemain;
    cin >> jenis_pemain;

    // Validasi jenis pemain
    while (jenis_pemain != "petani" && jenis_pemain != "peternak") {
        cout << "Jenis pemain tidak valid! Masukkan jenis pemain (petani/peternak): ";
        cin >> jenis_pemain;
    }

    cout << "Masukkan nama pemain: ";
    string nama_pemain;
    cin >> nama_pemain;

    // Validasi nama pemain unik
    bool nama_unik = true;
    while (nama_unik) {
        for (auto player : Game::players) {
            if (player->get_username() == nama_pemain) {
                cout << "Nama pemain sudah ada! Masukkan nama pemain yang lain: ";
                cin >> nama_pemain;
                nama_unik = true;
                break;
            } else {
                nama_unik = false;
            }
        }
    }

    // Validasi uang Walikota cukup
    if (m.gold < 50) {
        cout << "Uang tidak cukup!" << endl;
        return;
    }
    else{
        if (jenis_pemain == "petani") {
            CropFarmer* petani = new CropFarmer(nama_pemain, 50, 0);
            Game::players.insert(petani);
            m.gold = m.gold - 50;
        } else {
            LivestockFarmer* peternak = new LivestockFarmer(nama_pemain, 50, 0);
            Game::players.insert(peternak);
            m.gold = m.gold - 50;
        }
    }

    cout << "Pemain baru ditambahkan!" << endl;
    cout << "Selamat datang \"" << nama_pemain << "\" di kota ini!" << endl;
}
