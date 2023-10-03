#pragma once
#include <iostream>
#include "clsDoctor.h"
#include "src/Library/clsInputValidation.h"
#include "clsGlobal.h"
#include "clsScreen.h"
#include "clsCourses.h"
class clsShowCoursesListDoctor : protected clsScreen
{
public:
	static vector  <clsCourses> ShowCoursesListForDoctor()
	{
		ShowTabtScreen("\t Courses List");
		vector  <clsCourses> vCourses = clsCourses::GetCoursesList();
		short Counter = 0;
		for (clsCourses& i : vCourses)
		{
			Counter++;
			cout << Counter << ") Course " << i.Name << " -Code " << i.Code << endl;
		}
		return vCourses;
	}

};

