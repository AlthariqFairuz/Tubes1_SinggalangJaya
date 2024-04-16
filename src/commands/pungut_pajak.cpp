#include "commands.hpp"
#include "../Game.hpp"
#include "../abstracts/Taxable.hpp"
#include <map>
#include <tuple>

using std::cout;
using std::get;
using std::tuple;


void Command::pungut_pajak(Mayor &m) {
    cout << "Cring cring cring...\n";
    cout << "Pajak sudah dipungut!";
    
    set<tuple<int, string, string>> daftar;
    
    int total = 0;
    for (auto i = Game::players.begin(); i != Game::players.end(); ++i){
        auto person =  dynamic_cast<Person*>(*i);
        if (person->get_person_type() != PersonType::Walikota){
            int kkp_taxed = person->calculate_tax();
            daftar.insert({kkp_taxed, person->username, person->get_role()});
            m.gold += kkp_taxed;
            total += kkp_taxed;
        }
    }
    cout << "Berikut adalah detil dari pemungutan pajak:\n";
    int j = 1;
    for (auto i = daftar.begin(); i != daftar.end(); i++){
        cout << "   " << j<< "." << get<1>(*i) << " - " << get<2>(*i) << ": " << get<0>(*i)<<endl;
        j++;
    }

    cout << "Negara mendapatkan pemasukan sebesar " << total << " gulden" << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!"<<endl;
    cout << "BTW, mcLaren mu warna apa bosss"<<endl;
}
