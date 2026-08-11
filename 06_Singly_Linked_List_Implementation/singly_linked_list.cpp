#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << value << " inserted into linked list." << endl;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty." << endl;
            return;
        }

        Node* temp = head;

        cout << "Linked List: ";

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.display();

    return 0;
}
