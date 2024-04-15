#include "CropFarmer.hpp"

CropFarmer::CropFarmer(string username, int gold, int weight) : Person(username, gold, weight), StorageOwner(Game::storage_row, Game::storage_col), CroplandOwner(Game::cropland_row, Game::cropland_col)
{
}

CropFarmer::CropFarmer(string username, int gold, int weight, const StorageOwner &so, const CroplandOwner &co) : Person(username, gold, weight), StorageOwner(so), CroplandOwner(co)
{
}

string CropFarmer::get_username() const
{
    return username;
}

int CropFarmer::get_gold() const
{
    return gold;
}

int CropFarmer::get_weight() const
{
    return weight;
}

PersonType CropFarmer::get_person_type()
{
    return PersonType::Petani;
}

string CropFarmer::get_role() const
{
    return "Petani";
}

void CropFarmer::next()
{
    tambah_umur_ladang();
    cout << "Umur tumbuhan di ladang pertanian " << username << " telah bertambah 1" << endl;
}

int CropFarmer::calculate_tax()
{
    return 0;
}

void CropFarmer::cetak_penyimpanan() const
{
    Command::cetak_penyimpanan(*dynamic_cast<StorageOwner const *>(this));
}

void CropFarmer::cetak_ladang() const
{
    Command::cetak_ladang(*dynamic_cast<CroplandOwner const *>(this));
}

void CropFarmer::makan()
{
    Command::makan(*dynamic_cast<Person *>(this), *dynamic_cast<StorageOwner *>(this));
}

void CropFarmer::tanam()
{
    Command::tanam(*dynamic_cast<StorageOwner *>(this), *dynamic_cast<CroplandOwner *>(this));
}

void CropFarmer::panen()
{
    Command::panen_petani(*dynamic_cast<StorageOwner *>(this), *dynamic_cast<CroplandOwner *>(this));
}

void CropFarmer::beli()
{
    Command::beli(*dynamic_cast<Person *>(this), *dynamic_cast<StorageOwner *>(this));
}