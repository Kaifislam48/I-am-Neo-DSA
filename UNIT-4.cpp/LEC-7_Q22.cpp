/* Kamal is developing a program that finds the Kth smallest element in a Binary Search Tree (BST). He plans to use the Morris Traversal technique to optimize the search process. Your task is to assist Kamal in verifying and testing his code.



Implement a program that performs the following actions:



Build a Binary Search Tree (BST) by adding integers to it one by one.
Find and print the Kth smallest element in the BST.
Input format :
The first n lines of input consist of a series of positive integers (greater than zero) separated by space.

The input ends when a value (-1) is entered.

The last input of an integer represents the elements to be inserted into the binary search tree.

Output format :
After inserting all the elements into the binary search tree, the program should take an additional input k representing the k-th smallest element to be found in the BST.

The output displays the k-th smallest element in the BST.



Refer to the sample output for the formatting specifications.

Code constraints :
The input integers will be positive and greater than zero.

The number of elements in the binary search tree will be at most 1000.

1 <= k <= number of nodes in the BST.

Sample test cases :
Input 1 :
20
30
40
50
60
70
80
-1
3
Output 1 :
Smallest kth value 40
Input 2 :
1
2
3
4
5
-1
2
Output 2 :
Smallest kth value 2 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    TreeNode* current = root;
    int kthSmallest = 0;

    while (current != NULL) {
        if (current->left == NULL) {
            count++;
            if (count == k) {
                kthSmallest = current->val;
                break;
            }
            current = current->right;
        } else {
            TreeNode* pre = current->left;
            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = NULL;
                count++;
                if (count == k) {
                    kthSmallest = current->val;
                    break;
                }
                current = current->right;
            }
        }
    }

    return kthSmallest;
}

int main() {
    TreeNode* root = NULL;
    int val;
    
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        root = insert(root, val);
    }

    int k;
    cin >> k;

    int result = kthSmallest(root, k);
    cout << "Smallest kth value " << result << endl;

    return 0;
}
