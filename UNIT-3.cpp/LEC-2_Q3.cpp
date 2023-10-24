/* Janani is a dedicated math teacher who wants to simplify the process of solving complex mathematical expressions for her students.



She wishes to create a tool that can convert standard mathematical expressions written in infix notation into postfix notation. This tool will help her students better understand the order of operations and practice solving equations step-by-step.

Input format :
The input consists of a single line containing a mathematical expression in infix notation.

The expression contains the operators +, -, *, and /, as well as parentheses ().

Operand values are integers, and there are no spaces in the input.

Output format :
The output will be a single line containing the corresponding postfix expression obtained from the given infix expression.



Refer to the sample output for the formatting specifications.

Code constraints :
The input expression has at most 100 characters.and valid mathematical expression.

Sample test cases :
Input 1 :
(5-3)*(7+2)
Output 1 :
Postfix expression: 53-72+*
Input 2 :
(1+7)*3-8/(5+2)
Output 2 :
Postfix expression: 17+3*852+/- */

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
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
