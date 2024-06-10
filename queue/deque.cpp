#include <iostream>
#include <deque>

int main() {
    std::deque<int> myDeque;

    // Adding elements to the deque
    myDeque.push_back(10);
    myDeque.push_back(20);
    myDeque.push_front(5);

    std::cout << "Deque size: " << myDeque.size() << std::endl;
    std::cout << "Deque elements: ";
    for (int elem : myDeque) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Front element: " << myDeque.front() << std::endl;
    std::cout << "Back element: " << myDeque.back() << std::endl;

    // Removing elements from the deque
    myDeque.pop_front();
    std::cout << "After pop_front, front element: " << myDeque.front() << std::endl;

    myDeque.pop_back();
    std::cout << "After pop_back, back element: " << myDeque.back() << std::endl;

    std::cout << "Deque size: " << myDeque.size() << std::endl;

    return 0;
}
