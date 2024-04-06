#include "pcolor.hpp"

#include <iostream>

using std::cout;

void print_red(const string &text, bool newline) {
    cout << RED << text << NORMAL;
    if (newline) cout << '\n';
}
void print_green(const string &text, bool newline) {
    cout << GREEN << text << NORMAL;
    if (newline) cout << '\n';
}
void print_blue(const string &text, bool newline) {
    cout << BLUE << text << NORMAL;
    if (newline) cout << '\n';
}

void print_normal(const string &text, bool newline) {
    cout << text;
    if (newline) cout << '\n';
}
