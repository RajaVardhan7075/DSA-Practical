#include <iostream>
using namespace std;

struct Node {
    Node* prev;
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* rev_head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
        rev_head = nullptr;
    }

    // Insert at end
    void insert_at_end(int value) {
        Node* newnode = new Node{nullptr, value, nullptr};

        if (head == nullptr) {
            head = newnode;
            rev_head = newnode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;

        // New node becomes the last node
        rev_head = newnode;
    }

    // Insert at beginning
    void insert_at_beginning(int value) {
        Node* newnode = new Node{nullptr, value, head};

        if (head != nullptr) {
            head->prev = newnode;
        } else {
            // List was empty
            rev_head = newnode;
        }

        head = newnode;
    }

    // Insert after the first node containing target
    void insert_at_position(int value, int target) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == target) {
                Node* newnode = new Node{
                    temp,
                    value,
                    temp->next
                };

                if (temp->next != nullptr) {
                    temp->next->prev = newnode;
                } else {
                    // Inserting after the last node
                    rev_head = newnode;
                }

                temp->next = newnode;
                return;
            }

            temp = temp->next;
        }

        cout << "Target " << target << " not found.\n";
    }

    // Delete first node containing target
    void deletion_node(int target) {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == target) {
                // If deleting the head
                if (temp == head) {
                    head = temp->next;

                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else {
                    temp->prev->next = temp->next;

                    if (temp->next != nullptr) {
                        temp->next->prev = temp->prev;
                    }
                }

                // If deleting the last node
                if (temp == rev_head) {
                    rev_head = temp->prev;
                }

                delete temp;
                return;
            }

            temp = temp->next;
        }

        cout << "Target " << target << " not found.\n";
    }

    // Display list from beginning to end and end to beginning
    void display() {
        cout << "Forward: ";

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data;

            if (temp->next != nullptr) {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << " -> Null\n";

        cout << "Reverse: ";

        temp = rev_head;

        while (temp != nullptr) {
            cout << temp->data;

            if (temp->prev != nullptr) {
                cout << " -> ";
            }

            temp = temp->prev;
        }

        cout << " -> Null\n";
    }

    // Reverse the doubly linked list
    void reverse() {
        Node* curr = head;
        Node* temp = nullptr;

        while (curr != nullptr) {
            // Swap prev and next
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // Move to the next node in the original list
            curr = curr->prev;
        }

        // After reversal, old tail becomes the new head
        if (temp != nullptr) {
            head = temp->prev;
        }

        // New tail is the old head
        rev_head = temp;
    }

    // Destructor to free all dynamically allocated nodes
    ~LinkedList() {
        Node* temp = head;

        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }

        head = nullptr;
        rev_head = nullptr;
    }
};

int main() {
    LinkedList link;

    link.insert_at_end(10);
    link.insert_at_end(20);
    link.insert_at_end(30);

    link.insert_at_beginning(0);

    link.insert_at_position(35, 20);

    link.deletion_node(35);

    cout << "Original List:\n";
    link.display();

    link.reverse();

    cout << "\nReversed List:\n";
    link.display();

    return 0;
}
