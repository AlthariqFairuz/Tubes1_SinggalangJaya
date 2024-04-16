#include "Mayor.hpp"
#include "../commands/commands.hpp"

PersonType Mayor::get_person_type() {
    return PersonType::Walikota;
}

string Mayor::get_username() const {
    return username;
}

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
