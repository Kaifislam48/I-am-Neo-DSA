/* Bindu is working on a problem involving tree traversal, particularly the in-order traversal of a tree. She needs to construct a binary search tree (BST) from a set of integers and then traverse it in an in-order manner. 



Can you help her?



Write a program that takes a set of integers as input and constructs a binary search tree (BST) from those integers. After constructing the BST, perform an in-order traversal and display the elements in sorted order.

Input format :
The first line of input consists of an integer N, representing the number of integers to be inserted into the BST.

The second line consists of N space-separated integers, which are the elements to be inserted into the BST.

Output format :
The output displays the elements of the BST after performing an in-order traversal.

Sample test cases :
Input 1 :
5
4 2 6 1 3
Output 1 :
1 2 3 4 6 
Input 2 :
10
8 4 12 2 6 10 14 1 3 5
Output 2 :
1 2 3 4 5 6 8 10 12 14  */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    int N;
    cin >> N;

    int num;
    cin.ignore();
    Node* root = NULL;

    for (int i = 0; i < N; i++) {
        cin >> num;
        root = insertNode(root, num);
    }

    inOrderTraversal(root);

    return 0;
}