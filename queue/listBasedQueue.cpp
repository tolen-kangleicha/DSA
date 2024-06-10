#include <iostream>

struct Node {
    int data;
    Node *next;
    Node( int value ) : data( value ), next( nullptr ) {}
};

class ListQueue {
    Node *front;
    Node *rear;
    public:
        ListQueue() : front( nullptr ), rear( nullptr ) {}
        ~ListQueue() {
            while( !isEmpty() ) {
                dequeue();
            }
        }

        void enqueue( int );
        void dequeue();
        int peekFront();
        int peekRear();
        bool isEmpty();
        int size();
};

void ListQueue::enqueue( int value ) {
    Node *newNode = new Node( value );

    if( rear ) {
        rear -> next = newNode;
    } 
    rear = newNode;
    if( !front ) {
        front = rear;
    }
}

void ListQueue::dequeue() {
    if( isEmpty() ) {
        std::cout << "Queue underlfow" << std::endl;
        return;
    } else {
        Node *temp = front;
        front = front -> next;
        if( !front ) {
            rear = nullptr;
        }
        delete temp;
    }
}

int ListQueue::peekFront() {
    if( isEmpty() ) {
        std::cout << "The queue is empty" << std::endl;
        return -1;
    } else return front -> data;
}

int ListQueue::peekRear() {
    if( isEmpty() ) {
        std::cout << "The queue is empty" << std::endl;
        return -1;
    } else return rear -> data;
}

bool ListQueue::isEmpty() {
    return front == nullptr;
}

int ListQueue::size() {
    int count = 0;
    Node *current = front;
    while( current ) {
        count++;
        current = current -> next;
    }
    return count;
}

int main() {
    ListQueue myQueue;
    myQueue.enqueue( 23 );
    myQueue.enqueue( 43 );

    std::cout << "The size of the queue is " << myQueue.size() << std::endl;
    std::cout << "The fornt element is " << myQueue.peekFront() << std::endl;
    std::cout << "The rear element is " << myQueue.peekRear() << std::endl;

    myQueue.dequeue();
    
    if( myQueue.isEmpty() ) {
        std::cout << "The queue is empty" << std::endl;
    } else {
        std::cout << "The queue is not empty" << std::endl;
    }

    return 0;
}