/* You are working as a program developer at a renowned sports academy. As part of the academy's performance evaluation system, you are tasked with sorting the athletes based on their heights in descending order.



Write a program that takes an array of athlete names and their corresponding heights as input. Your program should use the Quick-Sort algorithm to sort the athletes' names in descending order based on their heights.

Input format :
The first line of input consists of an integer N, representing the number of athletes.

The following N lines consist of the athlete's name and height, separated by space.

Output format :
The output prints the athletes' names sorted in descending order based on their heights.

Code constraints :
N == names.length == heights.length

N > 0

names[i] consists of lower and upper case English letters.

All the values of heights are distinct.

Sample test cases :
Input 1 :
6
Mary 180
John 165
Emma 170
Joey 157
Tom 169
Cruise 175
Output 1 :
Mary Cruise Emma Tom John Joey 
Input 2 :
3
Alice 155
Bob 185
Bob 150
Output 2 :
Bob Alice Bob  */

#include <iostream>
#include <vector>
using namespace std;

struct Athlete {
    string name;
    int height;
};

int partition(vector<Athlete>& athletes, int low, int high) {
    Athlete pivot = athletes[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (athletes[j].height > pivot.height) {
            i++;
            swap(athletes[i], athletes[j]);
        }
    }

    swap(athletes[i + 1], athletes[high]);
    return i + 1;
}

void quickSort(vector<Athlete>& athletes, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(athletes, low, high);
        quickSort(athletes, low, pivotIndex - 1);
        quickSort(athletes, pivotIndex + 1, high);
    }
}

int main() {
    int N;
    cin >> N;
    vector<Athlete> athletes(N);

    for (int i = 0; i < N; i++) {
        cin >> athletes[i].name >> athletes[i].height;
    }

    quickSort(athletes, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << athletes[i].name << " ";
    }

    cout << endl;

    return 0;
}
