/* Dharshan is working on a program that involves binary trees. He needs to implement a program that calculates the post-order traversal of a binary tree. Specifically, he needs to create a function that, given the root of a binary tree, returns an array containing the post-order traversal of the tree.



Note:



The binary tree can have a maximum of 100 nodes.
All node values in the binary tree are unique.
For a node at index i in the input array, Its left child is at index 2 * i + 1, and its right child is at index 2 * i + 2.
The array represents the binary tree's structure, with each index corresponding to a node and its value.
Input format :
The first line contains an integer n, representing the number of elements in the array.

The second line contains n space-separated integers, arr [i], representing the values of the nodes in the binary tree. The elements are given in the order of a binary tree, where the i-th element is the value of the i-th node.

Output format :
The output displays a single line containing n space-separated integers, which represent the postorder traversal of the binary tree constructed from the input array.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 15

1 ≤ arr[i] ≤ 100

Sample test cases :
Input 1 :
6
1 2 3 4 5 6
Output 1 :
4 5 2 6 3 1  */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void postOrderTraversal(TreeNode* root, vector<int>& result) {
    if (root) {
        postOrderTraversal(root->left, result);
        postOrderTraversal(root->right, result);
        result.push_back(root->val);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<TreeNode*> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = new TreeNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n) {
            nodes[i]->left = nodes[2 * i + 1];
        }
        if (2 * i + 2 < n) {
            nodes[i]->right = nodes[2 * i + 2];
        }
    }

    vector<int> postOrder;
    postOrderTraversal(nodes[0], postOrder);

    for (int i = 0; i < n; i++) {
        cout << postOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
