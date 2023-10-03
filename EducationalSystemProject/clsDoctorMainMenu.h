#pragma once
#include <iostream>
#include "clsDoctor.h"
#include "src/Library/clsInputValidation.h"
#include "clsShowCoursesListDoctor.h"
#include "clsCreateCourseScreen.h"
#include "clsShowCoursesDetails.h"
#include "clsScreen.h"
class clsDoctorMainMenu : protected clsScreen
{

	enum enDoctorMenu { enListCourses = 1, enCreateCourses = 2, enViewCourses = 3, eCommunication =4,enLogOut = 5 };
		static	short _ReadDoctorMainMenueChoice()
		{
			cout << "Choice One Item Between [1 to 5] : ";
			short Choice = clsInputValidate::ReadNumberBetween(1, 5);
			return Choice;
		}
		static	void GoBackToDoctorMenue()
		{
			cout << "\n\nPress any key to go back to Main Menue...";
			system("pause>0");
			DoctorMainMenueScreen();
		}
		static void ShowCoursesList()
		{
			clsShowCoursesListDoctor::ShowCoursesListForDoctor();
		}
		static void CreateCourses()
		{
			clsCreateCourseScreen::CreateCourseScreen();
		}
		static void ShowCoursesDetails()
		{
			clsShowCoursesDetails::ShowCoursesDetails(false);
		}
		
		static void ShowCommunicationScreen()
		{
			cout << "Here Will Be Communication Screen";
		}
		static void LogOut()
		{
			cout << "Here Will Be Show Register In Course Screen";
		}

		static	void _PerformMainMenueChoiceScreen(enDoctorMenu	Doctor)
		{
			switch (Doctor)
			{
			case clsDoctorMainMenu::enListCourses:
				system("cls");
				ShowCoursesList();
				GoBackToDoctorMenue();
				break;
			case clsDoctorMainMenu::enCreateCourses:
				system("cls");
				CreateCourses();
				GoBackToDoctorMenue();
				break;
			case clsDoctorMainMenu::enViewCourses:
				system("cls");
				ShowCoursesDetails();
				GoBackToDoctorMenue();
				break;
			case clsDoctorMainMenu::eCommunication:
				system("cls");
				ShowCommunicationScreen();
				GoBackToDoctorMenue();
				break;
			case clsDoctorMainMenu::enLogOut:
				break;
			default:
				break;
			}
		}
	public:

		static void DoctorMainMenueScreen()
		{
			system("cls");
			cout << "\n----------------------------------------------------------------------------\n";
			cout << "\tWelcome Doctor " <<CurrentDoctor.FullName<< " You Are Logged In Main Menu  ";
			cout << "\n----------------------------------------------------------------------------\n";
			ShowUserNameAndDate();
			cout << "\t[1] List Courses.\n";
			cout << "\t[2] Create Courses.\n";
			cout << "\t[3] View Courses.\n";
			cout << "\t[4] Communication.\n";
			cout << "\t[5] Log out.\n";
			cout << "===========================================\n";
			_PerformMainMenueChoiceScreen((enDoctorMenu)_ReadDoctorMainMenueChoice());
		}
	};



