/* Your task is to create a program that implements a deque (double-ended queue) data structure. The program should count the number of alternate elements in the deque and return the result.

Input format :
The input consists of the elements of the dequeue.

The input is terminated by entering -1.

Output format :
The output prints the count of the alternate elements.



Refer to the sample output for the exact text and format.

Sample test cases :
Input 1 :
1
2
3
4
-1
Output 1 :
Number of alternate elements in the deque: 2
Input 2 :
1
2
-1
Output 2 :
Number of alternate elements in the deque: 1 */

#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> myDeque;

    int element;
    int count = 0;
    bool isAlternate = false;

    while (true) {
        cin >> element;

        if (element == -1) {
            break; // Exit the loop when -1 is encountered
        }

        myDeque.push_back(element);

        if (isAlternate) {
            count++;
        }

        isAlternate = !isAlternate; // Toggle isAlternate flag
    }

    cout << "Number of alternate elements in the deque: " << count << endl;

    return 0;
}
