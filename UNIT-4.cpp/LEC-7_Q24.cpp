/* 
Revi is fascinated by binary search trees (BSTs) and wants to perform some operations on them. He wishes to construct a binary search tree from a series of positive integers and calculate the sum of all the nodes in the BST.



Write a program to help Revi implement these operations using the BST concept.

Input format :
The input consists of a series of positive integers (greater than zero) separated by a space.

The input ends when -1 is entered.

The integers represent the elements to be inserted into the binary search tree.

Output format :
The output displays an integer value, which represents the sum of all the nodes in the BST.



Refer to the sample output for formatting specifications.

Code constraints :
The input integers will be positive and greater than zero.

The number of elements in the binary search tree will be at most 100.

Sample test cases :
Input 1 :
5
3
7
2
4
9
-1
Output 1 :
Sum of all nodes in the BST is 30
Input 2 :
6
3
1
4
2
-1
Output 2 :
Sum of all nodes in the BST is 16 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int sumOfNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    TreeNode* root = nullptr;
    int val;
    
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        root = insert(root, val);
    }

    int sum = sumOfNodes(root);
    cout << "Sum of all nodes in the BST is " << sum << endl;

    return 0;
}
