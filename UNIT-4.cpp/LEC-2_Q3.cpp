/* Arsha is working on a project where binary data is an essential part of the processing. To optimize data handling, Arsha needs to sort an array containing only two types of elements: 0s and 1s. Alex decides to implement a merge sort algorithm to efficiently sort this binary data.



Write a program to assist Arsha in implementing the logic of merge sort along with a recursive function to sort an array of binary data in ascending order.

Input format :
The first line contains an integer, representing the number of elements in the array.

The second line contains n space-separated integers, where each integer is either 0 or 1.

Output format :
The output displays the following result:



If the input contains elements other than 0 and 1, print "Invalid input.".
Otherwise, print a single line containing n space-separated integers, representing the sorted array in ascending order.


Refer to the sample outputs for the exact format.

Code constraints :
1 ≤ n ≤ 20

input = 0, and 1 only

Sample test cases :
Input 1 :
5
1 0 1 0 1
Output 1 :
0 0 1 1 1 
Input 2 :
3
1 0 2
Output 2 :
Invalid input.
Input 3 :
4
1 1 1 1
Output 3 :
1 1 1 1 
Input 4 :
2
0 0
Output 4 :
0 0  */

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] != 0 && arr[i] != 1) {
            cout << "Invalid input." << endl;
            return 0;
        }
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}