#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPos(int pos, int data) {
        if (pos < 0) {
            std::cout << "Position can't be negative." << std::endl;
            return;
        }

        Node* newNode = new Node(data);
        if (pos == 0) {
            insertAtBeginning(data);
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "The given position is greater than the size of the list." << std::endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void deleteFromPos(int pos) {
        if (pos < 0) {
            std::cout << "Position can't be negative." << std::endl;
            return;
        }

        if (head == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        if (pos == 0) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "The given position is greater than the size of the list." << std::endl;
            return;
        }

        if (temp == tail) {
            deleteFromEnd();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void deleteAnElement(int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Element not found." << std::endl;
            return;
        }

        if (temp == head) {
            deleteFromBeginning();
            return;
        }

        if (temp == tail) {
            deleteFromEnd();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void displayList() {
        Node* temp = head;

        if( head == nullptr && tail == nullptr ) {
            std::cout << "The list is empty." << std::endl;
        }

        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(3);
    list.insertAtBeginning(5);
    list.insertAtEnd(8);
    list.insertAtPos(0, 4);
    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.deleteFromPos(0);
    list.deleteAnElement(3);

    list.displayList();

    return 0;
}
