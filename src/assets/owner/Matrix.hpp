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

string self_format_int(int num, int desired_length);

template<typename T>
class Matrix {
    public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows);
        for (int i = 0; i < rows; ++i) {
            data[i].resize(cols);
        }
    }

    T &operator()(int row, int col) {
        return data[row][col];
    }

    const T &operator()(int row, int col) const {
        return data[row][col];
    }

    T &operator[](const std::pair<int, int> &index) {
        return data[index.first][index.second];
    }

    const T &operator[](const std::pair<int, int> &index) const {
        return data[index.first][index.second];
    }

    int get_rows() const { 
        return rows;
    }

    int get_cols() const {
        return cols;
    }

    void print() {
        cout << "   ";
        for (int i = 0; i < cols; ++i) {
            cout << "   " << (char)('A' + i) << "  ";
        }
        cout << '\n';
        cout << "   ";
        for (int i = 0; i < cols; ++i) {
            cout << "+-----";
        }
        cout << "+\n";
        for (int i = 0; i < rows; ++i) {
            cout << self_format_int(i, 2) << " ";
            for (int j = 0; j < cols; ++j) {
                auto entry = data[i][j];
                string entry_string;
                if (entry == T()) entry_string = "   ";
                else entry_string = string(entry);
                cout << "| " << entry_string << " ";
            }
            cout << "|\n   ";
            for (int i = 0; i < cols; ++i) {
                cout << "+-----";
            }
            cout << "+\n";
        }
        cout.flush();
    }

    private:
    int rows;
    int cols;
    vector<vector<string>> data;
};


#endif