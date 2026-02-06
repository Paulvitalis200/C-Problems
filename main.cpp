
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Pointer Based Array reversal
// Define a function that takes an array of integers (size 5-10) and a pointer to its first element,
// then reverses the array in place using pointer arithmetic in a loop. In main, read the array
// values from user input, call the function, and print the reversed array. Use decision making
// to check if the array contains any negative numbers and output a message if so.
// Emphasized concepts: Arrays, pointers, loops, functions, decision making, fundamental data types.

void reverseArray(int numbers[], int* ptr, int size) {
    bool hasNegative = false;
    for (int i = 0; i < size; i++) {
        if (numbers[i] < 0) {
            hasNegative = true;
            break;
        }
    }

    if (hasNegative) {
        cout << "Negative number found" << endl;
    }
    

    int* start = ptr;
    int* end = ptr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {

    int my_nums[10] = {};

    int* ptr = &my_nums[0];

    int size = 10;

    while (true) {
        string line;
        cout << "Enter some numbers: ";

        getline(cin, line);

        stringstream ss(line);

        int count = 0;

        for (int i = 0; i < size; i++) {
            if (ss >> my_nums[i]) {
                count++;
            }
        }

        if (count == size && ss.eof()) {
            break;
        } else {
            cout << "Invalid input" << endl;
            continue;
        }
    }

    reverseArray(my_nums, ptr, size);

    for (int i = 0; i < size; i++) {
        cout << my_nums[i] << " ";
    }

    

    return 0;
}
