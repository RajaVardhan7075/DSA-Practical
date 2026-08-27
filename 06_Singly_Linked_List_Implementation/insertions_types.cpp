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
    LinkedList() {
        head = nullptr;
    }

    void insert_at_beginning(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insert_at_end(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void insert_at_position(int value, int target) {
        Node* temp = head;

        while (temp->next != nullptr) {
            if (temp->data == target) {
                Node* newNode = new Node();

                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
            }

            temp = temp->next;
        }
    }

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

    list.insert_at_end(10);
    list.insert_at_end(20);
    list.insert_at_end(30);
    list.display();

    list.insert_at_beginning(7);
    list.insert_at_beginning(8);
    list.insert_at_beginning(9);
    list.display();

    list.insert_at_position(15, 10);
    list.insert_at_position(25, 20);
    list.insert_at_position(19, 15);
    list.display();

    return 0;
}
