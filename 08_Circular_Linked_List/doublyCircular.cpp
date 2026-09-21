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
    Node* rev_head;   // Points to the last node (tail)

public:
    // Constructor
    LinkedList() {
        head = nullptr;
        rev_head = nullptr;
    }

    // Insert at end
    void insert_at_end(int value) {
        Node* newnode = new Node;
        newnode->data = value;

        // If list is empty
        if (head == nullptr) {
            head = newnode;
            rev_head = newnode;

            // Circular links
            newnode->next = head;
            newnode->prev = head;

            return;
        }

        // New node goes after rev_head
        newnode->prev = rev_head;
        newnode->next = head;

        rev_head->next = newnode;
        head->prev = newnode;

        // New node becomes tail
        rev_head = newnode;
    }

    // Insert at beginning
    void insert_at_beginning(int value) {
        Node* newnode = new Node;
        newnode->data = value;

        // If list is empty
        if (head == nullptr) {
            head = newnode;
            rev_head = newnode;

            newnode->next = head;
            newnode->prev = head;

            return;
        }

        // Connect new node between tail and old head
        newnode->prev = rev_head;
        newnode->next = head;

        rev_head->next = newnode;
        head->prev = newnode;

        // New node becomes head
        head = newnode;
    }

    // Insert after the first occurrence of target
    void insert_at_position(int value, int target) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        do {
            if (temp->data == target) {
                Node* newnode = new Node;

                newnode->data = value;

                // Insert newnode after temp
                newnode->prev = temp;
                newnode->next = temp->next;

                temp->next->prev = newnode;
                temp->next = newnode;

                // If inserted after tail,
                // new node becomes the new tail
                if (temp == rev_head) {
                    rev_head = newnode;
                }

                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Target " << target << " not found.\n";
    }

    // Delete first occurrence of target
    void deletion_node(int target) {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;

        do {
            if (temp->data == target) {

                // Only one node in the list
                if (temp == head && temp == rev_head) {
                    delete temp;

                    head = nullptr;
                    rev_head = nullptr;

                    return;
                }

                // If deleting head
                if (temp == head) {
                    head = head->next;

                    rev_head->next = head;
                    head->prev = rev_head;

                    delete temp;
                    return;
                }

                // If deleting tail
                if (temp == rev_head) {
                    rev_head = rev_head->prev;

                    rev_head->next = head;
                    head->prev = rev_head;

                    delete temp;
                    return;
                }

                // Deleting a middle node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                delete temp;
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Target " << target << " not found.\n";
    }

    // Display forward and reverse
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        // Forward traversal
        cout << "Forward: ";

        Node* temp = head;

        do {
            cout << temp->data;

            temp = temp->next;

            if (temp != head) {
                cout << " -> ";
            }

        } while (temp != head);

        cout << " -> Head\n";

        // Reverse traversal
        cout << "Reverse: ";

        temp = rev_head;

        do {
            cout << temp->data;

            temp = temp->prev;

            if (temp != rev_head) {
                cout << " -> ";
            }

        } while (temp != rev_head);

        cout << " -> Tail\n";
    }

    // Reverse circular doubly linked list
    void reverse() {
        if (head == nullptr) {
            return;
        }

        // One node does not need reversing
        if (head == rev_head) {
            return;
        }

        Node* curr = head;
        Node* temp = nullptr;

        do {
            // Swap next and prev
            temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;

            // Move to next original node
            curr = temp;

        } while (curr != head);

        // Swap head and tail
        temp = head;
        head = rev_head;
        rev_head = temp;
    }

    // Destructor
    ~LinkedList() {
        if (head == nullptr) {
            return;
        }

        // Break the circular connection first
        rev_head->next = nullptr;
        head->prev = nullptr;

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

    // Insert at end
    link.insert_at_end(10);
    link.insert_at_end(20);
    link.insert_at_end(30);

    // Insert at beginning
    link.insert_at_beginning(0);

    // Insert 35 after 20
    link.insert_at_position(35, 20);

    // Delete 35
    link.deletion_node(35);

    cout << "Original Circular Doubly Linked List:\n";
    link.display();

    // Reverse
    link.reverse();

    cout << "\nReversed Circular Doubly Linked List:\n";
    link.display();

    return 0;
}
