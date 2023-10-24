/* You have been given the responsibility to create a program for task management in a to-do list using a Queue data structure. This to-do list has a predefined limit for the number of tasks it can hold, and the tasks will be stored in a Queue that is implemented using a linked list.



Your assignment is to develop the Queue data structure along with the required functions that enable the management of tasks within the to-do list.



The main functionalities of the task queue include:

Enqueue Task: Adding a task to the end of the queue.
Get Front Task: Retrieve the description of the first task in the queue.
Get Rear Task: Retrieve the description of the last task in the queue.
Input format :
The first line of input consists of an integer N, representing the number of tasks to enqueue.

The following N lines consist of the descriptions of the tasks, one per line.



Note: Use cin.ignore() to ignore the newline character after reading the value of N.

Output format :
The output displays the description of the tasks that are in the front and rear in the following format:

"Front Task: <<task name>>"

"Rear Task: Do laundry <<task name>>"



Refer to the sample output for the exact text and format.

Code constraints :
N > 0

The length of each task description is at most 150 characters.

Sample test cases :
Input 1 :
7
Finish report
Schedule meeting
Send emails
Attend training
Prepare presentation
Review documents
Submit expenses
Output 1 :
Front Task: Finish report
Rear Task: Submit expenses
Input 2 :
5
Buy groceries
Pay bills
Walk the dog
Call mom
Do laundry
Output 2 :
Front Task: Buy groceries
Rear Task: Do laundry */

#include <iostream>
#include <string>
using namespace std;

struct TaskNode {
    string description;
    TaskNode* next;
};

class TaskQueue {
private:
    TaskNode* front;
    TaskNode* rear;
    int maxSize;
    int currentSize;

public:
    TaskQueue(int size) {
        front = nullptr;
        rear = nullptr;
        maxSize = size;
        currentSize = 0;
    }

    void enqueue(const string& task) {
        if (currentSize >= maxSize) {
            cout << "To-do list is full. Cannot add more tasks." << endl;
            return;
        }

        TaskNode* newNode = new TaskNode;
        newNode->description = task;
        newNode->next = nullptr;

        if (front == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        currentSize++;
    }

    string getFrontTask() {
        if (front == nullptr) {
            return "To-do list is empty.";
        }

        return front->description;
    }

    string getRearTask() {
        if (rear == nullptr) {
            return "To-do list is empty.";
        }

        return rear->description;
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignore the newline character

    TaskQueue taskQueue(N);

    for (int i = 0; i < N; i++) {
        string task;
        getline(cin, task);
        taskQueue.enqueue(task);
    }

    cout << "Front Task: " << taskQueue.getFrontTask() << endl;
    cout << "Rear Task: " << taskQueue.getRearTask() << endl;

    return 0;
}
