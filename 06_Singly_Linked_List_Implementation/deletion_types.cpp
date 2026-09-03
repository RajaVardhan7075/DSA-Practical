// Delete from beginning
void delete_from_beginning() {
    if (head == nullptr) {
        cout << "Linked list is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}

// Delete from end
void delete_from_end() {
    if (head == nullptr) {
        cout << "Linked list is empty.\n";
        return;
    }

    // Only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    // Move to second-last node
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// Delete node containing target value
void delete_at_position(int target) {
    if (head == nullptr) {
        cout << "Linked list is empty.\n";
        return;
    }

    // If target is the first node
    if (head->data == target) {
        Node* temp = head;
        head = head->next;

        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        if (temp->next->data == target) {
            Node* nodeToDelete = temp->next;

            temp->next = nodeToDelete->next;

            delete nodeToDelete;
            return;
        }

        temp = temp->next;
    }

    cout << "Target " << target << " not found.\n";
}
