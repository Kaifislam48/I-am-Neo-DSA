/* You are given a binary tree, and your task is to determine whether it is a binary search tree (BST) or not. 



A binary search tree is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Write a program to check if the given binary tree is a BST or not based on these criteria.

Input format :
The first line of input consists of the root node's value as an integer.

For each non-null node, there will be two inputs: the value of the left child (if exists) or -1 if there is no left child, the value of the right child (if exists) or -1 if there is no right child.

Output format :
Print "The given binary tree is a BST" if the input binary tree satisfies the BST properties.

Otherwise, print "The given binary tree is not a BST".

Sample test cases :
Input 1 :
4 2 1 -1 -1 3 -1 -1 5 -1 -1
Output 1 :
The given binary tree is a BST
Input 2 :
3 2 1 -1 -1 4 -1 -1 5 -1 -1
Output 2 :
The given binary tree is not a BST */

#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(Node* root, int minValue, int maxValue) {
    if (root == nullptr) {
        return true;
    }

    if (root->data < minValue || root->data > maxValue) {
        return false;
    }

    return isBSTUtil(root->left, minValue, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, maxValue);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    int rootData;
    cin >> rootData;

    Node* root = new Node(rootData);

    int leftData, rightData;

    cin >> leftData;
    cin >> rightData;

    if (leftData != -1) {
        root->left = new Node(leftData);
    }
    if (rightData != -1) {
        root->right = new Node(rightData);
    }

    if (isBST(root)) {
        cout << "The given binary tree is a BST" << endl;
    } else {
        cout << "The given binary tree is not a BST" << endl;
    }

    return 0;
}
