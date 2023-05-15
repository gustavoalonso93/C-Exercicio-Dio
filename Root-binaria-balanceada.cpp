#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Erro ao alocar memória.\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* leftRotate(Node* root) {
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

Node* rightRotate(Node* root) {
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    int balance = getHeight(root->left) - getHeight(root->right);
    if (balance > 1) {
        if (data < root->left->data) {
            root = rightRotate(root);
        } else {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
    } else if (balance < -1) {
        if (data > root->right->data) {
            root = leftRotate(root);
        } else {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
    }

    return root;
}

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

return 0;
}