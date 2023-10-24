/* A computing system executes multiple tasks simultaneously. Your task is to implement a priority queue that prioritizes these tasks based on their importance and urgency.



The priority queue should prioritize tasks based on the following criteria:

Tasks with higher priority should be executed first.
In the case of tasks with equal priority, tasks with earlier deadlines should be executed first.


Your goal is to implement a custom priority queue using an array-based data structure. 



The priority queue should support the following operations:

push(task): Inserts a new task into the priority queue according to the priority and deadline criteria.
pop(): Removes and returns the highest-priority task from the priority queue.
top(): Returns the highest-priority task from the priority queue without removing it.
empty(): Returns true if the priority queue is empty; otherwise, returns false.


Note: A higher integer specifies high priority.

Input format :
The first line of the input consists of an integer N, the number of tasks to be executed by the computing system.

The following N lines of the input contain task details in the following format:

priority deadline taskName

where the priority is an integer representing the priority of the task, the deadline is an integer representing the deadline of the task, and taskName is a string representing the name of the task.

Output format :
The output prints a list of tasks executed by the computing system, in the order they were executed.



Refer to the sample output for the exact text and format.

Code constraints :
1 <= N <= 10^5

1 <= priority <= 10^9

1 <= deadline <= 10^9

Sample test cases :
Input 1 :
4
5 1 Task1
1 2 Task2
4 2 Task3
6 1 Task4
Output 1 :
Executed Tasks:
Task4
Task1
Task3
Task2
Input 2 :
4
100 4 Task1
100 2 Task2
100 3 Task3
100 1 Task4
Output 2 :
Executed Tasks:
Task4
Task2
Task3
Task1 */


#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Task {
    int priority;
    int deadline;
    string taskName;

    // Overloading the < operator to compare tasks based on priority and deadline
    bool operator<(const Task& other) const {
        if (priority != other.priority)
            return priority < other.priority;
        else
            return deadline > other.deadline;
    }
};

int main() {
    int N;
    cin >> N;

    priority_queue<Task> pq;

    for (int i = 0; i < N; i++) {
        Task task;
        cin >> task.priority >> task.deadline >> task.taskName;
        pq.push(task);
    }
    cout << "Executed Tasks:" << endl;
    while (!pq.empty()) {
        Task task = pq.top();
        pq.pop();
        cout << task.taskName << endl;
    }

    return 0;
}