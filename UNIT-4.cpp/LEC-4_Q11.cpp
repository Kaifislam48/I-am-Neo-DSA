/* You are given a binary search tree (BST) and an integer k. Your task is to find the kth smallest element in the BST.



Implement the function kthSmallest that takes the root of the BST and an integer k as input and returns the kth smallest element in the BST.

Input format :
The first line of input consists of a sequence of integers representing the elements of the BST. The input is terminated by -1.

The second line consists of an integer k, representing the position of the desired smallest element.

Output format :
The output prints a single integer, which is the kth smallest element in the BST.

Sample test cases :
Input 1 :
20 8 22 4 12 10 14 -1
3
Output 1 :
10
Input 2 :
20 8 4 12 10 14 22 -1
4
Output 2 :
12 */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int kthSmallestUtil(Node* root, int& k) {
    if (root == nullptr) {
        return -1;
    }

    int left = kthSmallestUtil(root->left, k);
    if (left != -1) {
        return left;
    }

    k--;
    if (k == 0) {
        return root->data;
    }

    return kthSmallestUtil(root->right, k);
}

int kthSmallest(Node* root, int k) {
    return kthSmallestUtil(root, k);
}

int main() {
    int value;
    Node* root = nullptr;

    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        root = insert(root, value);
    }

    int k;
    cin >> k;

    int result = kthSmallest(root, k);

    cout << result << endl;

    return 0;
}
