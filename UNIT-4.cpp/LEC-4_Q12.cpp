/* You are working on a critical customer database system for a large e-commerce platform. 



The database stores customer information, like their unique customer IDs, in a binary tree structure. Ensuring data integrity is paramount, as duplicate customer IDs can lead to serious data inconsistencies and operational issues. 



Your task is to develop a program that checks whether the binary tree containing customer IDs has any duplicate values. Detecting duplicates is essential to maintain the accuracy of customer records.

Input format :
The first line of input consists of an integer representing the value of the root node.

For each node in the tree, there are two integers,

Left child data: an integer representing the value of the left child node. Use -1 to indicate no left child.

Right child data: an integer representing the value of the right child node. Use -1 to indicate no right child.

Output format :
Print "Yes" if there are any duplicate customer IDs in the binary tree.

Otherwise, print "No".

Code constraints :
1 <= Number of nodes in the binary tree <= 100

1 <= Customer ID (node value) <= 100

Sample test cases :
Input 1 :
1
1
-1
-1
-1
-1
Output 1 :
Yes
Input 2 :
5
3
7
2
8
-1
-1
-1
-1
-1
-1
Output 2 :
No */

#include <iostream>
#include <unordered_set>
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

bool checkDuplicates(Node* root, unordered_set<int>& visitedIDs) {
    if (root == NULL) {
        return false;
    }
    if (visitedIDs.find(root->data) != visitedIDs.end()) {
        return true;
    }
    visitedIDs.insert(root->data);
    return checkDuplicates(root->left, visitedIDs) || checkDuplicates(root->right, visitedIDs);
}

bool hasDuplicateIDs(Node* root) {
    unordered_set<int> visitedIDs;
    return checkDuplicates(root, visitedIDs);
}

int main() {
    int rootData;
    cin >> rootData;

    Node* root = createNode(rootData);

    int leftChildData, rightChildData;
    cin >> leftChildData >> rightChildData;

    if (leftChildData != -1) {
        root->left = createNode(leftChildData);
    }
    if (rightChildData != -1) {
        root->right = createNode(rightChildData);
    }

    bool hasDuplicates = hasDuplicateIDs(root);
    if (hasDuplicates) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}