#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;
    myStack.push( 3 );
    myStack.push( 4 );
    myStack.push( 5 );
    myStack.pop();
    
    if( myStack.empty() ) {
        std::cout << "The stack is empty" << std::endl;
    } else {
        std::cout << "The top element is " << myStack.top() << std::endl;
        std::cout << "The size of the stack is " << myStack.size() << std::endl;
    }

    return 0;
}