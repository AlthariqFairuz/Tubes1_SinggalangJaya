#ifndef ASSETS_PERSON_HPP
#define ASSETS_PERSON_HPP

#include <string>

using std::string;

enum class PersonType {
    Petani,
    Peternak,
    Walikota,
};

class Person {
    public:
    string username;
    int gold;
    int weight;

    Person(string username, int gold, int weight) :
    username(username), gold(gold), weight(weight) {}
    
    virtual string get_username() const = 0;
    virtual int get_gold() const = 0;
    virtual int get_weight() const = 0;
    virtual PersonType get_person_type() = 0;
    virtual string get_role() const = 0;

    
    virtual int calculate_tax() = 0;
};

#endif