#pragma once
#include <iostream>
#include "clsDoctor.h"
#include "src/Library/clsInputValidation.h"
#include "clsGlobal.h"
#include "clsStudent.h"
#include "clsScreen.h"
#include "clsCourses.h"
#include"clsShowRegisterInCourseScreen.h"
#include"clsShowCoursesListDoctor.h"
class clsShowCoursesDetails : protected clsScreen
{


	static short _ReadTheCourseChoiceforSeeDetails(int CoursesNumber)
	{
		printf("choose the course to view details [1 - %d]  ? ", CoursesNumber);
		short TheChoice = clsInputValidate::ReadNumberBetween(1, CoursesNumber);
		return TheChoice;
	}

	static void _PrintStudentInfo( clsStudent& Student)
	{


		cout << "\n\t" << "Student : " << Student.FullName << " \n";
		cout << "_____________________________________________" << endl;
		cout << "\n\nID      : " << Student.getID() << endl;
		cout << "\nUserName: " << Student.UserName << endl;
		cout << "\nEmail   : " << Student.Email << endl;
		cout << "_____________________________________________" << endl;
	}
static	void StudentAreRegistgredinCourse(clsCourses Course)
	{
		vector <clsStudent> vStudent = clsStudent::GetStudentList();
		if (Course.NumberOfRegistredStudents == 0)
		{
			cout << "There is no Student Enrolled in this course yet !! ,,,\n\n";
			return;
		}
		for (clsStudent& i : vStudent)
		{
			if (i.CheckIfMyCourse(Course.StudentRegistred))
			{
				_PrintStudentInfo(i);
			}
		}
	}
	static void PrintCourseDetailsforStudent( clsCourses Course)
	{
		char Answer;
		cout << "\n\nCourse " << Course.Name << " With Code " << Course.Code << " -taught by Doctor " << Course.CreatorName << endl << endl;
		if (CurrentStudent.CheckIfMyCourse(Course.StudentRegistred))
		{
			cout << "You already Registred for this Course ! enjoy ";
			return;
		}
		cout << "You are not Registred For This Course Do you want to Registre ? y/n";
		cin >> Answer;
		if (towlower(Answer) == 'y')
			clsShowRegisterInCourseScreen::ShowCoursesListforRegistred();
	

	}
	static void PrintCourseDetailsforDoctor( clsCourses Course)
	{
		char Answer;
		cout << "\n\nCourse " << Course.Name << " With Code " << Course.Code << " -taught by Doctor " << Course.CreatorName << " Number of Student Registred : " << Course.NumberOfRegistredStudents << endl << endl;

		cout << "Do you want to see Registred Student ? y/n";
		cin >> Answer;
		if (towlower(Answer) == 'y')
			StudentAreRegistgredinCourse(Course);

	}
public : 
	static void ShowCoursesDetails(bool ForStudent = true)
	{
		ShowTabtScreen("\tCourses Details");
		vector <clsCourses> vCourses = clsShowCoursesListDoctor::ShowCoursesListForDoctor();
		short Choice = _ReadTheCourseChoiceforSeeDetails(vCourses.size());
		(ForStudent) ? PrintCourseDetailsforStudent(vCourses[Choice - 1]) : PrintCourseDetailsforDoctor(vCourses[Choice - 1]);
	}
};

