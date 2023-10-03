#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "src/Library/clsString.h"
#include "clsScreen.h"
#include "src/Library/clsInputValidation.h"
#include "clsGlobal.h"
#include "src/Library/clsUtil.h"
using namespace std;


class clsStudentRecivedEmailBoxScreen : protected clsScreen
{


		struct stRecivedEmailInfo
		{
			string _UserName;
			string EmailTo;
			string Subject;
			string Email;
			string _Time;
		};
		static void PrintRecivedEmailBoxRegisterRecord(stRecivedEmailInfo User)
		{
			cout << setw(20) << left << "" << "| " << setw(20) << left << User._Time;
			cout << "| " << setw(20) << left << User._UserName;
			cout << "| " << setw(30) << left << User.EmailTo;
			cout << "| " << setw(20) << left << User.Subject;
			cout << "| " << setw(30) << left << User.Email;
		}
		static	stRecivedEmailInfo ConvertLineToRecord(string Line)
		{
			vector <string> EmailInfo = clsString::SplitString(Line, "#//#");
			stRecivedEmailInfo Email;
			Email._Time = EmailInfo[0];
			Email._UserName = EmailInfo[1];
			Email.Subject = EmailInfo[2];
			Email.Email = EmailInfo[3];
			Email.EmailTo = EmailInfo[4];
			return Email;
		}

		static vector <stRecivedEmailInfo> _LoadRecivedMailBoxFromFileToVector()
		{
			fstream File;
			vector <stRecivedEmailInfo> vUserEmail;
			std::string ReciverFilePath = "C:\\dev\\EducationalSystemProject\\EducationalSystemProject\\RecievedMailBox\\" + CurrentStudent.FullName + "RecivedMailBox.txt";

			File.open(ReciverFilePath, ios::in);
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
			string Title = "\t  Recived Email Box Screen";
			string SubTitle = "\t    (" + to_string(Num) + ") Record(s).";

			_DrawScreenHeader(Title, SubTitle);

			cout << setw(15) << left << "" << "\n\t\t____________________________________________________________________________________________";
			cout << "_________________________________________\n" << endl;

			cout << setw(20) << left << "" << "| " << left << setw(20) << "Date /Time";
			cout << "| " << left << setw(20) << "UserName";
			cout << "| " << left << setw(30) << "Email Recived From";
			cout << "| " << left << setw(20) << "Subject";
			cout << "| " << left << setw(30) << "Email Content";
			cout << setw(15) << left << "" << "\n\t\t_____________________________________________________________________________________________";
			cout << "_________________________________________\n" << endl;
		}
		static vector <stRecivedEmailInfo> GetUserRecivedBoxList()
		{
			return _LoadRecivedMailBoxFromFileToVector();
		}
	public:

		static void ShowRecivedBoxScreen()
		{

			vector <stRecivedEmailInfo> vUser;
			vUser = GetUserRecivedBoxList();



			PrintRegistredTable(vUser.size());
			if (vUser.empty())
			{
				cout << clsUtil::Tabs(4) << left << setw(30) << "There is No Recived Email Box ,,";
			}
			for (auto& i : vUser)
			{
				PrintRecivedEmailBoxRegisterRecord(i);
				cout << endl;
			}

		}
	

};

