#pragma once
#include <iostream>
#include "clsDoctor.h"
#include "src/Library/clsInputValidation.h"
#include "clsGlobal.h"
#include "clsScreen.h"
#include "clsCourses.h"
class clsCreateCourseScreen : protected clsScreen
{
	static string _ReadCourseCode()
	{
		string CourseCode = clsInputValidate::ReadStrings("Enter Course Code : ");
		return CourseCode;
	}	
	
	static string _ReadCourseName()
	{
		string CourseName = clsInputValidate::ReadStrings("Enter Course Name : ");
		return CourseName;
	}
	static void _ReadCourseInfo(clsCourses &Course)
	{
		cout << "New Course Code " << Course.Code << " Please Enter The Rest Information : \n";
		Course.Name = _ReadCourseName();
		Course.StudentRegistred = clsCourses::_GetRandomMultipleofTwoNumber();
		Course.CreatorName = CurrentDoctor.FullName;
	}

public:

	static void CreateCourseScreen()
	{
		ShowTabtScreen("\n Create Course Screen ");
		char Answer = 'y';
		do
		{
		vector <clsCourses> vCourses = clsCourses::GetCoursesList();
		string CourseCode = _ReadCourseCode();

			while (clsCourses::isCourseExist(CourseCode))
			{
				cout << "Exist Course Code  Try Another One Please ,,,\n\n";
				CourseCode = _ReadCourseCode();
			}
			clsCourses NewCourse = clsCourses::GetAddNewCourseObject(CourseCode);
			_ReadCourseInfo(NewCourse);
			printf(" Created Succsefful ! ,,,\n\n");
			NewCourse.Save();
			cout << "Do you want to add more Courses ? y/n ";
			cin >> Answer;
		} while (towlower(Answer) == 'y');
		
	}

};

