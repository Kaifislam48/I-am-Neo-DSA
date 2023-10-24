/* You are given a series of integers, and your task is to process them using a Queue data structure. 



Implement a program to perform the following operations:

Initialize an empty queue.
Read an integer N from the standard input. This integer represents the number of elements to be processed.
Read N integers from the standard input and enqueue them into the queue one by one.
Calculate the sum of all the elements in the queue.
Output the sum to the standard output.
Input format :
The first line of input consists of an integer N, representing the number of elements in the queue.

The second line consists of N space-separated integers, each representing an element of the queue.

Output format :
If the queue is empty, print "Queue is empty." on a new line.

Otherwise, print the sum of the numbers in the queue.

Code constraints :
-102 ≤ element ≤ 102 (the value of an element in the queue)

The maximum capacity of the queue is 100.

Sample test cases :
Input 1 :
5
1 2 3 4 5
Output 1 :
15
Input 2 :
3
10 -20 30
Output 2 :
20
Input 3 :
0
Output 3 :
Queue is empty. */

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    queue<int> q;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        int element;
        cin >> element;
        q.push(element);
        sum += element;
    }

    if (q.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << sum << endl;
    }

    return 0;
}
