#include <iostream>
#include <vector>

// Function to partition the array on the basis of pivot
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivot element
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; ++j) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            ++i; // increment index of smaller element
            std::swap(arr[i], arr[j]); // swap
        }
    }
    std::swap(arr[i + 1], arr[high]); // swap the pivot element with the element at i+1
    return (i + 1);
}

// Function to perform quick sort on an array
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    std::cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
