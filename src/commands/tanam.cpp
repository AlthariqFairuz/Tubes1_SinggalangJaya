#include "commands.hpp"

void Command::tanam(StorageOwner &so, CroplandOwner &co) {    
    if (!so.is_exist_specified_item(ItemType::Plant)) {
        cout << "Tidak ada tanaman di penyimpanan" << endl;
        return;
    }
    if (co.land.is_full()) {
        cout << "Ladang pertanian penuh" << endl;
        return;
    }

    cout << "Pilih tanaman dari penyimpanan" << endl;
    auto src = so.query_specific_item(ItemType::Plant);
    auto selected_plant = dynamic_cast<Plant*>(so.storage(src.row, src.col));
    cout << "Kamu memilih " << selected_plant->get_name() << "." << endl;

    cout << "Pilih petak tanah yang akan ditanami" << endl;
    auto dst = co.query_empty_slot();

    so.storage.soft_erase(src.row, src.col);
    co.set_at(dst.row, dst.col, selected_plant);

    cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
    cout << selected_plant->get_name() << " berhasil ditanam!" << endl;
}