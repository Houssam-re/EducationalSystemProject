#pragma once
#include <iostream>
#include <fstream>
#include "clsStudent.h"
#include "src/Library/clsString.h"
#include "clsMyMath.h"
#include "src/Library/clsInputValidation.h"
using namespace std;
string CoursesFile = "Course.txt";
class clsCourses
{
	enum enMode { eUpdateMode = 1, eEmptyMode = 0, enAddCourseMode = 2 };
	
	enMode _Mode;
	string _Name;
	string _Code;
	string _CreatorName;
	int _NumberOfRegistredStudents;
	int _StudentRegistred;

	clsCourses(enMode Mode,string Name, string Code, string CreatorName, int NumberRgTsT, int StuRgst)
	{
		_Mode = Mode;
		_Name = Name;
		_Code = Code;
		_CreatorName = CreatorName;
		_NumberOfRegistredStudents = NumberRgTsT;
		_StudentRegistred = StuRgst;
	}


	static clsCourses _ConvertCourseLineToRecord(const string& Line)
	{
		vector <string> vstring = clsString::SplitString(Line,"#//#");
		return clsCourses(
			enMode::eUpdateMode,
			vstring[0],
			vstring[1],
			vstring[2],
			stoi(vstring[3]),
			stoi(vstring[4])); 
	}
	static string _ConvertCourseFromRecordToLine(clsCourses Course , const string& delim = "#//#")
	{
		string Line = "";
		Line += Course.Name + delim;
		Line += Course.Code + delim;
		Line += Course.CreatorName + delim;
		Line += to_string(Course.NumberOfRegistredStudents) + delim;
		Line += to_string(Course.StudentRegistred);
		return Line;
	}
	static clsCourses _GetEmptyCourseObject()
	{
		return clsCourses(enMode::eEmptyMode, "", "", "", 0, 0);
	}
	static void _SaveCoursesDataFromVectorToFile(vector <clsCourses>& vCourse, const string& DFile = CoursesFile)
	{
		fstream File;
		File.open(DFile, ios::out);
		if (!File.is_open())
		{
			cout << "There is a mistake in file ,,,";
			exit(1);
		}
		else
		{
			for (clsCourses& i : vCourse)
			{
				File << _ConvertCourseFromRecordToLine(i) << endl;
			}
			File.close();
		}

	}

	static vector <clsCourses>  _LoadCoursesListFromFileToVector(const string& sFile = CoursesFile)
	{
		fstream File;
		vector <clsCourses> vCourse;
		File.open(sFile, ios::in);
		if (!File.is_open())
		{
			cout << "There is a problem in Opening File,,,,";
			exit(1);
		}
		string Line;
		while (getline(File, Line))
		{
			vCourse.push_back(_ConvertCourseLineToRecord(Line));
		}
		return vCourse;
	}


public:
	enum enSave { eSaveSuccesfull = 1, sSaveFailed = 0 };
	void setName(string Name)
	{
		_Name = Name;
	}
	string getName()
	{
		return _Name;
	}
	__declspec(property(get = getName, put = setName))string Name;
	
	
	
	void setCode(string Code)
	{
		_Code = Code;
	}
	string getCode()
	{
		return _Code;
	}
	__declspec(property(get = getCode, put = setCode))string Code;
	
	
	
	void setCreatorName(string CreatorName)
	{
		_CreatorName = CreatorName;
	}
	string getCreatorName()
	{
		return _CreatorName;
	}
	__declspec(property(get = getCreatorName, put = setCreatorName))string CreatorName;
	
	
	
	
	void setNumberOfRegistredStudents(int NumberOfRegistredStudents)
	{
		_NumberOfRegistredStudents = NumberOfRegistredStudents;
	}
	int getNumberOfRegistredStudents()
	{
		return _NumberOfRegistredStudents;
	}
	__declspec(property(get = getNumberOfRegistredStudents, put = setNumberOfRegistredStudents))int NumberOfRegistredStudents;
	
	
	
	void setStudentRegistred(int StudentRegistred)
	{
		_StudentRegistred = StudentRegistred;
	}
	int getStudentRegistred()
	{
		return _StudentRegistred;
	}
	__declspec(property(get = getStudentRegistred, put = setStudentRegistred))int StudentRegistred;

	void _Update()
	{
		vector <clsCourses> vCourses = _LoadCoursesListFromFileToVector();
		for (clsCourses& i : vCourses)
		{
			if (i.Code == Code)
				i = *this;
		}
		_SaveCoursesDataFromVectorToFile(vCourses);
	}
	static int _GetRandomMultipleofTwoNumber()
	{
		vector <clsCourses> vCourses = GetCoursesList();
		int Random = clsMyMath::RandomMultipleOfTwoNumber(1, INT_MAX);
		for (clsCourses& i : vCourses)
		{
			if(i.StudentRegistred == Random)
				Random = clsMyMath::RandomMultipleOfTwoNumber(1, INT_MIN);
		}
		return Random;
	}
	void _AddNewCourse()
	{
		vector <clsCourses> vCourses = clsCourses::GetCoursesList();
		vCourses.push_back(*this);
		_SaveCoursesDataFromVectorToFile(vCourses);
	}
public:


	bool isEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	static clsCourses FindCourseByCode(string CourseCode)
	{
		vector <clsCourses > vCourses = _LoadCoursesListFromFileToVector();


		for (clsCourses& i : vCourses)
		{
			if (i.Code == CourseCode)
				return i;

		}
		return _GetEmptyCourseObject();
	 }
	
	static  clsCourses GetAddNewCourseObject(string CourseCode)
	{
		return clsCourses(enMode::enAddCourseMode, "", CourseCode, "", 0,0);
	}
	 static bool isCourseExist(string CourseCode)
	 {
		 clsCourses Course = clsCourses::FindCourseByCode(CourseCode);
		 return (!Course.isEmpty());
	 }
	 static short ReturnCoursesNumber()
	 {
		 vector <clsCourses> vCourses = _LoadCoursesListFromFileToVector();
		 return vCourses.size();
	 }
	 static vector <clsCourses> GetCoursesList()
	 {
		 return _LoadCoursesListFromFileToVector();
	 }
	 enSave Save()
	 {
		 switch (_Mode)
		 {
		 case clsCourses::eUpdateMode:
			 _Update();
			 return eSaveSuccesfull;
		 case clsCourses::eEmptyMode:
			 return sSaveFailed;
		 case clsCourses::enAddCourseMode:
			 _AddNewCourse();
			 _Mode = enMode::eUpdateMode;
			 return eSaveSuccesfull;
		 default:
			 break;
		 }
	 }
};

