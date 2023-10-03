#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "src/Library/clsString.h"
#include "src/Library/clsInputValidation.h"
#include "clsGlobal.h"
#include "src/Library/clsUtil.h"
#include "clsScreen.h"
using namespace std;

class clsStudentSendedEmailBoxScreen : protected clsScreen
{

	struct stSendedEmailInfo
	{
		string _UserName;
		string EmailTo;
		string Subject;
		string Email;
		string _Time;
	};
	static void PrintSenderEmailBoxRegisterRecord(stSendedEmailInfo User)
	{
		cout << setw(20) << left << "" << "| " << setw(20) << left << User._Time;
		cout << "| " << setw(20) << left << User._UserName;
		cout << "| " << setw(30) << left << User.EmailTo;
		cout << "| " << setw(20) << left << User.Subject;
		cout << "| " << setw(30) << left << User.Email;
	}
	static	stSendedEmailInfo ConvertLineToRecord(string Line)
	{
		vector <string> EmailInfo = clsString::SplitString(Line, "#//#");
		stSendedEmailInfo Email;
		Email._Time = EmailInfo[0];
		Email._UserName = EmailInfo[1];
		Email.Subject = EmailInfo[2];
		Email.Email = EmailInfo[3];
		Email.EmailTo = EmailInfo[5];
		return Email;
	}

	static vector <stSendedEmailInfo> _LoadSendedMailBoxFromFileToVector()
	{
		fstream File;
		vector <stSendedEmailInfo> vUserEmail;
		std::string SenderFilePath = "C:\\dev\\EducationalSystemProject\\EducationalSystemProject\\SendedMailBox\\" + CurrentStudent.FullName + "SendedMailBox.txt";

		File.open(SenderFilePath, ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				vUserEmail.push_back(ConvertLineToRecord(Line));
			}
			return vUserEmail;
		}
	}

	static void PrintRegistredTable(int Num)
	{
		string Title = "\t  Sended Email Box Screen";
		string SubTitle = "\t    (" + to_string(Num) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(15) << left << "" << "\n\t\t____________________________________________________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(20) << left << "" << "| " << left << setw(20) << "Date /Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(30) << "Email Sended To";
		cout << "| " << left << setw(20) << "Subject";
		cout << "| " << left << setw(30) << "Email Content";
		cout << setw(15) << left << "" << "\n\t\t_____________________________________________________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
	static vector <stSendedEmailInfo> GetUserSendedBoxList()
	{
		return _LoadSendedMailBoxFromFileToVector();
	}
public:

	static void ShowSendedBoxScreen()
	{

		vector <stSendedEmailInfo> vUser;
		vUser = GetUserSendedBoxList();



		PrintRegistredTable(vUser.size());
		if (vUser.empty())
		{
			cout << clsUtil::Tabs(4) << left << setw(30) << "There is No Sended Email Box ,,";
		}
		for (auto& i : vUser)
		{
			PrintSenderEmailBoxRegisterRecord(i);
			cout << endl;
		}

	}
};

