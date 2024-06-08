//implimentation of singly linked list

#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        Node( int value ) : data( value ), next( nullptr ) {}
};

class SinglyLinkedList
{
    private:
        Node *head;

    public:
        SinglyLinkedList() : head( nullptr ) {}

        void insertAtBeginning( int );
        void insertAtEnd( int );
        void insertAtPos( int , int );

        void deleteFromBeginning();
        void deleteFromEnd();
        void deleteFromPos( int );
        void deleteAnElement( int );

        void displayList();



};

void SinglyLinkedList::insertAtBeginning( int data )
{
    Node *newNode = new Node( data );
    newNode -> next = head;
    head = newNode;
}

void SinglyLinkedList::insertAtEnd( int data )
{
    Node *newNode = new Node( data );
    if( head == nullptr )
    {
        head = newNode;
    }
    Node *last = head;
    while( last -> next != nullptr )
    {
        last = last -> next;
    }

    last -> next = newNode;
}

void SinglyLinkedList::insertAtPos( int pos, int data )
{
    if( pos < 0 )
    {
        cout << "Position cann't be negative." << endl;
        return;
    }

    Node *newNode = new Node( data );
    if( pos == 0 )
    {
        newNode -> next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    for( int i = 0; temp != nullptr && i < pos - 1; i++ )
    {
        temp = temp -> next;
    }

    if( temp == nullptr )
    {
        cout << "The given position is greater than the size of the list." << endl;
        delete newNode;
        return;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;

}

void SinglyLinkedList::deleteFromBeginning()
{
    if( head == nullptr )
    {
        return;
    }
    Node *temp = head;
    head = head -> next;
    delete temp;
}

void SinglyLinkedList::deleteFromEnd()
{
    Node *temp = head;
    if( temp -> next == nullptr )
    {
        delete temp;
        head -> next = nullptr;
        return;
    }

    while( temp -> next -> next != nullptr )
    {
        temp = temp -> next;
    }

    delete temp -> next;
    temp -> next = nullptr;
}

void SinglyLinkedList::deleteFromPos( int pos )
{
    if( pos < 0 )
    {
        cout << "Position cann't be negative." << endl;
        return;
    }

    if( head == nullptr )
    {
        cout << "The list is empty." << endl;
    }

    if( pos == 0 )
    {
        Node *temp = head;
        head = head -> next;
        delete temp;
        return;
    }

    Node *temp = head;
    Node *prev = nullptr;
    for( int i = 0; temp != nullptr && i < pos; i++ )
    {
        prev = temp;
        temp = temp -> next;
    }
    if( temp == nullptr )
    {
        cout << "The given position is greater than the size of the list." << endl;
        return;
    }

    prev -> next = temp -> next;
    delete temp;
}

void SinglyLinkedList::deleteAnElement( int value )
{
    Node *temp = head;
    Node *prev = nullptr;

    if( temp != nullptr && temp -> data == value )
    {
        head = temp -> next;
        delete temp;
        return;
    }

    while( temp != nullptr && temp -> data != value )
    {
        prev = temp;
        temp = temp -> next;
    }
    if( temp == nullptr )
    {
        return;
    }

    prev -> next = temp -> next;
    delete temp;


}

void SinglyLinkedList::displayList()
{
    Node *node = head;

    if( head == nullptr )
    {
        cout << "The list is empty." << endl;
    }

    while( node != nullptr )
    {
        cout << node -> data << "  ";
        node = node -> next;
    }
}

int main()
{
    SinglyLinkedList list;

    list.insertAtBeginning( 3 );
    list.insertAtBeginning( 5 );
    list.insertAtEnd( 8 );
    list.insertAtPos( 0, 4 );
    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.deleteFromPos( 0 );
    list.deleteAnElement( 3 );

    list.displayList();

    return 0;
}