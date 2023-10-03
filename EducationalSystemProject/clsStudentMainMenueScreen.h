#pragma once
#include <iostream>
#include "src/clsStudent.h"
#include "src/Library/clsInputValidation.h"
#include "clsMyCoursesListScreen.h"
#include "clsShowRegisterInCourseScreen.h"
#include "clsShowCoursesDetails.h"
#include "clsCommunicationScreen.h"
class clsStudentMainMenueScreen : protected clsScreen
{
	enum enStudentMenu { enRegisterInCourse = 1, enListMyCourses = 2, enViewCourse = 3, enGradesReport = 4, eCommunication = 5, enLogout = 6	};
static	short _ReadStudentMainMenueChoice()
	{
		cout << "Choice One Item Between [1 to 6] : ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 6);
		return Choice;
	}
static	void _GoBackToStudentMainMenue()
	{
		cout << "\n\nPress any key to go back to Main Menue...";
		system("pause>0");
		StudentMainMenueScreen();
	}
	static void ShowRegsterInCourseScreen()
	{
		clsShowRegisterInCourseScreen::ShowCoursesListforRegistred();
	}
	static void ShowMyCoursesListScreen()
	{
		clsMyCoursesListScreen::ShowCoursesListforRegistred();
	}
	static void ShowViewCoursesScreen()
	{
		clsShowCoursesDetails::ShowCoursesDetails();
	}
	static void ShowGradesReportScreen()
	{
		cout << "Here Will Be Grade Report Screen";
	}
	
	static void ShowCommunicationScreen()
	{
		clsCommunicationScreen::ShowEmailBoxMainMenue();
	}
	static void LogOut()
	{
		cout << "Here Will Be Show Register In Course Screen";
	}

static	void _PerformMainMenueChoiceScreen(enStudentMenu Studnet)
	{
		switch (Studnet)
		{
		case clsStudentMainMenueScreen::enRegisterInCourse:
			system("cls");
			ShowRegsterInCourseScreen();
			_GoBackToStudentMainMenue();
			break;
		case clsStudentMainMenueScreen::enListMyCourses:
			system("cls");
			ShowMyCoursesListScreen();
			_GoBackToStudentMainMenue();
			break;
		case clsStudentMainMenueScreen::enViewCourse:
			system("cls");
			ShowViewCoursesScreen();
			_GoBackToStudentMainMenue();
			break;
		case clsStudentMainMenueScreen::enGradesReport:
			system("cls");
			ShowGradesReportScreen();
			_GoBackToStudentMainMenue();
			break;
		case clsStudentMainMenueScreen::eCommunication:
			system("cls");
			ShowCommunicationScreen();
			_GoBackToStudentMainMenue();
			break;
		case clsStudentMainMenueScreen::enLogout:
			//clsLoginPageScreen::ShowLoginPage();
			break;
		default:
			break;
		}
	}
public:

	static void StudentMainMenueScreen()
	{
		system("cls");
		cout << "\n-----------------------------------------------------------------------------\n";
		cout << "\t Welcome Student " << CurrentStudent.FullName << " Your are Logged in Main Menu  ";
		cout << "\n-----------------------------------------------------------------------------\n";
		ShowUserNameAndDate();
		cout << "\t[1] Register in  Courses.\n";
		cout << "\t[2] List My Courses.\n";
		cout << "\t[3] View a Courses.\n";
		cout << "\t[4] Grades Report.\n";
		cout << "\t[5] Communication.\n";
		cout << "\t[6] Log out.\n";
		cout << "===========================================\n";
		cout << "Choice One Item Between [1 to 5] : ";
		_PerformMainMenueChoiceScreen((enStudentMenu)_ReadStudentMainMenueChoice());
	}
};

