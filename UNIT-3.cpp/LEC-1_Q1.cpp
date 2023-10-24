/* Julie is enthusiastic about learning data structures, and she has started with one of the fundamental data structures: a stack. She is eager to practice using stacks with various operations like push, pop, and display. Can you help her by designing an interactive program that allows her to perform these stack operations and visualize how the stack changes?



Manages a stack using an array. Supports the following stack operations:

Push an element onto the stack.
Pop an element from the stack.
Display the elements currently in the stack.
Exit the program.


Note: This is a sample question asked in a TCS interview.

Input format :
The program expects the following inputs in a loop until the user chooses to exit.



An integer indicating the choice of operation:

1: Push an element onto the stack

2: Pop an element from the stack

3: Display the elements in the stack

4: Exit the program



If the choice is 1, the program expects an integer value to be pushed onto the stack.

Output format :
The program produces the following outputs based on the chosen operation:



Choice 1:

If the push operation is successful, it displays "Element <value> pushed onto the stack."

Choice 2:

If the pop operation is successful, it displays "Element <value> popped from the stack."

If the stack is empty, it displays "Stack Underflow. Cannot perform the pop operation."

Choice 3:

If the stack is empty, it displays "Stack is empty."

If the stack has elements, it displays "Elements in the stack: <element1> <element2> ..."

Choice 4:

If the choice is 4, it displays "Exiting the program."

If the choice is greater than 4 or an invalid input, it displays "Invalid choice."



Each output is followed by a newline character.



Refer to the sample output for the exact format.

Code constraints :
The maximum size of the stack is defined as MAX_SIZE = 100.

0 <= stack elements <= 200

Sample test cases :
Input 1 :
1
5
3
2
3
4
Output 1 :
Element 5 pushed onto the stack.
Elements in the stack: 5 
Element 5 popped from the stack.
Stack is empty.
Exiting the program.
Input 2 :
1
10
1
20
1
30
2
3
4
Output 2 :
Element 10 pushed onto the stack.
Element 20 pushed onto the stack.
Element 30 pushed onto the stack.
Element 30 popped from the stack.
Elements in the stack: 20 10 
Exiting the program.
Input 3 :
1
25
1
36
2
2
3
2
4
Output 3 :
Element 25 pushed onto the stack.
Element 36 pushed onto the stack.
Element 36 popped from the stack.
Element 25 popped from the stack.
Stack is empty.
Stack Underflow. Cannot perform pop operation.
Exiting the program.
Input 4 :
5
3
4
Output 4 :
Invalid choice.
Stack is empty.
Exiting the program. */


#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow. Cannot push more elements." << endl;
        } else {
            top++;
            arr[top] = value;
            cout << "Element " << value << " pushed onto the stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow. Cannot perform the pop operation." << endl;
        } else {
            int poppedValue = arr[top];
            top--;
            cout << "Element " << poppedValue << " popped from the stack." << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Elements in the stack:";
            for (int i = 0; i <= top; i++) {
                cout << " " << arr[i];
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice;

    do {
        cout << "Enter choice (1: Push, 2: Pop, 3: Display, 4: Exit): ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
