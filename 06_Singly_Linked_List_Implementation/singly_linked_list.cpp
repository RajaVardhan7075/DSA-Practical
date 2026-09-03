#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insert_at_beginning(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insert_at_end(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Insert after a node containing target value
    void insert_at_position(int value, int target) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == target) {
                Node* newNode = new Node();

                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;

                return;
            }

            temp = temp->next;
        }

        cout << "Target " << target << " not found.\n";
    }

    // Delete from beginning
    void delete_from_beginning() {
        if (head == nullptr) {
            cout << "Linked list is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;
    }

    // Delete from end
    void delete_from_end() {
        if (head == nullptr) {
            cout << "Linked list is empty.\n";
            return;
        }

        // If there is only one node
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;

        // Move to the second-last node
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete node containing target value
    void delete_at_position(int target) {
        if (head == nullptr) {
            cout << "Linked list is empty.\n";
            return;
        }

        // If target is in the first node
        if (head->data == target) {
            Node* temp = head;
            head = head->next;

            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            if (temp->next->data == target) {
                Node* nodeToDelete = temp->next;

                temp->next = nodeToDelete->next;

                delete nodeToDelete;
                return;
            }

            temp = temp->next;
        }

        cout << "Target " << target << " not found.\n";
    }

    // Traverse the linked list
    void traverse() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Search for a value
    bool search(int target) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == target) {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    // Reverse the singly linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;
    }

    // Display the linked list
    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "Null\n";
    }
};

int main() {

    LinkedList list;

    // Insert at end
    list.insert_at_end(10);
    list.insert_at_end(20);
    list.insert_at_end(30);

    cout << "After inserting at end:\n";
    list.display();

    // Insert at beginning
    list.insert_at_beginning(7);
    list.insert_at_beginning(8);
    list.insert_at_beginning(9);

    cout << "\nAfter inserting at beginning:\n";
    list.display();

    // Insert after target
    list.insert_at_position(15, 10);
    list.insert_at_position(25, 20);
    list.insert_at_position(19, 15);

    cout << "\nAfter inserting at positions:\n";
    list.display();

    // Delete from beginning
    list.delete_from_beginning();

    cout << "\nAfter deleting from beginning:\n";
    list.display();

    // Delete from end
    list.delete_from_end();

    cout << "\nAfter deleting from end:\n";
    list.display();

    // Delete target node
    list.delete_at_position(15);

    cout << "\nAfter deleting node containing 15:\n";
    list.display();

    // Traverse
    cout << "\nTraversing the linked list:\n";
    list.traverse();

    // Search
    int target = 20;

    cout << "\nSearching for " << target << ":\n";

    if (list.search(target)) {
        cout << target << " found in the linked list.\n";
    }
    else {
        cout << target << " not found in the linked list.\n";
    }

    // Reverse
    list.reverse();

    cout << "\nAfter reversing the linked list:\n";
    list.display();

    return 0;
}
