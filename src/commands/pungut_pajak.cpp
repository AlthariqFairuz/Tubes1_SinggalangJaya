#include "commands.hpp"
#include "../abstracts/Taxable.hpp"
#include <map>

using std::cout;
using std::get;

void Command::pungut_pajak(Mayor &m, set<GameLogic*, CompareUsername> &game) {
    cout << "Cring cring cring...\n";
    cout << "Pajak sudah dipungut!";
    
    set<std::tuple<int,string,string>> daftar;
    int total = 0;
    for (auto i = game.begin();i!=game.end();i++){
        auto person =  dynamic_cast<Person*>(*i);
        if (person->get_person_type() != PersonType::Walikota){
            int kkp_taxed = person->calculate_tax();
            PersonType temp = person->get_person_type();
            string type;
            if (temp == PersonType::Petani){
                type = "Petani";
            } else if (temp == PersonType::Peternak){
                type = "Peternak";
            }
            daftar.insert({kkp_taxed,person->username,type});
            m.gold+=kkp_taxed;
            total += kkp_taxed;
        }
    }
    cout << "Berikut adalah detil dari pemungutan pajak:\n";
    int j = 1;
    for (auto i = daftar.begin(); i != daftar.end(); i++){
        cout << "   " << j<< "." << get<1>(*i) << " - " << get<2>(*i) << ": " << get<0>(*i)<<endl;
        j++;
    }

    cout << "Negara mendapatkan pemasukan sebesar " << total << "gulden"<<endl;
    cout <<"Gunakan dengan baik dan jangan dikorupsi ya!"<<endl;
    cout << "BTW, mcLaren mu warna apa bosss"<<endl;
}

