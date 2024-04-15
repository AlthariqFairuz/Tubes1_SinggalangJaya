#ifndef ASSETS_OWNER_PASTURE_OWNER_HPP
#define ASSETS_OWNER_PASTURE_OWNER_HPP

#include "../Animal.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Matrix.hpp"
#include "../../utils/pcolor.hpp"

using std::cout, std::endl;
using std::string;
using std::vector;

class MatrixAnimal : public Matrix<Animal *>
{
public:
    MatrixAnimal(int rows, int cols) : Matrix<Animal *>(rows, cols)
    {
    }
    ~MatrixAnimal()
    {
    }

    void print() const
    {
        cout << "   ";
        for (int i = 0; i < cols; ++i)
        {
            cout << "   " << (char)('A' + i) << "  ";
        }
        cout << '\n';
        cout << "   ";
        for (int i = 0; i < cols; ++i)
        {
            cout << "+-----";
        }
        cout << "+\n";
        for (int i = 0; i < rows; ++i)
        {
            std::stringstream ss;
            ss << std::setw(2) << std::setfill('0') << i;
            cout << ss.str() << " ";

            for (int j = 0; j < cols; ++j)
            {
                auto entry = data[i][j];
                string entry_string;
                if (entry == 0)
                    entry_string = "   ";
                else
                    entry_string = entry->code;

                cout << "| ";
                if (entry != 0 && entry->ready_to_harvest())
                {
                    print_green(entry_string);
                }
                else
                {
                    print_red(entry_string);
                }
                cout << " ";
            }
            cout << "|\n   ";
            for (int i = 0; i < cols; ++i)
            {
                cout << "+-----";
            }
            cout << "+\n";
        }
        cout.flush();
    }
};

class PastureOwner
{
public:
    PastureOwner(int rows, int cols);

    PastureOwner(const PastureOwner &other);

    void set_at(int row, int col, Animal *animal);

    Coordinate query_animal();

    Coordinate query_empty_slot();

    Coordinate query_specified_animal(string _code);

    void cetak_peternakan() const;

    MatrixAnimal land;
    // private:
    // MatrixAnimal land;
};

#endif