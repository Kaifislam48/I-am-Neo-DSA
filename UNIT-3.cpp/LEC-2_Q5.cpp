/* Meenu is studying computer science and is currently learning about expressions in infix notation. She needs a program to convert infix expressions to postfix notation to help her with her studies. Can you help her by providing a program that performs this conversion?



The program should support the following operations:



Check if a character is an operator (+, -, *, or /).
Determine the precedence of an operator.
Convert an infix expression to postfix notation.


Example



Input:

(3+4)5

Output:

﻿34+5



Note: This is a sample question asked in TCS recruitment.

Input format :
The input consists of the infix expression to be converted to postfix notation.

Output format :
The output displays the postfix expression equivalent of the input infix expression.



Refer to the sample output for formatting specifications.

Code constraints :
The input line will not exceed a length of 100 characters.

The infix expression may contain operators (+, -, *, /) and parentheses (,).

Sample test cases :
Input 1 :
A+B*C-D/E
Output 1 :
Postfix expression: ABC*+DE/-
Input 2 :
3+4*5/(6-2)
Output 2 :
Postfix expression: 345*62-/+
Input 3 :
(3+4)5
Output 3 :
Postfix expression: 34+5 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // For other characters (like parentheses)
}

string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty())
                operatorStack.pop(); // Remove the '('
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operatorStack.empty() && operatorStack.top() != '(' && precedence(c) <= precedence(operatorStack.top())) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string infix;
    
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
