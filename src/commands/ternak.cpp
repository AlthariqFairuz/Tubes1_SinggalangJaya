#include "commands.hpp"

void Command::ternak(StorageOwner &so, PastureOwner &po) {
    if (!so.is_exist_specified_item(ItemType::Animal)) {
        cout << "Tidak ada hewan di penyimpanan" << endl;
        return;
    }
    if (po.land.is_full()) {
        cout << "Ladang peternakan penuh" << endl;
        return;
    }

    cout << "Pilih hewan dari penyimpanan" << endl;
    auto src = so.query_specific_item(ItemType::Animal);
    auto selected_animal = dynamic_cast<Animal*>(so.storage(src.row, src.col));
    cout << "Kamu memilih " << selected_animal->get_name() << "." << endl;

    cout << "Pilih petak tanah yang akan ditempati hewan" << endl;
    auto dst = po.query_empty_slot();

    so.storage.soft_erase(src.row, src.col);
    po.set_at(dst.row, dst.col, selected_animal);

    cout << "Dengan hati-hati, kamu meletakkan seekor " << selected_animal->get_name() << " di kandang." << endl;
    cout << selected_animal->get_name() << " telah menjadi peliharaan sekarang!" << endl;
}