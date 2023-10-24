/* You are designing an event registration system for a conference. 



As part of the system, you need to implement a Queue data structure using an array that stores only the even numbers representing the registration IDs of the participants. 



The queue will be used to keep track of the order in which participants register for the event.

Input format :
The first line of input consists of an integer N, representing the number of participants to register.

The following N lines consist of integers, representing the registration IDs of the participants.

Output format :
The output prints only the even number registration IDs of the participants in the order they registered, separated by space.

For odd registration IDs, print "Invalid element <element> Only even numbers can be enqueued".

Code constraints :
1 <= N <= 100

Sample test cases :
Input 1 :
6
2
4
6
8
10
12
Output 1 :
2 4 6 8 10 12 
Input 2 :
4
14
36
55
48
Output 2 :
Invalid element 55, only even numbers can be enqueued
14 36 48 
 */

#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue more elements." << endl;
            return;
        }

        if (value % 2 != 0) {
            cout << "Invalid element " << value << ", only even numbers can be enqueued" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        arr[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        int value = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }

        return value;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int N;
    cin >> N;

    Queue queue(N);

    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        if (id % 2 == 0) {
            queue.enqueue(id);
        } else {
            cout << "Invalid element " << id << ", only even numbers can be enqueued" << endl;
        }
    }

    queue.display();

    return 0;
}
