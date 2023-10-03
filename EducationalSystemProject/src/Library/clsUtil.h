#pragma once
#include "clsDate.h"
#include "clsString.h"
#include <iostream>
#include <iomanip>
#include <string>
class clsUtil
{

public:
    enum enCharType { MixChar = 1, CapitalChar = 2, SmallChar = 3 };
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }


    static int ReadPositiveNumber(string Message)
    {
        int Number = 0;
        do
        {
            cout << Message << endl;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }
    static void ReadArray(int arr[100], int& arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;
        cout << "\nEnter array elements: \n";
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "] : ";
            cin >> arr[i];
        }
        cout << endl;
    }

    static string ReadStrings(string WordOne)
    {
        string Word;
        cout << WordOne;
        getline(cin, Word);
        return Word;
    }

    static int MaxOfTwo(int a, int b)
    {
        return (a >= b) ? a : b;
    }
    static int MaxOfThree(int a, int b, int c)
    {
        return MaxOfTwo(MaxOfTwo(a, b), c);
    }
    static int MaxOfFour(int a, int b, int c, int d)
    {
        return MaxOfTwo(MaxOfThree(a, b, c), d);
    }

    static bool IsPrime(int a)
    {
        if (a == 1)
            return false;
        else
        {
            for (int i = 2; i <= a / 2; i++)
            {
                if (a % i == 0)
                    return false;
            }
        }
        return true;

    }
    static int ReverseNumber(int Number)
    {
        int Remainder = 0, Number2 = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Number2 = Number2 * 10 + Remainder;
        }
        return Number2;
    }
    static int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static bool isPowerOf2(int number) {
        return number > 0 && (number & (number - 1)) == 0;
    }
    static int RandomMultipleOfTwoNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        while (!isPowerOf2(randNum))
        {
            randNum = rand() % (To - From + 1) + From;
        }

        return randNum;
    }

    static void Fill2DArrayWithRandomNumber(int Array[100][100], short Row, short Colm)
    {
        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Colm; j++)
            {
                Array[i][j] = RandomNumber(1, 10);
            }
        }
    }

    static void FillArrayWithRandomNumber(int Array[100], short length)
    {
        for (short i = 0; i < length; i++)
        {
            Array[i] = RandomNumber(1, 20);
        }
    }
    static void Print2DArray(int Array[100][100], int Row, int Colm)
    {
        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Colm; j++)
            {
                cout << setw(3) << Array[i][j] << "  ";

            }
            cout << "\n";
        }
    }


    static void PrintArray(int Array[100], int len)
    {
        for (int j = 0; j < len; j++)
        {
            cout << setw(3) << Array[j] << "  ";
        }
        cout << "\n";
    }

    static int RowSum(int Array[100][100], int Row, int Colum)
    {
        int Sum = 0;
        for (int i = 0; i < Colum; i++)
        {
            Sum += Array[Row][i];
        }
        return Sum;
    }
    static void PrintEachRowSum(int Array[100][100], int Row, int Colum)
    {
        for (int i = 0; i < Row; i++)
        {
            cout << "The Sum Of Row" << i + 1 << " is : " << RowSum(Array, i, Colum) << endl;
        }
    }
    static int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;
        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }
        return Sum;
    }

    static void Swap(int& A, int& B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    }
    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool& A, bool& B)
    {
        bool Temp;
        Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(double& A, double& B)
    {
        double Temp;
        Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(string& A, string& B)
    {
        string Temp;
        Temp = A;
        A = B;
        B = Temp;
    }


    static bool IsPalindromeArray(int arr[100], int Length)
    {
        for (int i = 0; i < Length; i++)
        {
            if (arr[i] != arr[Length - i - 1])
            {
                return false;
            }
        };
        return true;
    }
    static void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrSum[i] = arr1[i] + arr2[i];
        }
    }

    static void FillArrayWith1toN(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = i + 1;
    }


    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1],
                arr[RandomNumber(1, arrLength) - 1]);
        }
    }
    static void PrintStringArray(string arr[100], int arrLength)
    {
        cout << "\nArray elements:\n\n";
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Array[" << i << "] : ";
            cout << arr[i] << "\n";
        }
        cout << "\n";
    }
    static void AddArrayElement(int Number, int arr[100], int& arrLength)
    {
        //its a new element so we need to add the length by 1
        arrLength++;
        arr[arrLength - 1] = Number;
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }


    static void InputUserNumbersInArray(int arr[100], int& arrLength)
    {
        bool AddMore = true;
        do
        {
            AddArrayElement(ReadPositiveNumber("Enter : "), arr, arrLength);
            cout << "\nDo you want to add more numbers? [0]:No,[1]:yes?";
            cin >> AddMore;
        } while (AddMore);
    }

    static char GetRandomChar(enCharType CharType)
    {
        switch (CharType)
        {
            short Mixt;
        case clsUtil::MixChar:
            Mixt = RandomNumber(2, 3);
            return (Mixt == 2) ? char(RandomNumber(65, 90)) : char(RandomNumber(97, 122));
        case clsUtil::CapitalChar:
            return char(RandomNumber(65, 90));
        default:
            return char(RandomNumber(97, 122));

        }
    }
    static string GenerateWord(enCharType ChType, short NumberOfCharInWord)
    {
        string word = "";

        for (short i = 0; i < NumberOfCharInWord; i++)
        {
            word += GetRandomChar(ChType);
        }
        return word;
    }
    static string GenerateKey(enCharType ChType)
    {
        string Key;
        Key += GenerateWord(ChType, 4) + '-';
        Key += GenerateWord(ChType, 4) + '-';
        Key += GenerateWord(ChType, 4) + '-';
        Key += GenerateWord(ChType, 4);
        return Key;
    }
    static void GenerateKeys(short KeysNumber, enCharType ChType)
    {
        for (short i = 0; i < KeysNumber; i++)
        {
            std::cout << "Key [" << i + 1 << "] : " << GenerateKey(ChType) << endl;
        }
    }



    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }


    static string  EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i < Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i < Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

    static string NumberToText(int Number)
    {
        if (Number == 0)
            return "";
        else
        {
            if (Number >= 1 && Number <= 19)
            {
                string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"
                ,"Eleven","Twelve","Thirteen","Fourteen","Fiveteen","Sixteen","Seventeen","Eightteen","Nineteen" };
                return arr[Number] + " ";
            }
            else if (Number >= 20 && Number <= 99)
            {
                string arr[] = { "","","Twenty","Thirty","Fourty","Fivety","Sixty","Seventy","Eighty","Ninety" };
                return arr[Number / 10] + " " + NumberToText(Number % 10);
            }
            else if (Number >= 100 && Number <= 999)
            {
                return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);
            }
            else if (Number >= 1000 && Number <= 999999)
            {
                return NumberToText(Number / 1000) + " Thounsed " + NumberToText(Number % 1000);
            }
            else if (Number >= 1000000 && Number <= 999999999)
            {
                return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);
            }
            else if (Number >= 1000000000 && Number <= 9999999999)
            {
                return NumberToText(Number / 1000000000) + " Billion " + NumberToText(Number % 1000000000);
            }

        }
    }

};
