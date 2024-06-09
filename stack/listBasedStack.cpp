#include <iostream>

class Node {
    public:
        int data;
        Node *next;
        Node( int data ) : data( data ), next( nullptr ) {}
};

class LinkedListStack {
    Node *top;
    public:
        LinkedListStack() : top( nullptr ) {}
        ~LinkedListStack() {
            while( !isEmpty() ) {
                pop();
            }
        }
        void push( int );
        void pop();
        int peek();
        bool isEmpty();
};

void LinkedListStack::push( int data ) {
    Node *newNode = new Node( data );
    newNode -> next = top;
    top = newNode;
}

void LinkedListStack::pop() {
    if( isEmpty() ) {
        std::cout << "Stack underflow" << std::endl;
    } else {
        Node *temp = top;
        top = top -> next;
        delete temp;
    }
}

int LinkedListStack::peek() {
    if( isEmpty() ) {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    } else return top -> data;
}

bool LinkedListStack::isEmpty() {
    return top == nullptr;
}

int main() {
    LinkedListStack myStack;
    myStack.push( 23 );
    
    std::cout << "The top element of the stack is " << myStack.peek() << std::endl;

    myStack.pop();
    std::cout << myStack.isEmpty() << std::endl;

    return 0;
}