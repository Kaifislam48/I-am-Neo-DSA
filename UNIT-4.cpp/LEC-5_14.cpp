/* Sara is an aspiring computer scientist working on a binary tree problem. Her task is to compare two binary trees to see if they are identical in structure and values. Can you assist her in solving this challenge?



To accomplish this, you need to develop a function that takes the roots of two binary trees as input and performs a preorder traversal on both trees simultaneously. 



During the traversal, you will compare the values of the corresponding nodes in both trees. If at any point the values differ, the trees are not identical, and the function should return false. However, if the traversal completes without finding any differences, the trees are considered identical, and the function should return true.

Input format :
The first line of input consists of an integer n1, followed by a list of space-separated integers representing the elements to be inserted into the first binary tree.

The third line consists of an integer n2, followed by a list of space-separated integers representing the elements to be inserted into the second binary tree.

Output format :
If the two binary trees are identical, the output prints, "The two binary trees are identical."

Otherwise, print "The two binary trees are not identical."

Sample test cases :
Input 1 :
5
10 5 15 2 8
5
10 5 15 2 8
Output 1 :
The two binary trees are identical.
Input 2 :
3
5 12 8
3
10 2 1
Output 2 :
The two binary trees are not identical.
Input 3 :
3
10 2 8
2
10 2
Output 3 :
The two binary trees are not identical. */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int preStart, int preEnd) {
    if (inStart > inEnd || preStart > preEnd) {
        return nullptr;
    }

    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    int inIndex = inStart;
    while (inIndex <= inEnd && inorder[inIndex] != rootVal) {
        inIndex++;
    }

    int leftSubtreeSize = inIndex - inStart;

    root->left = buildTree(inorder, preorder, inStart, inIndex - 1, preStart + 1, preStart + leftSubtreeSize);
    root->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preStart + leftSubtreeSize + 1, preEnd);

    return root;
}

bool isIdentical(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) {
        return true;
    }
    if (!root1 || !root2) {
        return false;
    }
    if (root1->val != root2->val) {
        return false;
    }
    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

int main() {
    int n1, n2;
    cin >> n1;
    vector<int> preorder1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> preorder1[i];
    }
    cin >> n2;
    vector<int> preorder2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> preorder2[i];
    }

    TreeNode* root1 = buildTree(preorder1, preorder1, 0, n1 - 1, 0, n1 - 1);
    TreeNode* root2 = buildTree(preorder2, preorder2, 0, n2 - 1, 0, n2 - 1);

    if (isIdentical(root1, root2)) {
        cout << "The two binary trees are identical." << endl;
    } else {
        cout << "The two binary trees are not identical." << endl;
    }

    return 0;
}
