/* Dev is learning about binary trees and their traversals. He is particularly interested in the in-order traversal of a binary tree. 



He decides to write a program to perform an in-order traversal of a binary tree.



Write a program to help Dev that takes as input a set of integers and constructs a binary tree. Then, perform an in-order traversal of the tree and print the values of the nodes.

Input format :
The first line of input consists of an integer N, representing the number of nodes in the binary tree.

The second line consists of N integers, representing the values of the nodes in the tree.

Output format :
The output prints the in-order traversal of the tree.

Sample test cases :
Input 1 :
4 
17 23 65 24
Output 1 :
17 23 24 65 
Input 2 :
6
78 22 30 12 34 27
Output 2 :
12 22 27 30 34 78  */

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

    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        root = insertNode(root, data);
    }

    inOrderTraversal(root);

    return 0;
}