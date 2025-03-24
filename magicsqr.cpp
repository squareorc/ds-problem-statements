#include <iostream>
#include <vector>
using namespace std;

// Function to generate an odd-sized magic square
void generateMagicSquare(int n) {
    if (n % 2 == 0) {
        cout << "Magic square is only possible for odd-sized matrices." << endl;
        return;
    }

    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    int num = 1;
    int i = 0, j = n / 2; // Start from the middle of the first row

    while (num <= n * n) {
        magicSquare[i][j] = num++;
        int newI = (i - 1 + n) % n; // Move up
        int newJ = (j + 1) % n;     // Move right

        if (magicSquare[newI][newJ] != 0) {
            i = (i + 1) % n; // Move down if the cell is already filled
        } else {
            i = newI;
            j = newJ;
        }
    }

    // Print the magic square
    cout << "Magic Square of size " << n << "x" << n << ":" << endl;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << magicSquare[row][col] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (odd number): ";
    cin >> n;

    generateMagicSquare(n);

    return 0;
}