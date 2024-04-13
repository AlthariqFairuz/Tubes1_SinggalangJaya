#ifndef INTERFACES_GAME_LOGIC_HPP
#define INTERFACES_GAME_LOGIC_HPP

#include <iostream>
#include <string>

using std::cout, std::endl;
using std::string;

class GameLogic {
    public:
    virtual ~GameLogic() {}
    
    virtual void cetak_penyimpanan() const {
        cout << get_username() << " tidak dapat mencetak penyimpanan" << endl;
    }
    virtual void pungut_pajak() {
        cout << get_username() << " tidak dapat memungut pajak" << endl;
    }
    virtual void cetak_ladang() const {
        cout << get_username() << " tidak dapat mencetak ladang" << endl;
    }
    virtual void cetak_peternakan() const {
        cout << get_username() << " tidak dapat mencetak peternakan" << endl;
    }
    virtual void tanam() {
        cout << get_username() << " tidak dapat menanam" << endl;
    }
    virtual void ternak() {
        cout << get_username() << " tidak dapat beternak" << endl;
    }
    virtual void bangun() {
        cout << get_username() << " tidak dapat membangun" << endl;
    }
    virtual void makan() {
        cout << get_username() << " tidak dapat makan" << endl;
    }
    virtual void kasih_makan() {
        cout << get_username() << " tidak dapat memberi makan" << endl;
    }
    virtual void beli() {
        cout << get_username() << " tidak dapat membeli" << endl;
    }
    virtual void jual() {
        cout << get_username() << " tidak dapat menjual" << endl;
    }
    virtual void panen() {
        cout << get_username() << " tidak dapat memanen" << endl;
    }
    virtual void tambah_pemain() {
        cout << get_username() << " tidak dapat menambah pemain" << endl;
    }

    virtual string get_username() const = 0;
    virtual void next() = 0;
};

class CompareUsername {
    public:
    bool operator()(const GameLogic *a, const GameLogic *b) const {
        return a->get_username() < b->get_username();
    }
};

#endif