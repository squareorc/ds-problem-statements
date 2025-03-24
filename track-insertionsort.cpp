#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void insertionSortWithTracking(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;

        // Print the array after each pass
        std::cout << "Pass " << i << ": ";
        printArray(arr);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};

    std::cout << "Original array: ";
    printArray(arr);

    insertionSortWithTracking(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}