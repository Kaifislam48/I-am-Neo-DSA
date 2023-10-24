/* Ragul wants to build a binary search tree (BST) and perform a key search operation on it. He needs your help to accomplish this. Write a program that helps Ragul create a BST and search for a specific key within it.



Note: This kind of question will help in clearing Wipro recruitment.

Input format :
The first line of input consists of the number of nodes n.

The second line of input consists of n unique values for nodes, separated by a space.

The third line of input consists of the key to be searched.

Output format :
The output displays one of the following messages based on whether the key is found in the binary search tree or not in the following format:



If the key is found in the binary search tree, print "The key <<key value>> is found in the binary search tree"
If the key is not found in the binary search tree, print "The key <<key value>> is not found in the binary search tree"


Refer to the sample output for the exact format.

Code constraints :
1 ≤ numNodes ≤ 10

Each node value is a unique integer.

1 <= key <= 1000

Sample test cases :
Input 1 :
7
101 102 103 105 106 108 110
102
Output 1 :
The key 102 is found in the binary search tree
Input 2 :
7
101 102 103 105 106 108 110
115
Output 2 :
The key 115 is not found in the binary search tree */

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

bool search(TreeNode* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->val == key) {
        return true;
    }
    if (key < root->val) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    int numNodes;
    cin >> numNodes;
    TreeNode* root = nullptr;

    for (int i = 0; i < numNodes; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int key;
    cin >> key;

    if (search(root, key)) {
        cout << "The key " << key << " is found in the binary search tree" << endl;
    } else {
        cout << "The key " << key << " is not found in the binary search tree" << endl;
    }

    return 0;
}
