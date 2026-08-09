#include <iostream>
using namespace std;

#define MAX 100

class Queue
{
private:
    int arr[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return rear == MAX - 1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (isEmpty())
        {
            front = 0;
        }

        arr[++rear] = value;
        cout << value << " inserted into the queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << arr[front] << " deleted from the queue." << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }

    void traverse()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue Elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void search(int value)
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            if (arr[i] == value)
            {
                cout << value << " found at position " << i << "." << endl;
                return;
            }
        }

        cout << value << " not found in the queue." << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n========== Queue Operations ==========\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Traverse\n";
        cout << "4. Search\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.traverse();
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                q.search(value);
                break;

            case 0:
                cout << "Program terminated." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
