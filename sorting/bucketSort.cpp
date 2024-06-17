#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform bucket sort on arr[]
void bucketSort(std::vector<float>& arr) {
    int n = arr.size();
    if (n <= 0)
        return;

    // 1) Create n empty buckets
    std::vector<std::vector<float>> buckets(n);

    // 2) Put array elements in different buckets
    for (int i = 0; i < n; ++i) {
        int bucketIndex = n * arr[i]; // Index in bucket
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; ++i)
        std::sort(buckets[i].begin(), buckets[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Function to print an array
void printArray(const std::vector<float>& arr) {
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    std::cout << "Original array: ";
    printArray(arr);

    bucketSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
