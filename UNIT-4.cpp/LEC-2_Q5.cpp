/* You are a student attending a class on sorting techniques taught by Professor Smith. Today, Professor Smith is explaining how to efficiently sort both positive and negative values using the merge sort algorithm and a recursive function. To better understand the concept, you decide to write a program.



Your task is to write code to implement a recursive merge sort algorithm for sorting positive and negative floating-point numbers, as explained by Professor Smith.

Input format :
The first line contains an integer n, representing the number of values to be sorted.

The second line contains n space-separated floating-point numbers.

Output format :
The output displays a single line containing n space-separated floating-point numbers, representing the sorted values in ascending order. Each number is rounded to two decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 15

-100.0 ≤ floating point numbers ≤ 100.0

Sample test cases :
Input 1 :
5
3.14 1.1 2.71 0.5 1.618
Output 1 :
Sorted Array:
0.50 1.10 1.62 2.71 3.14 
Input 2 :
6
-2.5 5.0 0.0 -1.5 2.0 3.5
Output 2 :
Sorted Array:
-2.50 -1.50 0.00 2.00 3.50 5.00  */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<double> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

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

void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<double> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    mergeSort(numbers, 0, n - 1);

    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}
