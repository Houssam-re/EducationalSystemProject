#pragma once
#include <math.h>
#include<iostream>
using namespace std;
class clsMyMath
{

public:
    int MaxOfTwo(int a, int b)
    {
        return (a >= b) ? a : b;
    }
    int MaxOfthree(int a, int b, int c)
    {
        return MaxOfTwo(MaxOfTwo(a, b), c);
    }
    int MaxOfFour(int a, int b, int c, int d)
    {
        return MaxOfTwo(MaxOfthree(a, b, c), d);
    }

    bool IsPrime(int a)
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


    int ReverseNumber(int Number)
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
    int RandomNumber(int From, int To)
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

};

