/* In a picturesque town, there lived a talented artist named Lily, who had a unique way of expressing herself through strings. She created a CustomString class that could magically invert the case of characters using the ! operator.



One day, a curious writer named Mark encountered Lily's creation and decided to put it to the test. Mark entered a captivating sentence into the console, and the CustomString class worked its charm, displaying the original sentence and its inverted counterpart.



Mark couldn't help but marvel at the power of operator overloading, realizing the endless possibilities it offered for crafting artistic and playful text transformations in their literary adventures.



Note: Use a character array.

Input format :
The input consists of a single line containing a string of characters. The string length does not exceed 100 characters.

Output format :
the output displays two lines of output:



The first line should contain the original string.

The second line should contain the inverted string after applying the unary ! operator.



Refer to the sample output for further formatting specifications.

Code constraints :
The input string will contain only printable ASCII characters (characters with ASCII values from 32 to 126).

The length of the input string will not exceed 100 characters.

Sample test cases :
Input 1 :
Hello WORLD
Output 1 :
Original String: Hello WORLD
Inverted String: hELLO world */

#include <iostream>
#include <cstring>

class CustomString {
private:
    char data[101]; // Assuming a maximum string length of 100 characters

public:
    CustomString(const char* str) {
        strncpy(data, str, 100);
        data[100] = '\0'; // Ensure null-terminated string
    }

    void invertCase() {
        for (int i = 0; data[i] != '\0'; i++) {
            if (islower(data[i])) {
                data[i] = toupper(data[i]);
            } else if (isupper(data[i])) {
                data[i] = tolower(data[i]);
            }
        }
    }

    void printOriginalString() {
        std::cout << "Original String: " << data << std::endl;
    }

    void printInvertedString() {
        std::cout << "Inverted String: " << data << std::endl;
    }

    // Overload the ! operator to invert the case of characters
    void operator!() {
        invertCase();
    }
};

int main() {
    char input[101];
    std::cin.getline(input, 101);

    CustomString customString(input);

    customString.printOriginalString();

    // Apply the unary ! operator to invert the case
    !customString;

    customString.printInvertedString();

    return 0;
}
