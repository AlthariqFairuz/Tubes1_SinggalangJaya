#ifndef GAME_HPP
#define GAME_HPP

#include "abstracts/GameLogic.hpp"
#include <set>

using std::set;

class Game {
    public:
    static void muat_konfigurasi();
    static void muat();
    static void next();
    static void simpan();
    static void exit();
    
    // row = Vertical, col = Horizontal
    static int winning_money;
    static int winning_weight;
    static int storage_row, storage_col;
    static int cropland_row, cropland_col;
    static int pasture_row, pasture_col;
    
    static set<GameLogic*, CompareUsername>::iterator current_player;

    static set<GameLogic*, CompareUsername> players;
};

#endif