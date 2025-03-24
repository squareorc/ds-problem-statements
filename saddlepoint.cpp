#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void findSaddlePoint(const vector<vector<int>>& matrix, int m, int n) {
    bool found = false;

    for (int i = 0; i < m; i++) {
        int minRow = numeric_limits<int>::max();
        int colIndex = -1;

        // Find the minimum element in the current row
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < minRow) {
                minRow = matrix[i][j];
                colIndex = j;
            }
        }

        // Check if the minimum element is the largest in its column
        bool isSaddlePoint = true;
        for (int k = 0; k < m; k++) {
            if (matrix[k][colIndex] > minRow) {
                isSaddlePoint = false;
                break;
            }
        }

        if (isSaddlePoint) {
            cout << "Saddle Point found at (" << i << ", " << colIndex << ") with value: " << minRow << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No Saddle Point found in the matrix." << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    findSaddlePoint(matrix, m, n);

    return 0;
}