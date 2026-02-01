#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include"ClsDate.h"
#include"ClsUtil.h"



int main()
{
    cout<<ClsUtil::getRandomNumber(1, 90)<<endl;
    cout << ClsUtil::GetRandomChar(ClsUtil::Letters::CapitalLetters) << endl;
    cout << ClsUtil::GenerateRandomWord(ClsUtil::Letters::CapitalLetters, 8) << endl;
    cout << ClsUtil::GenerateKey(ClsUtil::Letters::CapitalLetters)<<endl;
    ClsUtil::GenerateKeys(ClsUtil::Letters::CapitalLetters, 10);
    
    cout << "\n";

    int x = 10, y = 20;
    ClsUtil::swap(x, y);
    cout<<"Swap int: " << x << " " << y<<endl;
   
    double x1 = 10.5, y1 = 20.5;
    ClsUtil::swap(x1, y1);
    cout << "Swap Double: " << x1 << " " << y1 << endl;

    string Sx = "Ahmad", Sy = "Khalil";
    ClsUtil::swap(Sx, Sy);
    cout << "Swap string: " << Sx << " " << Sy << endl;

    ClsDate d1(1, 1, 2001), d2(1, 1, 2026);
    ClsUtil::swap(d1, d2);
    cout << "Swap Dates: \n";
    d1.PrintDate();
    d2.PrintDate();


    int arr[5] = { 1,2,3,4,5 };
    ClsUtil::ShuffleArray(arr, 5);
    cout << "Shuffle Array: ";
   
    for (const int &i : arr)
    {
        cout << i << " ";
    }

    cout << "\n";

    string arr2[5]= { "Harry", "Hermione", "Ron", "Dumbledore", "Voldemort" };
    ClsUtil::ShuffleArray(arr2, 5);
    cout << "Shuffle Array With Strings: ";

    for (const string& i : arr2)
    {
        cout << i << " ";
    }

    cout << "\n";


    int arr3[5];
    ClsUtil::FillArrayWithRandomNumbers(arr3, 5);
    cout << "Fill Array with Random Numbers: ";
    
    for (const int& i : arr3) {
        cout << i << " ";
    }
    cout << "\n";


    string arr4[5];
    ClsUtil::FillArrayWithRandomWords(arr4, 5, ClsUtil::Letters::CapitalLetters, 7);
    cout << "Fill Array with Random Words: ";
    for (const string& i : arr4) {
        cout << i << " ";
    }
    cout << "\n";

    string arr5[5];
    ClsUtil::FillArrayWithRandomKeys(arr5, 5, ClsUtil::Letters::Digit);
    cout << "Fill Array with Random Keys: \n";

    for (const string& i : arr5) {
        cout << i << "\n";
    }
    cout << "\n";


    cout << "Text1: " << ClsUtil::Taps(3) << "Text2: " << endl<<endl;

    int Key = 3;
    string Secret = "Starting tonight";
    Secret=ClsUtil::EncryptWord(Secret, Key);
    cout << Secret << endl;
    Secret = ClsUtil::DecryptWord(Secret, Key);
    cout << Secret<<endl;

    return 0;
}
