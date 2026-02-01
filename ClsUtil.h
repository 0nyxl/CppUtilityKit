#pragma once
#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ClsUtil
{
public:
 
    enum class Letters {
        CapitalLetters = 1, 
        SmallLetters = 2,
        Special = 3,
        Digit = 4,
        Mix = 5
    };

    static int getRandomNumber(int min, int max) {
        static bool initialized = false;
        if (!initialized) {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            initialized = true;
        }
        return min + (std::rand() % (max - min + 1));
    }

    static char getCharFromSet(std::string set) {
        return set[getRandomNumber(0, set.length() - 1)];
    }

   static char GetRandomChar(Letters type) {
       if (type == Letters::Mix) {
           type = static_cast<Letters>(getRandomNumber(1, 4));
       }

       switch (type) {
       case Letters::CapitalLetters:
           return static_cast<char>(getRandomNumber(65, 90));  // A-Z
       case Letters::SmallLetters:
           return static_cast<char>(getRandomNumber(97, 122)); // a-z
       case Letters::Digit:
           return static_cast<char>(getRandomNumber(48, 57));  // 0-9
       case Letters::Special:
           return getCharFromSet("!@#$%^&*()-_=+[]{}|;:,.<>?");
       default:
           return ' ';
       }
   }

   static string GenerateRandomWord(Letters type, short WordLengh) {

       string Word = "";
    
       for (size_t i = 0; i < WordLengh; i++)
       {
           Word += GetRandomChar(type);
       }
       return Word;
   }

   static string GenerateKey(Letters type) {
       string Key = "";
       int is4word = 0;
       for (size_t i = 0; i < 16; i++)
       {
           Key += GetRandomChar(type);
           is4word++;
           if (is4word>=4 && i != 15)
           {
               Key += '-';
               is4word = 0;
           }
       }
       return Key;
   }

   static void GenerateKeys(Letters type,short NumberOfKeys) {

       for (size_t i = 0; i < NumberOfKeys; i++)
       {
           cout << "Key [" << i + 1 << "] : " + GenerateKey(type)<<endl;
       }
   }

  static void swap(int& x, int& y) {
       int Temp = x;
       x = y;
       y = Temp;
   }

  static void swap(double& x, double& y) {
      double Temp = x;
      x = y;
      y = Temp;
  }

  static void swap(string& x,  string& y) {
      string Temp = x;
      x = y;
      y = Temp;
  }

  static void swap(ClsDate &x, ClsDate &y) {
     
      ClsDate Temp = x;
      x = y;
      y = Temp;
  }

  static void ShuffleArray(int arr[], int size) {
      for (int i = 0; i < size; i++)
      {
          int j = getRandomNumber(0, size - 1);
          swap(arr[i], arr[j]);
      }
  }

  static void ShuffleArray(string arr[], int size) {

      for (size_t i = 0; i < size; i++)
      {
          int j = getRandomNumber(0, size - 1);
          swap(arr[i], arr[j]);
      }
  }

  static void FillArrayWithRandomNumbers(int arr[],int size) {

      for (size_t i = 0; i < size; i++)
      {
          arr[i] = getRandomNumber(1,100);
      }

  }

  static void FillArrayWithRandomWords(string arr[], int size, Letters type, short WordLength) {

      for (size_t i = 0; i < size; i++)
      {
          arr[i] = GenerateRandomWord(type, WordLength);
      }
  }

  static void FillArrayWithRandomKeys(string arr[], int size, Letters type) {

      for (size_t i = 0; i < size; i++)
      {
          arr[i] = GenerateKey(type);
      }

  }

  static string Taps(short NumberofTaps) {
      string t="";
      for (size_t i = 0; i < NumberofTaps; i++)
      {
          t+="\t";
      }
      return t;
  }

  static string EncryptWord(string Word, short Key) {
    
      for (size_t i = 0; i < Word.length(); i++)
      {
          Word[i] = char(Word[i] + Key);
      }
      return Word;
    }

  static string DecryptWord(string &Word, short Key) {

      for (size_t i = 0; i < Word.length(); i++)
      {
          Word[i] = char(Word[i] - Key);
      }
      return Word;
  }

};
