#include "commands.hpp"
#include "exception.hpp"
#include "../assets/Product.hpp"

using std::cout;
using std::cin;
using std::endl;

void Command::makan(Person &p, StorageOwner &so) {
    if (!so.is_exist_specified_item(ItemType::Product)) {
        throw TidakAdaMakananException();
    }

    // Inisialisasi
    string slot;
    cout << "Pilih makanan dari penyimpanan" << std::endl;
    cout << endl;
    so.cetak_penyimpanan();
    cout << endl;

    // Input
    cout << "Slot: ";
    cin >> slot;
    Coordinate loc = location(slot);
    Product* product = dynamic_cast<Product*>(so.storage(loc.row, loc.col));
    if (!product) {
        cout << "Slot tidak valid" << endl;
        return;
    }

    // Validasi(true)
    if (so.storage(loc.row, loc.col)->get_item_type() == ItemType::Product && product->get_added_weight() > 0) {
        p.weight += product->get_added_weight();
        so.storage.soft_erase(loc.row, loc.col);
        cout << endl;
        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl << "Alhasil, berat badan kamu naik menjadi" << p.get_weight() <<endl;
        cout << R"(
                            ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣤⣤⣠⡄⡠⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⢀⠀⠀⠀⣀⣤⣾⣿⠿⠿⠛⠛⠛⠻⠿⠿⠿⠿⠿⠿⠿⠿⢿⣶⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⠗⣱⡧⣻⣾⣿⡿⠋⠁⣀⣤⠴⢀⠢⠐⠠⢀⠠⠀⡀⢀⠀⡀⠀⡀⠈⠉⠿⣷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⣿⣫⣾⢟⣽⣿⠟⠁⢀⡠⠞⠩⠀⡈⠀⠄⠂⡐⠀⢀⠂⠐⠂⠀⠀⠡⠄⣁⡈⠄⡀⠟⣿⣤⣄⢀⢦⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠠⢀⠠⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣟⣾⡿⣡⣿⠛⠁⢀⠀⣠⡴⠊⢀⠁⠀⠀⢠⠐⡠⠐⠀⡀⠂⠀⡀⠀⠀⠀⠀⠀⠑⠂⠠⠀⠙⣿⣮⣎⢾⣆⠀⠀⠀⠀⠀⠀⠀⠄⠂⢄⠀⠀
                ⠀⠀⠀⠀⠠⠁⠄⠂⠡⠀⠀⠀⠀⠀⣠⣬⣿⣷⣿⠏⡰⠟⠁⢀⢒⡴⡻⠋⠀⠀⡂⢨⠐⡌⢆⡣⡅⠀⠀⠀⠠⠁⠀⠄⠂⢀⠀⠀⠠⢀⠁⠐⠀⠘⢻⣿⣮⢿⣦⠀⠀⠀⠀⠠⠁⢌⠐⡀⠂⠀
                ⠀⠀⠀⠀⠀⠁⠂⠁⠂⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⡖⠁⠀⠐⣵⢯⡝⠤⢁⢀⣖⡡⢎⡳⣜⢣⡳⣝⢮⣐⠀⡀⠀⡁⠀⠌⠠⢈⠐⡀⠂⠌⡀⠀⡀⠈⢹⣿⣯⢿⣧⡀⠀⠀⠀⠁⠂⠄⠁⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣷⣿⣿⡿⠃⠀⠀⣤⡿⢯⣞⣼⠇⢢⣟⡬⡷⣭⢷⣎⠷⣭⢻⡷⣎⡳⢤⡁⠤⣁⢂⡁⢢⠘⢤⠉⠠⠘⡤⢐⠀⠀⠹⣿⣯⣿⡗⠀⠀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣾⢿⠟⠁⠀⢀⣾⢿⣹⢳⣞⡎⢠⣟⢮⣽⢷⢯⣟⣮⢟⣞⡯⢿⣳⡽⣣⢞⡴⡱⢎⡼⣡⢏⢮⡝⣆⠡⠜⣧⣚⡄⡀⣿⣿⣿⢻⣦⡀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣷⣿⠋⠀⢠⢀⢾⣯⢿⡱⣯⢾⢁⡾⣭⣟⡟⣎⡿⣽⣞⣯⢞⣯⠹⣯⣷⣛⡞⣶⡹⣏⡾⣵⡞⣧⢿⣻⣆⠡⢷⣻⣼⡰⢼⣿⣿⡿⣿⣿⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⡽⠁⢀⡰⡡⢮⣿⡽⣎⡷⡽⡏⣸⣽⢳⡟⡼⣸⣿⡿⣽⣞⢯⡏⢗⡬⢳⣯⣟⣼⡳⢯⡽⣞⡽⣯⢿⣽⣻⡄⢸⡷⣏⡷⢻⣿⢿⣟⣿⣿⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣿⠟⣡⣴⡞⢁⣞⣿⣷⣛⡾⣵⣻⢣⢿⡼⣿⣑⣱⠐⢿⣻⣷⣟⡞⣿⠀⠣⣣⠹⣾⢧⡟⣯⢳⣯⡽⣏⡿⢾⡽⣷⠀⣿⡽⣏⢿⣿⣻⣿⢾⣿⠀⠀⠀⢀⠀⠀⠀
                ⠀⠀⠀⠀⢀⢠⣾⣿⠿⣿⣽⢡⣿⣾⣿⢯⣿⢯⣿⣻⢷⡻⡽⢉⠄⠄⢃⠈⠌⣿⡈⣷⣏⡿⠀⢂⠐⡠⠟⢋⣿⣞⣳⡝⣾⣳⢯⣻⢾⡽⣿⡔⣯⣿⣹⣿⣳⣿⣟⣿⡇⢀⠂⡐⠠⠁⠀
                ⠀⠀⠀⠀⠀⠀⢀⡺⠟⢹⣿⣿⣿⢇⣾⣿⣟⣾⡿⣯⣿⣻⣽⢎⡷⣉⠆⠌⣈⠂⠱⠐⡘⡇⠸⣧⢽⠀⢂⠂⠔⡈⢄⠉⠿⣧⣻⢖⣯⣟⣧⠿⣽⣻⣷⢹⣾⡽⣾⡷⣿⣻⣿⡇⠀⠀⠀⠁⠀⠀
                ⠀⠀⠀⠀⠀⠀⠉⠀⠀⣾⣿⣾⡟⣼⣿⣟⣾⣿⢿⣿⣽⣟⡯⣾⣷⣴⣌⡰⠀⠎⡑⠢⠐⡠⢁⠹⣾⡔⠠⠉⡔⢈⠂⡌⢄⠙⢷⣏⡞⣽⣞⢿⣳⢯⢿⣟⣷⣏⡷⣟⣿⡷⣿⡇⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠄⠀⠀⢰⣿⣯⣿⣱⣿⣟⢾⣽⣿⣿⣯⣿⣾⣷⠣⢌⡉⢛⠻⣷⣬⣑⠦⡁⠐⡀⢂⠘⠃⠌⡐⢄⣊⡰⢐⣈⣦⣥⣿⣼⣚⣽⣻⣞⣽⣚⢿⣽⡞⣷⢻⣿⣟⣿⡇⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⣺⣿⢷⣧⣿⡿⣼⣫⣿⣿⣿⣽⣿⣽⣿⠠⢿⠿⠿⠿⢛⠛⡛⠓⠀⠡⠐⡀⢂⠁⠂⠌⣿⣴⣾⡿⢛⠛⢋⠍⡙⣷⣿⡷⣞⣧⣻⠾⣷⣟⢧⣿⣿⣞⣯⡗⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣞⣿⡿⣝⡗⡠⣿⣿⣿⣯⣿⣯⡿⡆⡇⢌⠡⡑⡈⠄⡁⠂⠡⢀⠡⢀⠂⡈⠄⠂⠄⠩⢙⠛⠿⢷⣾⡬⢱⣿⣿⣿⡽⣇⠸⣟⣿⣿⢞⣿⣾⢯⣿⣿⠀⠀⠀⠀⠀⠀
                ⠀⠀⠂⠀⠀⡀⠆⢰⣿⡿⣼⣿⣻⢧⡋⣕⣿⣿⣿⢿⣷⣿⡿⠋⡜⢠⠂⠄⠠⠐⠄⠁⢂⠀⠄⠡⠐⠀⡐⢈⠠⢁⠂⠜⡈⠆⡩⢐⣿⣿⣿⡾⠙⣿⡑⣻⣽⡿⣏⣷⡿⣯⣟⣿⠀⠐⡀⠆⠀⠀
                ⠀⠀⠀⠀⠐⠠⠈⣾⡿⣏⣿⢧⣟⣯⠰⢼⣿⣿⠃⣸⣿⣿⣧⡐⠘⢤⠌⠠⢁⠠⠀⢁⣠⣀⣂⣀⡄⢂⠀⡀⢂⠀⢂⠐⠠⢊⡱⢿⣿⣿⡴⡉⠠⢘⡱⡘⣷⣿⣯⢷⡿⡷⣿⣻⡀⠡⠐⡈⠄⠀
                ⠀⠀⠁⠀⠀⠁⠂⣿⣿⡽⣯⣟⣾⣍⠣⣾⡿⠁⢎⠻⣿⣾⡇⠳⢦⣈⣂⡁⢂⠠⠐⠀⠱⣏⡭⣛⣜⡟⠀⡀⠂⡐⠠⢈⣁⠞⢀⣾⣿⡿⢡⢎⡐⠀⡷⢡⢻⣽⡿⣞⣿⡽⣟⣿⡀⠠⠁⠐⠀⠀
                ⠀⠀⠀⠀⠀⠀⢸⣿⣳⢽⣳⢯⣟⠡⢣⡏⡀⢎⡍⠀⢿⣿⡇⠀⠈⠙⠻⢿⣿⣿⣿⣿⣶⠈⠑⠚⠁⠀⠠⢀⢡⣠⣵⣊⣁⠀⣜⣿⡿⠁⠈⢖⡸⡄⢸⢡⠺⣿⡽⣳⣯⣟⡿⣽⡇⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⣸⡿⣹⠞⠛⢟⠁⠀⠿⢀⣍⡺⠀⠀⠘⣿⡇⠀⠀⠀⠀⠈⢩⠛⢟⣻⢫⣀⠂⢠⣈⣤⢓⢞⣻⠀⠀⠀⠀⠀⣸⡟⠁⠀⠀⠘⣥⡚⡀⠇⠄⢺⡛⠇⣿⡞⣻⢯⣇⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⣼⡏⡉⠵⢀⢣⠣⢌⢂⠔⢠⢢⡡⡀⠀⠀⢹⡇⠀⠀⠀⠀⣠⣂⠻⣷⢅⡺⢴⣉⢳⠴⣚⢵⡛⠥⡠⡀⠀⠀⠀⡽⠁⠀⠀⠀⣀⢥⡲⠀⢌⠨⢔⡸⡐⠨⣍⠩⣟⢿⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⢀⡏⣷⡙⡌⢆⠣⠜⡰⢈⠐⢢⠣⡜⣾⠶⣄⠀⠇⠀⠀⣰⡿⡴⢡⠣⢍⡲⣑⡎⣟⢵⡇⢎⡲⢉⣎⠱⢸⣷⡀⠀⠀⠀⢀⡤⣾⢟⡱⢌⡱⢈⢒⠢⡡⢓⡔⡨⢣⡟⣸⡀⠀⠀⠀⠀
                ⠀⠀⠀⢀⣾⣿⣌⠷⣎⢡⠣⡑⠤⠁⡐⢈⡱⡘⢼⣿⣮⡳⣄⠈⠡⣼⡳⣇⠢⢉⠆⡱⣬⠻⣍⢏⡻⡜⣰⡿⠝⡦⣞⣿⡄⠂⣡⡴⢻⣼⣿⡎⠴⡁⠀⡀⠢⠑⣘⠢⣡⡵⢟⣼⣿⣇⠀⡀⠀⠀
                ⠀⠀⠀⣼⣿⣿⣿⣿⣾⣝⡶⣥⣀⢂⡔⢢⠥⣩⣿⣿⣿⣿⣎⢳⣸⡟⠴⣻⣎⣂⣬⢗⣿⢽⡸⣎⣽⠿⣬⣑⣻⣼⠳⡜⣿⣠⢏⣼⣿⣿⣿⣯⣵⠑⣆⠰⣀⣥⠶⣛⣽⣾⣿⣿⣿⣿⡆⢐⠀⠀
                ⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣷⣯⣟⡾⣧⣾⣿⣿⣿⣿⣿⣿⣧⢿⡜⣣⠝⡭⢛⡬⢏⡼⡷⡹⣜⡷⣙⠮⡹⢡⢻⠹⣔⢸⣧⣾⣿⣿⣿⣿⣿⣷⣯⢶⣻⣽⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠈⠀
                ⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣯⣿⣝⣯⣝⣎⣹⠞⡱⢣⠏⠴⠩⡞⣍⢶⡟⣵⣚⣿⢡⠓⡅⢋⠶⣉⠶⡙⢧⣯⣹⣹⣏⣿⣽⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀
                ⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢳⡿⣘⡕⢣⠎⠰⠁⠓⠌⢺⣟⠶⡽⣾⢁⠣⠘⢌⢪⡑⢎⡅⢎⣷⢛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀
                ⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢫⢜⣻⢳⡐⢎⠡⢈⠂⠡⢈⠂⢹⣾⡹⣝⣿⠀⠄⢃⡐⢢⡉⣎⡔⠃⢻⣧⡘⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧
                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠘⣇⣾⣟⠢⡜⢢⠑⣀⠊⡐⢄⠊⣼⣷⡹⢯⣾⠅⠌⢖⣠⣦⣤⣤⣼⢂⠙⣿⣌⡳⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⢻⣽⢪⠱⢎⠦⣨⢀⡜⣰⢃⠂⣿⢶⣹⡟⣼⡁⢎⠤⣡⢂⢦⣉⢯⠲⡈⢼⣷⠇⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⣾⣏⠧⣹⢮⣟⣶⣫⣼⣳⢎⣳⣟⣾⢣⢿⣹⡗⣎⢾⣱⢯⡶⣯⣟⡷⡌⣒⢾⡇⠐⡀⠂⠄⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
                )";
        return;
    }

    // Validasi(false)
    else {
        bool valid = false;
        while (!valid) {
            if (so.storage.is_empty(loc.row, loc.col) || loc == Coordinate(-1, -1) || loc.row < 0 || loc.row >= so.storage.get_rows() || loc.col < 0 || loc.col >= so.storage.get_cols()) {
                cout << endl;
                cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl << "Silahkan masukan slot yang berisi makanan."<< endl;
                cout << "Slot: ";
                cin >> slot;
                loc = location(slot);
            }
            else if (so.storage(loc.row, loc.col)->get_item_type() != ItemType::Product || product->get_added_weight() < 1) {  
                cout << endl;
                cout << R"(Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!" << endl << "Silahkan masukan slot yang berisi makanan.)" << endl;
                cout << "Slot: ";
                cin >> slot;
                loc = location(slot);
            }
            else {
                valid = true;
                p.weight += product->get_added_weight();
                so.storage.soft_erase(loc.row, loc.col);
                cout << endl;
                cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl << "Alhasil, berat badan kamu naik menjadi" << p.get_weight() <<endl;
                cout << R"(
                            ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣤⣤⣠⡄⡠⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⢀⠀⠀⠀⣀⣤⣾⣿⠿⠿⠛⠛⠛⠻⠿⠿⠿⠿⠿⠿⠿⠿⢿⣶⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⠗⣱⡧⣻⣾⣿⡿⠋⠁⣀⣤⠴⢀⠢⠐⠠⢀⠠⠀⡀⢀⠀⡀⠀⡀⠈⠉⠿⣷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⣿⣫⣾⢟⣽⣿⠟⠁⢀⡠⠞⠩⠀⡈⠀⠄⠂⡐⠀⢀⠂⠐⠂⠀⠀⠡⠄⣁⡈⠄⡀⠟⣿⣤⣄⢀⢦⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠠⢀⠠⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣟⣾⡿⣡⣿⠛⠁⢀⠀⣠⡴⠊⢀⠁⠀⠀⢠⠐⡠⠐⠀⡀⠂⠀⡀⠀⠀⠀⠀⠀⠑⠂⠠⠀⠙⣿⣮⣎⢾⣆⠀⠀⠀⠀⠀⠀⠀⠄⠂⢄⠀⠀
                ⠀⠀⠀⠀⠠⠁⠄⠂⠡⠀⠀⠀⠀⠀⣠⣬⣿⣷⣿⠏⡰⠟⠁⢀⢒⡴⡻⠋⠀⠀⡂⢨⠐⡌⢆⡣⡅⠀⠀⠀⠠⠁⠀⠄⠂⢀⠀⠀⠠⢀⠁⠐⠀⠘⢻⣿⣮⢿⣦⠀⠀⠀⠀⠠⠁⢌⠐⡀⠂⠀
                ⠀⠀⠀⠀⠀⠁⠂⠁⠂⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⡖⠁⠀⠐⣵⢯⡝⠤⢁⢀⣖⡡⢎⡳⣜⢣⡳⣝⢮⣐⠀⡀⠀⡁⠀⠌⠠⢈⠐⡀⠂⠌⡀⠀⡀⠈⢹⣿⣯⢿⣧⡀⠀⠀⠀⠁⠂⠄⠁⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣷⣿⣿⡿⠃⠀⠀⣤⡿⢯⣞⣼⠇⢢⣟⡬⡷⣭⢷⣎⠷⣭⢻⡷⣎⡳⢤⡁⠤⣁⢂⡁⢢⠘⢤⠉⠠⠘⡤⢐⠀⠀⠹⣿⣯⣿⡗⠀⠀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣾⢿⠟⠁⠀⢀⣾⢿⣹⢳⣞⡎⢠⣟⢮⣽⢷⢯⣟⣮⢟⣞⡯⢿⣳⡽⣣⢞⡴⡱⢎⡼⣡⢏⢮⡝⣆⠡⠜⣧⣚⡄⡀⣿⣿⣿⢻⣦⡀⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣷⣿⠋⠀⢠⢀⢾⣯⢿⡱⣯⢾⢁⡾⣭⣟⡟⣎⡿⣽⣞⣯⢞⣯⠹⣯⣷⣛⡞⣶⡹⣏⡾⣵⡞⣧⢿⣻⣆⠡⢷⣻⣼⡰⢼⣿⣿⡿⣿⣿⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⡽⠁⢀⡰⡡⢮⣿⡽⣎⡷⡽⡏⣸⣽⢳⡟⡼⣸⣿⡿⣽⣞⢯⡏⢗⡬⢳⣯⣟⣼⡳⢯⡽⣞⡽⣯⢿⣽⣻⡄⢸⡷⣏⡷⢻⣿⢿⣟⣿⣿⠀⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣿⠟⣡⣴⡞⢁⣞⣿⣷⣛⡾⣵⣻⢣⢿⡼⣿⣑⣱⠐⢿⣻⣷⣟⡞⣿⠀⠣⣣⠹⣾⢧⡟⣯⢳⣯⡽⣏⡿⢾⡽⣷⠀⣿⡽⣏⢿⣿⣻⣿⢾⣿⠀⠀⠀⢀⠀⠀⠀
                ⠀⠀⠀⠀⢀⢠⣾⣿⠿⣿⣽⢡⣿⣾⣿⢯⣿⢯⣿⣻⢷⡻⡽⢉⠄⠄⢃⠈⠌⣿⡈⣷⣏⡿⠀⢂⠐⡠⠟⢋⣿⣞⣳⡝⣾⣳⢯⣻⢾⡽⣿⡔⣯⣿⣹⣿⣳⣿⣟⣿⡇⢀⠂⡐⠠⠁⠀
                ⠀⠀⠀⠀⠀⠀⢀⡺⠟⢹⣿⣿⣿⢇⣾⣿⣟⣾⡿⣯⣿⣻⣽⢎⡷⣉⠆⠌⣈⠂⠱⠐⡘⡇⠸⣧⢽⠀⢂⠂⠔⡈⢄⠉⠿⣧⣻⢖⣯⣟⣧⠿⣽⣻⣷⢹⣾⡽⣾⡷⣿⣻⣿⡇⠀⠀⠀⠁⠀⠀
                ⠀⠀⠀⠀⠀⠀⠉⠀⠀⣾⣿⣾⡟⣼⣿⣟⣾⣿⢿⣿⣽⣟⡯⣾⣷⣴⣌⡰⠀⠎⡑⠢⠐⡠⢁⠹⣾⡔⠠⠉⡔⢈⠂⡌⢄⠙⢷⣏⡞⣽⣞⢿⣳⢯⢿⣟⣷⣏⡷⣟⣿⡷⣿⡇⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠄⠀⠀⢰⣿⣯⣿⣱⣿⣟⢾⣽⣿⣿⣯⣿⣾⣷⠣⢌⡉⢛⠻⣷⣬⣑⠦⡁⠐⡀⢂⠘⠃⠌⡐⢄⣊⡰⢐⣈⣦⣥⣿⣼⣚⣽⣻⣞⣽⣚⢿⣽⡞⣷⢻⣿⣟⣿⡇⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⣺⣿⢷⣧⣿⡿⣼⣫⣿⣿⣿⣽⣿⣽⣿⠠⢿⠿⠿⠿⢛⠛⡛⠓⠀⠡⠐⡀⢂⠁⠂⠌⣿⣴⣾⡿⢛⠛⢋⠍⡙⣷⣿⡷⣞⣧⣻⠾⣷⣟⢧⣿⣿⣞⣯⡗⠀⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣞⣿⡿⣝⡗⡠⣿⣿⣿⣯⣿⣯⡿⡆⡇⢌⠡⡑⡈⠄⡁⠂⠡⢀⠡⢀⠂⡈⠄⠂⠄⠩⢙⠛⠿⢷⣾⡬⢱⣿⣿⣿⡽⣇⠸⣟⣿⣿⢞⣿⣾⢯⣿⣿⠀⠀⠀⠀⠀⠀
                ⠀⠀⠂⠀⠀⡀⠆⢰⣿⡿⣼⣿⣻⢧⡋⣕⣿⣿⣿⢿⣷⣿⡿⠋⡜⢠⠂⠄⠠⠐⠄⠁⢂⠀⠄⠡⠐⠀⡐⢈⠠⢁⠂⠜⡈⠆⡩⢐⣿⣿⣿⡾⠙⣿⡑⣻⣽⡿⣏⣷⡿⣯⣟⣿⠀⠐⡀⠆⠀⠀
                ⠀⠀⠀⠀⠐⠠⠈⣾⡿⣏⣿⢧⣟⣯⠰⢼⣿⣿⠃⣸⣿⣿⣧⡐⠘⢤⠌⠠⢁⠠⠀⢁⣠⣀⣂⣀⡄⢂⠀⡀⢂⠀⢂⠐⠠⢊⡱⢿⣿⣿⡴⡉⠠⢘⡱⡘⣷⣿⣯⢷⡿⡷⣿⣻⡀⠡⠐⡈⠄⠀
                ⠀⠀⠁⠀⠀⠁⠂⣿⣿⡽⣯⣟⣾⣍⠣⣾⡿⠁⢎⠻⣿⣾⡇⠳⢦⣈⣂⡁⢂⠠⠐⠀⠱⣏⡭⣛⣜⡟⠀⡀⠂⡐⠠⢈⣁⠞⢀⣾⣿⡿⢡⢎⡐⠀⡷⢡⢻⣽⡿⣞⣿⡽⣟⣿⡀⠠⠁⠐⠀⠀
                ⠀⠀⠀⠀⠀⠀⢸⣿⣳⢽⣳⢯⣟⠡⢣⡏⡀⢎⡍⠀⢿⣿⡇⠀⠈⠙⠻⢿⣿⣿⣿⣿⣶⠈⠑⠚⠁⠀⠠⢀⢡⣠⣵⣊⣁⠀⣜⣿⡿⠁⠈⢖⡸⡄⢸⢡⠺⣿⡽⣳⣯⣟⡿⣽⡇⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⠀⣸⡿⣹⠞⠛⢟⠁⠀⠿⢀⣍⡺⠀⠀⠘⣿⡇⠀⠀⠀⠀⠈⢩⠛⢟⣻⢫⣀⠂⢠⣈⣤⢓⢞⣻⠀⠀⠀⠀⠀⣸⡟⠁⠀⠀⠘⣥⡚⡀⠇⠄⢺⡛⠇⣿⡞⣻⢯⣇⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⠀⣼⡏⡉⠵⢀⢣⠣⢌⢂⠔⢠⢢⡡⡀⠀⠀⢹⡇⠀⠀⠀⠀⣠⣂⠻⣷⢅⡺⢴⣉⢳⠴⣚⢵⡛⠥⡠⡀⠀⠀⠀⡽⠁⠀⠀⠀⣀⢥⡲⠀⢌⠨⢔⡸⡐⠨⣍⠩⣟⢿⠀⠀⠀⠀⠀
                ⠀⠀⠀⠀⢀⡏⣷⡙⡌⢆⠣⠜⡰⢈⠐⢢⠣⡜⣾⠶⣄⠀⠇⠀⠀⣰⡿⡴⢡⠣⢍⡲⣑⡎⣟⢵⡇⢎⡲⢉⣎⠱⢸⣷⡀⠀⠀⠀⢀⡤⣾⢟⡱⢌⡱⢈⢒⠢⡡⢓⡔⡨⢣⡟⣸⡀⠀⠀⠀⠀
                ⠀⠀⠀⢀⣾⣿⣌⠷⣎⢡⠣⡑⠤⠁⡐⢈⡱⡘⢼⣿⣮⡳⣄⠈⠡⣼⡳⣇⠢⢉⠆⡱⣬⠻⣍⢏⡻⡜⣰⡿⠝⡦⣞⣿⡄⠂⣡⡴⢻⣼⣿⡎⠴⡁⠀⡀⠢⠑⣘⠢⣡⡵⢟⣼⣿⣇⠀⡀⠀⠀
                ⠀⠀⠀⣼⣿⣿⣿⣿⣾⣝⡶⣥⣀⢂⡔⢢⠥⣩⣿⣿⣿⣿⣎⢳⣸⡟⠴⣻⣎⣂⣬⢗⣿⢽⡸⣎⣽⠿⣬⣑⣻⣼⠳⡜⣿⣠⢏⣼⣿⣿⣿⣯⣵⠑⣆⠰⣀⣥⠶⣛⣽⣾⣿⣿⣿⣿⡆⢐⠀⠀
                ⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣷⣯⣟⡾⣧⣾⣿⣿⣿⣿⣿⣿⣧⢿⡜⣣⠝⡭⢛⡬⢏⡼⡷⡹⣜⡷⣙⠮⡹⢡⢻⠹⣔⢸⣧⣾⣿⣿⣿⣿⣿⣷⣯⢶⣻⣽⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠈⠀
                ⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣯⣿⣝⣯⣝⣎⣹⠞⡱⢣⠏⠴⠩⡞⣍⢶⡟⣵⣚⣿⢡⠓⡅⢋⠶⣉⠶⡙⢧⣯⣹⣹⣏⣿⣽⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀
                ⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢳⡿⣘⡕⢣⠎⠰⠁⠓⠌⢺⣟⠶⡽⣾⢁⠣⠘⢌⢪⡑⢎⡅⢎⣷⢛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀
                ⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢫⢜⣻⢳⡐⢎⠡⢈⠂⠡⢈⠂⢹⣾⡹⣝⣿⠀⠄⢃⡐⢢⡉⣎⡔⠃⢻⣧⡘⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧
                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠘⣇⣾⣟⠢⡜⢢⠑⣀⠊⡐⢄⠊⣼⣷⡹⢯⣾⠅⠌⢖⣠⣦⣤⣤⣼⢂⠙⣿⣌⡳⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⢻⣽⢪⠱⢎⠦⣨⢀⡜⣰⢃⠂⣿⢶⣹⡟⣼⡁⢎⠤⣡⢂⢦⣉⢯⠲⡈⢼⣷⠇⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⣾⣏⠧⣹⢮⣟⣶⣫⣼⣳⢎⣳⣟⣾⢣⢿⣹⡗⣎⢾⣱⢯⡶⣯⣟⡷⡌⣒⢾⡇⠐⡀⠂⠄⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
                )";
                return;
            }
        }
    }
}