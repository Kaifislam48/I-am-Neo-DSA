/* Nithish is studying computer science and is currently learning about expressions and their conversion from infix notation to postfix notation. He has a programming assignment and needs your help to implement an infix-to-postfix conversion algorithm. Can you help him?



Write a program that takes an infix expression as input and converts it into a postfix expression. The program should support the following operators: '+', '-', '*', and '/'. It should also handle parentheses '(' and ')' to indicate the order of operations.



Note: This is a sample question asked in HCL recruitment.

Input format :
The input consists of an infix expression that includes only digits (0–9) and operators (+, -, *, /).

Output format :
The output displays the equivalent postfix expression of the given infix expression.



Refer to the sample output for the formatting specifications.

Code constraints :
The length of the expression <= 100 characters.

Sample test cases :
Input 1 :
1+2*3/4-5
Output 1 :
Postfix expression: 123*4/+5-
Input 2 :
5+6-4*8/2
Output 2 :
Postfix expression: 56+48*2/- */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix = "";

    for (char c : infix) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(')
                operatorStack.pop();
        } else {
            while (!operatorStack.empty() && precedence(c) <= precedence(operatorStack.top())) {
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
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
