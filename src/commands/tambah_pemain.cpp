#include "commands.hpp"

#include "../Game.hpp"

#include "../assets/LivestockFarmer.hpp"
#include "../assets/CropFarmer.hpp"

#include <iostream>

using std::cout, std::cin, std::endl;

void Command::tambah_pemain(Person &m) {
    cout << "Masukkan jenis pemain: ";
    string jenis_pemain;
    cin >> jenis_pemain;

    // Validasi jenis pemain
    while (jenis_pemain != "petani" && jenis_pemain != "peternak") {
        cout << endl;
        cout << "Jenis pemain tidak valid! Masukkan jenis pemain (petani/peternak): ";
        cin >> jenis_pemain;
    }

    cout << "Masukkan nama pemain (tanpa spasi): ";
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
    for (auto player_it = Game::players.begin(); player_it != Game::players.end(); ++player_it) {
        if ((*player_it)->get_role() == "Walikota") {
            Game::current_player = player_it;
            return;
        }
    }
}