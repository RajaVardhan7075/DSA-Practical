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
    else
        root->right = insert(root->right, value);

    return root;
}

// Preorder Traversal
// Root -> Left -> Right
void preorder(Node* root) {

    // Stop if there is no node
    if (root == nullptr)
        return;

    // Visit root
    cout << root->data << " ";

    // Visit left subtree
    preorder(root->left);

    // Visit right subtree
    preorder(root->right);
}

// Inorder Traversal
// Left -> Root -> Right
void inorder(Node* root) {

    // Stop if there is no node
    if (root == nullptr)
        return;

    // Visit left subtree
    inorder(root->left);

    // Visit root
    cout << root->data << " ";

    // Visit right subtree
    inorder(root->right);
}

// Postorder Traversal
// Left -> Right -> Root
void postorder(Node* root) {

    // Stop if there is no node
    if (root == nullptr)
        return;

    // Visit left subtree
    postorder(root->left);

    // Visit right subtree
    postorder(root->right);

    // Visit root
    cout << root->data << " ";
}

int main() {

    // Start with an empty tree
    Node* root = nullptr;

    int n, value;

    // Read number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    // Read values and create the BST
    cout << "Enter " << n << " values: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    // Display Preorder
    cout << "\nPreorder (Root-Left-Right): ";
    preorder(root);

    // Display Inorder
    cout << "\nInorder (Left-Root-Right): ";
    inorder(root);

    // Display Postorder
    cout << "\nPostorder (Left-Right-Root): ";
    postorder(root);

    cout << endl;

    return 0;
}
