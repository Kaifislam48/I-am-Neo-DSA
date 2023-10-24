/* Imagine you are a computer programmer tasked with creating a program to organize a collection of years in ascending order. This program will take a list of years as input and efficiently sort them using the Quick-Sort algorithm, ensuring that the years are arranged chronologically.

Input format :
The first line of input consists of an integer N, representing the number of years.

The second line consists of N space-separated integers, representing the years.

Output format :
The output prints the sorted dates in chronological order.

Code constraints :
N > 0

Each year is a 4-digit positive integer.

Sample test cases :
Input 1 :
5
2014 2009 2000 1997 1865
Output 1 :
1865 1997 2000 2009 2014 
Input 2 :
3
1496 3015 2056
Output 2 :
1496 2056 3015  */

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

