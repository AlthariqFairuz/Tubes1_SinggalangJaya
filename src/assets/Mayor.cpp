#include "Mayor.hpp"

Mayor::Mayor(string username, int gold, int weight) : Person(username, gold, weight), StorageOwner(Game::storage_row, Game::storage_col) {}

Mayor::Mayor(string username, int gold, int weight, const StorageOwner &so) : Person(username, gold, weight), StorageOwner(so) {}

PersonType Mayor::get_person_type()
{
    return PersonType::Walikota;
}

string Mayor::get_username() const
{
    return username;
}

void Mayor::next()
{
    // Tidak perlu tambah umur tanaman karena tidak ada ladang
}

void Mayor::cetak_penyimpanan() const
{
    Command::cetak_penyimpanan(*dynamic_cast<StorageOwner const *>(this));
}

void Mayor::makan()
{
    Command::makan(*dynamic_cast<Person *>(this), *dynamic_cast<StorageOwner *>(this));
}

void Mayor::bangun()
{
    Command::bangun(*dynamic_cast<StorageOwner *>(this));
}

void Mayor::beli()
{
    Command::beli(*dynamic_cast<Person *>(this), *dynamic_cast<StorageOwner *>(this));
}