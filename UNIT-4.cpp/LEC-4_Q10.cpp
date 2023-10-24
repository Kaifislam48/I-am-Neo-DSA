/* ﻿Imagine a scenario where you are developing a software system for a company that manages inventory for two different warehouses. Each warehouse's inventory is represented as a Binary Search Tree (BST) containing unique product IDs.



Your task is to create a program that checks if the inventory in both warehouses is identical. The program should compare the two BSTs and determine whether they contain the same product IDs or not.

Input format :
The first line of input consists of the space-separated product IDs for the first warehouse's inventory, terminated by -1.

The second line consists of the space-separated product IDs for the second warehouse's inventory, terminated by -1.

Output format :
If the inventories of both warehouses are identical, print "Both BSTs are identical"

Otherwise, print "BSTs are not identical"

Sample test cases :
Input 1 :
5 3 8 2 4 -1
5 3 8 2 4 -1
Output 1 :
Both BSTs are identical
Input 2 :
10 5 15 -1
10 5 20 -1
Output 2 :
BSTs are not identical */

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        root = new Node;
        root->data = data;
        root->left = root->right = nullptr;
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to check if two BSTs are identical
bool areIdenticalBSTs(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    } else if (root1 != nullptr && root2 != nullptr) {
        return (root1->data == root2->data) && 
               areIdenticalBSTs(root1->left, root2->left) && 
               areIdenticalBSTs(root1->right, root2->right);
    } else {
        return false;
    }
}

// Function to construct a BST from a space-separated string of integers
Node* constructBST(const string& input) {
    istringstream iss(input);
    vector<int> productIds;
    int id;
    
    while (iss >> id) {
        if (id == -1) {
            break;
        }
        productIds.push_back(id);
    }

    Node* root = nullptr;
    for (int productId : productIds) {
        root = insert(root, productId);
    }
    return root;
}

int main() {
    string input1, input2;
    getline(cin, input1);
    getline(cin, input2);

    Node* root1 = constructBST(input1);
    Node* root2 = constructBST(input2);

    if (areIdenticalBSTs(root1, root2)) {
        cout << "Both BSTs are identical" << endl;
    } else {
        cout << "BSTs are not identical" << endl;
    }

    return 0;
}
