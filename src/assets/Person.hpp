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


    virtual PersonType get_person_type() = 0;
};

#endif