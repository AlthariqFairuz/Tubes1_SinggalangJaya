#ifndef GAME_HPP
#define GAME_HPP

#include "abstracts/GameLogic.hpp"
#include <set>

using std::set;

class Game {
    public:
    static void muat_konfigurasi();
    void muat();
    void next();
    void simpan();
    void tambah_pemain();
    
    // row = Vertical, col = Horizontal
    static int winning_money;
    static int winning_weight;
    static int storage_row, storage_col;
    static int cropland_row, cropland_col;
    static int pasture_row, pasture_col;
    
    std::set<GameLogic *, CompareUsername>::iterator current_player;
    
    private:
    set<GameLogic*, CompareUsername> players;
};

#endif