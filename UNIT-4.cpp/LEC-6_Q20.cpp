/* Madhu is responsible for developing a program to manage a task scheduler. Each task is identified by a unique task ID, which is a positive integer.



Your task is to implement a program that reads task IDs as input until a sentinel value (-1) is entered, constructs a binary search tree with the task IDs, and then performs post-order traversal to display the tasks in the scheduler.

Input format :
The input consists of a series of positive integers representing the product IDs of items added to the shopping cart. The input ends when a negative integer (-1) is entered.

Output format :
The post-order traversal of the binary search tree displays the product IDs of items in the shopping cart.



Refer to the sample output for the formatting specifications.

Code constraints :
1 <= task ID <= 100

The input will be terminated by entering '-1'.

Sample test cases :
Input 1 :
6
3
1
4
2
-1
Output 1 :
Post order Traversal:
2 1 4 3 6 
Input 2 :
1
7
9
5
6
-1
Output 2 :
Post order Traversal:
6 5 9 7 1 
Input 3 :
100
20
200
10
30
150
300
-1
Output 3 :
Post order Traversal:
10 30 20 150 300 200 100 */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int taskID) {
    Node* newNode = new Node();
    if (!newNode) {
        return NULL;
    }
    newNode->data = taskID;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int taskID) {
    if (root == NULL) {
        return createNode(taskID);
    }
    if (taskID < root->data) {
        root->left = insertNode(root->left, taskID);
    } else if (taskID > root->data) {
        root->right = insertNode(root->right, taskID);
    }
    return root;
}

void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    int taskID;
    Node* root = NULL;

    while (true) {
        cin >> taskID;
        if (taskID == -1) {
            break;
        }
        root = insertNode(root, taskID);
    }

    cout << "Post order Traversal:" << endl;
    postOrderTraversal(root);

    return 0;
}