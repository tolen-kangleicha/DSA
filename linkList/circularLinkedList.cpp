#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Method to insert a node at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself for circularity
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Method to insert a node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself for circularity
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Method to delete the first node
    void deleteFromBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        if (head->next == head) { // Only one node in the list
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        Node* tempHead = head;
        head = head->next;
        delete tempHead;
    }

    // Method to delete the last node
    void deleteFromEnd() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        if (head->next == head) { // Only one node in the list
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }

    // Method to print the linked list
    void displayList() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtBeginning(3);
    list.insertAtBeginning(5);
    list.insertAtEnd(8);
    list.deleteFromBeginning();
    list.deleteFromEnd();

    std::cout << "Linked list: ";
    list.displayList(); // Output should be 3

    return 0;
}
