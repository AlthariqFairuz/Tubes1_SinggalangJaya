#ifndef ASSETS_OWNER_MATRIX_HPP
#define ASSETS_OWNER_MATRIX_HPP

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template <typename T>
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
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << ' ';
            }
            cout << '\n';
        }
        cout.flush();
    }

    private:
    int rows;
    int cols;
    vector<vector<T>> data;
};

#endif