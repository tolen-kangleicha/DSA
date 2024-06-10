#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> queue;

    queue.push( 23 );
    queue.push( 43 );
    queue.push( 44 );

    std::cout << "The top element is " << queue.top() << std::endl;

    queue.pop();

    std::cout << "The top element is " << queue.top() << std::endl;

    return 0;
}