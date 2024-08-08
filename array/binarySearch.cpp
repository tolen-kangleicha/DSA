#include <iostream>

int binarySearch( int *array, int size, int target ) {
    int beg = 0;
    int end = size - 1;

    for( int i = 0; i < size; i++ ) {
        int mid = ( beg + end ) / 2;
        if( array[ mid ] == target )
            return mid;
        else {
            if( array[ mid ] < target )
                beg = mid + 1;
            else 
                end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int array[] = { 2, 4, 6, 7, 8 };
    int size = sizeof( array ) / sizeof( array[ 0 ] );

    int target;
    std::cout << "Enter the element to be searched: ";
    std::cin >> target;

    int pos = binarySearch( array, size, target );
    if( pos == -1 )
        std::cout << "Element is not found" << std::endl;
    else 
        std::cout << "Element is found at position no. " << pos << " wrt 0 position." << std::endl;

    return 0;
}