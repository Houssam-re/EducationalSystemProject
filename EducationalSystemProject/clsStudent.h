#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "src/Library/clsString.h"
#include "src/clsPerson.h"
string StudentFile = "Students.txt";
class clsStudent : public clsPerson
{

private:
	enum enMode { eUpdateMode = 1, eEmptyMode = 0 , eAddNewStudentMode =2};
	enum enSave {eSaveSuccesfull = 1 , sSaveFailed = 0};
	enMode _Mode;
	int _RegistredCourses;
	bool MarkForDelete = false;

	clsStudent
	(enMode Mode, string FullName,string UserName, string Password, string ID, string Email, string PhoneNumber, int RegistredCourses) :clsPerson(FullName, UserName,ID, Password, Email, PhoneNumber)
	{
		_RegistredCourses = RegistredCourses;
		_Mode = Mode;
	}

static clsStudent _ConvertStudentLineToObject(string Line)
	{
		vector <string> vString = clsString::SplitString(Line, "#//#");
		return clsStudent
		(enMode::eUpdateMode, vString[0], vString[1], vString[2], vString[3], vString[4], vString[5], stoi(vString[6]));
	}
string _ConvertStudentRecordToLine(clsStudent& Student, const string& delim = "#//#")
{
	string word = "";
	word += Student.FullName + delim;
	word += Student.UserName + delim;
	word += Student.Password + delim;
	word += Student.getID() + delim;
	word += Student.Email + delim;
	word += Student.PhoneNumber + delim;
	word += to_string(Student.RegistredCourse);

	return word;
}
static	vector <clsStudent> _LoadStudentDataFromFileToVector(const string& DFile = StudentFile)
	{
		vector <clsStudent> vStudent;
		fstream File;
		File.open(DFile, ios::in);
		if (!File.is_open())
		{
			cout << "There is a mistake in file ,,,";
			exit(1);
		}
		else
		{
			string line;
			while (getline(File, line))
			{
				vStudent.push_back(_ConvertStudentLineToObject(line));
			}
		}
		return vStudent;
	}
		void _SaveStudentDataFromVectorToFile(vector <clsStudent> vStudents, const string& DFile = StudentFile)
		{
			fstream File;
			File.open(DFile, ios::out);
			if(File.is_open())
			for (clsStudent& i : vStudents)
			{
				File << _ConvertStudentRecordToLine(i) << endl;
			}
			File.close();
		}
		void _Update()
		{
			vector <clsStudent> vStudents = _LoadStudentDataFromFileToVector();
			for (clsStudent& i : vStudents)
			{
				if (i.UserName == UserName)
					i = *this;
			}
			_SaveStudentDataFromVectorToFile(vStudents);
		}
		void _AddNewStudent()
		{
			vector <clsStudent> vStudent = _LoadStudentDataFromFileToVector();
			vStudent.push_back(*this);
			_SaveStudentDataFromVectorToFile(vStudent);
		}
static  clsStudent _GetEmptyStudentObject()
	 {
		 return clsStudent(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	 }
void _PutEmailInSendedBox(string Line, string ReciverEmail)
{
	fstream File;
	Line += "#//#" + ReciverEmail;
	std::string SenderFilePath = "C:\\dev\\EducationalSystemProject\\EducationalSystemProject\\SendedMailBox\\" + FullName + "SendedMailBox.txt";
	File.open(SenderFilePath, ios::out | ios::app);
	if (File.is_open())
	{
		File << Line << endl;
		File.close();
	}
}
public:
	bool isEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}
	
	void setRegistredCourses(int RegistreNum)
	{
		_RegistredCourses = RegistreNum;
	}
	int getRegistredCourses()
	{
		return _RegistredCourses;
	}
	__declspec(property(get = getRegistredCourses, put = setRegistredCourses))int RegistredCourse;

	static clsStudent Find(string UserName)
	{
		vector <clsStudent> vclsStudents = _LoadStudentDataFromFileToVector();
		for (clsStudent& i : vclsStudents)
		{
			if (i.UserName == UserName)
			{
				return i;
			}
		}
		return _GetEmptyStudentObject();
	}	
	static clsStudent FindByEmail(string Email)
	{
		vector <clsStudent> vclsStudents = _LoadStudentDataFromFileToVector();
		for (clsStudent& i : vclsStudents)
		{
			if (i.Email == Email)
			{
				return i;
			}
		}
		return _GetEmptyStudentObject();
	}	
	static clsStudent Find(string UserName ,string Password)
	{
		clsStudent Student = Find(UserName);
		if (Student.Password == Password)
		{
			return Student;
		}
		else
			return _GetEmptyStudentObject();
	}
static	bool isStudentExist(string UserName)
	{
		clsStudent Student = clsStudent::Find(UserName);
		return (!Student.isEmpty());
	}
	bool CheckIfMyCourse(short RegisterNumber)
	{
		return (RegistredCourse & RegisterNumber);
	}
	static vector <clsStudent> GetStudentList()
	{
		return _LoadStudentDataFromFileToVector();
	}
	static  clsStudent GetAddNewStudentObject(string ID)
	{
		return clsStudent(enMode::eAddNewStudentMode, "", "", "", ID, "", "", 0);
	}
	
	 template <typename T> bool SendEmail(T Destination , string Subject,string Email)
	{
		fstream File;
		string Line = clsDate::GetSystemDateTimeString() + "#//#" + UserName + "#//#" + Subject + "#//#" + Email + "#//#" + getEmail();
		File.open("C:\\dev\\EducationalSystemProject\\EducationalSystemProject\\RecievedMailBox\\" + Destination.FullName + "RecivedMailBox.txt", ios::out | ios::app);
		if (File.is_open())
		{
			File << Line << endl;
			File.close();
			_PutEmailInSendedBox(Line, Destination.getEmail());
			return true;
		}
		return false;
	}
	enSave Save()
	{
		switch (_Mode)
		{
		case clsStudent::eUpdateMode:
			_Update();
			return eSaveSuccesfull;
		case clsStudent::eEmptyMode:
			return sSaveFailed;
		case clsStudent::eAddNewStudentMode:
			_AddNewStudent();
			_Mode = enMode::eUpdateMode;
			return eSaveSuccesfull;
		default:
			break;
		}
	}


};

