#include <iostream>
using namespace std;

// Node of the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Insert a value into the BST
Node* insert(Node* root, int value) {

    // If tree is empty, create a new node
    if (root == nullptr)
        return new Node(value);

    // Smaller values go to the left
    if (value < root->data)
        root->left = insert(root->left, value);

    // Larger values go to the right
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find the smallest node in a subtree
Node* findMin(Node* root) {

    // Keep moving to the left
    while (root->left != nullptr)
        root = root->left;

    return root;
}

// Delete a value from the BST
Node* deleteNode(Node* root, int value) {

    // Value not found
    if (root == nullptr)
        return root;

    // Search in the left subtree
    if (value < root->data)
        root->left = deleteNode(root->left, value);

    // Search in the right subtree
    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    // Value found
    else {

        // Case 1: Node has no left child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Node has no right child
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has two children
        // Find the smallest value in the right subtree
        Node* successor = findMin(root->right);

        // Copy successor's value
        root->data = successor->data;

        // Delete the duplicate successor node
        root->right = deleteNode(root->right, successor->data);
    }

    return root;
}

// Display BST using inorder traversal
void inorder(Node* root) {

    // Stop if there is no node
    if (root == nullptr)
        return;

    // Visit left subtree
    inorder(root->left);

    // Display current node
    cout << root->data << " ";

    // Visit right subtree
    inorder(root->right);
}

int main() {

    // Start with an empty tree
    Node* root = nullptr;

    int choice, value;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Inorder";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

            // Insert a value
            case 1:
                cout << "Enter value: ";
                cin >> value;

                root = insert(root, value);
                break;

            // Delete a value
            case 2:
                cout << "Enter value: ";
                cin >> value;

                root = deleteNode(root, value);
                break;

            // Display inorder traversal
            case 3:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;

            // Exit the program
            case 0:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
