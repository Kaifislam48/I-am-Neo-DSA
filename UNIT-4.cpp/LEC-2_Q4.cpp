/* Alice is working on a project that requires sorting and displaying the frequency of elements in an array. She needs your help to write a program to sort an array of positive integers and display the elements sorted by frequency in descending order. If two elements have the same frequency, they should be sorted in ascending order of their values.



For this project, your task is to implement the logic of the merge sort and a recursive function.

Input format :
The first line contains an integer n, representing the number of elements in the array.

The second line contains n space-separated integers, arr[i].

Output format :
The output prints a single line containing the sorted elements of the array separated by spaces.

Code constraints :
max_n = 100

1 ≤ n ≤ 25

1 <= arr[i] <= 100

Sample test cases :
Input 1 :
6
1 1 2 3 3 3
Output 1 :
3 3 3 1 1 2 
Input 2 :
7
2 2 3 1 3 2 3
Output 2 :
2 2 2 3 3 3 1 
Input 3 :
6
1 2 3 1 2 3
Output 3 :
1 1 2 2 3 3  */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Element {
    int value;
    int frequency;
};

bool compareElements(const Element &a, const Element &b) {
    if (a.frequency != b.frequency)
        return a.frequency > b.frequency;
    return a.value < b.value;
}

void merge(vector<Element> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Element> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (compareElements(L[i], R[j])) {
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

void mergeSort(vector<Element> &arr, int left, int right) {
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

    vector<Element> elements(n);

    for (int i = 0; i < n; i++) {
        cin >> elements[i].value;
        elements[i].frequency = 1;
    }

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (elements[i].value == elements[j].value) {
                elements[i].frequency++;
                elements[j].frequency = 0; // Mark the duplicate as processed
            }
        }
    }

    // Remove elements with frequency 0 (duplicates)
    elements.erase(remove_if(elements.begin(), elements.end(), [](const Element& e) {
        return e.frequency == 0;
    }), elements.end());

    mergeSort(elements, 0, elements.size() - 1);

    for (const Element &element : elements) {
        for (int i = 0; i < element.frequency; i++) {
            cout << element.value << " ";
        }
    }

    cout << endl;

    return 0;
}
