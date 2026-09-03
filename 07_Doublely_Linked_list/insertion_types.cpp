#include<iostream>
using namespace std;

struct Node{
    Node* prev;
    int data;
    Node* next;
};

class Delete{
    private:
    Node* head;
    Node* rev_head;
    
    public:
    Delete(){
        head = nullptr;
        rev_head = nullptr;
    }
    
    void insert_at_end(int value){
        Node* newnode = new Node();
        newnode-> prev = nullptr;
        newnode-> data = value;
        newnode-> next = nullptr;
        
        if(head == nullptr){
            head = newnode;
        }else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
            rev_head = newnode;
        }
    }
    
    void insert_at_begining(int value){
        Node* newnode = new Node();
        newnode->data = value;
        newnode->next = head;
        newnode->prev = nullptr;
        head->prev = newnode;
        head = newnode;
    }
    
    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"Null\n";
        
        cout<<"Display using prev\n";
        temp = rev_head;
        while(temp != nullptr){
            cout<<temp->data<<"->";
            temp = temp->prev;
        }
        cout<<"Null\n";
    }

};

int main(){
    Delete d;
    d.insert_at_end(10);
    d.insert_at_end(20);
    d.insert_at_end(30);
    d.display();
    
    d.insert_at_begining(9);
    d.insert_at_begining(8);
    d.display();
}
