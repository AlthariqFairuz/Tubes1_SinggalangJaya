#ifndef ASSETS_PERSON_HPP
#define ASSETS_PERSON_HPP

#include <string>

using std::string;

class Person {
    public:
    string username;
    int gold;
    int weight;

    Person(string username, int gold, int weight) :
    username(username), gold(gold), weight(weight) {}

};

#endif