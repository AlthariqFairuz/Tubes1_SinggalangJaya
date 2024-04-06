#ifndef UTILS_PCOLOR_HPP
#define UTILS_PCOLOR_HPP

#include <ostream>
#include <string>

using std::ostream;
using std::string;

constexpr const char NORMAL[] = "\x1B[0m";
constexpr const char RED[] = "\x1B[31m";
constexpr const char GREEN[] = "\x1B[32m";
constexpr const char BLUE[] = "\x1B[34m";

void print_red(const string &text, bool newline=false);
void print_green(const string &text, bool newline=false);
void print_blue(const string &text, bool newline=false);
void print_normal(const string &text, bool newline=false);


#endif