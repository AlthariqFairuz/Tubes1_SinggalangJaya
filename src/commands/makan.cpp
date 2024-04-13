#include "commands.hpp"
#include "../assets/Product.hpp"

void Command::makan(Person &p, StorageOwner &so) {
    if (!so.is_exist_consumable()) {
        cout << "Tidak ada item yang bisa dikonsumsi" << endl;
        return;
    }

    cout << "Pilih makananan dari penyimpanan" << endl;
    Coordinate loc =  so.query_consumable();

    auto selected_consumable = dynamic_cast<Product*>(so.storage(loc.row, loc.col));
    so.storage.soft_erase(loc.row, loc.col);

    p.weight += selected_consumable->get_added_weight();
    cout << "Dengan lahapnya, kamu memakan hidangan itu" << endl;
    cout << "Alhasil, berat badan kamu naik dari " << p.weight - selected_consumable->get_added_weight() << " menjadi " << p.weight << "." << endl;
}