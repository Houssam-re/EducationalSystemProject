#pragma once
#include "clsCourses.h"
#include "clsStudent.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "src/Library/clsInputValidation.h"
#include <iostream>
using namespace std;
class ShowSendEmailScreen : protected clsScreen
{

	enum eStorDc {eStudent = 1 , eDoctor = 2};
	static	string _ReadTheReciverEmail()
	{
		string ReciverEmail = clsInputValidate::ReadStrings("Enter The Reciver Email : ");
		return ReciverEmail;
	}
static	string _ReadTheSubjectEmail()
	{
		string Subject = clsInputValidate::ReadStrings("Enter The Subject of Email : ");
		return Subject;
	}
static	string _ReadTheEmail()
	{
		string Message = clsInputValidate::ReadStrings("Enter The message of Email : ");
		return Message;
	}
	
static	short ToStudentOrDoctor()
	{
		cout << "Do You Want To Send This Email To Student[1] or Doctor[2] ?  : ";
		short TheChoice = clsInputValidate::ReadNumberBetween(1, 2);
		return TheChoice;
	}
static  void SendEmailToStudent()
	{
		string ReciverEmail = _ReadTheReciverEmail();
		clsStudent Student = clsStudent::FindByEmail(ReciverEmail);
		while (Student.isEmpty())
		{
			cout << "invalid/Email Try Again ,,,,\n";
			ReciverEmail = _ReadTheReciverEmail();
			Student = clsStudent::FindByEmail(ReciverEmail);

		}
		string Subject = _ReadTheSubjectEmail();
		string Email = _ReadTheEmail();
		if (CurrentStudent.SendEmail(Student, Subject, Email))
		{
			cout << "Email Sended Secssfully...";
		}
		else
		{
			cout << "Email Not Sended,,";
		}
	}

static  void SendEmailToDoctor()
	{
		string ReciverEmail = _ReadTheReciverEmail();
		clsDoctor Doctor = clsDoctor::FindByEmail(ReciverEmail);
		while (Doctor.isEmpty())
		{
			cout << "invalid/Email Try Again ,,,,\n";
			ReciverEmail = _ReadTheReciverEmail();
			Doctor = clsDoctor::FindByEmail(ReciverEmail);

		}
		string Subject = _ReadTheSubjectEmail();
		string Email = _ReadTheEmail();
		if (CurrentStudent.SendEmail(Doctor, Subject, Email))
		{
			cout << "Email Sended Secssfully...";
		}
		else
		{
			cout << "Email Not Sended,,";
		}
	}


public :
	static void SendEmailScreen()
	{
		ShowTabtScreen("\tSend Email Screen");
		switch ((eStorDc)ToStudentOrDoctor())
		{
		case eStorDc::eStudent:
			SendEmailToStudent();
			break;
		case eStorDc::eDoctor:
			SendEmailToDoctor();
		}

	}
};

