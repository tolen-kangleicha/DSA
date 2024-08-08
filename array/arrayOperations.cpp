#include <iostream>
using namespace std;

void arr_display(int[], int);
void arr_delFront(int *&, int &);
void arr_delRear(int *&, int&);
void arr_addToFront(int *&, int &, int);
void arr_addToRear(int *&, int &, int);

int main() {
    int size;

    cout << "How many elements?" << endl;
    cin >> size;

    int *arr = new int[size];
    cout << "Please enter elements:" << endl;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    //Adding element at the front
    arr_addToFront(arr, size, 300);
    arr_addToFront(arr, size, 200);
    cout << "\nArray after adding elements at the front is" << endl;
    arr_display(arr, size);

    //Adding element at the rear
    arr_addToRear(arr, size, 10);
    arr_addToRear(arr, size, 20);
    cout << "\nArray after adding elements at the rear is" << endl;
    arr_display(arr, size);

    //Deleting element from the front
    arr_delFront(arr, size);
    cout << "\nArray after deleting an element from the front is" << endl;
    arr_display(arr, size);

    //Deleting element from the rear
    arr_delRear(arr, size);
    cout << "\nArray after deleting element from the rear is " << endl;
    arr_display(arr, size);

    return 0;
}

void arr_display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void arr_addToFront(int *&arr, int &size, int value) {
    if(size == 0) {
        arr = new int[1];
        arr[size++] = value;
        return;
    }
    int new_capacity = size + 1;
    int *new_arr = new int[new_capacity];
    new_arr[0] = value;
    for(int i = 0; i < size; i++) {
        new_arr[i+1] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    ++size;
}

void arr_addToRear(int *&arr, int &size, int value) {
    int new_capacity = size + 1;
    int *new_arr = new int[new_capacity];
    for(int i = 0; i < new_capacity; i++) {
        new_arr[i] = arr[i];
    }
    new_arr[size] = value;
    delete[] arr;
    arr = new_arr;
    ++size;
}

void arr_delFront(int *&arr, int &size) {
    if(size == 0) {
        cout << "The array is empty, nothing to delete from the front." << endl;
        return;
    }
    for(int i = 1; i < size; i++) {
        arr[i-1] = arr[i];
    }
    --size;
}

void arr_delRear(int *&arr, int &size) {
    if(size == 0) {
        cout << "The array is empty, nothing to delete form the rear." << endl;
        return;
    }
    --size;
    int new_capacity = size;
    int *new_arr = new int[new_capacity];
    for(int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
}
