#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:

    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack is overflow\n";
            return;
        }

        arr[++top] = val;
        cout << val << " pushed into Stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is underflow\n";
            return;
        }

        cout << arr[top--] << " Popped from Stack.\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Top element: " << arr[top] << "\n";
    }

    void traverse() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom): ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << "\n";
    }

    void search(int val) {

        for (int i = top; i >= 0; i--) {

            if (arr[i] == val) {
                cout << val << " found at position "
                     << (top - i + 1)
                     << " from top.\n";
                return;
            }
        }

        cout << val << " not found in stack.\n";
    }
};

int main() {

    Stack s;

    int choice, val;

    do {

        cout << "\n--- Stack Menu ---\n";
        cout << "1.Push\n2.Pop\n3.Peek\n4.Traverse\n5.Search\n0.Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.traverse();
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                s.search(val);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 0);

    return 0;
}
