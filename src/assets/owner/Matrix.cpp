#include "Matrix.hpp"

string self_format_int(int num, int desired_length) {
    std::stringstream ss;
    ss << std::setw(desired_length) << std::setfill('0') << num;
    return ss.str();
}