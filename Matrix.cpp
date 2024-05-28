#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
template <typename T>

class Matrix{
    private:
    int rows, columns;
    vector<vector<T> > data;

    public:
     // Costruttore
    Matrix(int rows, int columns) : rows(rows), columns(columns) {
        data.resize(rows, vector<T>(columns, 0));
        }

    void Set_Matrix(int row, int column, T x){
        if (row >= 0 && row < rows && column >= 0 && column < columns) {
        data[row][column] = x;
        } else{
            cout << "errore";
        }
    }     
    int Get_Value(int row, int column){
        double x = data[row][column];
        return T();
    }

    void Print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }


        void readFromTerminal() {
        cout << "Enter the elements of the matrix row by row:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cin >> data[i][j];
            }
        }
    }

    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Unable to open file" << endl;
            return;
        }

        string line;
        int row = 0;
        while (getline(file, line) && row < rows) {
            stringstream ss(line);
            for (int col = 0; col < columns; ++col) {
                ss >> data[row][col];
            }
            row++;
        }

        if (row < rows) {
            cerr << "File contains less data than expected" << endl;
        }

        file.close();
    } 
    static Matrix random_identity_matrix() {
        srand(time(0));
        int x = rand() % 100 + 1; // Numero casuale tra 1 e 100
        Matrix identity(x, x);
        for (int i = 0; i < x; ++i) {
            identity.data[i][i] = 1.0;
        }
        return identity;
    }

    Matrix sum_matrix(const Matrix& other) const{
        if(rows != other.rows || columns != other.columns)
            cout << "Le dimensioni delle matrici non corrispondono per la somma"<<endl;
        
        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
            result.data[i][j] = data[i][j] + other.data[i][j]; 
            }
        }
        return  result;
    }
    
    Matrix dot_matrix(const Matrix& other) const{
        if(columns != other.rows)
            cout << "errore di dimensioni";
        
        Matrix result(rows, other.columns);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < other.columns; j++){
                for (int k = 0; k < other.rows; k++){
                    result.data[i][j] += data[i][k]*other.data[k][j];
                }
                
            }
            
        }
        return result;
    }

    Matrix transpote() const{

        Matrix result(columns, rows);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                result.data[j][i] = data[i][j]; 
            }
        }

        return result;
        
    }
    };

    
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

