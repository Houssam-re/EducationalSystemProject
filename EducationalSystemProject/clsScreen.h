#pragma once
#include <iostream>
#include "clsGlobal.h"
#include "clsStudent.h"
#include"src/Library/clsUtil.h"
#include "src/Library/clsDate.h"
using namespace std;

class clsScreen
{
public:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (!SubTitle.empty())
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
      //  ShowUserNameAndDate();
    }
    //static void ShowUserNameAndDate()
    //{
    //    clsDate Date;
    //    cout << clsUtil::Tabs(3) << "User : " << CurrentUser.UserName << endl;
    //    cout << clsUtil::Tabs(3) << "Date : " << Date.WritMonthName() << " " << Date.WritDayName(Date.CalculeDayNum()) << " ";
    //    Date.Print();
    //    cout << endl << endl;

    //}
    static  void ShowTabtScreen(const string& WhatToWrite)
    {
        system("cls");
        cout << "\n-----------------------------------------------------------\n";
        cout << "\t" << WhatToWrite << " \n";
        cout << "\n-----------------------------------------------------------\n\n\n";
        ShowUserNameAndDate();

    }
    static void ShowUserNameAndDate()
    {
        clsDate Date;
        string FullNameOfUser =  (isStudent) ? CurrentStudent.getFullName()  : CurrentDoctor.getFullName();
        cout << "User : " << FullNameOfUser << endl;
        cout << "Date : " << Date.WritMonthName() << " " << Date.WritDayName(Date.CalculeDayNum()) << " ";
      //   FullNameOfUser = CurrentStudent.getFullName();
        Date.Print();
        cout << endl << endl;
    }

};

