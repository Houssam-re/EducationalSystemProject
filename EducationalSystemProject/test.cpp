#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "MyMath.h";
using namespace math;
using namespace std;

void LoginPage();
const string DoctorFile = "Doctor.txt";
const string StudentFile = "Student.txt";
const string CoursesFile = "Course.txt";
enum enLoginChoice { Login = 1, SignUp = 2, SystemShutDown = 3 };
enum enUserType { Admin = 3, Doctor = 1, Student = 2 };
enum enDoctorMenu { enListCourses = 1, enCreateCourses = 2, enViewCourses = 3, enLogOut = 4 };
enum enStudentMenu { enRegisterInCourse = 1, enListMyCourses = 2, enViewCourse = 3, enGradesReport = 4, enLogout = 5 };
struct stStudent
{
    string Username;
    string Password;
    string ID;
    string FullName;
    string Email;
    int RegistredCourses = 0;
    bool MarkForDelete = false;
};
struct stDocotor
{
    string Username;
    string Password;
    string ID;
    string FullName;
    string Email;
};
struct stCourse
{
    string Name;
    string code;
    string Creatorname;
    int numberOfstudentRegistred;
    int StudentRegistred;
};
stStudent CurrentStudent;
stDocotor CurentDoctor;
void DoctorScreen();
void StudentScreen();
void StudentRegisterInCourses();
bool CheckIfMyCourse(short RegisterNumber, const stStudent& Student = CurrentStudent);
void GoBackToStudentMenue();
void GoBackToDoctorMenue();

vector <string> SplitFunction(string String, const string& delim = "#//#")
{
    vector <string>vstring;
    short pos;
    string word = "";
    while ((pos = String.find(delim)) != string::npos)
    {
        word = String.substr(0, pos);
        if (!word.empty())
            vstring.push_back(word);
        String = String.erase(0, pos + delim.length());
    }
    if (!String.empty())
    {
        vstring.push_back(String);
    }
    return vstring;
}

string JoinFunction(const vector <string>& vString, const string& delim = "#//#")
{
    string line = "";
    line += vString[0] + delim;
    line += vString[1] + delim;
    line += vString[2] + delim;
    line += vString[3] + delim;
    line += vString[4];
    return line;
}

string ConvertDoctorRecordToLine(const stDocotor& Doctor, const string& delim = "#//#")
{
    string word = "";
    word += Doctor.ID + delim;
    word += Doctor.Username + delim;
    word += Doctor.Password + delim;
    word += Doctor.FullName + delim;
    word += Doctor.Email;
    return word;
}

string ConvertStudentRecordToLine(const stStudent& Student, const string& delim = "#//#")
{
    string word = "";
    word += Student.ID + delim;
    word += Student.Username + delim;
    word += Student.Password + delim;
    word += Student.FullName + delim;
    word += Student.Email + delim;
    word += to_string(Student.RegistredCourses);


    return word;
}

stDocotor ConvertDoctorLineToRecord(const string& Line)
{
    vector <string> vstring = SplitFunction(Line);
    stDocotor Doctor;
    Doctor.ID = vstring[0];
    Doctor.Username = vstring[1];
    Doctor.Password = vstring[2];
    Doctor.FullName = vstring[3];
    Doctor.Email = vstring[4];
    return Doctor;
}

stStudent ConvertStudentLineToRecord(const string& Line)
{
    vector <string> vstring = SplitFunction(Line);
    stStudent Student;
    Student.ID = vstring[0];
    Student.Username = vstring[1];
    Student.Password = vstring[2];
    Student.FullName = vstring[3];
    Student.Email = vstring[4];
    Student.RegistredCourses = stoi(vstring[5]);
    return Student;
}

stCourse ConvertCourseLineToRecord(const string& Line)
{
    vector <string> vstring = SplitFunction(Line);
    stCourse Course;
    Course.Name = vstring[0];
    Course.code = vstring[1];
    Course.Creatorname = vstring[2];
    Course.numberOfstudentRegistred = stoi(vstring[3]);
    Course.StudentRegistred = stoi(vstring[4]);

    return Course;
}

string ConvertCourseRecordToLine(const stCourse& Course, const string& delim = "#//#")
{

    string Line = "";
    Line += Course.Name + delim;
    Line += Course.code + delim;
    Line += Course.Creatorname + delim;
    Line += to_string(Course.numberOfstudentRegistred) + delim;
    Line += to_string(Course.StudentRegistred);
    return Line;
}

void PutDoctorCredentialFromVectorToFile(vector <stDocotor>& vDoctor, const string& DFile = DoctorFile)
{
    fstream File;
    File.open(DFile, ios::out | ios::app);
    if (!File.is_open())
    {
        cout << "There is a mistake in file ,,,";
        exit(1);
    }
    else
    {
        for (stDocotor& i : vDoctor)
        {
            File << ConvertDoctorRecordToLine(i);
        }
        File.close();
    }

}

void PutStudentCredentialFromVectorToFile(vector <stStudent>& vStudent, const string& DFile = StudentFile)
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
        for (stStudent& i : vStudent)
        {
            File << ConvertStudentRecordToLine(i) << endl;
        }
        File.close();
    }

}
void PutCourseCredentialFromVectorToFile(vector <stCourse>& vCourse, const string& DFile = CoursesFile)
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
        for (stCourse& i : vCourse)
        {
            File << ConvertCourseRecordToLine(i) << endl;
        }
        File.close();
    }

}

vector <stDocotor> PutDoctorCredentialFromFileToVector(const  string& DFile = DoctorFile)
{
    vector <stDocotor> vDoctor;
    fstream File;
    File.open(DFile, ios::in);
    if (!File.is_open())
    {
        File.open(DFile, ios::out);

    }
    else
    {
        string line;
        while (getline(File, line))
        {
            vDoctor.push_back(ConvertDoctorLineToRecord(line));
        }
    }
    return vDoctor;
}

vector <stStudent> PutStudentCredentialFromFileToVector(const string& DFile = StudentFile)
{
    vector <stStudent> vStudent;
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
            vStudent.push_back(ConvertStudentLineToRecord(line));
        }
    }
    return vStudent;
}

enLoginChoice ReadTheLoginChoice()
{
    short Choice;
    cin >> Choice;
    while (Choice > 3 || Choice < 1)
    {
        cout << "False Choice !,,,\n\n";
        cout << "Choice One Item Between [1 to 3] : ";
        cin >> Choice;
    };
    return (enLoginChoice)Choice;
}

enUserType ReadTheSecondLoginChoice()
{
    short Choice;
    cin >> Choice;
    while (Choice > 2 || Choice < 1)
    {
        cout << "False Choice !,,,\n\n";
        cout << "Choice One Item Between [1 to 2] : ";
        cin >> Choice;
    };
    return (enUserType)Choice;
}

enLoginChoice ShowLoginPage()
{
    system("cls");

    cout << "\n---------------------------------\n";
    cout << "\tLogin Screen";
    cout << "\n---------------------------------\n";
    cout << "\t[1] Login.\n";
    cout << "\t[2] Sign Up.\n";
    cout << "\t[3] ShutDown System.\n";
    cout << "===========================================\n";
    cout << "Choice One Item Between [1 to 3] : ";
    return  ReadTheLoginChoice();
}

void SignOrLoginScreen(const string& SignupOrLogIn)
{
    system("cls");
    cout << "\n---------------------------------\n";
    cout << "\t" << SignupOrLogIn << " Screen";
    cout << "\n---------------------------------\n";
}

enUserType ReadLogin(const string& SignupOrLogIn = "Login")
{
    SignOrLoginScreen(SignupOrLogIn);
    cout << "\t[1] Doctor.\n";
    cout << "\t[2] Student.\n";
    cout << "===========================================\n";
    cout << "Choice One Item Between [1 to 2] : ";
    return ReadTheSecondLoginChoice();
}

enDoctorMenu ReadDoctorMenuChoice()
{
    short Choice;
    cin >> Choice;
    while (Choice > 4 || Choice < 1)
    {
        cout << "False Choice !,,,\n\n";
        cout << "Choice One Item Between [1 to 4] : ";
        cin >> Choice;
    };
    return (enDoctorMenu)Choice;
}

enStudentMenu ReadStudentMenuChoice()
{
    short Choice;
    cin >> Choice;
    while (Choice > 5 || Choice < 1)
    {
        cout << "False Choice !,,,\n\n";
        cout << "Choice One Item Between [1 to 4] : ";
        cin >> Choice;
    };
    return (enStudentMenu)Choice;
}

enDoctorMenu ShowDoctorMenu()
{
    system("cls");
    cout << "\n----------------------------------------------------------------------------\n";
    cout << "\tWelcome Doctor " << CurentDoctor.FullName << " You Are Logged In Main Menu  ";
    cout << "\n----------------------------------------------------------------------------\n";
    cout << "\t[1] List Courses.\n";
    cout << "\t[2] Create Courses.\n";
    cout << "\t[3] View Courses.\n";
    cout << "\t[4] Log out.\n";
    cout << "===========================================\n";
    cout << "Choice One Item Between [1 to 4] : ";
    return ReadDoctorMenuChoice();
}

enStudentMenu ShowStudentMenu()
{
    system("cls");
    cout << "\n-----------------------------------------------------------------------------\n";
    cout << "\t Welcome Student " << CurrentStudent.FullName << " Your are Logged in Main Menu  ";
    cout << "\n-----------------------------------------------------------------------------\n";
    cout << "\t[1] Register in  Courses.\n";
    cout << "\t[2] List My Courses.\n";
    cout << "\t[3] View a Courses.\n";
    cout << "\t[4] Grades Report.\n";
    cout << "\t[5] Log out.\n";
    cout << "===========================================\n";
    cout << "Choice One Item Between [1 to 5] : ";
    return ReadStudentMenuChoice();
}

vector <stCourse>  LoadCoursesListFromFileToVector(const string& sFile = CoursesFile)
{
    fstream File;
    vector <stCourse> vCourse;
    File.open(sFile, ios::in);
    if (!File.is_open())
    {
        cout << "There is a problem in Opening File,,,,";
        exit(1);
    }
    string Line;
    while (getline(File, Line))
    {
        vCourse.push_back(ConvertCourseLineToRecord(Line));
    }
    return vCourse;
}

void ShowTabtScreen(const string& WhatToWrite)
{
    system("cls");
    cout << "\n---------------------------------\n";
    cout << "\t" << WhatToWrite << " \n";
    cout << "\n---------------------------------\n";
}

int ShowCoursesListforRegistred()
{
    ShowTabtScreen("Courses List for Registred");
    vector <stCourse> vCourse = LoadCoursesListFromFileToVector();
    short Counter = 0;
    for (stCourse& i : vCourse)
    {
        Counter++;
        if (!CheckIfMyCourse(i.StudentRegistred))
        {
            cout << Counter << ") Course " << i.Name << " -Code " << i.code << endl;
        }
        else
            cout << Counter << ") Course " << i.Name << " -Code " << i.code << " (Registred)" << endl;

    }
    return Counter;
}

int ShowCoursesList()
{
    ShowTabtScreen("Courses List");
    vector <stCourse> vCourse = LoadCoursesListFromFileToVector();
    short Counter = 0;
    for (stCourse& i : vCourse)
    {
        Counter++;
        cout << Counter << ") Course " << i.Name << " -Code " << i.code << endl;
    }
    return Counter;
}

void PrintCourseDetailsforStudent(const stCourse& Course)
{
    char Answer;
    cout << "\n\nCourse " << Course.Name << " With Code " << Course.code << " -taught by Doctor " << Course.Creatorname << endl << endl;
    if (CheckIfMyCourse(Course.StudentRegistred))
    {
        cout << "You already Registred for this Course ! enjoy ";
        GoBackToStudentMenue();
    }
    cout << "You are not Registred For This Course Do you want to Registre ? y/n";
    cin >> Answer;
    if (towlower(Answer) == 'y')
        StudentRegisterInCourses();
    GoBackToStudentMenue();

}

void PrintStudentInfo(const stStudent& Student)
{


    cout << "\n\t" << "Student : " << Student.FullName << " \n";
    cout << "_____________________________________________" << endl;
    cout << "\n\nID      : " << Student.ID << endl;
    cout << "\nUserName: " << Student.Username << endl;
    cout << "\nEmail   : " << Student.Email << endl;
    cout << "_____________________________________________" << endl;
}

void StudentAreRegistgredinCourse(const stCourse& Course)
{
    vector <stStudent> vStudent = PutStudentCredentialFromFileToVector();
    if (Course.numberOfstudentRegistred == 0)
    {
        cout << "There is no Student Enrolled in this course yet !! ,,,\n\n";
        GoBackToDoctorMenue();
    }
    for (const stStudent& i : vStudent)
    {
        if (CheckIfMyCourse(Course.StudentRegistred, i))
            PrintStudentInfo(i);
    }
    GoBackToDoctorMenue();
}

void PrintCourseDetailsforDoctor(const stCourse& Course)
{
    char Answer;
    cout << "\n\nCourse " << Course.Name << " With Code " << Course.code << " -taught by Doctor " << Course.Creatorname << " Number of Student Registred : " << Course.numberOfstudentRegistred << endl << endl;

    cout << "Do you want to see Registred Student ? y/n";
    cin >> Answer;
    if (towlower(Answer) == 'y')
        StudentAreRegistgredinCourse(Course);

    GoBackToDoctorMenue();

}

short ReadTheCourseChoiceforseeDetails(int CoursesNumber)
{
    short CourseChoice;
    do
    {
        printf("choose the course to view details [1 - %d]  ? ", CoursesNumber);
        cin >> CourseChoice;
    } while (CourseChoice  < 1 || CourseChoice > CoursesNumber);

    return CourseChoice;
}

void ShowCoursesDetails(bool ForStudent = true)
{
    vector <stCourse> vCourse = LoadCoursesListFromFileToVector();

    int CourseNumber = ShowCoursesList();

    short TheChoice = ReadTheCourseChoiceforseeDetails(CourseNumber);

    (ForStudent) ? PrintCourseDetailsforStudent(vCourse[TheChoice - 1]) : PrintCourseDetailsforDoctor(vCourse[TheChoice - 1]);

}

bool CheckIfMyCourse(short RegisterNumber, const stStudent& Student)
{
    return ((Student.RegistredCourses & RegisterNumber) == RegisterNumber);
}

void ShowMyCourseList()
{
    ShowTabtScreen("My Courses List");
    vector <stCourse> vCourse = LoadCoursesListFromFileToVector();
    short Counter = 0;
    for (stCourse& i : vCourse)
    {
        if (CheckIfMyCourse(i.StudentRegistred, CurrentStudent))
        {
            Counter++;
            cout << Counter << ") Course " << i.Name << " -Code " << i.code << endl;
        }
    }
}

void GoBackToStudentMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    StudentScreen();

}

void GoBackToDoctorMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    DoctorScreen();

}

void GotScreen()
{
    short Counter = 0;
    LoadCoursesListFromFileToVector();

}
bool FindCourseByCode(const string& CourseCode)
{

    vector <stCourse> vCourse = LoadCoursesListFromFileToVector();
    for (stCourse& i : vCourse)
    {
        if (CourseCode == i.code)
            return true;
    }
    return false;
}
string ReadCourseCode()
{
    string Code;
    cout << "Enter Course Code : ";
    cin >> Code;
    return Code;
}
string ReadCourseName()
{
    string Username;
    cout << "\nEnter Course Name : ";
    getline(cin >> ws, Username);
    return Username;
}
stCourse CreatCourse(const string& CourseCode)
{
    stCourse Course;
    Course.code = CourseCode;
    cout << "New Course Code " << CourseCode << " Please Enter The Rest Information : \n";
    Course.Name = ReadCourseName();
    Course.StudentRegistred = RandomMultipleOfTwoNumber(1, INT_MAX);
    Course.Creatorname = CurentDoctor.FullName;
    return Course;
}
void CreateCourses()
{

    vector <stCourse> vCourse = LoadCoursesListFromFileToVector();
    string CourseCode = ReadCourseCode();
    char Answer = 'y';
    while (towlower(Answer) == 'y')
    {
        while (FindCourseByCode(CourseCode))
        {
            cout << "Exist Course Code  Try Another One Please ,,,\n\n";
            CourseCode = ReadCourseCode();
        }
        vCourse.push_back(CreatCourse(CourseCode));

        printf(" Created Succsefful ! ,,,\n\n");
        PutCourseCredentialFromVectorToFile(vCourse);
        cout << "Do you want to add more Courses ? y/n ";
        cin >> Answer;
    }
    GoBackToDoctorMenue();
}



void DoctorScreen()
{

    short DoctorChoiceMenu = ShowDoctorMenu();
    switch ((enDoctorMenu)DoctorChoiceMenu)
    {
    case enDoctorMenu::enListCourses:
        ShowCoursesList();
        GoBackToDoctorMenue();
        break;
    case enDoctorMenu::enCreateCourses:
        CreateCourses();
        break;
    case enDoctorMenu::enViewCourses:
        ShowCoursesDetails(false);
        break;
    case enDoctorMenu::enLogOut:
        LoginPage();
        break;
    }
}

short ReadTheCourseChoiceforRegistred(int CoursesNumber)
{
    short CourseChoice;
    do
    {
        printf("choose the course to registre [1 - %d] course to Registre ? ", CoursesNumber);
        cin >> CourseChoice;
    } while (CourseChoice < 1 || CourseChoice > CoursesNumber);
    return CourseChoice;
}

bool RegistreInCourse(const string& StudentUsername, const stStudent& Student)
{
    vector <stStudent> vStudent = PutStudentCredentialFromFileToVector();
    for (stStudent& i : vStudent)
    {
        if (StudentUsername == i.Username)
        {

            i = Student;
            PutStudentCredentialFromVectorToFile(vStudent);
            return true;
        }
    }
    return false;
}

void StudentRegisterInCourses()
{
    vector <stCourse> vCourse = LoadCoursesListFromFileToVector();
    int CourseNumber = ShowCoursesListforRegistred();

    short TheChoice = ReadTheCourseChoiceforRegistred(CourseNumber);
    if (!CheckIfMyCourse(vCourse[TheChoice - 1].StudentRegistred, CurrentStudent))
    {
        CurrentStudent.RegistredCourses += vCourse[TheChoice - 1].StudentRegistred;
        RegistreInCourse(CurrentStudent.Username, CurrentStudent);
    }
    else
    {
        cout << "You already registred ,,,\n\n";
    }


}

void StudentScreen()
{
    short StudentChoiceMenu = ShowStudentMenu();
    switch ((enStudentMenu)StudentChoiceMenu)
    {
    case enStudentMenu::enRegisterInCourse:
        StudentRegisterInCourses();
        GoBackToStudentMenue();
        break;
    case enStudentMenu::enListMyCourses:
        ShowMyCourseList();
        GoBackToStudentMenue();
        break;
    case enStudentMenu::enViewCourse:
        ShowCoursesDetails();
        GoBackToStudentMenue();
        break;
    case enStudentMenu::enGradesReport:
        ShowTabtScreen("Grade will Added Soon,,,,,");
        GoBackToStudentMenue();
        break;
    case enStudentMenu::enLogout:
        LoginPage();
        break;
    }
}

string ReadDoctorID()
{
    string ID;
    cout << "Enter Doctor ID : ";
    cin >> ID;
    return ID;
}

string ReadDoctorUsername()
{
    string Username;
    cout << "\nEnter Doctor Username : ";
    cin >> Username;
    return Username;
}

string ReadDoctorFullname()
{
    string Fullname;
    cout << "\nEnter Doctor Fullname : ";
    getline(cin >> ws, Fullname);
    return Fullname;
}

string ReadDoctorGmail()
{
    string Gmail;
    cout << "\nEnter Doctor Gmail : ";
    getline(cin >> ws, Gmail);
    return Gmail;
}

string ReadDoctorPassword()
{
    string Password;
    cout << "\nEnter Doctor Password : ";
    getline(cin >> ws, Password);
    return Password;
}

string ReadStudentID()
{
    string ID;
    cout << "Enter Student ID : ";
    cin >> ID;
    return ID;
}


string ReadStudentUsername()
{
    string Username;
    cout << "\nEnter Student Username : ";
    cin >> Username;
    return Username;
}

string ReadStudentPassword()
{
    string Password;
    cout << "\nEnter Student Password : ";
    getline(cin >> ws, Password);
    return Password;
}

string ReadStudentFullname()
{
    string Fullname;
    cout << "\nEnter Student Fullname : ";
    getline(cin >> ws, Fullname);
    return Fullname;
}

string ReadStudentGmail()
{
    string Gmail;
    cout << "\nEnter Student Gmail : ";
    getline(cin >> ws, Gmail);
    return Gmail;
}

bool FindDoctorByID(const string& DoctorID)
{

    vector <stDocotor> vDoctor = PutDoctorCredentialFromFileToVector();
    for (stDocotor& i : vDoctor)
    {
        if (DoctorID == i.ID)
            return true;
    }
    return false;
}

bool FindStudentByID(const string& StudentID)
{

    vector <stStudent> vStudent = PutStudentCredentialFromFileToVector();
    for (stStudent& i : vStudent)
    {
        if (StudentID == i.ID)
            return true;
    }
    return false;
}



bool FindDoctorByUsername(const string& DoctorUsername, stDocotor& Doctor)
{
    vector <stDocotor> vDoctor = PutDoctorCredentialFromFileToVector();
    for (stDocotor& i : vDoctor)
    {
        if (DoctorUsername == i.Username)
        {
            Doctor = i;
            return true;
        }
    }
    return false;
}

bool FindStudentByUsername(const string& StudentUsername, stStudent& Student)
{
    vector <stStudent> vStudent = PutStudentCredentialFromFileToVector();
    for (stStudent& i : vStudent)
    {
        if (StudentUsername == i.Username)
        {
            Student = i;
            return true;
        }
    }
    return false;
}

bool isTrueDoctorPassword(const string& DoctorPassword)
{
    vector <stDocotor> vDoctor = PutDoctorCredentialFromFileToVector();
    for (stDocotor& i : vDoctor)
    {
        if (DoctorPassword == i.Password)
            return true;
    }
    return false;
}

bool isTrueStudentPassword(const string& StudentPassword)
{
    vector <stStudent> vStudent = PutStudentCredentialFromFileToVector();
    for (stStudent& i : vStudent)
    {
        if (StudentPassword == i.Password)
            return true;
    }
    return false;
}

bool CheckDoctorCredential(stDocotor& Doctor)
{
    string DoctorUsername = ReadDoctorUsername();
    string DoctorPassword = ReadDoctorPassword();

    short Counter = 0;
    char Answer;
    while (!FindDoctorByUsername(DoctorUsername, Doctor) && !isTrueDoctorPassword(DoctorPassword))
    {
        Counter++;
        cout << "InvaValid/Username/Password Try Again,,,,\n\n";
        if (Counter > 3)
        {
            cout << "Do You Want  To Came Back ? y/n  ";
            cin >> Answer;
            if ('y' == towlower(Answer))
            {
                LoginPage();
                return false;
            }
        }
        DoctorUsername = ReadDoctorUsername();
        DoctorPassword = ReadDoctorPassword();

    }
    return true;
}

bool CheckStudentCredential(stStudent& Student)
{
    string StudentUsername = ReadStudentUsername();
    string StudentPassword = ReadStudentPassword();

    short Counter = 0;
    char Answer;
    while (!FindStudentByUsername(StudentUsername, Student) || !isTrueStudentPassword(StudentPassword))
    {
        Counter++;
        cout << "InvaValid/Username/Password Try Again,,,,\n\n";
        if (Counter > 3)
        {
            cout << "Do You Want  To Came Back ? y/n  ";
            cin >> Answer;
            if ('y' == towlower(Answer))
            {
                LoginPage();
                return false;
            }
        }
        StudentUsername = ReadStudentUsername();
        StudentPassword = ReadStudentPassword();

    }
    return true;
}

stDocotor SignUpDoctor(const string& DoctorId)
{
    stDocotor Doctor;
    Doctor.ID = DoctorId;
    cout << "New Doctor ID " << DoctorId << " Please Enter The Rest Information : \n";
    Doctor.Username = ReadDoctorUsername();
    Doctor.Password = ReadDoctorPassword();
    Doctor.FullName = ReadDoctorFullname();
    Doctor.Email = ReadDoctorGmail();
    return Doctor;
}

stStudent SignUpStudent(const string& StudentId)
{
    stStudent Student;
    Student.ID = StudentId;
    cout << "New Student ID " << StudentId << " Please Enter The Rest Information : \n";
    Student.Username = ReadStudentUsername();
    Student.Password = ReadStudentPassword();
    Student.FullName = ReadStudentFullname();
    Student.Email = ReadStudentGmail();
    return Student;
}


void SignUpDoctorScreen()
{
    SignOrLoginScreen("Sign up ");
    vector <stDocotor> vDocotor = PutDoctorCredentialFromFileToVector();
    string DoctorID = ReadDoctorID();
    char Answer;
    while (FindDoctorByID(DoctorID))
    {
        cout << "Exist Doctor ID Try LogIn Please ,,,\n\n";
        printf("Go to LogIn ? y/n : ");
        cin >> Answer;
        if (towlower(Answer) == 'y')
            LoginPage();
        DoctorID = ReadDoctorID();
    }
    CurentDoctor = SignUpDoctor(DoctorID);
    vDocotor.push_back(CurentDoctor);
    printf("Sign up Succsefful ! ,,,\n\n");
    PutDoctorCredentialFromVectorToFile(vDocotor);

}

void SignUpStudentScreen()
{
    SignOrLoginScreen("Sign up ");
    vector <stStudent> vStudent = PutStudentCredentialFromFileToVector();
    string StudentID = ReadStudentID();
    char Answer;
    while (FindStudentByID(StudentID))
    {
        cout << "Exist Student ID Try LogIn Please ,,,\n\n";
        printf("Go to LogIn ? y/n : ");
        cin >> Answer;
        if (towlower(Answer) == 'y')
            LoginPage();
        StudentID = ReadStudentID();
    }
    CurrentStudent = SignUpStudent(StudentID);
    vStudent.push_back(CurrentStudent);
    printf("Sign up Succsefful ! ,,,\n\n");
    PutStudentCredentialFromVectorToFile(vStudent);

}

void ShowExitScreen()
{
    system("cls");
    cout << "\n---------------------------------\n";
    cout << "\t" << "Exist Screen\n";
    cout << "\n---------------------------------\n";
    exit(0);
}

void CheckFile(const string& File)
{
    fstream Files;
    Files.open(File, ios::in);
    if (!Files.is_open())
    {
        Files.open(File, ios::out);
    }

}

void LoginPage()
{
    system("cls");
    short LoginChoice = ShowLoginPage();
    short UserTypeChoice;

    switch ((enLoginChoice)LoginChoice)
    {
    case enLoginChoice::Login:
        UserTypeChoice = ReadLogin();
        if (UserTypeChoice == enUserType::Doctor)
        {

            if (CheckDoctorCredential(CurentDoctor))
                DoctorScreen();
        }
        else
        {

            if (CheckStudentCredential(CurrentStudent))
                StudentScreen();
        }

        break;
    case enLoginChoice::SignUp:
        UserTypeChoice = ReadLogin("Sign up ");
        if (UserTypeChoice == enUserType::Doctor)
        {
            SignUpDoctorScreen();
            DoctorScreen();
        }
        else
        {
            SignUpStudentScreen();
            StudentScreen();
        }
        break;
    case enLoginChoice::SystemShutDown:
        ShowExitScreen();
        break;
    }
}

void CheckFiles()
{
    CheckFile(DoctorFile);
    CheckFile(StudentFile);
    CheckFile(CoursesFile);
}

int main()
{
    CheckFiles();
    LoginPage();
}

