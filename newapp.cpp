/*
-----------------------------------------
STUDENT MANAGEMENT SYSTEM
Internship Project in C++

Developed By:
Your Name ketaki choudhury

Concepts Used:
- Classes & Objects
- File Handling
- Functions
- CRUD Operations
- Menu Driven Program
-----------------------------------------
*/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    int age;
    string course;
    float marks;

    // Add Student
    void addStudent()
    {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        // Check Duplicate Roll Number
        ifstream checkFile("students.txt");

        string line;

        while(getline(checkFile, line))
        {
            stringstream ss(line);
            string roll;

            getline(ss, roll, '|');

            if(stoi(roll) == rollNo)
            {
                cout << "\nRoll Number Already Exists!\n";
                checkFile.close();
                return;
            }
        }

        checkFile.close();

        ofstream file("students.txt", ios::app);

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Marks: ";
        cin >> marks;

        file << rollNo << "|"
             << name << "|"
             << age << "|"
             << course << "|"
             << marks << endl;

        file.close();

        cout << "\nStudent Added Successfully!\n";
    }

    // Display Students
    void displayStudents()
    {
        ifstream file("students.txt");

        if(!file)
        {
            cout << "\nNo Records Found!\n";
            return;
        }

        string line;

        cout << "\n====================================";
        cout << "\n        STUDENT RECORDS";
        cout << "\n====================================";

        while(getline(file, line))
        {
            stringstream ss(line);

            string roll, studentName, studentAge, studentCourse, studentMarks;
            getline(ss, roll, '|');
            getline(ss, studentName, '|');
            getline(ss, studentAge, '|');
            getline(ss, studentCourse, '|');
            getline(ss, studentMarks, '|');

            cout << "\n\nRoll Number : " << roll;
            cout << "\nName        : " << studentName;
            cout << "\nAge         : " << studentAge;
            cout << "\nCourse      : " << studentCourse;
            cout << "\nMarks       : " << studentMarks;
            cout << "\n------------------------------------";
        }

        file.close();
    }

    // Search Student
    void searchStudent()
    {
        ifstream file("students.txt");

        if(!file)
        {
            cout << "\nNo Records Found!\n";
            return;
        }

        int searchRoll;
        bool found = false;

        cout << "\nEnter Roll Number to Search: ";
        cin >> searchRoll;

        string line;

        while(getline(file, line))
        {
            stringstream ss(line);

            string roll, studentName, studentAge, studentCourse, studentMarks;

            getline(ss, roll, '|');
            getline(ss, studentName, '|');
            getline(ss, studentAge, '|');
            getline(ss, studentCourse, '|');
            getline(ss, studentMarks, '|');

            if(stoi(roll) == searchRoll)
            {
                cout << "\n====================================";
                cout << "\n         STUDENT FOUND";
                cout << "\n====================================";

                cout << "\nRoll Number : " << roll;
                cout << "\nName        : " << studentName;
                cout << "\nAge         : " << studentAge;
                cout << "\nCourse      : " << studentCourse;
                cout << "\nMarks       : " << studentMarks;

                found = true;
                break;
            }
        }

        if(!found)
        {
            cout << "\nStudent Not Found!\n";
        }

        file.close();
    }

    // Update Student
    void updateStudent()
    {
        ifstream file("students.txt");

        if(!file)
        {
            cout << "\nNo Records Found!\n";
            return;
        }

        ofstream tempFile("temp.txt");

        int updateRoll;
        bool found = false;

        cout << "\nEnter Roll Number to Update: ";
        cin >> updateRoll;

        string line;

        while(getline(file, line))
        {
            stringstream ss(line);

            string roll, studentName, studentAge, studentCourse, studentMarks;

            getline(ss, roll, '|');
            getline(ss, studentName, '|');
            getline(ss, studentAge, '|');
            getline(ss, studentCourse, '|');
            getline(ss, studentMarks, '|');

            if(stoi(roll) == updateRoll)
            {
                found = true;

                cin.ignore();

                cout << "\nEnter New Name: ";
                getline(cin, name);

                cout << "Enter New Age: ";
                cin >> age;

                cin.ignore();

                cout << "Enter New Course: ";
                getline(cin, course);

                cout << "Enter New Marks: ";
                cin >> marks;

                tempFile << updateRoll << "|"
                         << name << "|"
                         << age << "|"
                         << course << "|"
                         << marks << endl;

                cout << "\nRecord Updated Successfully!\n";
            }
            else
            {
                tempFile << line << endl;
            }
        }

        file.close();
        tempFile.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if(!found)
        {
            cout << "\nStudent Not Found!\n";
        }
    }

    // Delete Student
    void deleteStudent()
    {
        ifstream file("students.txt");

        if(!file)
        {
            cout << "\nNo Records Found!\n";
            return;
        }

        ofstream tempFile("temp.txt");

        int deleteRoll;
        bool found = false;

        cout << "\nEnter Roll Number to Delete: ";
        cin >> deleteRoll;

        string line;

        while(getline(file, line))
        {
            stringstream ss(line);

            string roll, studentName, studentAge, studentCourse, studentMarks;

            getline(ss, roll, '|');
            getline(ss, studentName, '|');
            getline(ss, studentAge, '|');
            getline(ss, studentCourse, '|');
            getline(ss, studentMarks, '|');

            if(stoi(roll) == deleteRoll)
            {
                found = true;
                cout << "\nRecord Deleted Successfully!\n";
            }
            else
            {
                tempFile << line << endl;
            }
        }

        file.close();
        tempFile.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if(!found)
        {
            cout << "\nStudent Not Found!\n";
        }
    }
};

// Menu Function
void menu()
{
    cout << "\n====================================";
    cout << "\n     STUDENT MANAGEMENT SYSTEM";
    cout << "\n====================================";
    cout << "\n1. Add Student";
    cout << "\n2. Display Students";
    cout << "\n3. Search Student";
    cout << "\n4. Update Student";
    cout << "\n5. Delete Student";
    cout << "\n6. Exit";
    cout << "\n====================================";
    cout << "\nEnter Your Choice: ";
}

// Main Function
int main()
{
    Student s;
    int choice;

    do
    {
        menu();
        cin >> choice;

        switch(choice)
        {
            case 1:
                s.addStudent();
                break;

            case 2:
                s.displayStudents();
                break;

            case 3:
                s.searchStudent();
                break;

            case 4:
                s.updateStudent();
                break;

            case 5:
                s.deleteStudent();
                break;

            case 6:
                cout << "\nThank You For Using Student Management System!\n";
                break;

            default:
                cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while(choice != 6);

    return 0;
}