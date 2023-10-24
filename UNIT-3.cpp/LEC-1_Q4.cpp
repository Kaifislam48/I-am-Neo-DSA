/* Nayana is given an array of integers and wants to find the Next Greater Element (NGE) for each element in the array. The NGE for an element arr[i] is the first greater element to the right of arr[i] in the array. If there is no greater element to the right, the NGE is considered -1. She needs your help to write a program to find the Next Greater Element (NGE) for each element in an array using a stack-based approach.



Examples:

a) For any array, the rightmost element always has the next greater element as -1.

b) For an array that is sorted in decreasing order, all elements have the next greater element as -1.



Note: This is a sample question asked in Capgemini recruitment.

Input format :
The first line contains an integer n, representing the number of elements in the array.

The next line contains n space-separated integers, representing the elements in the array.

Output format :
The output prints the next greater element for each element in the array.

Code constraints :
1 <= n <= 10

1 <= elements <= 100

Sample test cases :
Input 1 :
4
11 13 21 3
Output 1 :
11 13
13 21
21 -1
3 -1
Input 2 :
4
4 5 2 25
Output 2 :
4 5
5 25
2 25
25 -1
Input 3 :
5
5 4 3 2 1
Output 3 :
5 -1
4 -1
3 -1
2 -1
1 -1 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> nge(n, -1); // Initialize NGE array with -1
    stack<int> st;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            nge[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        if (nge[i] != -1) {
            cout << nge[i];
        } else {
            cout << -1;
        }
        cout << endl;
    }

    return 0;
}
