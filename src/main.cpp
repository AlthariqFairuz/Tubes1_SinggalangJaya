#include "Game.hpp"
#include "assets/Plant.hpp"
#include "assets/Animal.hpp"
#include "assets/Product.hpp"
#include "assets/Recipe.hpp"
#include "abstracts/GameLogic.hpp"


#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin;
using std::endl;
using std::string;

int main() {
    Game::muat_konfigurasi();
    Game::muat();
    
    cout << "Game dimulai dari " << (*Game::current_player)->get_username() << endl;


    while (true) {
        cout << "> ";
        cout.flush();

        string response;
        cin >> response;
        if (response == "NEXT") {
            Game::next();
        } else if (response == "SIMPAN") {
            Game::simpan();
        }
        // Game logic
        else if (response == "CETAK_PENYIMPANAN") {
            (*Game::current_player)->cetak_penyimpanan();
        } else if (response == "PUNGUT_PAJAK") {
            (*Game::current_player)->pungut_pajak();
        } else if (response == "CETAK_LADANG") {
            (*Game::current_player)->cetak_ladang();
        } else if (response == "CETAK_PETERNAKAN") {
            (*Game::current_player)->cetak_peternakan();
        } else if (response == "TANAM") {
            (*Game::current_player)->tanam();
        } else if (response == "TERNAK") {
            (*Game::current_player)->ternak();
        } else if (response == "BANGUN") {
            (*Game::current_player)->bangun();
        } else if (response == "MAKAN") {
            (*Game::current_player)->makan();
        } else if (response == "KASIH_MAKAN") {
            (*Game::current_player)->kasih_makan();
        } else if (response == "BELI") {
            (*Game::current_player)->beli();
        } else if (response == "JUAL") {
            (*Game::current_player)->jual();
        } else if (response == "PANEN") {
            (*Game::current_player)->panen();
        } else if (response == "TAMBAH_PEMAIN") {
            (*Game::current_player)->tambah_pemain();
        }


        else if (response == "KELUAR") {
            Game::exit();
        }
        else {
            cout << "Tidak dikenal perintah (" << response << ")" << endl;
        }
    }
    
}