/* In a grocery store, customers join a single queue to check out their items. The grocery store wants to implement a system to manage the checkout queue using a data structure. 



Each customer's arrival is recorded and added to the queue. The grocery store staff wants to display the queue in reverse order to check the customers' positions.



Implement a program to manage a grocery store checkout queue using a linked list. The program should allow customers to join the queue, and the order of their arrival should be reversed, meaning the first customer to join becomes the last in line. The program should display the current state of the queue.

Input format :
The first line of input consists of an integer N, representing the number of customers in the queue.

The next line consists of N space-separated integers, representing the customer positions.

Output format :
If the queue is not empty: Print the current state of the checkout queue, and display the customer positions in reverse order.

If the queue is empty: A message stating that the queue is empty.



Refer to the sample output for the exact text and format.

Code constraints :
N > 0

Sample test cases :
Input 1 :
3
5 10 15
Output 1 :
Queue: 15 10 5 
Input 2 :
6
10 15 20 25 30 35
Output 2 :
Queue: 35 30 25 20 15 10 
Input 3 :
0
Output 3 :
Queue is empty. */


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (front == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void displayReverseQueue(Node* front) {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* current = front;
    int size = 0;
    while (current != nullptr) {
        size++;
        current = current->next;
    }

    int* positions = new int[size];
    current = front;
    for (int i = size - 1; i >= 0; i--) {
        positions[i] = current->data;
        current = current->next;
    }

    cout << "Queue:";
    for (int i = 0; i < size; i++) {
        cout << " " << positions[i];
    }
    cout << endl;

    delete[] positions;
}

int main() {
    int N;
    cin >> N;
    Node* front = nullptr;
    Node* rear = nullptr;

    for (int i = 0; i < N; i++) {
        int position;
        cin >> position;
        enqueue(front, rear, position);
    }

    displayReverseQueue(front);

    return 0;
}
