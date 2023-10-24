/* You are working on a text processing system for a search engine. As part of the system, you need to implement a pattern-matching algorithm using a sliding window approach. 



Given a large text document and a pattern, you are required to find all occurrences of the pattern in the text document efficiently.



Your task is to write a program that performs the following operations:

Read the large text document and store it in memory.
Read the pattern from the user.
Implement a sliding window algorithm using a linked list-based deque to find all occurrences of the pattern in the text document.
Display the positions (starting indices) of all occurrences of the pattern in the text document.


Write a program to implement the above operations and display the positions of all occurrences of the pattern in the text document.



Your program should prompt the user to enter the required inputs and then output the positions of all occurrences of the pattern.



Note: This is a sample question asked in TCS recruitment.

Input format :
The first line of input consists of a sequence of strings.

The second line consists of the pattern to be found in the given string.

Output format :
If the pattern is found in the string, print the index or indexes where the pattern occurs. (index starts from 0)

If the pattern is not found, print "Pattern not found".

If the pattern is longer than the string, print "Pattern is longer than the string".



Refer to the sample output for the exact text and format.

Code constraints :
The strings are case-sensitive.

Sample test cases :
Input 1 :
abcdabcdeabcdabcdeabcdabcde
abcd
Output 1 :
Pattern found at index 0
Pattern found at index 4
Pattern found at index 9
Pattern found at index 13
Pattern found at index 18
Pattern found at index 22
Input 2 :
abcdefghij
abcdefghijkl
Output 2 :
Pattern is longer than the string
Input 3 :
Harry Potter
harry
Output 3 :
Pattern not found */

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    string text, pattern;
    getline(cin, text); // Read the large text document
    getline(cin, pattern); // Read the pattern from the user

    int textLen = text.length();
    int patternLen = pattern.length();

    if (patternLen > textLen) {
        cout << "Pattern is longer than the string" << endl;
        return 0;
    }

    deque<int> positions; // To store positions of pattern occurrences

    // Iterate through the text using a sliding window
    for (int i = 0; i <= textLen - patternLen; i++) {
        bool found = true;

        // Check if the pattern matches the current substring
        for (int j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }

        if (found) {
            positions.push_back(i);
        }
    }

    if (positions.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        for (int pos : positions) {
            cout << "Pattern found at index " << pos << endl;
        }
    }

    return 0;
}
