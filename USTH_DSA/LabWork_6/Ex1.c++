#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

vector<int> initializeArray(int n) {
    vector<int> arr;
    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 100);
    }

    return arr;
}

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* buildBinaryTree(const vector<int>& arr, int index, int n) {
    if (index >= n) {
        return nullptr;
    }

    Node* temp = createNode(arr[index]);
    temp->left = buildBinaryTree(arr, 2 * index + 1, n);
    temp->right = buildBinaryTree(arr, 2 * index + 2, n);

    return temp;
}

void displayTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    displayTree(root->left);
    cout << root->data << " ";
    displayTree(root->right);
}

Node* searchValue(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }

    Node* leftResult = searchValue(root->left, value);
    Node* rightResult = searchValue(root->right, value);

    if (leftResult != nullptr) {
        return leftResult;
    }

    return rightResult;
}

Node* findParent(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if ((root->left != nullptr && root->left->data == value) || (root->right != nullptr && root->right->data == value)) {
        return root;
    }

    Node* leftParent = findParent(root->left, value);
    if (leftParent != nullptr) {
        return leftParent;
    }

    return findParent(root->right, value);
}

void insertNode(Node* root, int value) {
    if (root == nullptr) {
        cout << "Error: Tree is empty!" << endl;
        return;
    }

    Node* newNode = createNode(value);
    Node* temp = searchValue(root, value);

    if (temp != nullptr) {
        cout << "Error: Node with value " << value << " already exists!" << endl;
        return;
    }

    while (true) {
        if (root->left == nullptr) {
            root->left = newNode;
            break;
        } else if (root->right == nullptr) {
            root->right = newNode;
            break;
        } else {
            root = root->left;
        }
    }
}

void removeNode(Node* root, int value) {
    if (root == nullptr) {
        cout << "Error: Tree is empty!" << endl;
        return;
    }

    Node* targetNode = searchValue(root, value);

    if (targetNode == nullptr) {
        cout << "Error: Node with value " << value << " does not exist!" << endl;
        return;
    }

    Node* parentNode = findParent(root, value);

    if (parentNode == nullptr) {
        cout << "Error: Cannot remove the root node." << endl;
        return;
    }

    if (parentNode->left == targetNode) {
        parentNode->left = nullptr;
    } else {
        parentNode->right = nullptr;
    }

    delete targetNode;
}

int main() {
    int n = 5;
    vector<int> arr = initializeArray(n);

    Node* root = buildBinaryTree(arr, 0, n);

    cout << "Binary Tree: ";
    displayTree(root);
    cout << endl;

    int valueToSearch = 20; 
    Node* searchResult = searchValue(root, valueToSearch);

    if (searchResult != nullptr) {
        cout << "Value " << valueToSearch << " found in the tree." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the tree." << endl;
    }

    int insertValue = 15;
    insertNode(root, insertValue);

    cout << "Updated Tree after insertion: ";
    displayTree(root);
    cout << endl;

    int removeValue = 41;
    removeNode(root, removeValue);

    cout << "Updated Tree after removal: ";
    displayTree(root);
    cout << endl;
}
