#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class CircularLinkedlist {
    Node* head;
    public:
    CircularLinkedlist() {
        head = nullptr;
    }
    
    void insert(int val) {
        Node* newnode = new Node();
        newnode->data = val;
        newnode->next = nullptr;
        if(head == nullptr) {
            head = newnode;
            newnode->next = head;
            return;
        }
        
        Node* temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    
    void deleteNode(int val) {
        if(!head) {
            cout << "List is empty\n";
            return;
        }
        
        Node* curr = head;
        Node* prev = nullptr;
        
        if(head->data == val && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        
        do {
            if(curr->data == val) {
                if(prev) {
                    prev->next = curr->next;
                } else {
                    Node* temp = head;
                    while(temp->next != head) {
                        temp = temp->next;
                    }
                    head = head->next;
                    temp->next = head;
                }
                delete curr;
                cout << val << " deleted.\n";
                return ;
            }
            prev = curr;
            curr = curr->next;
        } while(curr != head);
        cout << val << " not found.\n";
    } 
    
    void display() {
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while(temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedlist l;
    
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.insert(50);
    
    l.display();
    
    l.deleteNode(30);
    l.display();
}
