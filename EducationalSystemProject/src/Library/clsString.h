#pragma once
#include <iostream>
#include <vector>
using namespace std;
class clsString
{
private:
    string _Value;


public:

    clsString()
    {

        _Value = "";

    }
    clsString(string Value)
    {

        _Value = Value;
    }

    //Property Get
    void setString(string Value)
    {
        _Value = Value;
    }

    //Property Set
    string GetString()
    {
        return _Value;
    }

    __declspec(property(get = GetString, put = setString))string Value;
    static short CountWords(string S1)
    {

        string delim = " "; // delimiter  
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (!sWord.empty())
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }
    static  bool isVowel(char ch)
    {
        string vowel = "aeyuio";
        for (short i = 0; i < vowel.length(); i++)
        {
            if (vowel[i] == ch)
                return true;
        }
        return false;
    }
    static string JoinFunction(vector <string> vString, string delim = " ")
    {
        string line = "";
        for (short i = 0; i < vString.size() - 1; i++)
            line += vString[i] + delim;
        line += vString[vString.size() - 1];
        return line;
    }
    static string JoinFunction(string vString[], int length, string delim = " ")
    {
        string line = "";
        for (short i = 0; i < length - 1; i++)
            line += vString[i] + delim;
        line += vString[length - 1];
        return line;
    }
    short CountWords()
    {
        return CountWords(_Value);
    }
    static vector<string> SplitString(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (!S1.empty())
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }
    vector<string> SplitString(string Delim = " ")
    {
        return SplitString(_Value, Delim);
    }
    static short length(string S1)
    {

        short Counter = 0;
        for (char& i : S1)
        {
            Counter++;
        }
        return Counter;
    }

    short length()
    {
        return length(_Value);
    }
    string UpperFirstLetterOfEachWord(string& S1)
    {
        vector <string> vUpp = SplitString(S1, " ");
        for (string& i : vUpp)
        {
            i[0] = toupper(i[0]);
        }
        S1 = JoinFunction(vUpp);
        return S1;
    }

    void UpperFirstLetterOfEachWord()
    {
        UpperFirstLetterOfEachWord(_Value);
    }
    string LowerFirstLetterOfEachWord(string& S1)
    {
        vector <string> vUpp = SplitString(S1, " ");
        for (string& i : vUpp)
        {
            i[0] = towlower(i[0]);
        }
        S1 = JoinFunction(vUpp);
        return S1;
    }

    void LowerFirstLetterOfEachWord()
    {
        LowerFirstLetterOfEachWord(_Value);
    }

   static string UpperAllString(string& S1)
    {
        vector <string> vUpp = SplitString(S1, " ");
        for (string& i : vUpp)
        {
            for (short j = 0; j < i.length(); j++)
            {
                i[j] = toupper(i[j]);
            }
        }
        S1 = JoinFunction(vUpp);
        return S1;
    }
    void UpperAllString()
    {
        UpperAllString(_Value);
    }
    static string LowerCaseAllCharInString(string S1)
    {
        for (char& i : S1)
        {
            i = towlower(i);
        }
        return S1;
    }
    static string LowerAllString(string& S1)
    {
        vector <string> vUpp = SplitString(S1, " ");
        for (string& i : vUpp)
        {
            for (short j = 0; j < i.length(); j++)
            {
                i[j] = towlower(i[j]);
            }
        }
        S1 = JoinFunction(vUpp);
        return S1;
    }
    void LowerAllString()
    {
        LowerAllString(_Value);
    }
    static char invertLetterCase(char ch)
    {
        return (islower(ch)) ? towupper(ch) : towlower(ch);
    }
    static string InvertAllLetterCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = invertLetterCase(S1[i]);
        }
        return S1;
    }
    void InvertAllLetterCase()
    {
        _Value = InvertAllLetterCase(_Value);
    }

    static short CountCapitalLetters(string S1)
    {
        short Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
                Count++;
        }
        return Count;
    }

    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }
    static short CountSmallLetter(string S1)
    {
        short Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
                Count++;
        }
        return Count;
    }

    short CountSmallLetter()
    {
        return CountSmallLetter(_Value);
    }
    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    static short CountLetter(string S1, enWhatToCount What)
    {
        return  (What == enWhatToCount::CapitalLetters) ? CountCapitalLetters(S1) : ((What == enWhatToCount::SmallLetters) ? CountSmallLetter(S1) : (CountSmallLetter(S1) + CountCapitalLetters(S1)));
    }
    static short CountVowel(string S1)
    {
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (isVowel(towlower(S1[i])))
                Counter++;
        }
        return Counter;
    }
    short CountVowel()
    {
        return CountVowel(_Value);
    }
    short CountSpecificLetter(char ch, bool Same = true)
    {
        short Counter = 0;
        for (short i = 0; i < _Value.length(); i++)
        {
            if (Same)
            {
                if (_Value[i] == ch)
                    Counter++;
            }
            else
            {
                if (towlower(_Value[i]) == towlower(ch))
                    Counter++;
            }
        }
        return Counter;
    }
    static string TrimLeft(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
                return S1.substr(i, S1.length() - 1);
        }
        return S1;
    }
    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }
    static string TrimRight(string S1)
    {
        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
                return S1.substr(0, i);
        }
        return S1;
    }
    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }
    static string Trim(string S1)
    {
        S1 = TrimLeft(S1);
        S1 = TrimRight(S1);
        return S1;
    }
    void Trim()
    {
        _Value = Trim(_Value);
    }
    string RevereWordsInString()
    {
        vector <string> vstring = SplitString(_Value, " ");
        string temp;
        for (short i = 0; i < vstring.size() / 2; i++)
        {
            temp = vstring[i];
            vstring[i] = vstring[vstring.size() - 1 - i];
            vstring[vstring.size() - 1 - i] = temp;
        }
        _Value = JoinFunction(vstring);
        return _Value;
    }
    string ReplaceWord(string Replace, string ReplaceWith)
    {
        short pos = _Value.find(Replace);
        while ((pos = _Value.find(Replace)) != string::npos)
        {
            _Value = _Value.replace(pos, Replace.length(), ReplaceWith);

        }
        return _Value;
    }
    static string RemovePunct(string S1)
    {
        string with = "";
        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                with += S1[i];
            }
        }
        return with;
    }
    void RemovePunct()
    {
        _Value = RemovePunct(_Value);
    }
};

