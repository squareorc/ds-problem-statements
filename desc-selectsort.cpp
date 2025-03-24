#include <iostream>
#include <vector>
using namespace std;

// Function to perform selection sort in descending order
void selectionSortDescending(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Find the index of the maximum element in the remaining unsorted array
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        // Swap the found maximum element with the first element of the unsorted part
        swap(arr[i], arr[maxIndex]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    selectionSortDescending(arr);

    cout << "Sorted array in descending order: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}