#pragma once
#include "clsCourses.h"
#include "clsStudent.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "src/Library/clsInputValidation.h"
#include <iostream>
#include"ShowSendEmailScreen.h"
#include "clsStudentSendedBoxScreen.h"
#include "clsStudentRecivedEmailBoxScreen.h"
using namespace std;
class clsCommunicationScreen : protected clsScreen
{

        enum _enMailBoxMenu { eSendEmail = 1, eSendedEmailBox = 2, eReceivedEmailBox = 3, eMainMenu = 4 };
        static void GoBackToCommunicationMenue()
        {
            cout << "\n\nPress any key to go back to Communication Menue...";
            system("pause>0");
            ShowEmailBoxMainMenue();

        }
        static short ReadEmailBoxMenueOption()
        {
            int Choice; cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
            Choice = clsInputValidate::ReadNumberBetween<int>(1, 4, "Enter Number Between 1 and 4 : ");
            return Choice;
        }
        static void ShowSendEmailScreen()
        {
            ShowSendEmailScreen::SendEmailScreen();
        }
        static void ShowSendedEmailBoxScreen()
        {
            clsStudentSendedEmailBoxScreen::ShowSendedBoxScreen();
        }
        static void ShowRecivedEmailScreen()
        {
            clsStudentRecivedEmailBoxScreen::ShowRecivedBoxScreen();
        }

        static void _PerformEmailBoxMenueOption(_enMailBoxMenu MailBox)
        {
            switch (MailBox)
            {
            case _enMailBoxMenu::eSendEmail:
            {
                system("cls");
                ShowSendEmailScreen();
                GoBackToCommunicationMenue();
                break;
            }

            case _enMailBoxMenu::eSendedEmailBox:
            {
                system("cls");
                ShowSendedEmailBoxScreen();
                GoBackToCommunicationMenue();
                break;
            }


            case _enMailBoxMenu::eReceivedEmailBox:
            {
                system("cls");
                ShowRecivedEmailScreen();
                GoBackToCommunicationMenue();
                break;
            }

            case _enMailBoxMenu::eMainMenu:
            {

            }

            }

        }


    public:
        static void ShowEmailBoxMainMenue()
        {

  
            ShowTabtScreen("\tCommunication Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t  Mail Box Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Send Email.\n";
            cout << setw(37) << left << "" << "\t[2] Sended Email Box.\n";
            cout << setw(37) << left << "" << "\t[3] Received Email Box.\n";
            cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerformEmailBoxMenueOption((_enMailBoxMenu)ReadEmailBoxMenueOption());
        }


};

