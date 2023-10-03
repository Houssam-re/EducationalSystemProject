#pragma once
#include "clsCourses.h"
#include "clsStudent.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "src/Library/clsInputValidation.h"
#include <iostream>
using namespace std;
class clsShowRegisterInCourseScreen : protected clsScreen
{
	static short _ReadTheCourseChoiceforRegistred(int CoursesNumber)
	{
		printf("choose the course to registre [1 - %d] course to Registre ? ", CoursesNumber);
		short CourseChoice = clsInputValidate::ReadNumberBetween(1, CoursesNumber);
		return CourseChoice;
	}
public:

	static void ShowCoursesListforRegistred()
	{
		ShowTabtScreen("Courses List for Registred");
		vector <clsCourses> vCourse = clsCourses::GetCoursesList();
		short Counter = 0;
		short TheChoice;
		for (clsCourses& i : vCourse)
		{
			Counter++;
			if (!CurrentStudent.CheckIfMyCourse(i.StudentRegistred))
			{
				cout << Counter << ") Course " << i.Name << " -Code " << i.Code << endl;
			}
			else
				cout << Counter << ") Course " << i.Name << " -Code " << i.Code << " (Registred)" << endl;

		}
		TheChoice = _ReadTheCourseChoiceforRegistred(Counter);
		clsCourses Course = vCourse[TheChoice - 1];
		if (!CurrentStudent.CheckIfMyCourse(Course.StudentRegistred))
		{
			CurrentStudent.RegistredCourse += Course.StudentRegistred;
			CurrentStudent.Save();
			Course.NumberOfRegistredStudents++;
			Course.Save();
			if (Course.Save() == clsCourses::eSaveSuccesfull)
			{
				cout << "Registred Succseed ,,,,\n\n";
			}
			
		}
		else
		{
			cout << "You already registred ,,,\n\n";
		}
	}
};

