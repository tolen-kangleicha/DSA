#include <iostream>
using namespace std;

int searchElement(int *, int, int);
bool replaceElement(int *, int, int);
void displayArray(int *, int);

int main() {
    int arr[] = {2, 3, 5, 14, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int num;

    //printing the original array
    cout << "The original array is" << endl;
    displayArray(arr, size);

    cout << "\n\nEnter the number to be searched: ";
    cin >> num;

    int loc = searchElement(arr, size, num);
    if(loc != -1) 
        cout << "The element is found at position no. " << loc << endl;
    else    
        cout << "The entered no. is not an element of the array." << endl;

    //Replacing an element of the array
    int ele;
    cout << "\n\nEnter the element to be replaced: ";
    cin >> ele;
    if(replaceElement(arr, size, ele)) {
        cout << "The array after replacing the element is" << endl;
        displayArray(arr, size);
    } else {
        cout << "The entered no. is not an element of the array." << endl;
    }

    return 0;
}

int searchElement(int *arr, int size, int num) {
    for(int i = 0; i < size; i++) {
        if(num == arr[i]) {
            return i;
            break;
        }
    }
    return -1;
}

bool replaceElement(int *arr, int size, int num) {
    int loc = searchElement(arr, size, num);
    if(loc != -1) {
        arr[loc] = 4;
        return true;
    }
    return false;
}

void displayArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

