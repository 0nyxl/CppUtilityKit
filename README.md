# CppUtilityKit

CppUtilityKit is a beginner-friendly C++ utility library that provides a collection of helpful functions for common tasks in C++ projects. The library includes:

- Random number generation
- Random character, word, and key generation
- Array shuffling for integers and strings
- Swap functions for int, double, string, and custom classes
- Simple Caesar-style encryption and decryption
- Utility functions like tab formatting

This library is designed for learning and experimenting with C++ features like static methods, arrays, loops, and basic algorithms. It's lightweight, easy to integrate, and perfect for practice or small projects.

## Example Usage

```cpp
#include "ClsUtil.h"
#include <iostream>
using namespace std;

int main() {
    cout << ClsUtil::getRandomNumber(1, 100) << endl;
    cout << ClsUtil::GenerateRandomWord(ClsUtil::Letters::CapitalLetters, 8) << endl;

    int arr[5] = {1,2,3,4,5};
    ClsUtil::ShuffleArray(arr, 5);

    for (int x : arr)
        cout << x << " ";
}
