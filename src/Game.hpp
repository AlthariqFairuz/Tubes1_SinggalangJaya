#ifndef GAME_HPP
#define GAME_HPP

#include "abstracts/GameLogic.hpp"
#include <set>

using std::set;

class Game {
    public:
    void muat_konfigurasi();
    void muat();
    void next();
    void simpan();
    void tambah_pemain();
    
    // Width = Vertical, length = Horizontal
    static int winning_money;
    static int winning_weight;
    static int storage_width, storage_length;
    static int cropland_width, cropland_length;
    static int pasture_width, pasture_length;
    
    private:
    set<GameLogic*, CompareUsername> players;
    int curent_player;

};

#endif