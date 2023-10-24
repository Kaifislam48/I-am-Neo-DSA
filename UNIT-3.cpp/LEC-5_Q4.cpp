/* Ethan is working on a data analysis project that involves analyzing sales data from different regions. As part of his task, he needs to identify and display the data that has been sold the most using a double-ended queue (deque).



Write a program that Ethan can use to find and print the product ID that has been sold the most. 

Input format :
The input consists of the elements of the dequeue.

The input is terminated by entering -1.

Output format :
The output prints the most repeated element in the given dequeue, along with the count.



Refer to the sample output for the exact text and format.

Sample test cases :
Input 1 :
1
2
2
3
3
3
4
-1
Output 1 :
Most Repeated Element is 3 with Count 3
Input 2 :
11
15
15
22
-1
Output 2 :
Most Repeated Element is 15 with Count 2 */

#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;

int main() {
    deque<int> myDeque;

    int element;
    unordered_map<int, int> countMap; // To keep track of element counts

    while (true) {
        cin >> element;

        if (element == -1) {
            break;
        }

        myDeque.push_back(element);
        countMap[element]++;
    }

    int maxCount = 0;
    int mostRepeatedElement = -1;

    for (const auto& pair : countMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostRepeatedElement = pair.first;
        }
    }

    if (mostRepeatedElement != -1) {
        cout << "Most Repeated Element is " << mostRepeatedElement << " with Count " << maxCount << endl;
    }

    return 0;
}
