/* Venu is currently learning about postfix expressions in his computer science class. He has recently written a program to validate whether a given postfix expression is valid or not. However, he wants you to help him.



A valid postfix expression is one that adheres to the following rules:

It contains only digits, operators (+, -, *, /), and spaces.
It has valid operator placement, meaning that there must be at least two operands for every operator, and no operands should be left unused.
Division by zero is not allowed.


Example



Input 1 

23+

Output 1 

Valid postfix expression



Explanation:



In this input, The expression has two operands, 2 and 3, and one operator, +. The operator + is correctly placed after the two operands. When you evaluate this expression, you add operands 2 and 3, resulting in 5. So, the expression is a valid postfix expression, and the output is "Valid postfix expression."



Input 2 

42*+

Output 2 

Invalid postfix expression



Explanation:



In this input, the postfix expression is 42*+. The expression has two operands, 4 and 2, and two operators * and +.

However, the operator + is placed immediately after the operand 2, which is not allowed in postfix notation. There should be at least two operands for every operator. So, the expression is invalid due to incorrect operator-placement, and the output is "Invalid postfix expression."



Note: This is a sample question asked in TCS recruitment.

Input format :
The input consists of a single line containing the string S, which represents the postfix expression to be validated.

Output format :
The output displays either "Valid postfix expression" or "Invalid postfix expression" based on whether the input expression is valid or not.



Refer to the sample output for the formatting specifications.

Code constraints :
1 <= |S| <= 100

Sample test cases :
Input 1 :
23+
Output 1 :
Valid postfix expression
Input 2 :
42*+
Output 2 :
Invalid postfix expression */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValidPostfixExpression(const string& expression) {
    stack<int> operands;

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (operands.size() < 2) {
                return false;
            }

            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (c) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        return false;
                    }
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }

    return operands.size() == 1;
}

int main() {
    string expression;
    cin >> expression;

    if (isValidPostfixExpression(expression)) {
        cout << "Valid postfix expression" << endl;
    } else {
        cout << "Invalid postfix expression" << endl;
    }

    return 0;
}