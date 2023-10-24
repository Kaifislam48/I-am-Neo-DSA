/* Laddu has implemented a simple stack using an array with a maximum size of MAX_SIZE (defined as 10 in the code). The program provides the following operations:



Push: Add an integer to the stack.
Pop: Remove an integer from the top of the stack.
Check if Stack is Full: Determine if the stack is full.
Check if Stack is Empty: Determine if the stack is empty.
Exit: Terminate the program.


Note: This is a sample question asked in a Capgemini interview.

Input format :
If the choice represents the operation to be performed,

1: Push an integer onto the stack.

2: Pop an integer from the stack.

3: Check if the stack is full.

4: Check if the stack is empty.

5: Exit the program.

item, represents the integer to be pushed onto the stack, separated by a space.

Output format :
The output prints one of the following messages:

If the choice is 1 (Push), there is no output.

If the choice is 2 (Pop) and the stack is empty, print "Stack is empty!".

If the choice is 3 (Check if Full), and the stack is full, print "Stack is full!", and if the stack is not full, print "Stack is not full.".

If the choice is 4 (Check if Empty), and the stack is empty, print "Stack is empty!", and if the stack is not empty, print "Stack is not empty."

If the choice is 5 (Exit), the program should terminate immediately.

If the choice is more than 6, It prints "Invalid choice".



Refer to the sample output for the formatting specifications.

Code constraints :
1 <= choice <= 5

Sample test cases :
Input 1 :
1 2
1 6
2
3
4
5
Output 1 :
Stack is not full.
Stack is not empty.
Input 2 :
1 3
1 4
1 5
1 7
1 18
1 19
1 20
1 21
1 34
1 76
4
3
5
Output 2 :
Stack is not empty.
Stack is full!
Input 3 :
1 2
1 4
1 5
1 76
1 89
1 34
1 23
1 65
1 45
1 23
2
2
2
2
2
2
2
2
2
2
4
5
Output 3 :
Stack is empty!
Input 4 :
1 6
1 7
9
5
Output 4 :
Invalid choice
Input 5 :
1 4
2
2
5
Output 5 :
Stack is empty!*/


#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool push(int value) {
        if (top >= MAX_SIZE - 1) {
            return false;  // Stack is full
        }
        arr[++top] = value;
        return true;
    }

    bool pop() {
        if (top < 0) {
            return false;  // Stack is empty
        }
        top--;
        return true;
    }

    bool isFull() {
        return (top >= MAX_SIZE - 1);
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack stack;
    int choice, item;

    do {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> item;
                stack.push(item);
                break;

            case 2:
                if (stack.pop()) {
                    // Pop operation successful
                } else {
                    cout << "Stack is empty!" << endl;
                }
                break;

            case 3:
                if (stack.isFull()) {
                    cout << "Stack is full!" << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;

            case 4:
                if (stack.isEmpty()) {
                    cout << "Stack is empty!" << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 5:
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }

    } while (choice != 5);

    return 0;
}
