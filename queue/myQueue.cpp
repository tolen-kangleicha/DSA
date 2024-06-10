#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;
    
    myQueue.push( 20 );
    myQueue.push( 23 );
    
    std::cout << "Size of the queue = " << myQueue.size() << std::endl;
    std::cout << "Front element = " << myQueue.front() << std::endl;
    std::cout << "Back element = " << myQueue.back() << std::endl;

    myQueue.pop();
    
    if( myQueue.empty() ) {
        std::cout << "The queue is empty" << std::endl;
    } else {
        std::cout << "The queue is not empty" << std::endl;
    }

    return 0;
}