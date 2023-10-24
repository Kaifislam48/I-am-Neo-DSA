/* Write a program to implement a priority queue using an array-based approach. 



The priority queue should support the following operations:

Enqueue: Insert an element into the priority queue with a specified priority.
Dequeue: Remove the element with the highest priority from the priority queue.
isEmpty: Check if the priority queue is empty.
isFull: Check if the priority queue is full.
printPriorityQueue: Print the elements of the priority queue in the order of their priorities.


Note: This kind of question will be helpful in clearing Wipro recruitment.

Input format :
The first line of input consists of an integer N, representing the number of elements to be inserted into the priority queue.

This is followed by N lines, each containing two space-separated integers: element and priority.

The element represents the value to be inserted, and priority represents its priority. The priorities are non-negative integers.

Output format :
The first line of output prints the initial state of the priority queue after inserting all the elements, based on priority.

The second line prints the state of the priority queue after performing the dequeue operation.



Refer to the sample output for the exact text and format.

Code constraints :
The priority queue can store up to 100 elements (MAX_SIZE = 100).

Each element value is an integer ranging from −102 to 102

Each priority value is an integer ranging from 1 to 100.

Sample test cases :
Input 1 :
5
4 2
3 1
6 4
2 3
1 5
Output 1 :
Priority Queue: 3 4 2 6 1 
Priority Queue: 4 2 6 1 
Input 2 :
3
9 1
2 2
7 3
Output 2 :
Priority Queue: 9 2 7 
Priority Queue: 2 7  */

#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class PriorityQueue {
private:
    int* elements;
    int* priorities;
    int size;

public:
    PriorityQueue() {
        elements = new int[MAX_SIZE];
        priorities = new int[MAX_SIZE];
        size = 0;
    }

    ~PriorityQueue() {
        delete[] elements;
        delete[] priorities;
    }

    void enqueue(int element, int priority) {
        if (isFull()) {
            cout << "Priority Queue is full. Cannot enqueue." << endl;
            return;
        }

        int i = size - 1;
        while (i >= 0 && priority < priorities[i]) {
            elements[i + 1] = elements[i];
            priorities[i + 1] = priorities[i];
            i--;
        }

        elements[i + 1] = element;
        priorities[i + 1] = priority;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int highestPriorityElement = elements[0];

        for (int i = 1; i < size; i++) {
            elements[i - 1] = elements[i];
            priorities[i - 1] = priorities[i];
        }

        size--;
        return highestPriorityElement;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == MAX_SIZE;
    }

    void printPriorityQueue() const {
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    PriorityQueue priorityQueue;

    for (int i = 0; i < n; i++) {
        int element, priority;
        cin >> element >> priority;
        priorityQueue.enqueue(element, priority);
    }

    priorityQueue.printPriorityQueue();

    int highestPriorityElement = priorityQueue.dequeue();

    if (!priorityQueue.isEmpty()) {
        priorityQueue.printPriorityQueue();
    } else {
        cout << "Empty" << endl;
    }

    return 0;
}
