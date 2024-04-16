#ifndef ASSETS_OWNER_MATRIX_HPP
#define ASSETS_OWNER_MATRIX_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cassert>

using std::string;
using std::cout, std::endl;
using std::vector;

template<typename T>
class Matrix {
    public:
    Matrix(int _rows, int _cols) : rows(_rows), cols(_cols) {
        data.resize(rows);
        for (int i = 0; i < rows; ++i) {
            data[i].resize(cols);
        }
    }
    virtual ~Matrix() {

    }

    T &operator()(int row, int col) {
        return data[row][col];
    }

    const T &operator()(int row, int col) const {
        return data[row][col];
    }

    void set_at(int row, int col, T value) {
        data[row][col] = value;
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
    
    protected:
    int rows;
    int cols;
    vector<vector<T>> data;
};


template<typename T>
class Matrix<T*> {
    public:
    Matrix(int _rows, int _cols) : rows(_rows), cols(_cols) {
        data.resize(rows);
        for (int i = 0; i < rows; ++i) {
            data[i].resize(cols);
        }

        for (int i = 0; i < rows; ++i) {
            for (int j  = 0; j < cols; ++j) {
                data[i][j] = 0;                
            }
        }
    }
    virtual ~Matrix() {
        // for (int i = 0; i < rows; ++i) {
        //     for (int j = 0; j < cols; ++j) {
        //         if (data[i][j] != 0) {
        //             delete data[i][j];
        //             data[i][j] = 0;
        //         }
        //     }
        // }
    }
    int get_rows() {
        return rows;
    }

    int get_cols() {
        return cols;
    }
    
    T* &operator()(int row, int col) {
        return data[row][col];
    }

    const T* &operator()(int row, int col) const {
        return data[row][col];
    }

    void set_at(int row, int col, T* value) {
        if (data[row][col] != 0) {
            delete data[row][col];
        }
        data[row][col] = value;
    }

    void set(T* value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] == 0) {
                    data[i][j] = value;
                    return;
                }
            }
        }
        assert(false);
    }

    bool is_empty(int row, int col) {
        return data[row][col] == 0;
    }

    bool is_empty_matrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    bool is_full() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    
    void soft_erase(int row, int col) {
        if (data[row][col] != 0) {
            data[row][col] = 0;
        }
    }

    void hard_erase(int row, int col) {
        if (data[row][col] != 0) {
            delete data[row][col];
            data[row][col] = 0;
        }
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
    
    protected:
    int rows;
    int cols;
    vector<vector<T*>> data;
};

class Coordinate {
    public:
    int row, col;
    Coordinate() {}
    Coordinate(int row, int col) : row(row), col(col) {}
    Coordinate(const Coordinate &other) : row(other.row), col(other.col) {}
    
    bool operator==(const Coordinate &other);
};

Coordinate location(string loc);

#endif