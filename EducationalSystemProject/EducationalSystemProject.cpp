#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "clsStudentMainMenueScreen.h"
#include "clsDoctorMainMenu.h"
#include "clsLoginPageScreen.h"
using namespace std;

void CheckFile(const string& File)
{
    fstream Files;
    Files.open(File, ios::in);
    if (!Files.is_open())
    {
        Files.open(File, ios::out);
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
	while (true)
	{
        if (!clsLoginPageScreen::ShowLoginPage())
        {
            break;
        }
	}
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             