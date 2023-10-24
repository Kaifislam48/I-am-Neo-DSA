/* You've been assigned the challenge of developing a queue data structure using a linked list.



The program should allow users to interact with the queue by enqueuing positive integers and subsequently dequeuing and displaying elements.

Input format :
The input consists of a series of integers, one per line.

Enter positive integers into the queue.

Enter -1 to terminate input.

Output format :
The output prints the space-separated dequeued elements in the format:

"Dequeued elements: <<value 1>> <<value 2>> <<value 3>> ......... <<value n>>



Refer to the sample output for the exact text and format.

Sample test cases :
Input 1 :
1
2
3
4
-1
Output 1 :
Dequeued elements: 1 2 3 4 
Input 2 :
56
74
36
94
15
34
-1
Output 2 :
Dequeued elements: 56 74 36 94 15 34 */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue queue;

    while (true) {
        int value;
        cin >> value;

        if (value == -1) {
            break;
        }

        if (value > 0) {
            queue.enqueue(value);
        }
    }

    cout << "Dequeued elements:";
    while (!queue.isEmpty()) {
        int value = queue.dequeue();
        cout << " " << value;
    }
    cout << endl;

    return 0;
}
