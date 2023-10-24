/* Alex is a computer science enthusiast who is fascinated by data structures. Recently, Alex started learning about binary search trees and wants to implement a program that creates a binary search tree based on given inputs and then traverses the tree in preorder.



You are tasked with helping Alex by creating a program that should be structured as follows:

Define the necessary structures and functions.
Accept input integers from Alex until a non-positive integer is given (less than 1).
Build the binary search tree based on the input.
Perform a preorder traversal of the binary search tree and display the node data in preorder.


Note: An infinite line of integer input represents the nodes of the binary search tree. If any value less than 1 is encountered, the input loop has to break and print the preorder traversal of the tree.

Input format :
The input consists of space-separated positive integers, representing the nodes of a binary search tree.

The program will continue indefinitely until a value less than 1 is encountered, indicating the end of the input.

Output format :
The output prints the pre-order traversal of the constructed binary search tree, separated by space.

Code constraints :
0 < input integers <= 103

Sample test cases :
Input 1 :
2 3 1 0
Output 1 :
2 1 3 
Input 2 :
4 3 5 2 6 -9
Output 2 :
4 3 2 5 6  */

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

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int data;
    Node* root = NULL;

    while (true) {
        cin >> data;
        if (data < 1) {
            break;
        }
        root = insertNode(root, data);
    }

    preorderTraversal(root);

    return 0;
}