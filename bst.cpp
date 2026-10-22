#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left_child;
    Node *right_child;

    Node(int key) {
        data = key;
        left_child = nullptr;
        right_child = nullptr;
    }
};

Node* insertR(Node* r, int val) {
    if (r == nullptr) {
        return new Node(val);
    }

    if (r->data == val) {
        return r;
    }

    if (val > r->data) {
        r->right_child = insertR(r->right_child, val);
    } 
    else {
        r->left_child = insertR(r->left_child, val);
    }
    return r;
}
Node* search(Node* r, int val) {
    Node* current = r;

    while (current != nullptr) {
        if (current->data == val) {
            return current;
        }

        if (val < current->data) {
            current = current->left_child;
        } else {
            current = current->right_child;
        }
    }

    return nullptr;
}
Node* findMin(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node* current = root;
    while (current->left_child != nullptr) {
        current = current->left_child;
    }
    return current;
}

Node* findMax(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node* current = root;
    while (current->right_child != nullptr) {
        current = current->right_child;
    }
    return current;
}

int countNodes(const Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left_child) + countNodes(root->right_child);
}

int countLeaves(const Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left_child == nullptr && root->right_child == nullptr) {
        return 1;
    }
    return countLeaves(root->left_child) + countLeaves(root->right_child);
}

int countInRange(const Node* root, int min, int max) {
    if (root == nullptr) {
        return 0;
    }
    
    if (root->data > max) {
        return countInRange(root->left_child, min, max);
    }
    
    if (root->data < min) {
        return countInRange(root->right_child, min, max);
    }
    
    return 1 + countInRange(root->left_child, min, max) + countInRange(root->right_child, min, max);
}

