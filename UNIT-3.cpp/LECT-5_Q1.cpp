/* You are tasked with implementing a double-ended queue, a data structure that allows elements to be added or removed from both ends. 



You need to create a program that provides the following functionality:

Initialize an empty deque.
Insert elements at the front of the deque.
Insert elements at the back of the deque.
Print the elements of the deque.
Input format :
The first line of input consists of the first integer to insert at the front.

The second line consists of the second integer to insert at the front.

The third line consists of the first integer to insert at the back.

The fourth line consists of the second integer to insert at the back.

The fifth line consists of the third integer to insert at the front.

The sixth line consists of the third integer to insert at the back.

Output format :
The output prints the dequeue elements, separated by space.

Code constraints :
number of inputs = 6

Sample test cases :
Input 1 :
101
201
102
202
103
204
Output 1 :
103 201 101 102 202 204 
Input 2 :
4 
5
6
9
2
3
Output 2 :
2 5 4 6 9 3  */

#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> myDeque; // Initialize an empty deque

    int front1, front2, back1, back2, front3, back3;

    cin >> front1 >> front2 >> back1 >> back2 >> front3 >> back3;

    // Insert elements at the front of the deque
    myDeque.push_front(front1);
    myDeque.push_front(front2);
    myDeque.push_front(front3);

    // Insert elements at the back of the deque
    myDeque.push_back(back1);
    myDeque.push_back(back2);
    myDeque.push_back(back3);

    // Print the elements of the deque
    for (int num : myDeque) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
