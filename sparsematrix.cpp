#include <iostream>
using namespace std;

// Function to convert a matrix to its sparse form
void convertToSparseForm(int **matrix, int rows, int cols) {
    // Count non-zero elements
    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    // Allocate memory for sparse matrix
    int sparseMatrix[nonZeroCount][3];
    int k = 0;

    // Fill sparse matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Display the sparse matrix
    cout << "Sparse Matrix Representation:" << endl;
    cout << "Row\tCol\tValue" << endl;
    for (int i = 0; i < nonZeroCount; i++) {
        cout << sparseMatrix[i][0] << "\t" << sparseMatrix[i][1] << "\t" << sparseMatrix[i][2] << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> m >> n;

    // Dynamically allocate memory for the matrix
    int **matrix = new int*[m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    convertToSparseForm(matrix, m, n);

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}