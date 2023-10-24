/* You are developing a food delivery platform that handles orders from two different regions. The system uses two queues implemented using linked lists to manage incoming orders from each region. 



Your task is to implement a program that checks if the two queues have the same order sequence.

Input format :
The first line consists of an integer N1, representing the number of orders for the first queue.

The second line consists of N1 space-separated integers, representing the order details for the first queue.

The third line consists of an integer N2, representing the number of orders for the second queue.

The fourth line consists of N2 space-separated integers, representing the order details for the second queue.

Output format :
The output prints whether the queues have the same elements or different elements.



Refer to the sample output for the exact text and format.

Code constraints :
The order numbers are integers.

The number of orders for each queue is non-negative.

Sample test cases :
Input 1 :
3
1 2 3
3
1 2 3
Output 1 :
The queues have the same elements in the same order.
Input 2 :
1
2 
4
8 3 9 6
Output 2 :
The queues do not have the same elements in the same orde */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void enqueue(Node*& rear, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (rear == nullptr) {
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue(Node*& front) {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
        return -1;
    }

    int data = front->data;
    Node* temp = front;
    front = front->next;
    delete temp;
    return data;
}

bool areQueuesEqual(Node* queue1Front, Node* queue2Front) {
    while (queue1Front != nullptr && queue2Front != nullptr) {
        if (queue1Front->data != queue2Front->data) {
            return false;
        }
        queue1Front = queue1Front->next;
        queue2Front = queue2Front->next;
    }

    return queue1Front == nullptr && queue2Front == nullptr;
}

int main() {
    int N1, N2;
    cin >> N1;
    Node* queue1Front = nullptr;
    Node* queue1Rear = nullptr;

    for (int i = 0; i < N1; i++) {
        int order;
        cin >> order;
        enqueue(queue1Rear, order);
        if (queue1Front == nullptr) {
            queue1Front = queue1Rear;
        }
    }

    cin >> N2;
    Node* queue2Front = nullptr;
    Node* queue2Rear = nullptr;

    for (int i = 0; i < N2; i++) {
        int order;
        cin >> order;
        enqueue(queue2Rear, order);
        if (queue2Front == nullptr) {
            queue2Front = queue2Rear;
        }
    }

    if (areQueuesEqual(queue1Front, queue2Front)) {
        cout << "The queues have the same elements in the same order." << endl;
    } else {
        cout << "The queues do not have the same elements in the same order." << endl;
    }

    return 0;
}
