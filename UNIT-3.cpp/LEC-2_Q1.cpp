/* Usha is currently studying computer science and is interested in mathematical expressions and their evaluation. She came across an infix expression that includes mathematical operators and functions and wants to convert it into postfix notation. She needs your help to implement a program that can perform this task.



Your task is to implement a program that takes an infix mathematical expression with function calls, converts it into postfix notation, and prints the postfix expression.



Example



Input: sin(3x)+cos(4x)

Output: sin3xcos4x+



Note: This is a sample question asked in Capgemini recruitment.

Input format :
The input consists of a single line containing the infix mathematical expression with function calls. The expression will contain:

Arithmetic operators: +, -, *, /, %, ^.
Functions: sin, cos, tan, exp, log, sqrt.
Parentheses: (and).
Numeric values (integers)
Spaces may be included in the input, but they should be ignored.

Output format :
The output displays the postfix expression obtained from the input infix expression.



Refer to the sample output for the formatting specifications.

Code constraints :
maximum length of 100 characters.

Sample test cases :
Input 1 :
sin(x)+2*cos(y)
Output 1 :
Postfix expression: sinx2cosy*+
Input 2 :
sin(cos(x)*tan(y))
Output 2 :
Postfix expression: sincosxtany*
Input 3 :
sin(3x)+cos(4x)
Output 3 :
Postfix expression: sin3xcos4x+ */

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

bool isFunction(const string& token) {
    return token == "sin" || token == "cos" || token == "tan" || token == "exp" || token == "log" || token == "sqrt";
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix = "";
    string token = "";

    for (char c : infix) {
        if (isspace(c))
            continue;

        if (isalnum(c) || c == 'x') {
            token += c;
        } else {
            if (!token.empty()) {
                postfix += token;
                token = "";
                postfix += " ";
            }

            if (c == '(') {
                operatorStack.push(c);
            } else if (c == ')') {
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    postfix += operatorStack.top();
                    postfix += " ";
                    operatorStack.pop();
                }
                if (!operatorStack.empty())
                    operatorStack.pop();
            } else if (isOperator(c)) {
                while (!operatorStack.empty() && getPrecedence(c) <= getPrecedence(operatorStack.top())) {
                    postfix += operatorStack.top();
                    postfix += " ";
                    operatorStack.pop();
                }
                operatorStack.push(c);
            }
        }
    }

    if (!token.empty()) {
        postfix += token;
        postfix += " ";
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        postfix += " ";
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string infix;
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
