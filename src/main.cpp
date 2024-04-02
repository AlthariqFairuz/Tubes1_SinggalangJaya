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
    Game game;
    game.muat_konfigurasi();
    game.muat();

    while (true) {
        string response;
        cin >> response;
        if (response == "NEXT") {
            game.next();
        } else if (response == "SIMPAN") {
            game.simpan();
        }
        // Game logic
        else if (response == "CETAK_PENYIMPANAN") {
            (*game.current_player)->cetak_penyimpanan();
        } else if (response == "PUNGUT_PAJAK") {
            (*game.current_player)->pungut_pajak();
        } else if (response == "CETAK_LADANG") {
            (*game.current_player)->cetak_ladang();
        } else if (response == "CETAK_PETERNAKAN") {
            (*game.current_player)->cetak_peternakan();
        } else if (response == "TANAM") {
            (*game.current_player)->tanam();
        } else if (response == "TERNAK") {
            (*game.current_player)->ternak();
        } else if (response == "BANGUN") {
            (*game.current_player)->bangun();
        } else if (response == "MAKAN") {
            (*game.current_player)->makan();
        } else if (response == "KASIH_MAKAN") {
            (*game.current_player)->kasih_makan();
        } else if (response == "BELI") {
            (*game.current_player)->beli();
        } else if (response == "JUAL") {
            (*game.current_player)->jual();
        } else if (response == "PANEN") {
            (*game.current_player)->panen();
        } else if (response == "TAMBAH_PEMAIN") {
            (*game.current_player)->tambah_pemain();
        } 
        else {
            cout << "Tidak dikenal perintah (" << response << ")" << endl;
        }
    }
}