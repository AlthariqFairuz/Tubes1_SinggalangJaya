#ifndef ASSETS_OWNER_MATRIX_HPP
#define ASSETS_OWNER_MATRIX_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using std::string;
using std::cout, std::endl;
using std::vector;

string format_int(int num, int desired_length);

class Coordinate {
    public:
    int row, col;
    Coordinate(int row, int col) : row(row), col(col) {}
};

template<typename T>
class Matrix {
    public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows);
        for (int i = 0; i < rows; ++i) {
            data[i].resize(cols);
        }
    }

    virtual T &operator()(int row, int col) {
        return data[row][col];
    }

    virtual const T &operator()(int row, int col) const {
        return data[row][col];
    }

    int get_rows() const { 
        return rows;
    }

    int get_cols() const {
        return cols;
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << ' ';
            }
            cout << '\n';
        }
        cout.flush();
    }

    static Coordinate location(string loc) {
        int row = loc[0] - 'A';
        int col = (loc[1] - '0') * 10 + (loc[2] - '0');
        return Coordinate(row, col);
    }

    protected:
    int rows;
    int cols;
    vector<vector<T>> data;
};


#endif