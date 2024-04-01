#ifndef INTERFACES_GAME_LOGIC_HPP
#define INTERFACES_GAME_LOGIC_HPP

#include <string>

using std::string;

class GameLogic {
    public:
    virtual void cetak_penyimpanan();
    virtual void pungut_pajak();
    virtual void cetak_ladang();
    virtual void cetak_peternakan();
    virtual void tanam();
    virtual void ternak();
    virtual void bangun();
    virtual void makan();
    virtual void kasih_makan();
    virtual void beli();
    virtual void jual();
    virtual void panen();
    virtual void tambah_pemain();

    virtual string get_username() const;
};

class CompareUsername {
    public:
    bool compare_usernames(const GameLogic *a, const GameLogic *b) const {
        return a->get_username() < b->get_username();
    }
};

#endif