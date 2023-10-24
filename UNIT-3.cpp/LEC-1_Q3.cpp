/* Bindu is working on a program to convert decimal numbers to binary representation using a stack data structure implemented with a linked list. She needs your help in designing and implementing this program.



Your task is to design and implement the stack with the specified push and pop operations to support this conversion.

Input format :
The input consists of an integer d, representing the decimal number to be converted into binary.

Output format :
The output is a single line containing the binary representation of the input decimal number in the format "Binary representation: [binary]".



Refer to the sample output for formatting specifications.

Code constraints :
The stack used for the conversion can have a maximum size of 32.

1 <= d <= 512

Sample test cases :
Input 1 :
10
Output 1 :
Binary representation: 1010
Input 2 :
37
Output 2 :
Binary representation: 100101 */

#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    bool pop(int& value) {
        if (isEmpty()) {
            return false;
        }
        Node* temp = top;
        top = top->next;
        value = temp->data;
        delete temp;
        return true;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    int decimal;
    cin >> decimal;

    Stack stack;
    int quotient = decimal;

    while (quotient > 0) {
        int remainder = quotient % 2;
        stack.push(remainder);
        quotient /= 2;
    }

    cout << "Binary representation: ";
    while (!stack.isEmpty()) {
        int bit;
        if (stack.pop(bit)) {
            cout << bit;
        }
    }

    cout << endl;

    return 0;
}
