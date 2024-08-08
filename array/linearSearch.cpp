#include <iostream>

int lenearSearch( int *, int, int );

int main() {
    int array[] = { 3, 5, 6, 2, 7 };
    int size = sizeof( array ) / sizeof( array[ 0 ] );

    int element;
    std::cout << "Enter element to be searched: ";
    std::cin >> element;

    int pos = lenearSearch( array, size, element );
    if( pos != -1 ) {
        std::cout << element << " is found at position no. " << pos << " wrt 0 position." << std::endl;
    } else {
        std::cout << element << " is not an element of the array." << std::endl;
    }

    return 0;
}

int lenearSearch( int *array, int size, int element ) {
    for( int i = 0; i < size; i++ ) {
        if( array[ i ] == element ) {
            return i;
        }
    }
    return -1;
}