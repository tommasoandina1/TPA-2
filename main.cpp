#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    // Esempio di utilizzo con tipo double
    Matrix<double> A(2, 2);

    // Lettura della matrice dal terminale
    // cout << "Reading matrix from terminal:" << endl;
    // A.readFromTerminal();
    // A.Print();

    // Lettura della matrice da un file
    cout << "Lettura della matrice dal file:" << endl;
    A.readFromFile("Matrici.txt");
    A.Print();

    // Creazione di una matrice identità casuale
    Matrix<double> identity = Matrix<double>::random_identity_matrix();
    cout << "Matrice identità casuale:" << endl;
    identity.Print();

    Matrix<double> B(2, 2);
    B.Set_Matrix(0, 0, 1.0);
    B.Set_Matrix(0, 1, 2.0);
    B.Set_Matrix(1, 0, 3.0);
    B.Set_Matrix(1, 1, 4.0);

    Matrix<double> C = A.sum_matrix(B);
    cout << "Somma delle matrici A e B:" << endl;
    C.Print();

    Matrix<double> D = A.dot_matrix(B);
    cout << "Moltiplicazione delle matrici A e B:" << endl;
    D.Print();

    return 0;
}