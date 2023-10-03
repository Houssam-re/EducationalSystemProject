#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "src/Library/clsString.h"
#include "src/clsPerson.h"
const string DoctorFile = "Doctor.txt";
class clsDoctor : public clsPerson
{
private:
	enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewDoctor =2  , enCreateCourse = 3 };
	enum enSave { eSaveSuccesfull = 1, sSaveFailed = 0 };
	enMode _Mode;

	clsDoctor
	(enMode Mode, string FullName, string UserName, string Password, string ID, string Email, string PhoneNumber) :clsPerson(FullName, UserName, ID, Password, Email, PhoneNumber)
	{
		_Mode = Mode;
	}

	static clsDoctor _ConvertDoctorLineToObject(string Line)
	{
		vector <string> vString = clsString::SplitString(Line, "#//#");
		return clsDoctor
		(enMode::eUpdateMode, vString[0], vString[1], vString[2], vString[3], vString[4], vString[5]);
	}
	string _ConvertDoctorRecordToLine(clsDoctor& Doctor, const string& delim = "#//#")
	{
		string word = "";
		word += Doctor.FullName + delim;
		word += Doctor.UserName + delim;
		word += Doctor.Password + delim;
		word += Doctor.getID() + delim;
		word += Doctor.Email + delim;
		word += Doctor.PhoneNumber ;

		return word;
	}
	static	vector <clsDoctor> _LoadDoctorDataFromFileToVector(const string& DFile = DoctorFile)
	{
		vector <clsDoctor> vDoctor;
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
				vDoctor.push_back(_ConvertDoctorLineToObject(line));
			}
		}
		return vDoctor;
	}
	void _SaveDoctorDataFromVectorToFile(vector <clsDoctor> vDoctor, const string& DFile = DoctorFile)
	{
		fstream File;
		File.open(DFile, ios::out);
		if (File.is_open())
			for (clsDoctor& i : vDoctor)
			{
				File << _ConvertDoctorRecordToLine(i) <<endl;
			}
		File.close();
	}
	void _Update()
	{
		vector <clsDoctor> vDoctor = _LoadDoctorDataFromFileToVector();
		for (clsDoctor& i : vDoctor)
		{
			if (i.UserName == UserName)
				i = *this;
		}
		_SaveDoctorDataFromVectorToFile(vDoctor);
	}

	void _AddNewDoctor()
	{
		vector <clsDoctor> vDoctor = _LoadDoctorDataFromFileToVector();
		vDoctor.push_back(*this);
		_SaveDoctorDataFromVectorToFile(vDoctor);
	}
	static  clsDoctor _GetEmptyDoctorObject()
	{
		return clsDoctor(enMode::eEmptyMode, "", "", "", "", "", "");
	}


public:
	static  clsDoctor GetAddNewDoctorObject(string ID)
	{
		return clsDoctor(enMode::eAddNewDoctor, "", "", "", ID, "", "");
	}
	bool isEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	static clsDoctor Find(string UserName)
	{
		vector <clsDoctor> vclsDoctor = _LoadDoctorDataFromFileToVector();
		for (clsDoctor& i : vclsDoctor)
		{
			if (i.UserName == UserName)
			{
				return i;
			}
		}
		return _GetEmptyDoctorObject();
	}	
	static clsDoctor FindByEmail(string Email)
	{
		vector <clsDoctor> vclsDoctor = _LoadDoctorDataFromFileToVector();
		for (clsDoctor& i : vclsDoctor)
		{
			if (i.Email == Email)
			{
				return i;
			}
		}
		return _GetEmptyDoctorObject();
	}
	static clsDoctor Find(string UserName, string Password)
	{
		clsDoctor Student = Find(UserName);
		if (Student.Password == Password)
		{
			return Student;
		}
		else
			return _GetEmptyDoctorObject();
	}
	static bool isDoctorExist(string UserName)
	{
		clsDoctor Doctor = clsDoctor::Find(UserName);
		return (!Doctor.isEmpty());
	}

	enSave Save()
	{
		switch (_Mode)
		{
		case clsDoctor::eEmptyMode:
			return sSaveFailed;
		case clsDoctor::eUpdateMode:
			_Update();
			return eSaveSuccesfull;
		case clsDoctor::eAddNewDoctor:
			_AddNewDoctor();
			_Mode = enMode::eUpdateMode;
			return eSaveSuccesfull;
		case clsDoctor::enCreateCourse:
			break;
		default:
			break;
		}
	}
};

