#include "Mayor.hpp"
#include "../commands/commands.hpp"

void Mayor::set_storage(StorageOwner &so) {
    for (int i = 0; i < storage.get_rows(); ++i) {
        for (int j = 0; j < storage.get_cols(); ++j) {
            storage(i, j) = so.storage(i, j);
        }
    }
}

string Mayor::get_username() const {
    return username;
}

int Mayor::get_gold() const {
    return gold;
}

int Mayor::get_weight() const {
    return weight;
}

PersonType Mayor::get_person_type() {
    return PersonType::Walikota;
}

string Mayor::get_role() const {
    return "Walikota";
}



// string Mayor::get_username() const {
//     return username;
// }

void Mayor::next() {
    // Tidak perlu tambah umur tanaman karena tidak ada ladang
}

int Mayor::calculate_tax() {
    return 0;
}

void Mayor::cetak_penyimpanan() const {
    Command::cetak_penyimpanan(*dynamic_cast<StorageOwner const *>(this));
}
 
void Mayor::pungut_pajak(){
    // Command::pungut_pajak(*dynamic_cast<Mayor*>(this), *(Game::players));
}
void Mayor::makan() {
    Command::makan(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}

void Mayor::bangun() {
    Command::bangun(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}

void Mayor::beli() {
    Command::beli(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}

void Mayor::jual() {
    Command::jual(*dynamic_cast<Person*>(this), *dynamic_cast<StorageOwner*>(this));
}

void Mayor::tambah_pemain() {
    Command::tambah_pemain(*dynamic_cast<Person*>(this));
}