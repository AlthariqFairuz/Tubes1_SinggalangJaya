#include "commands.hpp"
#include "../assets/Product.hpp"

using std::cin;

void Command::makan(Person &p, StorageOwner &so) {
    if (!so.is_exist_consumable()) {
        // Throw exception
        cout << R"(Tidak ada item yang bisa dikonsumsi.
        
        ██╗     ███╗   ███╗ █████╗  ██████╗ 
        ██║     ████╗ ████║██╔══██╗██╔═══██╗
        ██║     ██╔████╔██║███████║██║   ██║
        ██║     ██║╚██╔╝██║██╔══██║██║   ██║
        ███████╗██║ ╚═╝ ██║██║  ██║╚██████╔╝
        ╚══════╝╚═╝     ╚═╝╚═╝  ╚═╝ ╚═════╝ 
                                    )" << endl;
        return;
    }
    // Inisialisasi
    while (true) {
        string slot;
        cout << "Pilih makanan dari penyimpanan" << std::endl;
        cout << endl;
        so.cetak_penyimpanan();
        cout << endl;

        // Input
        cout << "Slot: ";
        cin >> slot;
        Coordinate loc = location(slot);

        // Ambil slot kosong
        if (so.storage.is_empty(loc.row, loc.col) || loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= so.storage.get_rows() || loc.col < 0 || loc.col >= so.storage.get_cols()) {
            cout << endl;
            cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl << "Silahkan masukan slot yang berisi makanan."<< endl;
            continue;
        }

        // Ambil yang ga bisa dimakan/bukan produk
        else if (so.storage(loc.row, loc.col)->get_item_type() != ItemType::Product) {  
            cout << endl;
            cout << R"(Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!" << endl << "Silahkan masukan slot yang berisi makanan.)" << endl;
            continue;
        }

        // Ambil yang ga bisa dimakan/bukan consumable
        else if (!dynamic_cast<Product*>(so.storage(loc.row, loc.col))->is_consumable()) {
            cout << endl;
            cout << R"(Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!" << endl << "Silahkan masukan slot yang berisi makanan.)" << endl;
            continue;
        }
        // Valid
        else {
            Product* selected_consumable = dynamic_cast<Product*>(so.storage(loc.row, loc.col));
            p.weight += selected_consumable->get_added_weight();
            so.storage.soft_erase(loc.row, loc.col);
            cout << endl;
            cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl << "Alhasil, berat badan kamu naik menjadi" << p.weight <<endl;
            return;
        }
    }
}