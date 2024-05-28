#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Matrix {
private:
    int rows, columns;
    std::vector<std::vector<T> > data;

public:
    // Costruttore
    Matrix(int rows, int columns);

    void Set_Matrix(int row, int column, T x);
    T Get_Value(int row, int column) const;
    void Print() const;
    void readFromTerminal();
    void readFromFile(const std::string& filename);
    
    static Matrix random_identity_matrix();

    Matrix sum_matrix(const Matrix& other) const;
    Matrix dot_matrix(const Matrix& other) const;
    Matrix transpose() const;
};


#endif 
