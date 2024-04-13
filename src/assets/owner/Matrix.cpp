#include "Matrix.hpp"

bool Coordinate::operator==(const Coordinate &other) {
    return row == other.row && col == other.col;
}

Coordinate location(string loc) {
    if (loc.size() != 3) return Coordinate(-1, -1);
    int col = loc[0] - 'A';
    int row = (loc[1] - '0') * 10 + (loc[2] - '0');
    return Coordinate(row, col);
}