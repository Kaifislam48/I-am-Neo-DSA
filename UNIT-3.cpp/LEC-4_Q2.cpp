/* You are given a task by your teacher. The task is to develop a student registration system for a university. The system needs to maintain a priority queue of student registration requests based on their admission urgency.



Each student registration request is represented by a unique identifier (ID) and has an associated priority value. The priority is determined based on the urgency of admission, with higher priority given to students who are both highly motivated for admission and have exceptional academic achievements.



To implement the priority queue, you have decided to use a linked list data structure with a priority queue approach. Each student registration request will be stored in a node of the linked list, along with its priority value. The linked list will be organized in such a way that student requests with smaller priority values will be positioned first.

Input format :
The first line of input specifies the number of student registration requests to be processed.

The following input line each will contain two integers separated by space: the unique identifier (ID) of a student registration request and its priority value.

Output format :
The program should output the student registration requests in the priority queue after all the requests have been processed.

The student requests with smaller priority values will be positioned first.



Refer to the sample output for the exact text and format.

Code constraints :
The student registration system can handle up to 1000 registration requests.

The priority values range from 1 to 10.

Sample test cases :
Input 1 :
5
101 3
102 5
103 4
104 2
105 1
Output 1 :
Priority Queue: 105 104 101 103 102 
Input 2 :
3
201 8
202 9
203 7
Output 2 :
Priority Queue: 203 201 202  */


#include <iostream>

using namespace std;

struct StudentRequest {
    int id;
    int priority;
    StudentRequest* next;

    StudentRequest(int id, int priority) : id(id), priority(priority), next(nullptr) {}
};

void insert(StudentRequest*& head, int id, int priority) {
    StudentRequest* newNode = new StudentRequest(id, priority);

    if (!head || priority < head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        StudentRequest* current = head;
        while (current->next && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printPriorityQueue(StudentRequest* head) {
    cout << "Priority Queue: ";
    while (head) {
        cout << head->id << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    StudentRequest* priorityQueue = nullptr;

    for (int i = 0; i < n; i++) {
        int id, priority;
        cin >> id >> priority;
        insert(priorityQueue, id, priority);
    }

    printPriorityQueue(priorityQueue);

    while (priorityQueue) {
        StudentRequest* temp = priorityQueue;
        priorityQueue = priorityQueue->next;
        delete temp;
    }

    return 0;
}
