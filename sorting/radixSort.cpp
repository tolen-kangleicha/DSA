#include <iostream>
#include <vector>
#include <algorithm>

// Function to get the maximum value in arr[]
int getMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

// Function to perform counting sort on arr[] according to the digit represented by exp
void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n); // Output array
    int count[10] = {0}; // Count array to store count of occurrences of digits

    // Store count of occurrences of digits in count[]
    for (int i = 0; i < n; ++i)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers according to the current digit
    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

// Function to perform radix sort on arr[]
void radixSort(std::vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr);

    // Do counting sort for every digit. Note that instead of passing the digit number,
    // exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    std::cout << "Original array: ";
    printArray(arr);

    radixSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
