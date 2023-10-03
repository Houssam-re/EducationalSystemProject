#pragma once
#include "clsCourses.h"
#include "clsStudent.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "src/Library/clsInputValidation.h"
#include <iostream>
using namespace std;
class clsMyCoursesListScreen : protected clsScreen
{

public:
	static void ShowCoursesListforRegistred()
	{
		ShowTabtScreen("My  Courses List ");
		vector <clsCourses> vCourse = clsCourses::GetCoursesList();
		short Counter = 0;
		short TheChoice;
		for (clsCourses& i : vCourse)
		{
			Counter++;
			if (CurrentStudent.CheckIfMyCourse(i.StudentRegistred))
			{
				cout << Counter << ") Course " << i.Name << " -Code " << i.Code << endl;
			}
			

		}
	}
};

