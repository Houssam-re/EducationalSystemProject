#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
private:
    string _FullName;
    string _UserName;
    string _ID;
    string _Email;
    string _Password;
    string _PhoneNumber;

public:
    clsPerson(string FullName,
        string UserName,
        string ID,
        string Password,
        string Email,
        string PhoneNumber)
    {
        _UserName = UserName;
        _FullName = FullName;
        _Password = Password;
        _ID = ID;
        _Email = Email;
        _PhoneNumber = PhoneNumber;
    }

    void setFullName(string FirstName)
    {
        _FullName = FirstName;
    }

    string getFullName()
    {
        return _FullName;
    }

    __declspec(property(get = getFullName, put = setFullName)) string FullName;

    void setUserName(string UserName)
    {
        _UserName = UserName;
    }

    string getUserName()
    {
        return _UserName;
    }

    __declspec(property(get = getUserName, put = setUserName)) string UserName;


    //Read_Only
    string getID()
    {
        return _ID;
    }
    void setEmail(string Email)
    {
        _Email = Email;
    }

    string getEmail()
    {
        return _Email;
    }

    __declspec(property(get = getEmail, put = setEmail)) string Email;

    void setPhoneNumber(string PhoneNumber)
    {
        _PhoneNumber = PhoneNumber;
    }

    string getPhoneNumber()
    {
        return _PhoneNumber;
    }

    __declspec(property(get = getPhoneNumber, put = setPhoneNumber)) string PhoneNumber;

    void setPassword(string Password)
    {
        _Password = Password;
    }

    string getPassword()
    {
        return _Password;
    }

    __declspec(property(get = getPassword, put = setPassword)) string Password;


};
