#ifndef COMMANDS_COMMANDS_HPP
#define COMMANDS_COMMANDS_HPP

#include "../abstracts/GameLogic.hpp"
#include "../Game.hpp"

// #include "../assets/Mayor.hpp"
#include "../assets/Mayor.hpp"

#include "../assets/owner/StorageOwner.hpp"
#include "../assets/owner/PastureOwner.hpp"
#include "../assets/owner/CroplandOwner.hpp"

class Command {
    public:
    static void cetak_penyimpanan(const StorageOwner &so);
    static void pungut_pajak(Mayor &m, set<GameLogic*, CompareUsername> &game);
    static void cetak_ladang(const CroplandOwner &co);
    static void cetak_peternakan(const PastureOwner &po);
    static void tanam(StorageOwner &so, CroplandOwner &co);
    static void ternak(StorageOwner &so, PastureOwner &po);
    static void bangun(Person &p, StorageOwner &so);
    static void makan(Person &p, StorageOwner &so);
    static void kasih_makan(StorageOwner &so, PastureOwner &po);
    static void panen_petani(StorageOwner &so, CroplandOwner &co);
    static void panen_peternak(StorageOwner &so, PastureOwner &po);
    static void beli(Person &p, StorageOwner &so);
    static void jual(Person &p, StorageOwner &so);
};

#endif