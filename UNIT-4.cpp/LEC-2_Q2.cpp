/* At the "Fresh Mart" grocery store, they recently received a large shipment of various products, and they need to organize their inventory efficiently. They've hired you to help them sort the products in descending order based on their product IDs.



Develop a program to aid the Fresh Mart team in organizing their inventory using a recursive function and implementing the merge sort logic. Each product in the store is identified by a distinct product ID, and the objective is to present the products to customers in descending order.

Input format :
The first line consists of an integer, n, representing the number of products in the inventory.

The next line consists of n space-separated integers, each representing a unique Product ID.

Output format :
The output displays a single line containing the Product IDs sorted in descending order, separated by spaces.

Code constraints :
1 ≤ n ≤ 10

1 ≤ Product ID ≤ 1000

Sample test cases :
Input 1 :
5
1 9 7 6 8
Output 1 :
9 8 7 6 1 
Input 2 :
4
754 312 505 44
Output 2 :
754 505 312 44  */

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
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

void mergeSort(int arr[], int left, int right) {
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

    int productIDs[n];
    for (int i = 0; i < n; i++) {
        cin >> productIDs[i];
    }

    mergeSort(productIDs, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << productIDs[i] << " ";
    }

    cout << endl;

    return 0;
}
