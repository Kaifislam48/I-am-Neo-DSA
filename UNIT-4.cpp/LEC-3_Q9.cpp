/* You are working on a project to implement a feature that displays the list of users in alphabetical order based on their names.



To achieve this, you decide to use the Quick-Sort algorithm to efficiently sort the names. The user inputs the number of users and then the name of each user. Once the names are collected, the program must apply the Quick Sort algorithm to sort and display the names in alphabetical order.



Note: This kind of question will be helpful in clearing Capgemini recruitment.

Input format :
The first line of input consists of an integer N, representing the number of users.

The following N lines consist of the names of the users (starting with uppercase letters).

Output format :
The output prints the sorted list of names in alphabetical order.

Code constraints :
N > 0

Sample test cases :
Input 1 :
5
Alice
Denver
Aadhil
Charlie
Zen
Output 1 :
Aadhil
Alice
Charlie
Denver
Zen
Input 2 :
6
Chandler
Monica
Ross
Joey
Rachel
Phoebe
Output 2 :
Chandler
Joey
Monica
Phoebe
Rachel
Ross
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compareNames(string a, string b) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    return a < b;
}

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    sort(names.begin(), names.end(), compareNames);

    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }

    return 0;
}