#include <iostream>

class ArrayStack {
    int top;
    int capacity;
    int *stack;
    
    public:
        ArrayStack( int size ) {
            capacity = size;
            stack = new int[ capacity ];
            top = -1;
        }

        ~ArrayStack() {
            delete[] stack;
        }

        void push( int );
        void pop();
        int peek();
        bool isEmpty();
};

void ArrayStack::push( int data ) {
    if( top == capacity - 1 ) {
        std::cout << "The stack is full <stack overflow>" << std::endl;
        return;
    } else {
        stack[ ++top ] = data;
    }
}

void ArrayStack::pop() {
    if( isEmpty() ) {
        std::cout << "The stack is empty <stack underflow>" << std::endl;
        return;
    } else top--;
}

bool ArrayStack::isEmpty() {
    return top == -1;
}

int ArrayStack::peek() {
    if( isEmpty() ) {
        std::cout << "The stack is empty" << std::endl;
        return -1;
    } else return stack[ top ];  
}

int main() {
    int size;
    std::cout << "Enter the size of the stack: ";
    std::cin >> size;

    ArrayStack myStack( size );

    int element;
    std::cout << "Enter elements of the stack: " << std::endl;
    for( int i = 0; i < size; i++ ) {
        std::cin >> element;
        myStack.push( element );
    }

    std::cout << "\nThe elements in the stack are: " << std::endl;
    for( int i = 0; i < size; i++ ) {
        std::cout << myStack.peek() << "  ";
        myStack.pop();
    }
    std::cout << std::endl;

    return 0;
}