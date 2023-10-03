#pragma once
#include <iostream>
#include "src/clsStudent.h"
#include "src/Library/clsInputValidation.h"
#include "clsDoctor.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "clsDoctorMainMenu.h"
#include "clsStudentMainMenueScreen.h"
class clsLoginPageScreen : protected clsScreen
{
    void _CheckFile(const string& File)
    {
        fstream Files;
        Files.open(File, ios::in);
        if (!Files.is_open())
        {
            Files.open(File, ios::out);
        }

    }

    enum eUserType { eStudent =1 , eDoctor = 2, eSystemShutDown = 3};
    enum eLoginType {eLogIn = 1 , eSignUp = 2};


static	short _ReadLoginMainMenueChoice()
    {
        cout << "Choice One Item Between [1 to 3] : ";
        short Choice = clsInputValidate::ReadNumberBetween(1, 3);
        return Choice;
    }   
    
static   void _ReadStudentCredential(clsStudent &Student)
    {
        Student.UserName = clsInputValidate::ReadStrings("Enter Student Username :");
        while (clsStudent::isStudentExist(Student.UserName))
        {
            cout << "Exist Student username,,, Try another one ,\n\n";
            Student.UserName = clsInputValidate::ReadStrings("Enter Student Username :");
            Student.Password = clsInputValidate::ReadStrings("Enter Student Password :");
        }
        Student.Password = clsInputValidate::ReadStrings("Enter Student Password :");
        Student.FullName = clsInputValidate::ReadStrings("Enter Student FullName :");
        Student.Email = clsInputValidate::ReadStrings("Enter Student Email :");
        Student.PhoneNumber = clsInputValidate::ReadStrings("Enter Student PhoneNumber :");
       
    } 
    
static void _ReadDoctorCredential(clsDoctor& Doctor)
    {
        Doctor.UserName = clsInputValidate::ReadStrings("Enter Doctor Username :");
        Doctor.Password = clsInputValidate::ReadStrings("Enter Doctor Password :");
        while (clsDoctor::isDoctorExist(Doctor.UserName))
        {
            cout << "Exist Doctor username,,, Try another one ,\n\n";
            Doctor.UserName = clsInputValidate::ReadStrings("Enter Doctor Username :");
            Doctor.Password = clsInputValidate::ReadStrings("Enter Doctor Password :");
        }
        Doctor.FullName = clsInputValidate::ReadStrings("Enter Doctor FullName :");
        Doctor.Email    = clsInputValidate::ReadStrings("Enter Doctor Email :");
        Doctor.PhoneNumber = clsInputValidate::ReadStrings("Enter Doctor PhoneNumber :");
       
    }

static	short _ReadLoginChoice()
    {
        cout << "Choice One Item Between [1 to 2] : ";
        short Choice = clsInputValidate::ReadNumberBetween(1, 2);
        return Choice;
    }

static  string  _ReadUsername(string message)
    {
        string Username = clsInputValidate::ReadStrings(message);
        return Username;
    }  
    
static  string  _ReadPassword(string message)
    {
        string Password = clsInputValidate::ReadStrings(message);
        return Password;
    }

static string _ReadID()
  {
      string ID = clsInputValidate::ReadStrings("Enter ID : ");
      return ID;
   }

static void CreateStudent()
  {
      string ID = _ReadID();
      clsStudent Student = clsStudent::GetAddNewStudentObject(ID);
      _ReadStudentCredential(Student);
      Student.Save();
      CurrentStudent = Student;
  }  
  
static void CreateDoctor()
  {
      string ID = _ReadID();
      clsDoctor Doctor= clsDoctor::GetAddNewDoctorObject(ID);
      _ReadDoctorCredential(Doctor);
      Doctor.Save();
      CurrentDoctor = Doctor;
  }

static   bool _CheckDoctorCredential(clsDoctor &Doctor)
    {
        string DoctorUsername = _ReadUsername("Enter Doctor Username : ");
        string DoctorPassword = _ReadPassword("Enter Doctor Password : ");;
        Doctor = clsDoctor::Find(DoctorUsername, DoctorPassword);
        while (Doctor.isEmpty())
        {
            cout << "InvaValid/Username/Password Try Again, , , , \n\n";
            DoctorUsername = _ReadUsername("Enter Doctor Username : ");
            DoctorPassword = _ReadPassword("Enter Doctor Password : ");
            Doctor = clsDoctor::Find(DoctorUsername, DoctorPassword);
        }
        return true;
    }  
    
static bool _CheckStudentCredential(clsStudent &Student)
    {
        string StudentUsername = _ReadUsername("Enter Student Username : ");
        string StudentPassword = _ReadPassword("Enter Student Password : ");;
        Student = clsStudent::Find(StudentUsername, StudentPassword);
        while (Student.isEmpty())
        {
            cout << "InvaValid/Username/Password Try Again, , , , \n\n";
            StudentUsername = _ReadUsername("Enter Student Username : ");
            StudentPassword = _ReadPassword("Enter Student Password : ");
            Student = clsStudent::Find(StudentUsername, StudentPassword);
        }
        return true;
    }

static  void GoToStudentScreen()
    {
        if (_CheckStudentCredential(CurrentStudent))
        {
            clsStudentMainMenueScreen::StudentMainMenueScreen();
        }
    } 
    
static  void GoToDoctorScreen()
    {
        if (_CheckDoctorCredential(CurrentDoctor))
        {
            clsDoctorMainMenu::DoctorMainMenueScreen();
        }
    }

static void _PerformChoiceOnLogin(eUserType User)
  {
      
      switch (User)
      {
      
      case clsLoginPageScreen::eStudent:
          isStudent = true;
          GoToStudentScreen();
         
          break;
      case clsLoginPageScreen::eDoctor:
          GoToDoctorScreen();
          break;
      default:
          break;
      }
  } 

static void _PerformChoiceOnSignUp(eUserType User)
  {
      ;
      switch (User)
      {
      case clsLoginPageScreen::eStudent:
          CreateStudent();
          clsStudentMainMenueScreen::StudentMainMenueScreen();
          break;
      case clsLoginPageScreen::eDoctor:
          CreateDoctor();
          clsDoctorMainMenu::DoctorMainMenueScreen();
          break;
      }
  }

static void Login()
  {

      ShowTabtScreen("\tLogin");
      cout << "\t[1] Student.\n";
      cout << "\t[2] Doctor.\n";
      cout << "===========================================\n";
      cout << "Choice One Item Between [1 to 2] : ";
      _PerformChoiceOnLogin((eUserType)_ReadLoginChoice());
  } 

static void SignUp()
  {

      ShowTabtScreen("\Sign Up");
      cout << "\t[1] Student.\n";
      cout << "\t[2] Doctor.\n";
      cout << "===========================================\n";
      cout << "Choice One Item Between [1 to 2] : ";
      _PerformChoiceOnSignUp((eUserType)_ReadLoginChoice());
  }

static bool _PerfromLoginMainMenuScreen(eLoginType Type)
    {
        switch (Type)
        {
        case clsLoginPageScreen::eLogIn:
            Login();
            break;
        case clsLoginPageScreen::eSignUp:
            SignUp();
            break;
        case clsLoginPageScreen::eSystemShutDown:
            return false;
        default:
            return true;
        }
    }



public :

static bool  ShowLoginPage()
    {
        system("cls");

        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";
        cout << "\t[1] Login.\n";
        cout << "\t[2] New ? Sign Up Now !.\n";
        cout << "\t[3] ShutDown System.\n";
        cout << "===========================================\n";
        cout << "Choice One Item Between [1 to 3] : ";
        return _PerfromLoginMainMenuScreen((eLoginType)_ReadLoginMainMenueChoice());
    }
};

